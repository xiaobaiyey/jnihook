/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/10/25 1:44 PM
* @ class 模块需要art 和 dalvik 两个cpp 用于获取到方法名称
*
*/

#ifndef UNPACKER_JNIHOOK_H
#define UNPACKER_JNIHOOK_H

#include <jni.h>
#include "JNIInterface.h"

class JniHook {
public:
    static JniHook *getInstance(JNIEnv *env, JNIInterface *jniInterface);

    void hookFindClass();

    void hookFromReflectedMethod();

    void hookFromReflectedField();

    void hookToReflectedMethod();

    void hookGetSuperclass();

    void hookIsAssignableFrom();

    void hookToReflectedField();

    void hookThrow();

    void hookThrowNew();

    void hookExceptionOccurred();

    void hookExceptionDescribe();

    void hookExceptionClear();

    void hookFatalError();

    void hookPushLocalFrame();

    void hookPopLocalFrame();

    void hookNewGlobalRef();

    void hookDeleteGlobalRef();

    void hookDeleteLocalRef();

    void hookIsSameObject();

    void hookNewLocalRef();

    void hookEnsureLocalCapacity();

    void hookAllocObject();

    void hookNewObject();

    void hookNewObjectV();

    void hookNewObjectA();

    void hookGetObjectClass();

    void hookIsInstanceOf();

    void hookGetMethodID();

    void hookCallObjectMethod();

    void hookCallObjectMethodV();

    void hookCallObjectMethodA();

    void hookCallBooleanMethod();

    void hookCallBooleanMethodV();

    void hookCallBooleanMethodA();

    void hookCallByteMethod();

    void hookCallByteMethodV();

    void hookCallByteMethodA();

    void hookCallCharMethod();

    void hookCallCharMethodV();

    void hookCallCharMethodA();

    void hookCallShortMethod();

    void hookCallShortMethodV();

    void hookCallShortMethodA();

    void hookCallIntMethod();

    void hookCallIntMethodV();

    void hookCallIntMethodA();

    void hookCallLongMethod();

    void hookCallLongMethodV();

    void hookCallLongMethodA();

    void hookCallFloatMethod();

    void hookCallFloatMethodV();

    void hookCallFloatMethodA();

    void hookCallDoubleMethod();

    void hookCallDoubleMethodV();

    void hookCallDoubleMethodA();

    void hookCallVoidMethod();

    void hookCallVoidMethodV();

    void hookCallVoidMethodA();

    void hookCallNonvirtualObjectMethod();

    void hookCallNonvirtualObjectMethodV();

    void hookCallNonvirtualObjectMethodA();

    void hookCallNonvirtualBooleanMethod();

    void hookCallNonvirtualBooleanMethodV();

    void hookCallNonvirtualBooleanMethodA();

    void hookCallNonvirtualByteMethod();

    void hookCallNonvirtualByteMethodV();

    void hookCallNonvirtualByteMethodA();

    void hookCallNonvirtualCharMethod();

    void hookCallNonvirtualCharMethodV();

    void hookCallNonvirtualCharMethodA();

    void hookCallNonvirtualShortMethod();

    void hookCallNonvirtualShortMethodV();

    void hookCallNonvirtualShortMethodA();

    void hookCallNonvirtualIntMethod();

    void hookCallNonvirtualIntMethodV();

    void hookCallNonvirtualIntMethodA();

    void hookCallNonvirtualLongMethod();

    void hookCallNonvirtualLongMethodV();

    void hookCallNonvirtualLongMethodA();

    void hookCallNonvirtualFloatMethod();

    void hookCallNonvirtualFloatMethodV();

    void hookCallNonvirtualFloatMethodA();

    void hookCallNonvirtualDoubleMethod();

    void hookCallNonvirtualDoubleMethodV();

    void hookCallNonvirtualDoubleMethodA();

    void hookCallNonvirtualVoidMethod();

    void hookCallNonvirtualVoidMethodV();

    void hookCallNonvirtualVoidMethodA();

    void hookGetFieldID();

    void hookGetObjectField();

    void hookGetBooleanField();

    void hookGetByteField();

    void hookGetCharField();

    void hookGetShortField();

    void hookGetIntField();

    void hookGetLongField();

    void hookGetFloatField();

    void hookGetDoubleField();

    void hookSetObjectField();

    void hookSetBooleanField();

    void hookSetByteField();

    void hookSetCharField();

    void hookSetShortField();

    void hookSetIntField();

    void hookSetLongField();

    void hookSetFloatField();

    void hookSetDoubleField();

    void hookGetStaticMethodID();

    void hookCallStaticObjectMethod();

    void hookCallStaticObjectMethodV();

    void hookCallStaticObjectMethodA();

    void hookCallStaticBooleanMethod();

    void hookCallStaticBooleanMethodV();

    void hookCallStaticBooleanMethodA();

    void hookCallStaticByteMethod();

    void hookCallStaticByteMethodV();

    void hookCallStaticByteMethodA();

    void hookCallStaticCharMethod();

    void hookCallStaticCharMethodV();

    void hookCallStaticCharMethodA();

    void hookCallStaticShortMethod();

    void hookCallStaticShortMethodV();

    void hookCallStaticShortMethodA();

    void hookCallStaticIntMethod();

    void hookCallStaticIntMethodV();

    void hookCallStaticIntMethodA();

    void hookCallStaticLongMethod();

    void hookCallStaticLongMethodV();

    void hookCallStaticLongMethodA();

    void hookCallStaticFloatMethod();

    void hookCallStaticFloatMethodV();

    void hookCallStaticFloatMethodA();

    void hookCallStaticDoubleMethod();

    void hookCallStaticDoubleMethodV();

    void hookCallStaticDoubleMethodA();

    void hookCallStaticVoidMethod();

    void hookCallStaticVoidMethodV();

    void hookCallStaticVoidMethodA();

    void hookGetStaticFieldID();

    void hookGetStaticObjectField();

    void hookGetStaticBooleanField();

    void hookGetStaticByteField();

    void hookGetStaticCharField();

    void hookGetStaticShortField();

    void hookGetStaticIntField();

    void hookGetStaticLongField();

    void hookGetStaticFloatField();

    void hookGetStaticDoubleField();

    void hookSetStaticObjectField();

    void hookSetStaticBooleanField();

    void hookSetStaticByteField();

    void hookSetStaticCharField();

    void hookSetStaticShortField();

    void hookSetStaticIntField();

    void hookSetStaticLongField();

    void hookSetStaticFloatField();

    void hookSetStaticDoubleField();

    void hookNewString();

    void hookGetStringLength();

    void hookGetStringChars();

    void hookReleaseStringChars();

    void hookNewStringUTF();

    void hookGetStringUTFLength();

    void hookGetStringUTFChars();

    void hookReleaseStringUTFChars();

    void hookGetArrayLength();

    void hookNewObjectArray();

    void hookGetObjectArrayElement();

    void hookSetObjectArrayElement();

    void hookNewBooleanArray();

    void hookNewByteArray();

    void hookNewCharArray();

    void hookNewShortArray();

    void hookNewIntArray();

    void hookNewLongArray();

    void hookNewFloatArray();

    void hookNewDoubleArray();

    void hookGetBooleanArrayElements();

    void hookGetByteArrayElements();

    void hookGetCharArrayElements();

    void hookGetShortArrayElements();

    void hookGetIntArrayElements();

    void hookGetLongArrayElements();

    void hookGetFloatArrayElements();

    void hookGetDoubleArrayElements();

    void hookReleaseBooleanArrayElements();

    void hookReleaseByteArrayElements();

    void hookReleaseCharArrayElements();

    void hookReleaseShortArrayElements();

    void hookReleaseIntArrayElements();

    void hookReleaseLongArrayElements();

    void hookReleaseFloatArrayElements();

    void hookReleaseDoubleArrayElements();

    void hookGetBooleanArrayRegion();

    void hookGetByteArrayRegion();

    void hookGetCharArrayRegion();

    void hookGetShortArrayRegion();


    void hookGetLongArrayRegion();

    void hookGetFloatArrayRegion();

    void hookGetDoubleArrayRegion();

    void hookSetBooleanArrayRegion();

    void hookSetByteArrayRegion();

    void hookSetCharArrayRegion();

    void hookSetShortArrayRegion();

    void hookSetIntArrayRegion();

    void hookSetLongArrayRegion();

    void hookSetFloatArrayRegion();

    void hookSetDoubleArrayRegion();

    void hookRegisterNatives();

    void hookUnregisterNatives();

    void hookMonitorEnter();

    void hookMonitorExit();

    void hookGetJavaVM();

    void hookGetStringRegion();

    void hookGetStringUTFRegion();

    void hookGetPrimitiveArrayCritical();

    void hookReleasePrimitiveArrayCritical();

    void hookGetStringCritical();

    void hookReleaseStringCritical();

    void hookNewWeakGlobalRef();

    void hookDeleteWeakGlobalRef();

    void hookExceptionCheck();

    void hookNewDirectByteBuffer();

    void hookGetDirectBufferAddress();

    void hookGetDirectBufferCapacity();

    void hookGetObjectRefType();


private:
    JniHook(JNIEnv *env);

    JniHook();

    /*系统版本*/
    int sdk_version;


private:
    JNIEnv *m_env;
};


#endif //UNPACKER_JNIHOOK_H
