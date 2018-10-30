/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/9/11 下午2:47
* @ class describe
*/

#ifndef UNPACKER_INSTRUCTION_H
#define UNPACKER_INSTRUCTION_H


#include <cassert>
#include "../HookInfo.h"

class Instruction {
public:
    virtual ~Instruction() {}

    static void *getOriginalAddr(HookInfo *info);

    /*create jump stub to jump to new func*/
    virtual bool createStub(HookInfo *info) = 0;

    /*create original jump stub to jump to old func*/
    virtual bool createCallOriginalStub(HookInfo *info) {
        info->setCallOriginalIns(nullptr);
        assert(false && "not support yet");
        return false;
    };

    /*create back stub*/
    bool createBackStub(HookInfo *info);


    /*make jump stub enable(patch func stub))*/
    static bool enableJumpStub(HookInfo *info);

    /*make jump stub disable(restore old func)*/
    static bool disableJumpStub(HookInfo *info);

    static FunctionType getFunctionType(void *functionAddr) {
#if defined(__arm__)
        if (0 == functionAddr) {
            return ERRTYPE;
        } else if (((unsigned) functionAddr & 3) == 0) {
            return ARM;
        } else {
            return THUMB;
        }
#elif defined(__aarch64__)
        return ARM64;
#elif defined(__i386__)
            return X86;
#elif defined(__x86_64__)
            return X64;
#elif defined(__mips64__)  /* mips64el-* toolchain defines __mips__ too */
            return MIPS64;
#elif defined(__mips__)
            return MIPS;
#endif
    }

    static bool patchMemory(void *dest, void *src, uint32_t len);
};


#endif //UNPACKER_INSTRUCTION_H
