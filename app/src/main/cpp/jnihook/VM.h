/**
* @ name jnihook
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/10/31 11:16 AM
* @ class describe
*/

#ifndef JNIHOOK_VM_H
#define JNIHOOK_VM_H

#include <jni.h>

class VM {
public:
    static VM *getInstance();


    void hookLoadNativeLibary(void *newFunPtr, bool beforecall);

    const char *getClasstName(jclass clazz);

    const char *getObjectName(jobject object);

    /**
     * you must delete return value
     */
    char *getMethodName(jmethodID jmethodID1);

    /**
     * you must delete return value
     */
    char *getFiledName(jfieldID jfieldID1);

    void closeOptClass();

    void hookDexFileParse(void *newFunPtr, bool beforecall);

public:


private:
    VM();

    int getSdkVersion();

    void *Current();

private:
    int sdk_version;
    void *vm_handle;


};


#endif //JNIHOOK_VM_H
