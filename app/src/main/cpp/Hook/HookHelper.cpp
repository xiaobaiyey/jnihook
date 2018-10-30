/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/9/5 上午10:03
* @ class describe
*/

#include "HookHelper.h"
#include "instruction/Instruction.h"
#include "Helper.h"

#if defined(__arm__)

#include "instruction/ArmInstruction.h"
#include "instruction/ThumbInstruction.h"
#include "Helper.h"

#elif defined(__aarch64__)
#include "instruction/Arm64Instruction.h"


#elif defined(__i386__) || defined(__x86_64__)
#include "instruction/IntelInstruction.h"
#elif defined(__mips64__)  /* mips64el-* toolchain defines __mips__ too */
#include "instruction/Mips64Instruction.h"
#elif defined(__mips__)
#include "instruction/MipsInstruction.h"
#endif

static HookHelper *mIns = nullptr;

HookHelper *HookHelper::getInstance() {

    if (mIns == nullptr) {
        mIns = new HookHelper();
    }
    return mIns;
}

HookHelper::HookHelper() {

}

HookHelper::~HookHelper() {

}

bool HookHelper::hook(void *originalFunAddr) {
    auto info = getHookInfo(originalFunAddr);
    if (info == nullptr) {
        return false;
    }
    if (info->getHookStatus() == HOOKED) {
        return true;
    } else if (info->getHookStatus() != REGISTERED) {
        return false;
    }
    return Hook(info);
}

bool HookHelper::unhook(void *originalFuncAddr) {
    auto info = getHookInfo(originalFuncAddr);
    if (info == nullptr) {
        return false;
    }
    if (info->getHookStatus() == REGISTERED) {
        return true;
    } else if (info->getHookStatus() != HOOKED) {
        return false;
    }
    return UnHook(info);
}

void HookHelper::hookAll() {
    for (auto it: hook_map) {
        if (it.second->getHookStatus() == REGISTERED) {
            Hook(it.second);
        }
    }
}

void HookHelper::unhookAll() {
    for (auto it: hook_map) {
        if (it.second->getHookStatus() == HOOKED) {
            UnHook(it.second);
        }
    }
}

bool HookHelper::isAlreadyHooked(void *originalFunAddr) {
    auto it = hook_map.find(originalFunAddr);
    if (it == hook_map.end()) {
        return false;
    }
    auto info = it->second;
    return info->getHookStatus() == HOOKED;
}

void *HookHelper::getCallOriginFuncAddr(void *originalFunAddr) {
    auto info = getHookInfo(originalFunAddr);
    if (info == nullptr) {
        return 0;
    }
    return (void *) info->getCallOriginalIns();
}

void *HookHelper::getNewFunAddr(void *originalFunAddr) {
    auto info = getHookInfo(originalFunAddr);
    if (info == nullptr) {
        return 0;
    }
    return (void *) info->getHookAddr();
}

int HookHelper::getHookedCount() {
    return hook_map.size();
}

HookInfo *HookHelper::getHookInfo(void *origFunAddr) {
    auto it = hook_map.find(origFunAddr);
    if (it == hook_map.end()) {
        return nullptr;
    }
    return it->second;
}

bool HookHelper::Hook(HookInfo *info) {
    if (!Instruction::enableJumpStub(info)) {
        return false;
    }
    info->setHookStatus(HOOKED);
    return true;
}

bool HookHelper::UnHook(HookInfo *info) {
    if (!Instruction::disableJumpStub(info)) {
        return false;
    }
    info->setHookStatus(REGISTERED);
    return true;
}

void HookHelper::addHookInfo(HookInfo *info) {
    hook_map[(void *) info->getOriginalAddr()] = info;
}

bool HookHelper::delHookInfo(HookInfo *info) {
    auto it = hook_map.find((void *) info->getOriginalAddr());
    if (it != hook_map.end()) {
        delete it->second;
        hook_map.erase(it);
        return true;
    }
    return false;
}

HOOK_STATUS HookHelper::registerHook(void *orginalFunAddr, void *newFunAddr, void **callOrigin) {
    if (!Helper::isFunctionAddr((void *) orginalFunAddr)
        || !Helper::isFunctionAddr((void *) newFunAddr)) {
        return FERROR_NOT_EXECUTABLE;
    }

    auto info = getHookInfo(orginalFunAddr);
    if (nullptr != info) {
        auto hookStatus = info->getHookStatus();
        if (HOOKED == hookStatus) {
            return FERROR_ALREADY_HOOKED;
        } else if (REGISTERED == hookStatus) {
            delHookInfo(info);
        }
    }

    // check for FunctionType
    auto type = Instruction::getFunctionType(orginalFunAddr);
    if (ERRTYPE == type) {
        return FERROR_UNKNOWN;
    }

    info = new HookInfo((void *) orginalFunAddr, (void *) newFunAddr);
    info->setOriginalFunctionType(type);

    Instruction *instruction = nullptr;
    switch (type) {
#if defined(__arm__)
        case ARM:
            instruction = new ArmInstruction();
            break;
        case THUMB:
            instruction = new ThumbInstruction();
            break;
#elif defined(__aarch64__)
        case ARM64:
            instruction = new Arm64Instruction();
            break;
#elif defined(__i386__) || defined(__x86_64__)
        case X86:
        case X64:
            instruction = new IntelInstruction();
            break;
#elif defined(__mips64__)
            case MIPS64:
            instruction = new Mips64Instruction();
            break;
#elif defined(__mips__)
        case MIPS:
            instruction = new MipsInstruction();
            break;
#endif
        default:
            assert(false && "not support abi");
            return FERROR_UNKNOWN;
            break;
    }

    if (!instruction->createStub(info)
        || !instruction->createBackStub(info)
        || (callOrigin != nullptr) ?
        !instruction->createCallOriginalStub(info) : false  // want a callback
            ) {
        delete instruction;
        delete info;
        return FERROR_MEMORY;
    }

    addHookInfo(info);
    info->setHookStatus(REGISTERED);

    if (callOrigin != nullptr) {
        *callOrigin = (void *) info->getCallOriginalIns();
    }

    delete instruction;
    return FERROR_SUCCESS;
}
