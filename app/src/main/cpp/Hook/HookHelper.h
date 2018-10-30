/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/9/5 上午10:03
* @ class describe
*/

#ifndef UNPACKER_HOOKHELPER_H
#define UNPACKER_HOOKHELPER_H

#include <map>
#include "HookInfo.h"

enum HOOK_STATUS {
    FERROR_UNKNOWN = -1,
    FERROR_SUCCESS = 0,
    FERROR_NOT_REGISTERED,
    FERROR_NOT_EXECUTABLE,
    FERROR_ALREADY_HOOKED,
    FERROR_MEMORY,
};


class HookHelper {
public:
    static HookHelper *getInstance();

    /* you must register a func before hook.
    * callOrigin pointer to call origin funcation, not support yet!!!*/
    HOOK_STATUS registerHook(void *orginalFunAddr, void *newFunAddr,
                             void **callOrigin);

    HookHelper();

    ~HookHelper();

public:
    bool hook(void *originalFunAddr);

    HookInfo *getHookInfo(void *origFunAddr);

    /* do unhook func*/
    bool unhook(void *originalFuncAddr);


    void hookAll();

    void unhookAll();

    /* check whether func is hooked.*/
    bool isAlreadyHooked(void *originalFunAddr);

    /* if func is hooked, return call original address.*/
    void *getCallOriginFuncAddr(void *originalFunAddr);

    /* if func is hooked, return hook func address*/
    void *getNewFunAddr(void *originalFunAddr);

    int getHookedCount();

private:
    std::map<void *, HookInfo *> hook_map;

    /* hook function and flash memory*/
    bool Hook(HookInfo *info);

    /* unhook funciton and flash memory*/
    bool UnHook(HookInfo *info);

    void addHookInfo(HookInfo *info);

    bool delHookInfo(HookInfo *info);
};


#endif //UNPACKER_HOOKHELPER_H
