/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/10/26 11:29 AM
* @ class describe
*/

#ifndef UNPACKER_JNIINTERFACE_H
#define UNPACKER_JNIINTERFACE_H

#include <jni.h>
#include <stdarg.h>

class JNIInterface {
public:
    virtual void FindClass(JNIEnv *, const char *) {};

    virtual void FromReflectedMethod(JNIEnv *, jobject) {};

    virtual void FromReflectedField(JNIEnv *, jobject) {};

    virtual void ToReflectedMethod(JNIEnv *, jclass, jmethodID, jboolean) {};

    virtual void GetSuperclass(JNIEnv *, jclass) {};

    virtual void IsAssignableFrom(JNIEnv *, jclass, jclass) {};

    virtual void ToReflectedField(JNIEnv *, jclass, jfieldID, jboolean) {};

    virtual void Throw(JNIEnv *, jthrowable) {};

    virtual void ThrowNew(JNIEnv *, jclass, const char *) {};

    virtual void ExceptionOccurred(JNIEnv *) {};

    virtual void ExceptionDescribe(JNIEnv *) {};

    virtual void ExceptionClear(JNIEnv *) {};

    virtual void FatalError(JNIEnv *, const char *) {};

    virtual void PushLocalFrame(JNIEnv *, jint) {};

    virtual void PopLocalFrame(JNIEnv *, jobject) {};

    virtual void NewGlobalRef(JNIEnv *, jobject) {};

    virtual void DeleteGlobalRef(JNIEnv *, jobject) {};

    virtual void DeleteLocalRef(JNIEnv *, jobject) {};

    virtual void IsSameObject(JNIEnv *, jobject, jobject) {};

    virtual void NewLocalRef(JNIEnv *, jobject) {};

    virtual void EnsureLocalCapacity(JNIEnv *, jint) {};

    virtual void AllocObject(JNIEnv *, jclass) {};

    virtual void NewObject(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void NewObjectV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void NewObjectA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void GetObjectClass(JNIEnv *, jobject) {};

    virtual void IsInstanceOf(JNIEnv *, jobject, jclass) {};

    virtual void GetMethodID(JNIEnv *, jclass, const char *, const char *) {};

    virtual void CallObjectMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallObjectMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallObjectMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallBooleanMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallBooleanMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallBooleanMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallByteMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallByteMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallByteMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallCharMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallCharMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallCharMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallShortMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallShortMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallShortMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallIntMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallIntMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallIntMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallLongMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallLongMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallLongMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallFloatMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallFloatMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallFloatMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallDoubleMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallDoubleMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallDoubleMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallVoidMethod(JNIEnv *, jobject, jmethodID, ...) {};

    virtual void CallVoidMethodV(JNIEnv *, jobject, jmethodID, va_list) {};

    virtual void CallVoidMethodA(JNIEnv *, jobject, jmethodID, jvalue *) {};

    virtual void CallNonvirtualObjectMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualObjectMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualObjectMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualBooleanMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualBooleanMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualBooleanMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualByteMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualByteMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualByteMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualCharMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualCharMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualCharMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualShortMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualShortMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualShortMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualIntMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualIntMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualIntMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualLongMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualLongMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualLongMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualFloatMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualFloatMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualFloatMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualDoubleMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualDoubleMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualDoubleMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void CallNonvirtualVoidMethod(JNIEnv *, jobject, jclass, jmethodID, ...) {};

    virtual void CallNonvirtualVoidMethodV(JNIEnv *, jobject, jclass, jmethodID, va_list) {};

    virtual void CallNonvirtualVoidMethodA(JNIEnv *, jobject, jclass, jmethodID, jvalue *) {};

    virtual void GetFieldID(JNIEnv *, jclass, const char *, const char *) {};

    virtual void GetObjectField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetBooleanField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetByteField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetCharField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetShortField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetIntField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetLongField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetFloatField(JNIEnv *, jobject, jfieldID) {};

    virtual void GetDoubleField(JNIEnv *, jobject, jfieldID) {};

    virtual void SetObjectField(JNIEnv *, jobject, jfieldID, jobject) {};

    virtual void SetBooleanField(JNIEnv *, jobject, jfieldID, jboolean) {};

    virtual void SetByteField(JNIEnv *, jobject, jfieldID, jbyte) {};

    virtual void SetCharField(JNIEnv *, jobject, jfieldID, jchar) {};

    virtual void SetShortField(JNIEnv *, jobject, jfieldID, jshort) {};

    virtual void SetIntField(JNIEnv *, jobject, jfieldID, jint) {};

    virtual void SetLongField(JNIEnv *, jobject, jfieldID, jlong) {};

    virtual void SetFloatField(JNIEnv *, jobject, jfieldID, jfloat) {};

    virtual void SetDoubleField(JNIEnv *, jobject, jfieldID, jdouble) {};

    virtual void GetStaticMethodID(JNIEnv *, jclass, const char *, const char *) {};

    virtual void CallStaticObjectMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticObjectMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticObjectMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticBooleanMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticBooleanMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticBooleanMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticByteMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticByteMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticByteMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticCharMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticCharMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticCharMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticShortMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticShortMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticShortMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticIntMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticIntMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticIntMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticLongMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticLongMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticLongMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticFloatMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticFloatMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticFloatMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticDoubleMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticDoubleMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticDoubleMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void CallStaticVoidMethod(JNIEnv *, jclass, jmethodID, ...) {};

    virtual void CallStaticVoidMethodV(JNIEnv *, jclass, jmethodID, va_list) {};

    virtual void CallStaticVoidMethodA(JNIEnv *, jclass, jmethodID, jvalue *) {};

    virtual void GetStaticFieldID(JNIEnv *, jclass, const char *, const char *) {};

    virtual void GetStaticObjectField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticBooleanField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticByteField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticCharField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticShortField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticIntField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticLongField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticFloatField(JNIEnv *, jclass, jfieldID) {};

    virtual void GetStaticDoubleField(JNIEnv *, jclass, jfieldID) {};

    virtual void SetStaticObjectField(JNIEnv *, jclass, jfieldID, jobject) {};

    virtual void SetStaticBooleanField(JNIEnv *, jclass, jfieldID, jboolean) {};

    virtual void SetStaticByteField(JNIEnv *, jclass, jfieldID, jbyte) {};

    virtual void SetStaticCharField(JNIEnv *, jclass, jfieldID, jchar) {};

    virtual void SetStaticShortField(JNIEnv *, jclass, jfieldID, jshort) {};

    virtual void SetStaticIntField(JNIEnv *, jclass, jfieldID, jint) {};

    virtual void SetStaticLongField(JNIEnv *, jclass, jfieldID, jlong) {};

    virtual void SetStaticFloatField(JNIEnv *, jclass, jfieldID, jfloat) {};

    virtual void SetStaticDoubleField(JNIEnv *, jclass, jfieldID, jdouble) {};

    virtual void NewString(JNIEnv *, const jchar *, jsize) {};

    virtual void GetStringLength(JNIEnv *, jstring) {};

    virtual void GetStringChars(JNIEnv *, jstring, jboolean *) {};

    virtual void ReleaseStringChars(JNIEnv *, jstring, const char *) {};

    virtual void NewStringUTF(JNIEnv *, const char *) {};

    virtual void GetStringUTFLength(JNIEnv *, jstring) {};

    virtual void GetStringUTFChars(JNIEnv *, jstring, jboolean *) {};

    virtual void ReleaseStringUTFChars(JNIEnv *, jstring, const char *) {};

    virtual void GetArrayLength(JNIEnv *, jarray) {};

    virtual void NewObjectArray(JNIEnv *, jsize, jclass, jobject) {};

    virtual void GetObjectArrayElement(JNIEnv *, jobjectArray, jsize) {};

    virtual void SetObjectArrayElement(JNIEnv *, jobjectArray, jsize, jobject) {};

    virtual void NewBooleanArray(JNIEnv *, jsize) {};

    virtual void NewByteArray(JNIEnv *, jsize) {};

    virtual void NewCharArray(JNIEnv *, jsize) {};

    virtual void NewShortArray(JNIEnv *, jsize) {};

    virtual void NewIntArray(JNIEnv *, jsize) {};

    virtual void NewLongArray(JNIEnv *, jsize) {};

    virtual void NewFloatArray(JNIEnv *, jsize) {};

    virtual void NewDoubleArray(JNIEnv *, jsize) {};

    virtual void GetBooleanArrayElements(JNIEnv *, jbooleanArray, jboolean *) {};

    virtual void GetByteArrayElements(JNIEnv *, jbyteArray, jboolean *) {};

    virtual void GetCharArrayElements(JNIEnv *, jcharArray, jboolean *) {};

    virtual void GetShortArrayElements(JNIEnv *, jshortArray, jboolean *) {};

    virtual void GetIntArrayElements(JNIEnv *, jintArray, jboolean *) {};

    virtual void GetLongArrayElements(JNIEnv *, jlongArray, jboolean *) {};

    virtual void GetFloatArrayElements(JNIEnv *, jfloatArray, jboolean *) {};

    virtual void GetDoubleArrayElements(JNIEnv *, jdoubleArray, jboolean *) {};

    virtual void ReleaseBooleanArrayElements(JNIEnv *, jbooleanArray, jboolean *, jint) {};

    virtual void ReleaseByteArrayElements(JNIEnv *, jbyteArray, jbyte *, jint) {};

    virtual void ReleaseCharArrayElements(JNIEnv *, jcharArray, jchar *, jint) {};

    virtual void ReleaseShortArrayElements(JNIEnv *, jshortArray, jshort *, jint) {};

    virtual void ReleaseIntArrayElements(JNIEnv *, jintArray, jint *, jint) {};

    virtual void ReleaseLongArrayElements(JNIEnv *, jlongArray, jlong *, jint) {};

    virtual void ReleaseFloatArrayElements(JNIEnv *, jfloatArray, jfloat *, jint) {};

    virtual void ReleaseDoubleArrayElements(JNIEnv *, jdoubleArray, jdouble *, jint) {};

    virtual void GetBooleanArrayRegion(JNIEnv *, jbooleanArray, jsize, jsize, jboolean *) {};

    virtual void GetByteArrayRegion(JNIEnv *, jbyteArray, jsize, jsize, jbyte *) {};

    virtual void GetCharArrayRegion(JNIEnv *, jcharArray, jsize, jsize, jchar *) {};

    virtual void GetShortArrayRegion(JNIEnv *, jshortArray, jsize, jsize, jshort *) {};

    virtual void GetIntArrayRegion(JNIEnv *, jintArray, jsize, jsize, jint *) {};

    virtual void GetLongArrayRegion(JNIEnv *, jlongArray, jsize, jsize, jlong *) {};

    virtual void GetFloatArrayRegion(JNIEnv *, jfloatArray, jsize, jsize, jfloat *) {};

    virtual void GetDoubleArrayRegion(JNIEnv *, jdoubleArray, jsize, jsize, jdouble *) {};

    virtual void SetBooleanArrayRegion(JNIEnv *, jbooleanArray, jsize, jsize, const jboolean *) {};

    virtual void SetByteArrayRegion(JNIEnv *, jbyteArray, jsize, jsize, const jbyte *) {};

    virtual void SetCharArrayRegion(JNIEnv *, jcharArray, jsize, jsize, const jchar *) {};

    virtual void SetShortArrayRegion(JNIEnv *, jshortArray, jsize, jsize, const jshort *) {};

    virtual void SetIntArrayRegion(JNIEnv *, jintArray, jsize, jsize, const jint *) {};

    virtual void SetLongArrayRegion(JNIEnv *, jlongArray, jsize, jsize, const jlong *) {};

    virtual void SetFloatArrayRegion(JNIEnv *, jfloatArray, jsize, jsize, const jfloat *) {};

    virtual void SetDoubleArrayRegion(JNIEnv *, jdoubleArray, jsize, jsize, const jdouble *) {};

    virtual void RegisterNatives(JNIEnv *, jclass, const JNINativeMethod *, jint) {};

    virtual void UnregisterNatives(JNIEnv *, jclass) {};

    virtual void MonitorEnter(JNIEnv *, jobject) {};

    virtual void MonitorExit(JNIEnv *, jobject) {};

    virtual void GetJavaVM(JNIEnv *, JavaVM **) {};

    virtual void GetStringRegion(JNIEnv *, jstring, jsize, jsize, jchar *) {};

    virtual void GetStringUTFRegion(JNIEnv *, jstring, jsize, jsize, char *) {};

    virtual void GetPrimitiveArrayCritical(JNIEnv *, jarray, jboolean *) {};

    virtual void ReleasePrimitiveArrayCritical(JNIEnv *, jarray, void *, jint) {};

    virtual void GetStringCritical(JNIEnv *, jstring, jboolean *) {};

    virtual void ReleaseStringCritical(JNIEnv *, jstring, const jchar *) {};

    virtual void NewWeakGlobalRef(JNIEnv *, jobject) {};

    virtual void DeleteWeakGlobalRef(JNIEnv *, jweak) {};

    virtual void ExceptionCheck(JNIEnv *) {};

    virtual void NewDirectByteBuffer(JNIEnv *, void *, jlong) {};

    virtual void GetDirectBufferAddress(JNIEnv *, jobject) {};

    virtual void GetDirectBufferCapacity(JNIEnv *, jobject) {};

    virtual ~JNIInterface() {};
};


#endif //UNPACKER_JNIINTERFACE_H
