/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/10/25 1:44 PM
* @ class 用来hook jni相关方法
* 功能只能用于插装,不能用于拦截
*
*/

#include "JniHook.h"
#include "JNIInterface.h"
#include <HookHelper.h>
/**
 * 定义宏 hook
 */
#define HOOKJNI(_funname, _val)              \
        {                                   \
        HookHelper* helper=HookHelper::getInstance();\
        helper->registerHook((void *) *(unsigned int *) ((*(unsigned int *) this->m_env) + _val), \
        ((void*)&my ## _funname),\
        ((void**)&old ## _funname));\
        helper->hook((void *) *(unsigned int *) ((*(unsigned int *) this->m_env) + _val));\
        }                            \

static JniHook *jniHook = nullptr;
static JNIInterface *gjniInterface = nullptr;

JniHook::JniHook(JNIEnv *env) : m_env(env) {
}

JniHook::JniHook() {

}

JniHook *JniHook::getInstance(JNIEnv *env, JNIInterface *jniInterface) {
    if (jniHook == nullptr) {
        jniHook = new JniHook(env);
    }
    if (jniInterface != nullptr) {
        gjniInterface = jniInterface;
    }
    return jniHook;
}


jclass (*oldFindClass)(JNIEnv *env, const char *name);

jclass myFindClass(JNIEnv *env, const char *name) {

    gjniInterface->FindClass(env, name);
    return oldFindClass(env, name);
}

void JniHook::hookFindClass() {
    HOOKJNI(FindClass, 0x18);
}

jint (*oldRegisterNatives)(JNIEnv *env, jclass jclazz,
                           const JNINativeMethod *methods, jint nMethods);

jint myRegisterNatives(JNIEnv *env, jclass jclazz,
                       const JNINativeMethod *methods, jint nMethods) {
    gjniInterface->RegisterNatives(env, jclazz, methods, nMethods);
    return oldRegisterNatives(env, jclazz, methods, nMethods);
}

void JniHook::hookRegisterNatives() {
    HOOKJNI(RegisterNatives, 0x35c);
}

jmethodID (*oldGetMethodID)(JNIEnv *env, jclass jclazz, const char *name, const char *sig);

jmethodID myGetMethodID(JNIEnv *env, jclass jclazz, const char *name, const char *sig) {

    gjniInterface->GetMethodID(env, jclazz, name, sig);
    return oldGetMethodID(env, jclazz, name, sig);
}

void JniHook::hookGetMethodID() {
    HOOKJNI(GetMethodID, 0x84);
}


jclass (*oldGetSuperclass)(JNIEnv *env, jclass jclazz);

jclass myGetSuperclass(JNIEnv *env, jclass jclazz) {
    gjniInterface->GetSuperclass(env, jclazz);
    return oldGetSuperclass(env, jclazz);
}

void JniHook::hookGetSuperclass() {
    HOOKJNI(GetSuperclass, offsetof(JNINativeInterface, GetSuperclass));
}


jmethodID (*oldFromReflectedMethod)(JNIEnv *env, jobject jmethod);

jmethodID myFromReflectedMethod(JNIEnv *env, jobject jmethod) {
    gjniInterface->FromReflectedMethod(env, jmethod);
    return oldFromReflectedMethod(env, jmethod);
}


jfieldID (*oldFromReflectedField)(JNIEnv *env, jobject jfield);

jfieldID myFromReflectedField(JNIEnv *env, jobject jfield) {
    gjniInterface->FromReflectedField(env, jfield);
    return oldFromReflectedField(env, jfield);
}


jobject (*oldToReflectedMethod)(JNIEnv *env, jclass jcls, jmethodID methodID, jboolean isStatic);

jobject myToReflectedMethod(JNIEnv *env, jclass jcls, jmethodID methodID, jboolean isStatic) {

    gjniInterface->ToReflectedMethod(env, jcls, methodID, isStatic);
    return oldToReflectedMethod(env, jcls, methodID, isStatic);
}

/*
* Determine whether an object of clazz1 can be safely cast to clazz2.
*
* Like IsInstanceOf, but with a pair of class objects instead of obj+class.
*/
jboolean (*oldIsAssignableFrom)(JNIEnv *env, jclass jclazz1, jclass jclazz2);

jboolean myIsAssignableFrom(JNIEnv *env, jclass jclazz1, jclass jclazz2) {
    /*	ScopedJniThreadState ts(env);
        ClassObject* clazz1 = (ClassObject*)dvmDecodeIndirectRef(ts.self(), jclazz1);
        ClassObject* clazz2 = (ClassObject*)dvmDecodeIndirectRef(ts.self(), jclazz2);*/
    gjniInterface->IsAssignableFrom(env, jclazz1, jclazz2);
    return oldIsAssignableFrom(env, jclazz1, jclazz2);
}

/*
* Convert a fieldID to a java.lang.reflect.Field.
*
* (The "isStatic" field does not appear in the spec.)
*
* Throws OutOfMemory and returns NULL on failure.
*/
jobject (*oldToReflectedField)(JNIEnv *env, jclass jcls, jfieldID fieldID, jboolean isStatic);

jobject myToReflectedField(JNIEnv *env, jclass jcls, jfieldID fieldID, jboolean isStatic) {
    /*ScopedJniThreadState ts(env);
    ClassObject* clazz = (ClassObject*)dvmDecodeIndirectRef(ts.self(), jcls);
    Object* obj = dvmCreateReflectObjForField(clazz, (Field*)fieldID);
    dvmReleaseTrackedAlloc(obj, NULL);*/
    gjniInterface->ToReflectedField(env, jcls, fieldID, isStatic);
    return oldToReflectedField(env, jcls, fieldID, isStatic);
}


/*
* Take this exception and throw it.
*/
jint (*oldThrow)(JNIEnv *env, jthrowable jobj);

jint myThrow(JNIEnv *env, jthrowable jobj) {
    /*ScopedJniThreadState ts(env);
    if (jobj != NULL) {
        Object* obj = dvmDecodeIndirectRef(ts.self(), jobj);
        dvmSetException(ts.self(), obj);
        return JNI_OK;
    }*/
    gjniInterface->Throw(env, jobj);
    return oldThrow(env, jobj);
}

/*
* Constructs an exception object from the specified class with the message
* specified by "message", and throws it.
*/
jint (*oldThrowNew)(JNIEnv *env, jclass jclazz, const char *message);

jint myThrowNew(JNIEnv *env, jclass jclazz, const char *message) {
    /*	ScopedJniThreadState ts(env);
        ClassObject* clazz = (ClassObject*)dvmDecodeIndirectRef(ts.self(), jclazz);
        dvmThrowException(clazz, message);*/
    // TODO: should return failure if this didn't work (e.g. OOM)
    gjniInterface->ThrowNew(env, jclazz, message);
    return oldThrowNew(env, jclazz, message);
}

/*
* If an exception is being thrown, return the exception object.  Otherwise,
* return NULL.
*
* TODO: if there is no pending exception, we should be able to skip the
* enter/exit checks.  If we find one, we need to enter and then re-fetch
* the exception (in case it got moved by a compacting GC).
*/
jthrowable (*oldExceptionOccurred)(JNIEnv *env);

jthrowable myExceptionOccurred(JNIEnv *env) {
    gjniInterface->ExceptionOccurred(env);
    return oldExceptionOccurred(env);
}

/*
* Print an exception and stack trace to stderr.
*/
void (*oldExceptionDescribe)(JNIEnv *env);

void myExceptionDescribe(JNIEnv *env) {
    gjniInterface->ExceptionDescribe(env);
    return;
}

/*
* Clear the exception currently being thrown.
*
* TODO: we should be able to skip the enter/exit stuff.
*/
void (*oldExceptionClear)(JNIEnv *env);

void myExceptionClear(JNIEnv *env) {
    /*ScopedJniThreadState ts(env);
    dvmClearException(ts.self());*/
    gjniInterface->ExceptionClear(env);
    oldExceptionClear(env);
}

/*
* Kill the VM.  This function does not return.
*/
void (*oldFatalError)(JNIEnv *env, const char *msg);

void myFatalError(JNIEnv *env, const char *msg) {
    gjniInterface->FatalError(env, msg);
    oldFatalError(env, msg);
}

/*
* Push a new JNI frame on the stack, with a new set of locals.
*
* The new frame must have the same method pointer.  (If for no other
* reason than FindClass needs it to get the appropriate class loader.)
*/
jint (*oldPushLocalFrame)(JNIEnv *env, jint capacity);

jint myPushLocalFrame(JNIEnv *env, jint capacity) {
    gjniInterface->PushLocalFrame(env, capacity);
    return oldPushLocalFrame(env, capacity);
}


jobject (*oldPopLocalFrame)(JNIEnv *env, jobject jresult);

jobject myPopLocalFrame(JNIEnv *env, jobject jresult) {
    gjniInterface->PopLocalFrame(env, jresult);
    return oldPopLocalFrame(env, jresult);
}


jobject (*oldNewGlobalRef)(JNIEnv *env, jobject jobj);

jobject myNewGlobalRef(JNIEnv *env, jobject jobj) {
    /*ScopedJniThreadState ts(env);
    Object* obj = dvmDecodeIndirectRef(ts.self(), jobj);
    return addGlobalReference(obj);*/
    gjniInterface->NewGlobalRef(env, jobj);
    return oldNewGlobalRef(env, jobj);
}

/*
* Delete a reference from the global list.
*/
void (*oldDeleteGlobalRef)(JNIEnv *env, jobject jglobalRef);

void myDeleteGlobalRef(JNIEnv *env, jobject jglobalRef) {
    /*	ScopedJniThreadState ts(env);
        deleteGlobalReference(jglobalRef);*/
    gjniInterface->DeleteGlobalRef(env, jglobalRef);
    oldDeleteGlobalRef(env, jglobalRef);
}


/*
* Add a reference to the local list.
*/
jobject (*oldNewLocalRef)(JNIEnv *env, jobject jobj);

jobject myNewLocalRef(JNIEnv *env, jobject jobj) {
    /*ScopedJniThreadState ts(env);
    Object* obj = dvmDecodeIndirectRef(ts.self(), jobj);*/
    gjniInterface->NewLocalRef(env, jobj);
    return oldNewLocalRef(env, jobj);
}

/*
* Delete a reference from the local list.
*/
void (*oldDeleteLocalRef)(JNIEnv *env, jobject jlocalRef);

void myDeleteLocalRef(JNIEnv *env, jobject jlocalRef) {
    /*ScopedJniThreadState ts(env);
    deleteLocalReference(ts.self(), jlocalRef);*/
    gjniInterface->DeleteLocalRef(env, jlocalRef);
    oldDeleteLocalRef(env, jlocalRef);
}

/*
* Ensure that the local references table can hold at least this many
* references.
*/
jint (*oldEnsureLocalCapacity)(JNIEnv *env, jint capacity);

jint myEnsureLocalCapacity(JNIEnv *env, jint capacity) {
    /*ScopedJniThreadState ts(env);
    bool okay = ensureLocalCapacity(ts.self(), capacity);
    if (!okay)
    {
        dvmThrowOutOfMemoryError("can't ensure local reference capacity");
    }
    return okay ? 0 : -1;*/
    gjniInterface->EnsureLocalCapacity(env, capacity);
    return oldEnsureLocalCapacity(env, capacity);
}


/*
* Determine whether two Object references refer to the same underlying object.
*/
jboolean (*oldIsSameObject)(JNIEnv *env, jobject jref1, jobject jref2);

jboolean myIsSameObject(JNIEnv *env, jobject jref1, jobject jref2) {
    /*ScopedJniThreadState ts(env);
    Object* obj1 = dvmDecodeIndirectRef(ts.self(), jref1);
    Object* obj2 = dvmDecodeIndirectRef(ts.self(), jref2);
    return (obj1 == obj2);*/
    gjniInterface->IsSameObject(env, jref1, jref2);
    return oldIsSameObject(env, jref1, jref2);
}

/*
* Allocate a new object without invoking any constructors.
*/
jobject (*oldAllocObject)(JNIEnv *env, jclass jclazz);

jobject myAllocObject(JNIEnv *env, jclass jclazz) {

    gjniInterface->AllocObject(env, jclazz);
    return oldAllocObject(env, jclazz);
}

jobject (*oldNewObjectV)(JNIEnv *env, jclass jclazz, jmethodID methodID, va_list args);

jobject myNewObjectV(JNIEnv *env, jclass jclazz, jmethodID methodID, va_list args) {
    /*ScopedJniThreadState ts(env);
    ClassObject* clazz = (ClassObject*)dvmDecodeIndirectRef(ts.self(), jclazz);

    if (!canAllocClass(clazz) || (!dvmIsClassInitialized(clazz) && !dvmInitClass(clazz))) {
        assert(dvmCheckException(ts.self()));
        return NULL;
    }

    Object* newObj = dvmAllocObject(clazz, ALLOC_DONT_TRACK);
    jobject result = addLocalReference(ts.self(), newObj);
    if (newObj != NULL) {
        JValue unused;
        dvmCallMethodV(ts.self(), (Method*)methodID, newObj, true, &unused, args);
    }*/
    gjniInterface->NewObjectV(env, jclazz, methodID, args);
    return oldNewObjectV(env, jclazz, methodID, args);
}

/*
* Allocate a new object and invoke the supplied constructor.
*/
jobject (*oldNewObject)(JNIEnv *env, jclass jclazz, jmethodID methodID, ...);

jobject myNewObject(JNIEnv *env, jclass jclazz, jmethodID methodID, ...) {
    if (oldNewObjectV != nullptr) {
        va_list args;
        va_start(args, methodID);
        jobject res = oldNewObjectV(env, jclazz, methodID, args);
        va_end(args);
        return res;
    } else {
        va_list args;
        va_start(args, methodID);
        jobject res = env->NewObject(jclazz, methodID, args);
        va_end(args);
        return res;
    }
}

jobject (*oldNewObjectA)(JNIEnv *env, jclass jclazz, jmethodID methodID, jvalue *args);

jobject myNewObjectA(JNIEnv *env, jclass jclazz, jmethodID methodID, jvalue *args) {
    gjniInterface->NewObjectA(env, jclazz, methodID, args);

    return oldNewObjectA(env, jclazz, methodID, args);
}


jclass (*oldGetObjectClass)(JNIEnv *env, jobject jobj);

jclass myGetObjectClass(JNIEnv *env, jobject jobj) {
    gjniInterface->GetObjectClass(env, jobj);
    return oldGetObjectClass(env, jobj);
}

jboolean (*oldIsInstanceOf)(JNIEnv *env, jobject jobj, jclass jclazz);

jboolean myIsInstanceOf(JNIEnv *env, jobject jobj, jclass jclazz) {
    gjniInterface->IsInstanceOf(env, jobj, jclazz);
    return oldIsInstanceOf(env, jobj, jclazz);
}

/*
* Get a field ID (instance fields).
*/
jfieldID (*oldGetFieldID)(JNIEnv *env, jclass jclazz, const char *name, const char *sig);

jfieldID myGetFieldID(JNIEnv *env, jclass jclazz, const char *name, const char *sig) {
    gjniInterface->GetFieldID(env, jclazz, name, sig);
    return oldGetFieldID(env, jclazz, name, sig);
}

/*
* Get the method ID for a  method in a class.
*/
jmethodID (*oldGetStaticMethodID)(JNIEnv *env, jclass jclazz, const char *name, const char *sig);

jmethodID myGetStaticMethodID(JNIEnv *env, jclass jclazz, const char *name, const char *sig) {
    gjniInterface->GetStaticMethodID(env, jclazz, name, sig);
    return oldGetStaticMethodID(env, jclazz, name, sig);
}

/*
* Get a field ID ( fields).
*/
jfieldID (*oldGetStaticFieldID)(JNIEnv *env, jclass jclazz, const char *name, const char *sig);

jfieldID myGetStaticFieldID(JNIEnv *env, jclass jclazz, const char *name, const char *sig) {
    gjniInterface->GetStaticFieldID(env, jclazz, name, sig);
    return oldGetStaticFieldID(env, jclazz, name, sig);
}

/*
* Get a  field.
*
* If we get an object reference, add it to the local refs list.
*/
#define GET_STATIC_TYPE_FIELD(_ctype, _jname, _isref)                            \
     _ctype (*oldGetStatic##_jname##Field)(JNIEnv* env, jclass jclazz,    \
        jfieldID fieldID);                                                        \
     _ctype myGetStatic##_jname##Field(JNIEnv* env, jclass jclazz,            \
        jfieldID fieldID)                                                        \
    {                                                                            \
        gjniInterface->GetStatic##_jname##Field(env,jclazz,fieldID);\
        return oldGetStatic##_jname##Field(env,jclazz,fieldID);                    \
    }

GET_STATIC_TYPE_FIELD(jobject, Object, true);

GET_STATIC_TYPE_FIELD(jboolean, Boolean, false);

GET_STATIC_TYPE_FIELD(jbyte, Byte, false);

GET_STATIC_TYPE_FIELD(jchar, Char, false);

GET_STATIC_TYPE_FIELD(jshort, Short, false);

GET_STATIC_TYPE_FIELD(jint, Int, false);

GET_STATIC_TYPE_FIELD(jlong, Long, false);

GET_STATIC_TYPE_FIELD(jfloat, Float, false);

GET_STATIC_TYPE_FIELD(jdouble, Double, false);


/*
* Set a  field.
*/
#define SET_STATIC_TYPE_FIELD(_ctype, _ctype2, _jname, _isref)              \
      void (*oldSetStatic##_jname##Field)(JNIEnv* env, jclass jclazz,  \
        jfieldID fieldID, _ctype value);                                    \
     void mySetStatic##_jname##Field(JNIEnv* env, jclass jclazz,        \
        jfieldID fieldID, _ctype value)                                     \
    {                                                                       \
        gjniInterface->SetStatic##_jname##Field(env,jclazz,fieldID,value); \
        oldSetStatic##_jname##Field(env,jclazz,fieldID,value);                \
    }


SET_STATIC_TYPE_FIELD(jobject, Object *, Object, true);

SET_STATIC_TYPE_FIELD(jboolean, bool, Boolean, false);

SET_STATIC_TYPE_FIELD(jbyte, s1, Byte, false);

SET_STATIC_TYPE_FIELD(jchar, u2, Char, false);

SET_STATIC_TYPE_FIELD(jshort, s2, Short, false);

SET_STATIC_TYPE_FIELD(jint, s4, Int, false);

SET_STATIC_TYPE_FIELD(jlong, s8, Long, false);

SET_STATIC_TYPE_FIELD(jfloat, float, Float, false);

SET_STATIC_TYPE_FIELD(jdouble, double, Double, false);


/*
* Get an instance field.
*
* If we get an object reference, add it to the local refs list.
*/
#define GET_TYPE_FIELD(_ctype, _jname, _isref)                              \
     _ctype (*oldGet##_jname##Field)(JNIEnv* env, jobject jobj,       \
        jfieldID fieldID);                                                   \
     _ctype myGet##_jname##Field(JNIEnv* env, jobject jobj,             \
        jfieldID fieldID)                                                   \
    {                                                                       \
        gjniInterface->Get##_jname##Field(env,jobj,fieldID);  \
        return oldGet##_jname##Field(env,jobj,fieldID);                        \
    }


GET_TYPE_FIELD(jobject, Object, true);

GET_TYPE_FIELD(jboolean, Boolean, false);

GET_TYPE_FIELD(jbyte, Byte, false);

GET_TYPE_FIELD(jchar, Char, false);

GET_TYPE_FIELD(jshort, Short, false);

GET_TYPE_FIELD(jint, Int, false);

GET_TYPE_FIELD(jlong, Long, false);

GET_TYPE_FIELD(jfloat, Float, false);

GET_TYPE_FIELD(jdouble, Double, false);


/*
* Set an instance field.
*/
#define SET_TYPE_FIELD(_ctype, _ctype2, _jname, _isref)                     \
     void (*oldSet##_jname##Field)(JNIEnv* env, jobject jobj,          \
        jfieldID fieldID, _ctype value);                                     \
     void mySet##_jname##Field(JNIEnv* env, jobject jobj,               \
        jfieldID fieldID, _ctype value)                                     \
    {                                                                       \
        gjniInterface->Set##_jname##Field(env,jobj,fieldID,value); \
        oldSet##_jname##Field(env,jobj,fieldID,value);                        \
    }


SET_TYPE_FIELD(jobject, Object *, Object, true);

SET_TYPE_FIELD(jboolean, bool, Boolean, false);

SET_TYPE_FIELD(jbyte, s1, Byte, false);

SET_TYPE_FIELD(jchar, u2, Char, false);

SET_TYPE_FIELD(jshort, s2, Short, false);

SET_TYPE_FIELD(jint, s4, Int, false);

SET_TYPE_FIELD(jlong, s8, Long, false);

SET_TYPE_FIELD(jfloat, float, Float, false);

SET_TYPE_FIELD(jdouble, double, Double, false);


/*
* Make a virtual method call.
*
* Three versions (..., va_list, jvalue[]) for each return type.  If we're
* returning an Object, we have to add it to the local references table.
*/
#define CALL_VIRTUAL(_ctype, _jname, _retfail, _retok, _isref)              \
     _ctype (*oldCall##_jname##MethodV)(JNIEnv* env, jobject jobj,          \
        jmethodID methodID, va_list args);                                  \
     _ctype myCall##_jname##MethodV(JNIEnv* env, jobject jobj,              \
        jmethodID methodID, va_list args)                                   \
    {                                                                       \
        gjniInterface->Call##_jname##MethodV(env,jobj,methodID,args);       \
        return oldCall##_jname##MethodV(env,jobj,methodID,args);            \
    }                                                                       \
      _ctype (*oldCall##_jname##Method)(JNIEnv* env, jobject jobj,          \
        jmethodID methodID, ...);                                           \
     _ctype myCall##_jname##Method(JNIEnv* env, jobject jobj,               \
        jmethodID methodID, ...)                                            \
    {                                                                       \
        if(oldCall##_jname##MethodV==NULL){                                 \
             va_list args;                                                  \
             va_start(args, methodID);                                      \
            _ctype result=env->Call##_jname##MethodV(jobj,methodID,args);    \
             va_end(args);\
            return    result;    \
        }else{                                                                \
                                                                            \
        va_list args;                                                        \
        va_start(args, methodID);                                            \
        _ctype result = oldCall##_jname##MethodV(env,jobj, methodID, args);    \
        va_end(args);                                                        \
        return    result;        }                                                    \
                                                                                \
    }                                                                       \
      _ctype (*oldCall##_jname##MethodA)(JNIEnv* env, jobject jobj,   \
        jmethodID methodID, jvalue* args);                                  \
     _ctype myCall##_jname##MethodA(JNIEnv* env, jobject jobj,          \
        jmethodID methodID, jvalue* args)                                   \
    {                                                                       \
        gjniInterface->Call##_jname##MethodA(env,jobj,methodID,args); \
        return oldCall##_jname##MethodA(env,jobj,methodID,args);            \
    }

CALL_VIRTUAL(jobject, Object, NULL, (jobject) result.l, true);

CALL_VIRTUAL(jboolean, Boolean, 0, result.z, false);

CALL_VIRTUAL(jbyte, Byte, 0, result.b, false);

CALL_VIRTUAL(jchar, Char, 0, result.c, false);

CALL_VIRTUAL(jshort, Short, 0, result.s, false);

CALL_VIRTUAL(jint, Int, 0, result.i, false);

CALL_VIRTUAL(jlong, Long, 0, result.j, false);

CALL_VIRTUAL(jfloat, Float, 0.0f, result.f, false);

CALL_VIRTUAL(jdouble, Double, 0.0, result.d, false);


#define CALL_VIRTUAL_VOID(_jname, _retfail, _retok, _isref)              \
     void (*oldCall##_jname##MethodV)(JNIEnv* env, jobject jobj,          \
        jmethodID methodID, va_list args);                                  \
     void myCall##_jname##MethodV(JNIEnv* env, jobject jobj,          \
        jmethodID methodID, va_list args)                                   \
    {                                                                       \
        gjniInterface->Call##_jname##MethodV(env,jobj,methodID,args);      \
        return oldCall##_jname##MethodV(env,jobj,methodID,args);              \
    }                                                                       \
      void (*oldCall##_jname##Method)(JNIEnv* env, jobject jobj,           \
        jmethodID methodID, ...);\
     void myCall##_jname##Method(JNIEnv* env, jobject jobj,           \
        jmethodID methodID, ...)                                            \
    {                                                                       \
        if(oldCall##_jname##MethodV==NULL){                            \
             va_list args;    \
             va_start(args, methodID);\
            env->Call##_jname##MethodV(jobj,methodID,args);    \
             va_end(args);\
        }else{                                                                \
                                                                            \
        va_list args;                                                        \
        va_start(args, methodID);                                            \
        oldCall##_jname##MethodV(env,jobj, methodID, args);    \
        va_end(args);                                                        \
            }                                                    \
                                                                                \
    }                                                                       \
      void (*oldCall##_jname##MethodA)(JNIEnv* env, jobject jobj,   \
        jmethodID methodID, jvalue* args);                                  \
     void myCall##_jname##MethodA(JNIEnv* env, jobject jobj,          \
        jmethodID methodID, jvalue* args)                                   \
    {                     \
         gjniInterface->Call##_jname##MethodA(env,jobj,methodID,args); \
        return oldCall##_jname##MethodA(env,jobj,methodID,args);            \
    }

CALL_VIRTUAL_VOID(Void, , , false);
/*
* Make a "non-virtual" method call.  We're still calling a virtual method,
* but this time we're not doing an indirection through the object's vtable.
* The "clazz" parameter defines which implementation of a method we want.
*
* Three versions (..., va_list, jvalue[]) for each return type.
*/

#define CALL_NONVIRTUAL(_ctype, _jname, _retfail, _retok, _isref)           \
      _ctype (*oldCallNonvirtual##_jname##MethodV)(JNIEnv* env, jobject jobj,\
        jclass jclazz, jmethodID methodID, va_list args);                    \
      _ctype myCallNonvirtual##_jname##MethodV(JNIEnv* env, jobject jobj,\
        jclass jclazz, jmethodID methodID, va_list args)                    \
    {                                                                       \
        gjniInterface->CallNonvirtual##_jname##MethodV(env,jobj,jclazz,methodID,args); \
        return oldCallNonvirtual##_jname##MethodV(env,jobj,jclazz,methodID,args); \
    }                                                                       \
     _ctype (*oldCallNonvirtual##_jname##Method)(JNIEnv* env, jobject jobj, \
        jclass jclazz, jmethodID methodID, ...);                            \
     _ctype myCallNonvirtual##_jname##Method(JNIEnv* env, jobject jobj, \
        jclass jclazz, jmethodID methodID, ...)                             \
    {                                                                       \
        if(oldCall##_jname##MethodV==NULL){                            \
             va_list args;    \
             va_start(args, methodID);\
            _ctype result=env->CallNonvirtual##_jname##MethodV(jobj, jclazz, methodID, args);    \
             va_end(args);\
            return    result;    \
        }else                                                                \
        {                                                                    \
            va_list args;                                                        \
            va_start(args, methodID);                                            \
            _ctype result = oldCallNonvirtual##_jname##MethodV(env, jobj, jclazz, methodID, args);    \
        va_end(args);                                                        \
        return    result;\
            }                                                    \
    }                                                                       \
     _ctype(*oldCallNonvirtual##_jname##MethodA)(JNIEnv* env, jobject jobj, \
        jclass jclazz, jmethodID methodID, jvalue* args);                   \
     _ctype myCallNonvirtual##_jname##MethodA(JNIEnv* env, jobject jobj,\
        jclass jclazz, jmethodID methodID, jvalue* args)                    \
    {    \
         gjniInterface->CallNonvirtual##_jname##MethodA(env,jobj,jclazz,methodID,args);   \
        return oldCallNonvirtual##_jname##MethodA(env,jobj,jclazz,methodID,args);\
    }


CALL_NONVIRTUAL(jobject, Object, NULL, (jobject) result.l, true);

CALL_NONVIRTUAL(jboolean, Boolean, 0, result.z, false);

CALL_NONVIRTUAL(jbyte, Byte, 0, result.b, false);

CALL_NONVIRTUAL(jchar, Char, 0, result.c, false);

CALL_NONVIRTUAL(jshort, Short, 0, result.s, false);

CALL_NONVIRTUAL(jint, Int, 0, result.i, false);

CALL_NONVIRTUAL(jlong, Long, 0, result.j, false);

CALL_NONVIRTUAL(jfloat, Float, 0.0f, result.f, false);

CALL_NONVIRTUAL(jdouble, Double, 0.0, result.d, false);


#define CALL_NONVIRTUAL_VOID(_jname, _retfail, _retok, _isref)                          \
      void (*oldCallNonvirtual##_jname##MethodV)(JNIEnv* env, jobject jobj,             \
        jclass jclazz, jmethodID methodID, va_list args);                    \
      void myCallNonvirtual##_jname##MethodV(JNIEnv* env, jobject jobj,\
        jclass jclazz, jmethodID methodID, va_list args)                    \
    {                                                                       \
        gjniInterface->CallNonvirtual##_jname##MethodV(env,jobj,jclazz,methodID,args);\
        return oldCallNonvirtual##_jname##MethodV(env,jobj,jclazz,methodID,args); \
    }                                                                       \
     void (*oldCallNonvirtual##_jname##Method)(JNIEnv* env, jobject jobj, \
        jclass jclazz, jmethodID methodID, ...);                            \
     void myCallNonvirtual##_jname##Method(JNIEnv* env, jobject jobj, \
        jclass jclazz, jmethodID methodID, ...)                             \
    {                                                                       \
        if(oldCallNonvirtual##_jname##MethodV==NULL){                            \
             va_list args;    \
             va_start(args, methodID);\
            env->CallNonvirtual##_jname##MethodV(jobj, jclazz, methodID, args);    \
             va_end(args);\
        }else                                                                \
        {                                                                    \
            va_list args;                                                        \
            va_start(args, methodID);                                            \
             oldCallNonvirtual##_jname##MethodV(env, jobj, jclazz, methodID, args);    \
        va_end(args);                                                        \
            }                                                    \
    }                                                                       \
     void(*oldCallNonvirtual##_jname##MethodA)(JNIEnv* env, jobject jobj, \
        jclass jclazz, jmethodID methodID, jvalue* args);                   \
     void myCallNonvirtual##_jname##MethodA(JNIEnv* env, jobject jobj,\
        jclass jclazz, jmethodID methodID, jvalue* args)                    \
    {                                                                       \
        gjniInterface->CallNonvirtual##_jname##MethodA(env,jobj,jclazz,methodID,args);\
        return oldCallNonvirtual##_jname##MethodA(env,jobj,jclazz,methodID,args);\
    }


CALL_NONVIRTUAL_VOID(Void, , , false);


/*
* Call a  method.
*/
#define CALL_STATIC(_ctype, _jname, _retfail, _retok, _isref)               \
      _ctype (*oldCallStatic##_jname##MethodV)(JNIEnv* env, jclass jclazz,   \
        jmethodID methodID, va_list args);                                  \
      _ctype myCallStatic##_jname##MethodV(JNIEnv* env, jclass jclazz,   \
        jmethodID methodID, va_list args)                                   \
    {                                                                       \
         gjniInterface->CallStatic##_jname##MethodV(env,jclazz,methodID,args); \
       return oldCallStatic##_jname##MethodV(env,jclazz,methodID,args);        \
    }                                                                       \
      _ctype (*oldCallStatic##_jname##Method)(JNIEnv* env, jclass jclazz,    \
        jmethodID methodID, ...) ;                                           \
     _ctype myCallStatic##_jname##Method(JNIEnv* env, jclass jclazz,    \
        jmethodID methodID, ...)                                            \
    {                                                                       \
        if(oldCall##_jname##MethodV==NULL){                            \
             va_list args;    \
             va_start(args, methodID);\
            _ctype result=env->CallStatic##_jname##MethodV(jclazz, methodID, args);    \
             va_end(args);\
            return    result;    \
        }else                                                                \
        {                                                                    \
            va_list args;                                                        \
            va_start(args, methodID);                                            \
            _ctype result = oldCallStatic##_jname##MethodV(env, jclazz, methodID, args);    \
        va_end(args);                                                        \
        return    result;    }                                                    \
    }                                                                       \
     _ctype (*oldCallStatic##_jname##MethodA)(JNIEnv* env, jclass jclazz,   \
        jmethodID methodID, jvalue* args);                                  \
     _ctype myCallStatic##_jname##MethodA(JNIEnv* env, jclass jclazz,   \
        jmethodID methodID, jvalue* args)                                   \
    {                                                                       \
        gjniInterface->CallStatic##_jname##MethodA(env,jclazz,methodID,args); \
        return oldCallStatic##_jname##MethodA(env,jclazz,methodID,args);\
    }

CALL_STATIC(jobject, Object, NULL, (jobject) result.l, true);

CALL_STATIC(jboolean, Boolean, 0, result.z, false);

CALL_STATIC(jbyte, Byte, 0, result.b, false);

CALL_STATIC(jchar, Char, 0, result.c, false);

CALL_STATIC(jshort, Short, 0, result.s, false);

CALL_STATIC(jint, Int, 0, result.i, false);

CALL_STATIC(jlong, Long, 0, result.j, false);

CALL_STATIC(jfloat, Float, 0.0f, result.f, false);

CALL_STATIC(jdouble, Double, 0.0, result.d, false);


/*
* Call a  void method.
*/
#define CALL_STATIC_VOID(_jname, _retfail, _retok, _isref)                            \
      void (*oldCallStatic##_jname##MethodV)(JNIEnv* env, jclass jclazz,        \
        jmethodID methodID, va_list args);                                            \
                                                                                    \
      void myCallStatic##_jname##MethodV(JNIEnv* env, jclass jclazz,            \
        jmethodID methodID, va_list args)                                            \
    {                                                                                \
        gjniInterface->CallStatic##_jname##MethodV(env,jclazz,methodID,args);  \
       return oldCallStatic##_jname##MethodV(env,jclazz,methodID,args);                \
    }                                                                                \
      void (*oldCallStatic##_jname##Method)(JNIEnv* env, jclass jclazz,        \
        jmethodID methodID, ...) ;                                                    \
     void myCallStatic##_jname##Method(JNIEnv* env, jclass jclazz,            \
        jmethodID methodID, ...)                                                    \
    {                                                                                \
        if(oldCallStatic##_jname##MethodV==NULL){                                    \
             va_list args;                                                        \
             va_start(args, methodID);                                                \
             env->CallStatic##_jname##MethodV(jclazz, methodID, args);                \
             va_end(args);                                                            \
        }else                                                                        \
        {                                                                            \
            va_list args;                                                            \
            va_start(args, methodID);                                                \
             oldCallStatic##_jname##MethodV(env, jclazz, methodID, args);            \
        va_end(args);                                                                \
        }                                                                            \
    }                                                                                \
     void (*oldCallStatic##_jname##MethodA)(JNIEnv* env, jclass jclazz,        \
        jmethodID methodID, jvalue* args);                                            \
     void myCallStatic##_jname##MethodA(JNIEnv* env, jclass jclazz,            \
        jmethodID methodID, jvalue* args)                                            \
    {                                                                                \
       gjniInterface->CallStatic##_jname##MethodA(env,jclazz,methodID,args);  \
        return oldCallStatic##_jname##MethodA(env,jclazz,methodID,args);            \
    }

CALL_STATIC_VOID(Void, , , false);


/*
* Create a new String from Unicode data.
*
* If "len" is zero, we will return an empty string even if "unicodeChars"
* is NULL.  (The JNI spec is vague here.)
*/
jstring (*oldNewString)(JNIEnv *env, const jchar *unicodeChars, jsize len);

jstring myNewString(JNIEnv *env, const jchar *unicodeChars, jsize len) {
    /*	ScopedJniThreadState ts(env);
        StringObject* jstr = dvmCreateStringFromUnicode(unicodeChars, len);
        if (jstr == NULL) {
            return NULL;
        }
        dvmReleaseTrackedAlloc((Object*)jstr, NULL);
        return (jstring)addLocalReference(ts.self(), (Object*)jstr)*/
    ;
    gjniInterface->NewString(env, unicodeChars, len);
    return oldNewString(env, unicodeChars, len);
}


jsize (*oldGetStringLength)(JNIEnv *env, jstring jstr);

jsize myGetStringLength(JNIEnv *env, jstring jstr) {
    gjniInterface->GetStringLength(env, jstr);
    return oldGetStringLength(env, jstr);
}

const jchar *(*oldGetStringChars)(JNIEnv *env, jstring jstr, jboolean *isCopy);

const jchar *myGetStringChars(JNIEnv *env, jstring jstr, jboolean *isCopy) {

    return oldGetStringChars(env, jstr, isCopy);
}

void (*oldReleaseStringChars)(JNIEnv *env, jstring jstr, const char *chars);

void myReleaseStringChars(JNIEnv *env, jstring jstr, const char *chars) {
    gjniInterface->ReleaseStringChars(env, jstr, chars);
    return oldReleaseStringChars(env, jstr, chars);
}

jstring (*oldNewStringUTF)(JNIEnv *env, const char *bytes);

jstring myNewStringUTF(JNIEnv *env, const char *bytes) {
    gjniInterface->NewStringUTF(env, bytes);
    return oldNewStringUTF(env, bytes);
}

jsize (*oldGetStringUTFLength)(JNIEnv *env, jstring jstr);

jsize myGetStringUTFLength(JNIEnv *env, jstring jstr) {
    gjniInterface->GetStringUTFLength(env, jstr);
    return oldGetStringUTFLength(env, jstr);
}

const char *(*oldGetStringUTFChars)(JNIEnv *env, jstring jstr, jboolean *isCopy);

const char *myGetStringUTFChars(JNIEnv *env, jstring jstr, jboolean *isCopy) {
    gjniInterface->GetStringUTFChars(env, jstr, isCopy);
    return oldGetStringUTFChars(env, jstr, isCopy);
}

/*
* Release a string created by GetStringUTFChars().
*/
void (*oldReleaseStringUTFChars)(JNIEnv *env, jstring jstr, const char *utf);

void myReleaseStringUTFChars(JNIEnv *env, jstring jstr, const char *utf) {
    gjniInterface->ReleaseStringChars(env, jstr, utf);
    free((char *) utf);
}

/*
* Return the capacity of the array.
*/
jsize (*oldGetArrayLength)(JNIEnv *env, jarray jarr);

jsize myGetArrayLength(JNIEnv *env, jarray jarr) {
    gjniInterface->GetArrayLength(env, jarr);
    return oldGetArrayLength(env, jarr);
}

jobjectArray (*oldNewObjectArray)(JNIEnv *env, jsize length,
                                  jclass jelementClass, jobject jinitialElement);

jobjectArray myNewObjectArray(JNIEnv *env, jsize length,
                              jclass jelementClass, jobject jinitialElement) {
    gjniInterface->NewObjectArray(env, length, jelementClass, jinitialElement);
    return oldNewObjectArray(env, length, jelementClass, jinitialElement);
}


jobject (*oldGetObjectArrayElement)(JNIEnv *env, jobjectArray jarr, jsize index);

jobject myGetObjectArrayElement(JNIEnv *env, jobjectArray jarr, jsize index) {
    gjniInterface->GetObjectArrayElement(env, jarr, index);
    return oldGetObjectArrayElement(env, jarr, index);
}


void (*oldSetObjectArrayElement)(JNIEnv *env, jobjectArray jarr, jsize index, jobject jobj);

void mySetObjectArrayElement(JNIEnv *env, jobjectArray jarr, jsize index, jobject jobj) {
    gjniInterface->SetObjectArrayElement(env, jarr, index, jobj);
    return oldSetObjectArrayElement(env, jarr, index, jobj);
}


#define NEW_PRIMITIVE_ARRAY(_artype, _jname, _typechar)                    \
     _artype (*oldNew##_jname##Array)(JNIEnv* env, jsize length);    \
     _artype myNew##_jname##Array(JNIEnv* env, jsize length) {    \
       gjniInterface->New##_jname##Array(env,length);\
       return oldNew##_jname##Array(env,length);                        \
    }                                                                    \


NEW_PRIMITIVE_ARRAY(jbooleanArray, Boolean, 'Z');

NEW_PRIMITIVE_ARRAY(jbyteArray, Byte, 'B');

NEW_PRIMITIVE_ARRAY(jcharArray, Char, 'C');

NEW_PRIMITIVE_ARRAY(jshortArray, Short, 'S');

NEW_PRIMITIVE_ARRAY(jintArray, Int, 'I');

NEW_PRIMITIVE_ARRAY(jlongArray, Long, 'J');

NEW_PRIMITIVE_ARRAY(jfloatArray, Float, 'F');

NEW_PRIMITIVE_ARRAY(jdoubleArray, Double, 'D');


jint (*oldUnregisterNatives)(JNIEnv *env, jclass jclazz);

jint myUnregisterNatives(JNIEnv *env, jclass jclazz) {
    gjniInterface->UnregisterNatives(env, jclazz);
    return oldUnregisterNatives(env, jclazz);
}


jint (*oldMonitorEnter)(JNIEnv *env, jobject jobj);

jint myMonitorEnter(JNIEnv *env, jobject jobj) {
    gjniInterface->MonitorEnter(env, jobj);
    return oldMonitorEnter(env, jobj);
}


jint (*oldMonitorExit)(JNIEnv *env, jobject jobj);

jint myMonitorExit(JNIEnv *env, jobject jobj) {
    gjniInterface->MonitorExit(env, jobj);
    return oldMonitorExit(env, jobj);
}

jint (*oldGetJavaVM)(JNIEnv *env, JavaVM **vm);

jint myGetJavaVM(JNIEnv *env, JavaVM **vm) {
    gjniInterface->GetJavaVM(env, vm);
    return oldGetJavaVM(env, vm);
}

void (*oldGetStringRegion)(JNIEnv *env, jstring jstr, jsize start, jsize len, jchar *buf);

void myGetStringRegion(JNIEnv *env, jstring jstr, jsize start, jsize len, jchar *buf) {
    gjniInterface->GetStringRegion(env, jstr, start, len, buf);
    return oldGetStringRegion(env, jstr, start, len, buf);
}


void (*oldGetStringUTFRegion)(JNIEnv *env, jstring jstr, jsize start, jsize len, char *buf);

void myGetStringUTFRegion(JNIEnv *env, jstring jstr, jsize start, jsize len, char *buf) {
    gjniInterface->GetStringUTFRegion(env, jstr, start, len, buf);
    return oldGetStringUTFRegion(env, jstr, start, len, buf);
}

void *(*oldGetPrimitiveArrayCritical)(JNIEnv *env, jarray jarr, jboolean *isCopy);

void *myGetPrimitiveArrayCritical(JNIEnv *env, jarray jarr, jboolean *isCopy) {
    gjniInterface->GetPrimitiveArrayCritical(env, jarr, isCopy);
    return oldGetPrimitiveArrayCritical(env, jarr, isCopy);
}


void (*oldReleasePrimitiveArrayCritical)(JNIEnv *env, jarray jarr, void *carray, jint mode);

void myReleasePrimitiveArrayCritical(JNIEnv *env, jarray jarr, void *carray, jint mode) {
    gjniInterface->ReleasePrimitiveArrayCritical(env, jarr, carray, mode);
    return oldReleasePrimitiveArrayCritical(env, jarr, carray, mode);
}

const jchar *(*oldGetStringCritical)(JNIEnv *env, jstring jstr, jboolean *isCopy);

const jchar *myGetStringCritical(JNIEnv *env, jstring jstr, jboolean *isCopy) {
    gjniInterface->GetStringCritical(env, jstr, isCopy);
    return oldGetStringCritical(env, jstr, isCopy);
}

void (*oldReleaseStringCritical)(JNIEnv *env, jstring jstr, const jchar *carray);

void myReleaseStringCritical(JNIEnv *env, jstring jstr, const jchar *carray) {
    gjniInterface->ReleaseStringCritical(env, jstr, carray);
    return oldReleaseStringCritical(env, jstr, carray);
}


jweak (*oldNewWeakGlobalRef)(JNIEnv *env, jobject jobj);

jweak myNewWeakGlobalRef(JNIEnv *env, jobject jobj) {
    gjniInterface->NewWeakGlobalRef(env, jobj);
    return oldNewWeakGlobalRef(env, jobj);
}


void (*oldDeleteWeakGlobalRef)(JNIEnv *env, jweak wref);

void myDeleteWeakGlobalRef(JNIEnv *env, jweak wref) {
    gjniInterface->DeleteWeakGlobalRef(env, wref);
    return oldDeleteWeakGlobalRef(env, wref);
}

jboolean (*oldExceptionCheck)(JNIEnv *env);

jboolean myExceptionCheck(JNIEnv *env) {
    gjniInterface->ExceptionCheck(env);
    return oldExceptionCheck(env);
}


jobjectRefType (*oldGetObjectRefType)(JNIEnv *env, jobject jobj);

jobjectRefType myGetObjectRefType(JNIEnv *env, jobject jobj) {
    return oldGetObjectRefType(env, jobj);
}

jobject (*oldNewDirectByteBuffer)(JNIEnv *env, void *address, jlong capacity);

jobject myNewDirectByteBuffer(JNIEnv *env, void *address, jlong capacity) {
    gjniInterface->NewDirectByteBuffer(env, address, capacity);
    return oldNewDirectByteBuffer(env, address, capacity);
}


void *(*oldGetDirectBufferAddress)(JNIEnv *env, jobject jbuf);

void *myGetDirectBufferAddress(JNIEnv *env, jobject jbuf) {
    gjniInterface->GetDirectBufferAddress(env, jbuf);
    return oldGetDirectBufferAddress(env, jbuf);
}

jlong (*oldGetDirectBufferCapacity)(JNIEnv *env, jobject jbuf);

jlong myGetDirectBufferCapacity(JNIEnv *env, jobject jbuf) {
    gjniInterface->GetDirectBufferCapacity(env, jbuf);
    return oldGetDirectBufferCapacity(env, jbuf);
}



/*
* Get a pointer to a C array of primitive elements from an array object
* of the matching type.
*
* In a compacting GC, we either need to return a copy of the elements or
* "pin" the memory.  Otherwise we run the risk of native code using the
* buffer as the destination of e.g. a blocking read() call that wakes up
* during a GC.
*/
#define GET_PRIMITIVE_ARRAY_ELEMENTS(_ctype, _jname) \
     _ctype* (*oldGet##_jname##ArrayElements)(JNIEnv* env, \
        _ctype##Array jarr, jboolean* isCopy); \
     _ctype* myGet##_jname##ArrayElements(JNIEnv* env, \
        _ctype##Array jarr, jboolean* isCopy) \
    { \
        gjniInterface->Get##_jname##ArrayElements(env,jarr,isCopy);\
       return oldGet##_jname##ArrayElements(env,jarr,isCopy);\
    }\

/*
* Release the storage locked down by the "get" function.
*
* The spec says, "'mode' has no effect if 'elems' is not a copy of the
* elements in 'array'."  They apparently did not anticipate the need to
* un-pin memory.
*/
#define RELEASE_PRIMITIVE_ARRAY_ELEMENTS(_ctype, _jname)                    \
      void (*oldRelease##_jname##ArrayElements)(JNIEnv* env,                 \
        _ctype##Array jarr, _ctype* elems, jint mode);                       \
     void myRelease##_jname##ArrayElements(JNIEnv* env,                 \
        _ctype##Array jarr, _ctype* elems, jint mode)                       \
    {                                                                       \
        gjniInterface->Release##_jname##ArrayElements(env,jarr,elems,mode);\
         oldRelease##_jname##ArrayElements(env,jarr,elems,mode);\
    }\


/*
* Copy a section of a primitive array to a buffer.
*/
#define GET_PRIMITIVE_ARRAY_REGION(_ctype, _jname) \
     void (*oldGet##_jname##ArrayRegion)(JNIEnv* env, \
        _ctype##Array jarr, jsize start, jsize len, _ctype* buf); \
     void myGet##_jname##ArrayRegion(JNIEnv* env, \
        _ctype##Array jarr, jsize start, jsize len, _ctype* buf) \
    { \
     gjniInterface->Get##_jname##ArrayRegion(env,jarr,start,len,buf);\
       return oldGet##_jname##ArrayRegion(env,jarr,start,len,buf);\
    }\

/*
* Copy a section of a primitive array from a buffer.
*/
#define SET_PRIMITIVE_ARRAY_REGION(_ctype, _jname) \
     void (*oldSet##_jname##ArrayRegion)(JNIEnv* env, \
        _ctype##Array jarr, jsize start, jsize len, const _ctype* buf);\
     void mySet##_jname##ArrayRegion(JNIEnv* env, \
        _ctype##Array jarr, jsize start, jsize len, const _ctype* buf) \
    { \
        gjniInterface->Set##_jname##ArrayRegion(env,jarr,start,len,buf);\
       return oldSet##_jname##ArrayRegion(env,jarr,start,len,buf);\
    }\
/*
* 4-in-1:
*  Get<Type>ArrayElements
*  Release<Type>ArrayElements
*  Get<Type>ArrayRegion
*  Set<Type>ArrayRegion
*/


#define PRIMITIVE_ARRAY_FUNCTIONS(_ctype, _jname)                           \
    GET_PRIMITIVE_ARRAY_ELEMENTS(_ctype, _jname);                           \
    RELEASE_PRIMITIVE_ARRAY_ELEMENTS(_ctype, _jname);                       \
    GET_PRIMITIVE_ARRAY_REGION(_ctype, _jname);                             \
    SET_PRIMITIVE_ARRAY_REGION(_ctype, _jname);                             \


PRIMITIVE_ARRAY_FUNCTIONS(jboolean, Boolean);

PRIMITIVE_ARRAY_FUNCTIONS(jbyte, Byte);

PRIMITIVE_ARRAY_FUNCTIONS(jchar, Char);

PRIMITIVE_ARRAY_FUNCTIONS(jshort, Short);

PRIMITIVE_ARRAY_FUNCTIONS(jint, Int);

PRIMITIVE_ARRAY_FUNCTIONS(jlong, Long);

PRIMITIVE_ARRAY_FUNCTIONS(jfloat, Float);

PRIMITIVE_ARRAY_FUNCTIONS(jdouble, Double);


void JniHook::hookFromReflectedMethod() {
    HOOKJNI(FromReflectedMethod, 0x1c);
}

void JniHook::hookFromReflectedField() {
    HOOKJNI(FromReflectedField, 0x20);
}

void JniHook::hookToReflectedMethod() {
    HOOKJNI(ToReflectedMethod, 0x24);
}


void JniHook::hookIsAssignableFrom() {
    HOOKJNI(IsAssignableFrom, 0x2c);
}

void JniHook::hookToReflectedField() {
    HOOKJNI(ToReflectedField, 0x30);
}

void JniHook::hookThrow() {
    HOOKJNI(Throw, 0x34);
}

void JniHook::hookThrowNew() {
    HOOKJNI(ThrowNew, 0x38);
}

void JniHook::hookExceptionOccurred() {
    HOOKJNI(ExceptionOccurred, 0x3c);
}

void JniHook::hookExceptionDescribe() {
    HOOKJNI(ExceptionDescribe, 0x40);
}

void JniHook::hookExceptionClear() {
    HOOKJNI(ExceptionClear, 0x44);
}

void JniHook::hookFatalError() {
    HOOKJNI(FatalError, 0x48);
}

void JniHook::hookPushLocalFrame() {
    HOOKJNI(PushLocalFrame, 0x4c);
}

void JniHook::hookPopLocalFrame() {
    HOOKJNI(PopLocalFrame, 0x50);
}

void JniHook::hookNewGlobalRef() {
    HOOKJNI(NewGlobalRef, 0x54);
}

void JniHook::hookDeleteGlobalRef() {
    HOOKJNI(DeleteGlobalRef, 0x58);
}

void JniHook::hookDeleteLocalRef() {
    HOOKJNI(DeleteLocalRef, 0x5c);
}

void JniHook::hookIsSameObject() {
    HOOKJNI(IsSameObject, 0x60);
}

void JniHook::hookNewLocalRef() {
    HOOKJNI(NewLocalRef, 0x64);
}

void JniHook::hookEnsureLocalCapacity() {
    HOOKJNI(EnsureLocalCapacity, 0x68);
}

void JniHook::hookAllocObject() {
    HOOKJNI(AllocObject, 0x6c);
}

void JniHook::hookNewObject() {
    HOOKJNI(NewObject, 0x70);
}

void JniHook::hookNewObjectV() {
    HOOKJNI(NewObjectV, 0x74);
}

void JniHook::hookNewObjectA() {
    HOOKJNI(NewObjectA, 0x78);
}

void JniHook::hookGetObjectClass() {
    HOOKJNI(GetObjectClass, 0x7c);
}

void JniHook::hookIsInstanceOf() {
    HOOKJNI(IsInstanceOf, 0x80);
}


void JniHook::hookCallObjectMethod() {
    HOOKJNI(CallObjectMethod, 0x88);
}

void JniHook::hookCallObjectMethodV() {
    HOOKJNI(CallObjectMethodV, 0x8c);
}

void JniHook::hookCallObjectMethodA() {
    HOOKJNI(CallObjectMethodA, 0x90);
}

void JniHook::hookCallBooleanMethod() {
    HOOKJNI(CallBooleanMethod, 0x94);
}

void JniHook::hookCallBooleanMethodV() {
    HOOKJNI(CallBooleanMethodV, 0x98);
}

void JniHook::hookCallBooleanMethodA() {
    HOOKJNI(CallBooleanMethodA, 0x9c);
}

void JniHook::hookCallByteMethod() {
    HOOKJNI(CallByteMethod, 0xa0);
}

void JniHook::hookCallByteMethodV() {
    HOOKJNI(CallByteMethodV, 0xa4);
}

void JniHook::hookCallByteMethodA() {
    HOOKJNI(CallByteMethodA, 0xa8);
}

void JniHook::hookCallCharMethod() {
    HOOKJNI(CallCharMethod, 0xac);
}

void JniHook::hookCallCharMethodV() {
    HOOKJNI(CallCharMethodV, 0xb0);
}

void JniHook::hookCallCharMethodA() {
    HOOKJNI(CallCharMethodA, 0xb4);
}

void JniHook::hookCallShortMethod() {
    HOOKJNI(CallShortMethod, 0xb8);
}

void JniHook::hookCallShortMethodV() {
    HOOKJNI(CallShortMethodV, 0xbc);
}

void JniHook::hookCallShortMethodA() {
    HOOKJNI(CallShortMethodA, 0xc0);
}

void JniHook::hookCallIntMethod() {
    HOOKJNI(CallIntMethod, 0xc4);
}

void JniHook::hookCallIntMethodV() {
    HOOKJNI(CallIntMethodV, 0xc8);
}

void JniHook::hookCallIntMethodA() {
    HOOKJNI(CallIntMethodA, 0xcc);
}

void JniHook::hookCallLongMethod() {
    HOOKJNI(CallLongMethod, 0xd0);
}

void JniHook::hookCallLongMethodV() {
    HOOKJNI(CallLongMethodV, 0xd4);
}

void JniHook::hookCallLongMethodA() {
    HOOKJNI(CallLongMethodA, 0xd8);
}

void JniHook::hookCallFloatMethod() {
    HOOKJNI(CallFloatMethod, 0xdc);
}

void JniHook::hookCallFloatMethodV() {
    HOOKJNI(CallFloatMethodV, 0xe0);
}

void JniHook::hookCallFloatMethodA() {
    HOOKJNI(CallFloatMethodA, 0xe4);
}

void JniHook::hookCallDoubleMethod() {
    HOOKJNI(CallDoubleMethod, 0xe8);
}

void JniHook::hookCallDoubleMethodV() {
    HOOKJNI(CallDoubleMethodV, 0xec);
}

void JniHook::hookCallDoubleMethodA() {
    HOOKJNI(CallDoubleMethodA, 0xf0);
}

void JniHook::hookCallVoidMethod() {
    HOOKJNI(CallVoidMethod, 0xf4);
}

void JniHook::hookCallVoidMethodV() {
    HOOKJNI(CallVoidMethodV, 0xf8);
}

void JniHook::hookCallVoidMethodA() {
    HOOKJNI(CallVoidMethodA, 0xfc);
}

void JniHook::hookCallNonvirtualObjectMethod() {
    HOOKJNI(CallNonvirtualObjectMethod, 0x100);
}

void JniHook::hookCallNonvirtualObjectMethodV() {
    HOOKJNI(CallNonvirtualObjectMethodV, 0x104);
}

void JniHook::hookCallNonvirtualObjectMethodA() {
    HOOKJNI(CallNonvirtualObjectMethodA, 0x108);
}

void JniHook::hookCallNonvirtualBooleanMethod() {
    HOOKJNI(CallNonvirtualBooleanMethod, 0x10c);
}

void JniHook::hookCallNonvirtualBooleanMethodV() {
    HOOKJNI(CallNonvirtualBooleanMethodV, 0x110);
}

void JniHook::hookCallNonvirtualBooleanMethodA() {
    HOOKJNI(CallNonvirtualBooleanMethodA, 0x114);
}

void JniHook::hookCallNonvirtualByteMethod() {
    HOOKJNI(CallNonvirtualByteMethod, 0x118);
}

void JniHook::hookCallNonvirtualByteMethodV() {
    HOOKJNI(CallNonvirtualByteMethodV, 0x11c);
}

void JniHook::hookCallNonvirtualByteMethodA() {
    HOOKJNI(CallNonvirtualByteMethodA, 0x120);
}

void JniHook::hookCallNonvirtualCharMethod() {
    HOOKJNI(CallNonvirtualCharMethod, 0x124);
}

void JniHook::hookCallNonvirtualCharMethodV() {
    HOOKJNI(CallNonvirtualCharMethodV, 0x128);
}

void JniHook::hookCallNonvirtualCharMethodA() {
    HOOKJNI(CallNonvirtualCharMethodA, 0x12c);
}

void JniHook::hookCallNonvirtualShortMethod() {
    HOOKJNI(CallNonvirtualShortMethod, 0x130);
}

void JniHook::hookCallNonvirtualShortMethodV() {
    HOOKJNI(CallNonvirtualShortMethodV, 0x134);
}

void JniHook::hookCallNonvirtualShortMethodA() {
    HOOKJNI(CallNonvirtualShortMethodA, 0x138);
}

void JniHook::hookCallNonvirtualIntMethod() {
    HOOKJNI(CallNonvirtualIntMethod, 0x13c);
}

void JniHook::hookCallNonvirtualIntMethodV() {
    HOOKJNI(CallNonvirtualIntMethodV, 0x140);
}

void JniHook::hookCallNonvirtualIntMethodA() {
    HOOKJNI(CallNonvirtualIntMethodA, 0x144);
}

void JniHook::hookCallNonvirtualLongMethod() {
    HOOKJNI(CallNonvirtualLongMethod, 0x148);
}

void JniHook::hookCallNonvirtualLongMethodV() {
    HOOKJNI(CallNonvirtualLongMethodV, 0x14c);
}

void JniHook::hookCallNonvirtualLongMethodA() {
    HOOKJNI(CallNonvirtualLongMethodA, 0x150);
}

void JniHook::hookCallNonvirtualFloatMethod() {
    HOOKJNI(CallNonvirtualFloatMethod, 0x154);
}

void JniHook::hookCallNonvirtualFloatMethodV() {
    HOOKJNI(CallNonvirtualFloatMethodV, 0x158);
}

void JniHook::hookCallNonvirtualFloatMethodA() {
    HOOKJNI(CallNonvirtualFloatMethodA, 0x15c);
}

void JniHook::hookCallNonvirtualDoubleMethod() {
    HOOKJNI(CallNonvirtualDoubleMethod, 0x160);
}

void JniHook::hookCallNonvirtualDoubleMethodV() {
    HOOKJNI(CallNonvirtualDoubleMethodV, 0x164);
}

void JniHook::hookCallNonvirtualDoubleMethodA() {
    HOOKJNI(CallNonvirtualDoubleMethodA, 0x168);
}

void JniHook::hookCallNonvirtualVoidMethod() {
    HOOKJNI(CallNonvirtualVoidMethod, 0x16c);
}

void JniHook::hookCallNonvirtualVoidMethodV() {
    HOOKJNI(CallNonvirtualVoidMethodV, 0x170);
}

void JniHook::hookCallNonvirtualVoidMethodA() {
    HOOKJNI(CallNonvirtualVoidMethodA, 0x174);
}

void JniHook::hookGetFieldID() {
    HOOKJNI(GetFieldID, 0x178);
}

void JniHook::hookGetObjectField() {
    HOOKJNI(GetObjectField, 0x17c);
}

void JniHook::hookGetBooleanField() {
    HOOKJNI(GetBooleanField, 0x180);
}

void JniHook::hookGetByteField() {
    HOOKJNI(GetByteField, 0x184);
}

void JniHook::hookGetCharField() {
    HOOKJNI(GetCharField, 0x188);
}

void JniHook::hookGetShortField() {
    HOOKJNI(GetShortField, 0x18c);
}

void JniHook::hookGetIntField() {
    HOOKJNI(GetIntField, 0x190);
}

void JniHook::hookGetLongField() {
    HOOKJNI(GetLongField, 0x194);
}

void JniHook::hookGetFloatField() {
    HOOKJNI(GetFloatField, 0x198);
}

void JniHook::hookGetDoubleField() {
    HOOKJNI(GetDoubleField, 0x19c);
}

void JniHook::hookSetObjectField() {
    HOOKJNI(SetObjectField, 0x1a0);
}

void JniHook::hookSetBooleanField() {
    HOOKJNI(SetBooleanField, 0x1a4);
}

void JniHook::hookSetByteField() {
    HOOKJNI(SetByteField, 0x1a8);
}

void JniHook::hookSetCharField() {
    HOOKJNI(SetCharField, 0x1ac);
}

void JniHook::hookSetShortField() {
    HOOKJNI(SetShortField, 0x1b0);
}

void JniHook::hookSetIntField() {
    HOOKJNI(SetIntField, 0x1b4);
}

void JniHook::hookSetLongField() {
    HOOKJNI(SetLongField, 0x1b8);
}

void JniHook::hookSetFloatField() {
    HOOKJNI(SetFloatField, 0x1bc);
}

void JniHook::hookSetDoubleField() {
    HOOKJNI(SetDoubleField, 0x1c0);
}

void JniHook::hookGetStaticMethodID() {
    HOOKJNI(GetStaticMethodID, 0x1c4);
}

void JniHook::hookCallStaticObjectMethod() {
    HOOKJNI(CallStaticObjectMethod, 0x1c8);
}

void JniHook::hookCallStaticObjectMethodV() {
    HOOKJNI(CallStaticObjectMethodV, 0x1cc);
}

void JniHook::hookCallStaticObjectMethodA() {
    HOOKJNI(CallStaticObjectMethodA, 0x1d0);
}

void JniHook::hookCallStaticBooleanMethod() {
    HOOKJNI(CallStaticBooleanMethod, 0x1d4);
}

void JniHook::hookCallStaticBooleanMethodV() {
    HOOKJNI(CallStaticBooleanMethodV, 0x1d8);
}

void JniHook::hookCallStaticBooleanMethodA() {
    HOOKJNI(CallStaticBooleanMethodA, 0x1dc);
}

void JniHook::hookCallStaticByteMethod() {
    HOOKJNI(CallStaticByteMethod, 0x1e0);
}

void JniHook::hookCallStaticByteMethodV() {
    HOOKJNI(CallStaticByteMethodV, 0x1e4);
}

void JniHook::hookCallStaticByteMethodA() {
    HOOKJNI(CallStaticByteMethodA, 0x1e8);
}

void JniHook::hookCallStaticCharMethod() {
    HOOKJNI(CallStaticCharMethod, 0x1ec);
}

void JniHook::hookCallStaticCharMethodV() {
    HOOKJNI(CallStaticCharMethodV, 0x1f0);
}

void JniHook::hookCallStaticCharMethodA() {
    HOOKJNI(CallStaticCharMethodA, 0x1f4);
}

void JniHook::hookCallStaticShortMethod() {
    HOOKJNI(CallStaticShortMethod, 0x1f8);
}

void JniHook::hookCallStaticShortMethodV() {
    HOOKJNI(CallStaticShortMethodV, 0x1fc);
}

void JniHook::hookCallStaticShortMethodA() {
    HOOKJNI(CallStaticShortMethodA, 0x200);
}

void JniHook::hookCallStaticIntMethod() {
    HOOKJNI(CallStaticIntMethod, 0x204);
}

void JniHook::hookCallStaticIntMethodV() {
    HOOKJNI(CallStaticIntMethodV, 0x208);
}

void JniHook::hookCallStaticIntMethodA() {
    HOOKJNI(CallStaticIntMethodA, 0x20c);
}

void JniHook::hookCallStaticLongMethod() {
    HOOKJNI(CallStaticLongMethod, 0x210);
}

void JniHook::hookCallStaticLongMethodV() {
    HOOKJNI(CallStaticLongMethodV, 0x214);
}

void JniHook::hookCallStaticLongMethodA() {
    HOOKJNI(CallStaticLongMethodA, 0x218);
}

void JniHook::hookCallStaticFloatMethod() {
    HOOKJNI(CallStaticFloatMethod, 0x21c);
}

void JniHook::hookCallStaticFloatMethodV() {
    HOOKJNI(CallStaticFloatMethodV, 0x220);
}

void JniHook::hookCallStaticFloatMethodA() {
    HOOKJNI(CallStaticFloatMethodA, 0x224);
}

void JniHook::hookCallStaticDoubleMethod() {
    HOOKJNI(CallStaticDoubleMethod, 0x228);
}

void JniHook::hookCallStaticDoubleMethodV() {
    HOOKJNI(CallStaticDoubleMethodV, 0x22c);
}

void JniHook::hookCallStaticDoubleMethodA() {
    HOOKJNI(CallStaticDoubleMethodA, 0x230);
}

void JniHook::hookCallStaticVoidMethod() {
    HOOKJNI(CallStaticVoidMethod, 0x234);
}

void JniHook::hookCallStaticVoidMethodV() {
    HOOKJNI(CallStaticVoidMethodV, 0x238);
}

void JniHook::hookCallStaticVoidMethodA() {
    HOOKJNI(CallStaticVoidMethodA, 0x23c);
}

void JniHook::hookGetStaticFieldID() {
    HOOKJNI(GetStaticFieldID, 0x240);
}

void JniHook::hookGetStaticObjectField() {
    HOOKJNI(GetStaticObjectField, 0x244);
}

void JniHook::hookGetStaticBooleanField() {
    HOOKJNI(GetStaticBooleanField, 0x248);
}

void JniHook::hookGetStaticByteField() {
    HOOKJNI(GetStaticByteField, 0x24c);
}

void JniHook::hookGetStaticCharField() {
    HOOKJNI(GetStaticCharField, 0x250);
}

void JniHook::hookGetStaticShortField() {
    HOOKJNI(GetStaticShortField, 0x254);
}

void JniHook::hookGetStaticIntField() {
    HOOKJNI(GetStaticIntField, 0x258);
}

void JniHook::hookGetStaticLongField() {
    HOOKJNI(GetStaticLongField, 0x25c);
}

void JniHook::hookGetStaticFloatField() {
    HOOKJNI(GetStaticFloatField, 0x260);
}

void JniHook::hookGetStaticDoubleField() {
    HOOKJNI(GetStaticDoubleField, 0x264);
}

void JniHook::hookSetStaticObjectField() {
    HOOKJNI(SetStaticObjectField, 0x268);
}

void JniHook::hookSetStaticBooleanField() {
    HOOKJNI(SetStaticBooleanField, 0x26c);
}

void JniHook::hookSetStaticByteField() {
    HOOKJNI(SetStaticByteField, 0x270);
}

void JniHook::hookSetStaticCharField() {
    HOOKJNI(SetStaticCharField, 0x274);
}

void JniHook::hookSetStaticShortField() {
    HOOKJNI(SetStaticShortField, 0x278);
}

void JniHook::hookSetStaticIntField() {
    HOOKJNI(SetStaticIntField, 0x27c);
}

void JniHook::hookSetStaticLongField() {
    HOOKJNI(SetStaticLongField, 0x280);
}

void JniHook::hookSetStaticFloatField() {
    HOOKJNI(SetStaticFloatField, 0x284);
}

void JniHook::hookSetStaticDoubleField() {
    HOOKJNI(SetStaticDoubleField, 0x288);
}

void JniHook::hookNewString() {
    HOOKJNI(NewString, 0x28c);
}

void JniHook::hookGetStringLength() {
    HOOKJNI(GetStringLength, 0x290);
}

void JniHook::hookGetStringChars() {
    HOOKJNI(GetStringChars, 0x294);
}

void JniHook::hookReleaseStringChars() {
    HOOKJNI(ReleaseStringChars, 0x298);
}

void JniHook::hookNewStringUTF() {
    HOOKJNI(NewStringUTF, 0x29c);
}

void JniHook::hookGetStringUTFLength() {
    HOOKJNI(GetStringUTFLength, 0x2a0);
}

void JniHook::hookGetStringUTFChars() {
    HOOKJNI(GetStringUTFChars, 0x2a4);
}

void JniHook::hookReleaseStringUTFChars() {
    HOOKJNI(ReleaseStringUTFChars, 0x2a8);
}

void JniHook::hookGetArrayLength() {
    HOOKJNI(GetArrayLength, 0x2ac);
}

void JniHook::hookNewObjectArray() {
    HOOKJNI(NewObjectArray, 0x2b0);
}

void JniHook::hookGetObjectArrayElement() {
    HOOKJNI(GetObjectArrayElement, 0x2b4);
}

void JniHook::hookSetObjectArrayElement() {
    HOOKJNI(SetObjectArrayElement, 0x2b8);
}

void JniHook::hookNewBooleanArray() {
    HOOKJNI(NewBooleanArray, 0x2bc);
}

void JniHook::hookNewByteArray() {
    HOOKJNI(NewByteArray, 0x2c0);
}

void JniHook::hookNewCharArray() {
    HOOKJNI(NewCharArray, 0x2c4);
}

void JniHook::hookNewShortArray() {
    HOOKJNI(NewShortArray, 0x2c8);
}

void JniHook::hookNewIntArray() {
    HOOKJNI(NewIntArray, 0x2cc);
}

void JniHook::hookNewLongArray() {
    HOOKJNI(NewLongArray, 0x2d0);
}

void JniHook::hookNewFloatArray() {
    HOOKJNI(NewFloatArray, 0x2d4);
}

void JniHook::hookNewDoubleArray() {
    HOOKJNI(NewDoubleArray, 0x2d8);
}

void JniHook::hookGetBooleanArrayElements() {
    HOOKJNI(GetBooleanArrayElements, 0x2dc);
}

void JniHook::hookGetByteArrayElements() {
    HOOKJNI(GetByteArrayElements, 0x2e0);
}

void JniHook::hookGetCharArrayElements() {
    HOOKJNI(GetCharArrayElements, 0x2e4);
}

void JniHook::hookGetShortArrayElements() {
    HOOKJNI(GetShortArrayElements, 0x2e8);
}

void JniHook::hookGetIntArrayElements() {
    HOOKJNI(GetIntArrayElements, 0x2ec);
}

void JniHook::hookGetLongArrayElements() {
    HOOKJNI(GetLongArrayElements, 0x2f0);
}

void JniHook::hookGetFloatArrayElements() {
    HOOKJNI(GetFloatArrayElements, 0x2f4);
}

void JniHook::hookGetDoubleArrayElements() {
    HOOKJNI(GetDoubleArrayElements, 0x2f8);
}

void JniHook::hookReleaseBooleanArrayElements() {
    HOOKJNI(ReleaseBooleanArrayElements, 0x2fc);
}

void JniHook::hookReleaseByteArrayElements() {
    HOOKJNI(ReleaseByteArrayElements, 0x300);
}

void JniHook::hookReleaseCharArrayElements() {
    HOOKJNI(ReleaseCharArrayElements, 0x304);
}

void JniHook::hookReleaseShortArrayElements() {
    HOOKJNI(ReleaseShortArrayElements, 0x308);
}

void JniHook::hookReleaseIntArrayElements() {
    HOOKJNI(ReleaseIntArrayElements, 0x30c);
}

void JniHook::hookReleaseLongArrayElements() {
    HOOKJNI(ReleaseLongArrayElements, 0x310);
}

void JniHook::hookReleaseFloatArrayElements() {
    HOOKJNI(ReleaseFloatArrayElements, 0x314);
}

void JniHook::hookReleaseDoubleArrayElements() {
    HOOKJNI(ReleaseDoubleArrayElements, 0x318);
}

void JniHook::hookGetBooleanArrayRegion() {
    HOOKJNI(GetBooleanArrayRegion, 0x31c);
}

void JniHook::hookGetByteArrayRegion() {
    HOOKJNI(GetByteArrayRegion, 0x320);
}

void JniHook::hookGetCharArrayRegion() {
    HOOKJNI(GetCharArrayRegion, 0x324);
}

void JniHook::hookGetShortArrayRegion() {
    HOOKJNI(GetShortArrayRegion, 0x328);
}


void JniHook::hookGetLongArrayRegion() {
    HOOKJNI(GetLongArrayRegion, 0x330);
}

void JniHook::hookGetFloatArrayRegion() {
    HOOKJNI(GetFloatArrayRegion, 0x334);
}

void JniHook::hookGetDoubleArrayRegion() {
    HOOKJNI(GetDoubleArrayRegion, 0x338);
}

void JniHook::hookSetBooleanArrayRegion() {
    HOOKJNI(SetBooleanArrayRegion, 0x33c);
}

void JniHook::hookSetByteArrayRegion() {
    HOOKJNI(SetByteArrayRegion, 0x340);
}


void JniHook::hookSetCharArrayRegion() {
    HOOKJNI(SetCharArrayRegion, 0x344);
}

void JniHook::hookSetShortArrayRegion() {
    HOOKJNI(SetShortArrayRegion, 0x348);
}

void JniHook::hookSetIntArrayRegion() {
    HOOKJNI(SetIntArrayRegion, 0x34c);
}

void JniHook::hookSetLongArrayRegion() {
    HOOKJNI(SetLongArrayRegion, 0x350);
}

void JniHook::hookSetFloatArrayRegion() {
    HOOKJNI(SetFloatArrayRegion, 0x354);
}

void JniHook::hookSetDoubleArrayRegion() {
    HOOKJNI(SetDoubleArrayRegion, 0x358);
}


void JniHook::hookUnregisterNatives() {
    HOOKJNI(UnregisterNatives, 0x360);
}

void JniHook::hookMonitorEnter() {
    HOOKJNI(MonitorEnter, 0x364);
}

void JniHook::hookMonitorExit() {
    HOOKJNI(MonitorExit, 0x368);
}

void JniHook::hookGetJavaVM() {
    HOOKJNI(GetJavaVM, 0x36c);
}

void JniHook::hookGetStringRegion() {
    HOOKJNI(GetStringRegion, 0x370);
}

void JniHook::hookGetStringUTFRegion() {
    HOOKJNI(GetStringUTFRegion, 0x374);
}

void JniHook::hookGetPrimitiveArrayCritical() {
    HOOKJNI(GetPrimitiveArrayCritical, 0x378);
}

void JniHook::hookReleasePrimitiveArrayCritical() {
    HOOKJNI(ReleasePrimitiveArrayCritical, 0x37c);
}

void JniHook::hookGetStringCritical() {
    HOOKJNI(GetStringCritical, 0x380);
}

void JniHook::hookReleaseStringCritical() {
    HOOKJNI(ReleaseStringCritical, 0x384);
}

void JniHook::hookNewWeakGlobalRef() {
    HOOKJNI(NewWeakGlobalRef, 0x388);
}

void JniHook::hookDeleteWeakGlobalRef() {
    HOOKJNI(DeleteWeakGlobalRef, 0x38c);
}

void JniHook::hookExceptionCheck() {
    HOOKJNI(ExceptionCheck, 0x390);
}

void JniHook::hookNewDirectByteBuffer() {
    HOOKJNI(NewDirectByteBuffer, 0x394);
}

void JniHook::hookGetDirectBufferAddress() {
    HOOKJNI(GetDirectBufferAddress, 0x398);
}

void JniHook::hookGetDirectBufferCapacity() {
    HOOKJNI(GetDirectBufferCapacity, 0x39c);
}

void JniHook::hookGetObjectRefType() {
    HOOKJNI(GetObjectRefType, 0x3a0);
}