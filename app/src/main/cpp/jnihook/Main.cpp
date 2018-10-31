/**
* @ name jnihook
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/10/30 3:36 PM
* @ class 测试类
*/
#include <jni.h>
#include <android/log.h>
#include "JNIInterface.h"
#include "JniHook.h"
#include "VM.h"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, __FUNCTION__, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, __FUNCTION__,__VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, __FUNCTION__, __VA_ARGS__))
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, __FUNCTION__,__VA_ARGS__))

/**
 * 创建一个类继承JNIInterface
 * 用于实现所要hook的方法
 */
class Test : public JNIInterface {
public:

    void NewStringUTF(JNIEnv *env, const char *string) override {
        JNIInterface::NewStringUTF(env, string);
        //此处用编写拦截 代码
        LOGI(string);
    }

    void
    GetMethodID(JNIEnv *env, jclass jclass1, const char *string, const char *string1) override {
        JNIInterface::GetMethodID(env, jclass1, string, string1);
        VM *vm = VM::getInstance();
        const char *class_name = vm->getClasstName(jclass1);
        LOGI("Class:%s Method:%s%s", class_name, string, string1);
    }

    void GetFieldID(JNIEnv *env, jclass jclass1, const char *string, const char *string1) override {
        JNIInterface::GetFieldID(env, jclass1, string, string1);
        VM *vm = VM::getInstance();
        const char *class_name = vm->getClasstName(jclass1);
        LOGI("Class:%s Field:%s:%s", class_name, string, string1);
    }

    void FindClass(JNIEnv *env, const char *string) override {
        JNIInterface::FindClass(env, string);
        LOGI(string);
    }

    void CallObjectMethodV(JNIEnv *env, jobject jobject1, jmethodID id, va_list list) override {
        JNIInterface::CallObjectMethodV(env, jobject1, id, list);
        VM *vm = VM::getInstance();
        const char *class_name = vm->getObjectName(jobject1);
        char *method_name = vm->getMethodName(id);
        LOGI("Class:%s Method:%s", class_name, method_name);
        delete method_name;

    }

    void CallObjectMethodA(JNIEnv *env, jobject jobject1, jmethodID id, jvalue *jvalue1) override {
        JNIInterface::CallObjectMethodA(env, jobject1, id, jvalue1);
        VM *vm = VM::getInstance();
        const char *class_name = vm->getObjectName(jobject1);
        char *method_name = vm->getMethodName(id);
        LOGI("Class:%s Method:%s", class_name, method_name);
        delete method_name;
    }
};


void jnihook(JNIEnv *env) {
    //new
    Test *test = new Test;
    //获取实例 传入参数
    JniHook *jniHook = JniHook::getInstance(env, test);
    //hook 对应方法
    //jniHook->hookNewStringUTF();
    jniHook->hookGetMethodID();
    jniHook->hookGetFieldID();
    jniHook->hookFindClass();
    jniHook->hookCallObjectMethodA();
    jniHook->hookCallObjectMethodV();

}


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    LOGD("in jni onload");
    jnihook(env);
    return JNI_VERSION_1_4;
}