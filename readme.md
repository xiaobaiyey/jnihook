### 用途

用于hook JNI相关函数

### 用法

可以参考jnihook 目录下的Main.cpp文件

* 创建回调类需要继承JNIInterface如下:并在回调类中实现要hook的方法

```c++

/**
 * 创建一个类继承JNIInterface
 * 用于实现所要hook的方法
 */
class Test : public JNIInterface {
public:

    void NewStringUTF(JNIEnv *env, const char *string) override {
        JNIInterface::NewStringUTF(env, string);
        //此处用编写拦截 代码
        LOGI("%s",string);
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
        LOGI("%s",string);
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

```

* 调用JniHook中的相关方法对指定方法进行hook，如：

```c++

    //获取实例 传入参数
    JniHook *jniHook = JniHook::getInstance(env, test);
    //hook 对应方法
    jniHook->hookNewStringUTF();

```

* enjoy it

### 效果图

![](./test.png)


### 参考

Hook方案来自：[https://github.com/F8LEFT/FAInHook](https://github.com/F8LEFT/FAInHook)
Arm64hook方案来自：[https://github.com/Rprop/And64InlineHook](https://github.com/Rprop/And64InlineHook)

