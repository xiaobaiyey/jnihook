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
};


void jnihook(JNIEnv *env) {
    //new
    Test *test = new Test;
    //获取实例 传入参数
    JniHook *jniHook = JniHook::getInstance(env, test);
    //hook 对应方法
    jniHook->hookNewStringUTF();
    jstring jstr = env->NewStringUTF("hello");
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