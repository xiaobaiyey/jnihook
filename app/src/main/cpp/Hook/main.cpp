/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/9/17 下午11:53
* @ class describe
*/


#include <jni.h>
#include <android/log.h>
#include <asm/fcntl.h>
#include "HookHelper.h"
#include "LogHex.h"

#define TOSTR(fmt) #fmt
#define FLFMT(fmt) TOSTR([%s:%d]fmt)


#include <android/log.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <unistd.h>

#define FLOG_TAG "loig"

#ifdef EXEC
#define LOGE(...) printf(__VA_ARGS__ );printf("\n");
#define LOGD(...) printf(__VA_ARGS__ );printf("\n");
#define LOGW(...) printf(__VA_ARGS__ );printf("\n");
#define LOGI(...)printf(__VA_ARGS__ );printf("\n");
#define LOGV(...) printf(__VA_ARGS__ );printf("\n");
#else
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, FLOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, FLOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, FLOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, FLOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, FLOG_TAG, __VA_ARGS__)
#endif


#define FLOGE(fmt, ...) __android_log_print(ANDROID_LOG_ERROR, FLOG_TAG, FLFMT(fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define FLOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, FLOG_TAG, FLFMT(fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define FLOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN, FLOG_TAG, FLFMT(fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define FLOGI(fmt, ...) __android_log_print(ANDROID_LOG_INFO, FLOG_TAG, FLFMT(fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define FLOGV(fmt, ...) __android_log_print(ANDROID_LOG_VERBOSE, FLOG_TAG, FLFMT(fmt), __FUNCTION__, __LINE__, ##__VA_ARGS__)

#include <string>

int (*p_open)(const char *name, int flags, ...) = nullptr;

int f_open(const char *name, int flags, ...) {
    LOGI("start open");
    mode_t mode = 0;
    if ((flags & O_CREAT) != 0) {
        va_list args;
        va_start(args, flags);
        mode = static_cast<mode_t >(va_arg(args, int));
        va_end(args);
    }
    auto rel = p_open(name, flags, mode);
    FLOGE(%d = open %s %d %d, rel, name, flags, mode);
    return rel;
}

pid_t (*p_fork)();

pid_t f_fork() {
    LOGI("start f hook");
    pid_t forkd = p_fork();
    LOGI("fork res: %d", forkd);
    return forkd;
}

ssize_t (*p_read)(int fd, void *dest, size_t request);

ssize_t f_read(int fd, void *dest, size_t request) {
    LOGI("start read");
    LOGI("read data %d at %p: %d", fd, dest, request);
    return p_read(fd, dest, request);
}

JNIEXPORT jint JNI_OnLoads(JavaVM *vm, void *reserved) {

    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }

    return JNI_VERSION_1_4;
}


extern "C" JNIEXPORT jstring

JNICALL
Java_com_android_arm64hook_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    HookHelper *helper = HookHelper::getInstance();
    auto libc = dlopen("system/lib/libc.so", RTLD_NOW);
    void *resl = dlsym(libc, "read");
    LOGI("lic:%p", &fork);
    LOGI("ric:%p", &resl);
    LOGI("f_fork:%p", &f_fork);
    LOGI("p_fork:%p", &p_fork);
    helper->registerHook((void *) &fork, (void *) &f_fork, (void **) &p_fork);
    // helper->registerHook((void *) resl, (void *) &f_read, (void **) &p_read);
    LOGI("registerHook over");
    LogHex::DumpHex(resl, 32);
    helper->hookAll();
    LOGI("hook start");
    fork();
    LOGI("unhook start");
    helper->unhook((void *) &fork);
    pid_t forkend = fork();
    LOGI("test end %d", forkend);
    LogHex::DumpHex(resl, 32);
    LogHex::DumpHex(&p_fork, 32);

    //fork();
    return env->NewStringUTF(hello.c_str());
}

int main(int argc, char const *argv[]) {
    HookHelper *helper = HookHelper::getInstance();
    LOGI("hook start");
    auto libc = dlopen("system/lib/libc.so", RTLD_NOW);
    void *resl = dlsym(libc, "read");
    LOGI("lic:%p", &fork);
    LOGI("ric:%p", &resl);
    LOGI("f_fork:%p", &f_fork);
    LOGI("p_fork:%p", &p_fork);
    helper->registerHook((void *) resl, (void *) &f_read, (void **) &p_read);
    helper->hookAll();
    //A64HookFunction((void *)resl, (void *) &f_fork, (void **) &p_fork);
    fork();
    LOGI("hook over");
    return 0;
}
