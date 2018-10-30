

#include "Instruction.h"
#include "../Helper.h"
#include <unistd.h>
#include <string.h>

bool Instruction::enableJumpStub(HookInfo *info) {
    auto origAddr = getOriginalAddr(info);
    auto len = info->getJumpStubLen();
    auto stubAddr = info->getJumpStubBack();
    return patchMemory(origAddr, stubAddr, len);
}

bool Instruction::disableJumpStub(HookInfo *info) {
    auto origAddr = getOriginalAddr(info);
    auto len = info->getBackLen();
    auto stubAddr = info->getOriginalStubBack();
    return patchMemory(origAddr, stubAddr, len);
}

bool Instruction::patchMemory(void *dest, void *src, uint32_t len) {
    if (dest == nullptr || src == nullptr || len == 0) {
        return false;
    }
    if (!Helper::unProtectMemory(dest, len)) {
        return false;
    }

    memcpy(dest, src, len);
    Helper::protectMemory(dest, len);
#ifdef __arm__
    cacheflush((unsigned long) dest, (unsigned long) dest + len, 0);
#endif

#if defined(__aarch64__)
#define __flush_cache(c, n)        __builtin___clear_cache(reinterpret_cast<char *>(c), reinterpret_cast<char *>(c) + n)
    __flush_cache((unsigned long) dest, len);
#endif

    return true;
}

bool Instruction::createBackStub(HookInfo *info) {
    auto len = info->getJumpStubLen();
    if (len == 0) {
        return false;
    }
    auto stub = new uint8_t[len];
    info->setOriginalStubBack(stub);
    info->setBackLen(len);
    memcpy(stub, getOriginalAddr(info), len);
    return true;
}

void *Instruction::getOriginalAddr(HookInfo *info) {
    auto addr = info->getOriginalAddr();
    if (info->getOriginalFunctionType() == THUMB) {
        addr = (void *) ((unsigned long) addr & (~0x1L));
    }
    return addr;
}
