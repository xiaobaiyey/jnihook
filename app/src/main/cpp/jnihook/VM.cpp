/**
* @ name jnihook
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/10/31 11:16 AM
* @ class describe
*/

#include "VM.h"
#include <string>
#include <sys/system_properties.h>
#include <stdlib.h>
#include <android/log.h>
#include <HookHelper.h>
#include <dlfcn.h>
#include "DexDefine.H"
#include "fake_dlfcn.h"
//平台定义宏
#define Pie 28   //9.0
#define Oreo_R1 27   //8.1
#define Oreo 26   //8.0
#define Nougat_MR1 25 //7.1.1
#define Nougat 24 //7.0
#define Marshmallow 23 //6.0
#define LOLLIPOP_MR1 22 //5.1
#define LOLLIPOP 21  //5.0
#define KITKAT 19 //4.4


//-===========================日志 相关定义=============================
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, __FUNCTION__, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, __FUNCTION__, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, __FUNCTION__, __VA_ARGS__))

//===========================虚拟机相关 相关定义=============================
static void (*Nativefundvm)(const char *libpath);

static bool gdvmbeforecall = false;

static void *(*NativeFunDvmDexFileParse)(const u1 *data, size_t length, DexFile *result);

static bool gdvmbeforeCallDexFileParse = false;


void *(*dvmThreadSelf)();

Object *(*dvmDecodeIndirectRef)(void *self, jobject jobj);

void *(*DecodeJObject)(void *thisobj, jobject thisObject);

void *pthread_key_self_handle = nullptr;

const char *(*getClassDescriptor)(void *thisobj, void *temp);

#define pthread_key_self_Symbol "_ZN3art6Thread17pthread_key_self_E"

#define  ThreadDecodeJObject_symbol  "_ZNK3art6Thread13DecodeJObjectEP8_jobject"

#define Class_GetDescriptor_symbol "_ZN3art6mirror5Class13GetDescriptorEPNSt3__112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE"
//DexFileOpenMemory
#define DexFileOpenMemory_Symbol_API_21 "_ZN3art7DexFile10OpenMemoryEPKhjRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEjPNS_6MemMapEPS9_"
//android 6.0 7.0
#define DexFileOpenMemory_Symbol_API_24 "_ZN3art7DexFile10OpenMemoryEPKhjRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEjPNS_6MemMapEPKNS_10OatDexFileEPS9_"
#define loadNativeLibarySymbol_API_22 "_ZN3art9JavaVMExt17LoadNativeLibraryERKNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS_6HandleINS_6mirror11ClassLoaderEEEPS7_"
#define loadNativeLibarySymbol_API_23  "_ZN3art9JavaVMExt17LoadNativeLibraryEP7_JNIEnvRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEP8_jobjectPS9_"
#define loadNativeLibarySymbol_API_25 "_ZN3art9JavaVMExt17LoadNativeLibraryEP7_JNIEnvRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEP8_jobjectP8_jstringPS9_"
//thread
//-===========================dex 结构相关定义相关定义===================

static VM *vm = nullptr;

VM *VM::getInstance() {
    if (vm == nullptr) {
        vm = new VM;

    }
    return vm;
}

VM::VM() {
    sdk_version = getSdkVersion();
    if (sdk_version <= 19) {
        //初始化dalvik相关方法
        vm_handle = dlopen("/system/lib/libdvm.so", RTLD_NOW);
        dvmThreadSelf = (void *(*)()) dlsym(vm_handle, "_Z13dvmThreadSelfv");
        dvmDecodeIndirectRef = (Object *(*)(void *self, jobject jobj)) dlsym(
                vm_handle, "_Z20dvmDecodeIndirectRefP6ThreadP8_jobject");
    } else {
        vm_handle = fake_dlopen("/system/lib/libart.so", RTLD_NOW);
        DecodeJObject = (void *(*)(void *, jobject)) fake_dlsym(vm_handle,
                                                                ThreadDecodeJObject_symbol);
        getClassDescriptor = (const char *(*)(void *, void *)) (fake_dlsym(vm_handle,
                                                                           Class_GetDescriptor_symbol));
    }


}

int VM::getSdkVersion() {
    int sdkversion = 0;
    char val[PROP_VALUE_MAX];
    memset(val, 0, PROP_VALUE_MAX);
    __system_property_get("ro.build.version.sdk", val);
    sdkversion = atoi(val);
    return sdkversion;
}

/**
 * it's for jni
 */

const char *VM::getClasstName(jclass clazz) {
    if (sdk_version <= KITKAT) {
        ClassObject *clazzobject = (ClassObject *) dvmDecodeIndirectRef(dvmThreadSelf(),
                                                                        clazz);
        if (clazzobject == nullptr) {
            return nullptr;
        }
        return clazzobject->descriptor;
    } else {
        void *pVoid = DecodeJObject(Current(), clazz);
        std::string tmp;
        const char *data = getClassDescriptor(pVoid, &tmp);
        return data;
    }


}

/**
 * it's for jni
 */
const char *VM::getObjectName(jobject object) {
    if (sdk_version <= KITKAT) {
        Object *object1 = dvmDecodeIndirectRef(dvmThreadSelf(), object);
        ClassObject *clazz = object1->clazz;
        if (clazz == nullptr) {
            return nullptr;
        }
        return clazz->descriptor;
    } else {
        void *k_class = nullptr;
        void *pVoid = DecodeJObject(Current(), object);
        switch (sdk_version) {
            case LOLLIPOP: {
                Object_API21 *object_api21 = (Object_API21 *) (pVoid);
                k_class = (void *) object_api21->klass_;
            }
                break;
            case LOLLIPOP_MR1: {
                Object_API22 *object_api22 = (Object_API22 *) (pVoid);
                k_class = (void *) object_api22->klass_;

            }
                break;
            case Marshmallow: {
                Object_API23 *object_api23 = (Object_API23 *) (pVoid);
                k_class = (void *) object_api23->klass_;
            }
                break;
            case Nougat: {
                Object_API24 *object_api24 = (Object_API24 *) (pVoid);
                k_class = (void *) object_api24->klass_;
            }
                break;
            case Nougat_MR1: {
                Object_API25 *object_api25 = (Object_API25 *) (pVoid);
                k_class = (void *) object_api25->klass_;

            }
                break;
            case Oreo: {
                Object_API26 *object_api26 = (Object_API26 *) (pVoid);
                k_class = (void *) object_api26->klass_;
            }
            case Oreo_R1: {
                Object_API27 *object_api27 = (Object_API27 *) (pVoid);
                k_class = (void *) object_api27->klass_;
            }
                break;
            case Pie: {
                Object_API28 *object_api28 = (Object_API28 *) (pVoid);
                k_class = (void *) object_api28->klass_;
            }
                break;
            default: {
                LOGE("其它平台暂时不支持");
            }
                break;
        }
        std::string tmp;
        const char *data = getClassDescriptor(k_class, &tmp);
        return data;
    }
    return nullptr;
}

/**
 * it's for jni
 */
char *VM::getMethodName(jmethodID jmethodID1) {
    if (sdk_version <= KITKAT) {
        Method *method = (Method *) jmethodID1;
        std::string temp = method->name;
        temp = temp + method->shorty;
        char *data = new char[temp.length() + 1];
        memset(data, 0, temp.length() + 1);
        sprintf(data, "%s", temp.c_str());
        return data;
    } else {
        if (jmethodID1 == nullptr) {
            LOGE("getMethodName jmethod_id==nullptr");
            return nullptr;
        }
        uint32_t ac = 0;
        DexFileArt *dexFileArt;
        switch (sdk_version) {
            case LOLLIPOP: {
                ArtMethod_API21 *method_api21 = (ArtMethod_API21 *) (jmethodID1);
                ac = method_api21->dex_method_index_;
                uint32_t declaring_class_ = method_api21->declaring_class_;
                Class_API21 *class_api21 = (Class_API21 *) declaring_class_;
                DexCache_API21 *dexCache_api21 = (DexCache_API21 *) class_api21->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api21->dex_file_);

            }
                break;
            case LOLLIPOP_MR1: {
                ArtMethod_API22 *method_api22 = (ArtMethod_API22 *) (jmethodID1);
                ac = method_api22->dex_method_index_;
                uint32_t declaring_class_ = method_api22->declaring_class_;
                Class_API22 *class_api22 = (Class_API22 *) declaring_class_;
                DexCache_API22 *dexCache_api22 = (DexCache_API22 *) class_api22->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api22->dex_file_);
            }
                break;
            case Marshmallow: {
                ArtMethod_API23 *method_api23 = (ArtMethod_API23 *) (jmethodID1);
                ac = method_api23->dex_method_index_;

                uint32_t declaring_class_ = method_api23->declaring_class_;
                Class_API23 *class_api23 = (Class_API23 *) declaring_class_;
                DexCache_API23 *dexCache_api23 = (DexCache_API23 *) class_api23->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api23->dex_file_);

            }
                break;
            case Nougat: {
                ArtMethod_API24 *method_api24 = (ArtMethod_API24 *) (jmethodID1);
                ac = method_api24->dex_method_index_;
                uint32_t declaring_class_ = method_api24->declaring_class_;
                Class_API24 *class_api24 = (Class_API24 *) declaring_class_;
                DexCache_API24 *dexCache_api24 = (DexCache_API24 *) class_api24->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api24->dex_file_);
            }
                break;
            case Nougat_MR1: {
                ArtMethod_API25 *method_api25 = (ArtMethod_API25 *) (jmethodID1);
                ac = method_api25->dex_method_index_;
                uint32_t declaring_class_ = method_api25->declaring_class_;
                Class_API25 *class_api25 = (Class_API25 *) declaring_class_;
                DexCache_API25 *dexCache_api25 = (DexCache_API25 *) class_api25->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api25->dex_file_);
            }
                break;
            case Oreo: {
                ArtMethod_API26 *method_api26 = (ArtMethod_API26 *) (jmethodID1);
                ac = method_api26->dex_method_index_;
                uint32_t declaring_class_ = method_api26->declaring_class_;
                Class_API26 *class_api26 = (Class_API26 *) declaring_class_;
                DexCache_API26 *dexCache_api26 = (DexCache_API26 *) class_api26->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api26->dex_file_);
            }
                break;
            case Oreo_R1: {
                ArtMethod_API27 *method_api27 = (ArtMethod_API27 *) (jmethodID1);
                ac = method_api27->dex_method_index_;
                uint32_t declaring_class_ = method_api27->declaring_class_;
                Class_API27 *class_api27 = (Class_API27 *) declaring_class_;
                DexCache_API27 *dexCache_api27 = (DexCache_API27 *) class_api27->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api27->dex_file_);
            }
                break;
            case Pie: {
                ArtMethod_API28 *method_api28 = (ArtMethod_API28 *) (jmethodID1);
                ac = method_api28->dex_method_index_;
                uint32_t declaring_class_ = method_api28->declaring_class_;
                Class_API28 *class_api28 = (Class_API28 *) declaring_class_;
                DexCache_API28 *dexCache_api28 = (DexCache_API28 *) class_api28->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api28->dex_file_);
            }
                break;
            default: {
                LOGE("其它系统版本暂时不支持");
                ac = -1;
            }
                break;
        }
        DexFile *pDexFile = new DexFile;
        dexFileSetupBasicPointers(pDexFile, dexFileArt->data);
        FieldMethodInfo fieldMethodInfo;
        getMethodInfo(pDexFile, ac, &fieldMethodInfo);
        std::string data = fieldMethodInfo.name;
        data = data + fieldMethodInfo.signature;
        delete pDexFile;;
        int len = data.length() + 1;
        char *temp = new char[len];
        memset(temp, 0, len);
        sprintf(temp, "%s", data.c_str());
        return temp;
    }

}

/**
 * it's for jni
 */
char *VM::getFiledName(jfieldID jfieldID1) {
    if (sdk_version <= KITKAT) {
        Field *field = (Field *) jfieldID1;
        std::string temp = field->name;
        temp = temp + ":" + field->signature;
        char *data = new char[temp.length() + 1];
        memset(data, 0, temp.length() + 1);
        sprintf(data, "%s", temp.c_str());
        return data;
    } else {
        if (jfieldID1 == nullptr) {
            LOGE("getFiledName field==nullptr");
            return nullptr;
        }

        uint32_t ac = 0;
        DexFileArt *dexFileArt;
        switch (sdk_version) {
            case LOLLIPOP: {
                ArtField_API21 *method_api21 = (ArtField_API21 *) (jfieldID1);
                ac = method_api21->field_dex_idx_;
                uint32_t declaring_class_ = method_api21->declaring_class_;
                Class_API21 *class_api21 = (Class_API21 *) declaring_class_;
                DexCache_API21 *dexCache_api21 = (DexCache_API21 *) class_api21->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api21->dex_file_);

            }
                break;
            case LOLLIPOP_MR1: {
                ArtField_API22 *method_api22 = (ArtField_API22 *) (jfieldID1);
                ac = method_api22->field_dex_idx_;
                uint32_t declaring_class_ = method_api22->declaring_class_;
                Class_API22 *class_api22 = (Class_API22 *) declaring_class_;
                DexCache_API22 *dexCache_api22 = (DexCache_API22 *) class_api22->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api22->dex_file_);
            }
                break;
            case Marshmallow: {
                ArtField_API23 *method_api23 = (ArtField_API23 *) (jfieldID1);
                ac = method_api23->field_dex_idx_;
                uint32_t declaring_class_ = method_api23->declaring_class_;
                Class_API23 *class_api23 = (Class_API23 *) declaring_class_;
                DexCache_API23 *dexCache_api23 = (DexCache_API23 *) class_api23->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api23->dex_file_);

            }
                break;
            case Nougat: {
                ArtField_API24 *method_api24 = (ArtField_API24 *) (jfieldID1);
                ac = method_api24->field_dex_idx_;
                uint32_t declaring_class_ = method_api24->declaring_class_;
                Class_API24 *class_api24 = (Class_API24 *) declaring_class_;
                DexCache_API24 *dexCache_api24 = (DexCache_API24 *) class_api24->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api24->dex_file_);
            }
                break;
            case Nougat_MR1: {
                ArtField_API25 *method_api25 = (ArtField_API25 *) (jfieldID1);
                ac = method_api25->field_dex_idx_;
                uint32_t declaring_class_ = method_api25->declaring_class_;
                Class_API25 *class_api25 = (Class_API25 *) declaring_class_;
                DexCache_API25 *dexCache_api25 = (DexCache_API25 *) class_api25->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api25->dex_file_);
            }
                break;
            case Oreo: {
                ArtField_API26 *method_api26 = (ArtField_API26 *) (jfieldID1);
                ac = method_api26->field_dex_idx_;
                uint32_t declaring_class_ = method_api26->declaring_class_;
                Class_API26 *class_api26 = (Class_API26 *) declaring_class_;
                DexCache_API26 *dexCache_api26 = (DexCache_API26 *) class_api26->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api26->dex_file_);
            }
                break;
            case Oreo_R1: {
                ArtField_API27 *method_api27 = (ArtField_API27 *) (jfieldID1);
                ac = method_api27->field_dex_idx_;
                uint32_t declaring_class_ = method_api27->declaring_class_;
                Class_API27 *class_api27 = (Class_API27 *) declaring_class_;
                DexCache_API27 *dexCache_api27 = (DexCache_API27 *) class_api27->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api27->dex_file_);
            }
                break;
            case Pie: {
                ArtField_API28 *method_api28 = (ArtField_API28 *) (jfieldID1);
                ac = method_api28->field_dex_idx_;
                uint32_t declaring_class_ = method_api28->declaring_class_;
                Class_API28 *class_api28 = (Class_API28 *) declaring_class_;
                DexCache_API28 *dexCache_api28 = (DexCache_API28 *) class_api28->dex_cache_;
                dexFileArt = reinterpret_cast<DexFileArt *>(dexCache_api28->dex_file_);
            }
                break;
            default: {
                LOGE("其它系统版本暂时不支持");
                ac = -1;
            }
                break;
        }
        DexFile *pDexFile = new DexFile;
        dexFileSetupBasicPointers(pDexFile, dexFileArt->data);
        FieldMethodInfo fieldMethodInfo;
        getFieldInfo(pDexFile, ac, &fieldMethodInfo);
        std::string data = fieldMethodInfo.name;
        data = data + ":";
        data = data + fieldMethodInfo.signature;
        delete pDexFile;;
        int len = data.length() + 1;
        char *temp = new char[len];
        memset(temp, 0, len);
        sprintf(temp, "%s", data.c_str());
        return temp;
    }
    return nullptr;
}

/**
 * hook 系统加载so 相关函数
 */

bool (*olddvmLoadNativeCode)(const char *pathName, void *classLoader,
                             char **detail);

bool NewdvmLoadNativeCode(const char *pathName, void *classLoader,
                          char **detail) {
    bool res;
    if (gdvmbeforecall) {
        Nativefundvm(pathName);
        res = olddvmLoadNativeCode(pathName, classLoader, detail);
    } else {
        res = olddvmLoadNativeCode(pathName, classLoader, detail);
        Nativefundvm(pathName);
    }

    return res;
}

bool
(*oldLoadNativeLibrary_API25)(void *JavaVMExt, JNIEnv *env, const char **path, jobject class_loader,
                              jstring library_path,
                              std::string *error_msg);

bool LoadNativeLibrary_API25(void *JavaVMExt, JNIEnv *env, const char **path, jobject class_loader,
                             jstring library_path,
                             std::string *error_msg) {
    bool res = false;
    LOGE("start load %s", path[2]);
    if (gdvmbeforecall) {
        Nativefundvm(path[2]);
        res = oldLoadNativeLibrary_API25(JavaVMExt, env, path, class_loader, library_path,
                                         error_msg);
    } else {
        res = oldLoadNativeLibrary_API25(JavaVMExt, env, path, class_loader, library_path,
                                         error_msg);

        Nativefundvm(path[2]);
    }
    return res;
}

bool
(*oldLoadNativeLibrary_API23)(void *JavaVMExt, JNIEnv *env, const char **path, jobject class_loader,
                              std::string *error_msg);

bool LoadNativeLibrary_API23(void *JavaVMExt, JNIEnv *env, const char **path, jobject class_loader,
                             std::string *error_msg) {
    bool res = false;
    LOGE("start load %s", path[2]);
    if (gdvmbeforecall) {
        Nativefundvm(path[2]);
        res = oldLoadNativeLibrary_API23(JavaVMExt, env, path, class_loader, error_msg);
    } else {
        res = oldLoadNativeLibrary_API23(JavaVMExt, env, path, class_loader, error_msg);
        Nativefundvm(path[2]);
    }
    return res;
}

bool (*oldLoadNativeLibrary_API22)(void *JavaVMExt, const char **path, void *class_loader,
                                   std::string *detail);

bool LoadNativeLibrary_API22(void *JavaVMExt, const char **path, void *class_loader,
                             std::string *detail) {
    bool res = false;
    LOGE("start load %s", path[2]);
    //在so 加载之前执行代码
    if (gdvmbeforecall) {
        Nativefundvm(path[2]);
        res = oldLoadNativeLibrary_API22(JavaVMExt, path, class_loader, detail);
    } else //加载后执行d代码
    {
        res = oldLoadNativeLibrary_API22(JavaVMExt, path, class_loader, detail);
        Nativefundvm(path[2]);
    }
    return res;
}

void VM::hookLoadNativeLibary(void *newFunPtr, bool beforecall) {
    if (sdk_version <= KITKAT) {
        gdvmbeforecall = beforecall;
        Nativefundvm = (void (*)(const char *)) newFunPtr;
        void *dvmloadNativeCode = dlsym((void *) vm_handle, "_Z17dvmLoadNativeCodePKcP6ObjectPPc");
        HookHelper *helper = HookHelper::getInstance();
        helper->registerHook(dvmloadNativeCode, (void *) &NewdvmLoadNativeCode,
                             (void **) &olddvmLoadNativeCode);
        helper->hook(dvmloadNativeCode);
    } else {
        Nativefundvm = (void (*)(const char *)) (newFunPtr);
        gdvmbeforecall = beforecall;
        HookHelper *helper = HookHelper::getInstance();
        if (sdk_version == Nougat_MR1 || sdk_version == Nougat) {
            void *symbol = fake_dlsym(vm_handle, loadNativeLibarySymbol_API_25);
            if (symbol == nullptr) {
                LOGE("symbol null");
            }

            helper->registerHook(symbol, (void *) &LoadNativeLibrary_API25,
                                 (void **) &oldLoadNativeLibrary_API25);
            helper->hookAll();
            return;
        } else if (sdk_version == Marshmallow) {
            void *symbol = fake_dlsym(vm_handle, loadNativeLibarySymbol_API_23);
            if (symbol == nullptr) {
                LOGE("symbol null ");
            }
            helper->registerHook(symbol, (void *) &LoadNativeLibrary_API23,
                                 (void **) &oldLoadNativeLibrary_API23);
            helper->hookAll();
            return;
        } else if (sdk_version == LOLLIPOP_MR1 || sdk_version == LOLLIPOP) {
            void *symbol = fake_dlsym(vm_handle, loadNativeLibarySymbol_API_22);
            if (symbol == nullptr) {
                LOGE("symbol null ");
            }
            helper->registerHook(symbol, (void *) &LoadNativeLibrary_API22,
                                 (void **) &oldLoadNativeLibrary_API22);
            helper->hookAll();
            return;
        } else {
            LOGE("android 4.4 art暂不支持");
        }
    }
}


void (*olddvmOptimizeClass)(ClassObject *, bool);

void dvmOptimizeClass(ClassObject *clazz, bool essentialOnly) {
    return;
}

bool (*olddvmVerifyCodeFlow)(void *vdata);

bool dvmVerifyCodeFlow(void *vdata) {
    return true;
}

void VM::closeOptClass() {
    if (sdk_version <= KITKAT) {
        HookHelper *helper = HookHelper::getInstance();
        void *dvmOptimizeClassPtr = dlsym((void *) vm_handle,
                                          "_Z16dvmOptimizeClassP11ClassObjectb");
        helper->registerHook(dvmOptimizeClassPtr, (void *) &dvmOptimizeClass,
                             (void **) &olddvmOptimizeClass);
        void *_Z17dvmVerifyCodeFlowP12VerifierData = dlsym(vm_handle,
                                                           "_Z17dvmVerifyCodeFlowP12VerifierData");
        helper->registerHook(_Z17dvmVerifyCodeFlowP12VerifierData, (void *) &dvmVerifyCodeFlow,
                             (void **) &olddvmVerifyCodeFlow);
        helper->hookAll();
    } else {
        LOGE("not support art");
    }
}


DexFile *(*olddexFileParse)(const u1 *data, size_t length, int flags);

DexFile *newDexFileParse(const u1 *data, size_t length, int flags) {
    DexFile *res;
    if (gdvmbeforeCallDexFileParse) {
        NativeFunDvmDexFileParse(data, length, nullptr);
        res = olddexFileParse(data, length, flags);
    } else {
        res = olddexFileParse(data, length, flags);
        NativeFunDvmDexFileParse(data, length, res);
    }
    return res;
}

const void *(*oldOpenMemory_1)(void *thiz, const u1 *dex_file,
                               size_t size,
                               const std::string &location,
                               uint32_t location_checksum,
                               void *mem_map,
                               const void *oat_file,
                               std::string *error_msg);

const void *OpenMemory_1(void *thiz, const u1 *dex_file,
                         size_t size,
                         const std::string &location,
                         uint32_t location_checksum,
                         void *mem_map,
                         const void *oat_file,
                         std::string *error_msg) {
    LOGI("found a dex file");
    if (gdvmbeforeCallDexFileParse) {
        const void *res = oldOpenMemory_1(thiz, dex_file, size, location, location_checksum,
                                          mem_map, oat_file,
                                          error_msg);
        NativeFunDvmDexFileParse(dex_file, size, nullptr);
        return res;
    } else {
        NativeFunDvmDexFileParse(dex_file, size, nullptr);
        const void *res = oldOpenMemory_1(thiz, dex_file, size, location, location_checksum,
                                          mem_map, oat_file,
                                          error_msg);

        return res;
    }
}

const void *(*oldOpenMemory_0)(void *thiz, const u1 *dex_file,
                               size_t size,
                               const std::string &location,
                               uint32_t location_checksum,
                               void *mem_map,
                               std::string *error_msg);

const void *OpenMemory_0(void *thiz, const u1 *dex_file,
                         size_t size,
                         const std::string &location,
                         uint32_t location_checksum,
                         void *mem_map,
                         std::string *error_msg) {
    LOGI("found a dex file");
    if (gdvmbeforeCallDexFileParse) {
        const void *res = oldOpenMemory_0(thiz, dex_file, size, location, location_checksum,
                                          mem_map, error_msg);
        NativeFunDvmDexFileParse(dex_file, size, nullptr);
        return res;
    } else {
        NativeFunDvmDexFileParse(dex_file, size, nullptr);
        const void *res = oldOpenMemory_0(thiz, dex_file, size, location, location_checksum,
                                          mem_map, error_msg);

        return res;
    }
}

void VM::hookDexFileParse(void *newFunPtr, bool beforecall) {
    if (sdk_version <= KITKAT) {
        gdvmbeforeCallDexFileParse = beforecall;
        NativeFunDvmDexFileParse = (void *(*)(const u1 *, size_t, DexFile *)) newFunPtr;
        void *dvmloadNativeCode = dlsym((void *) vm_handle, "_Z12dexFileParsePKhji");
        HookHelper *helper = HookHelper::getInstance();
        helper->registerHook(dvmloadNativeCode, (void *) &newDexFileParse,
                             (void **) &olddexFileParse);
        helper->hook(dvmloadNativeCode);
    } else {
        HookHelper *helper = HookHelper::getInstance();
        void *handle = fake_dlsym(vm_handle, DexFileOpenMemory_Symbol_API_21);
        if (handle != nullptr) {
            helper->registerHook(handle, (void *) &OpenMemory_0, (void **) &oldOpenMemory_0);
        }
        handle = fake_dlsym(vm_handle, DexFileOpenMemory_Symbol_API_24);
        if (handle != nullptr) {
            helper->registerHook(handle, (void *) &OpenMemory_1, (void **) &oldOpenMemory_1);
        }
        helper->hookAll();
    }


}

#include <pthread.h>

void *VM::Current() {
#if defined(__aarch64__)
# define __get_tls() ({ void** __val; __asm__("mrs %0, tpidr_el0" : "=r"(__val)); __val; })
#elif defined(__arm__)
# define __get_tls() ({ void** __val; __asm__("mrc p15, 0, %0, c13, c0, 3" : "=r"(__val)); __val; })
#elif defined(__mips__)
# define __get_tls() \
    /* On mips32r1, this goes via a kernel illegal instruction trap that's optimized for v1. */ \
    ({ register void** __val asm("v1"); \
       __asm__(".set    push\n" \
               ".set    mips32r2\n" \
               "rdhwr   %0,$29\n" \
               ".set    pop\n" : "=r"(__val)); \
       __val; })
#elif defined(__i386__)
# define __get_tls() ({ void** __val; __asm__("movl %%gs:0, %0" : "=r"(__val)); __val; })
#elif defined(__x86_64__)
# define __get_tls() ({ void** __val; __asm__("mov %%fs:0, %0" : "=r"(__val)); __val; })
#else
#error unsupported architecture
#endif
    enum {
        TLS_SLOT_SELF = 0,
        // The kernel requires this specific slot for x86.
                TLS_SLOT_THREAD_ID,
        TLS_SLOT_ERRNO,

        // These two aren't used by bionic itself, but allow the graphics code to
        // access TLS directly rather than using the pthread API.
                TLS_SLOT_OPENGL_API = 3,
        TLS_SLOT_OPENGL = 4,

        // This slot is only used to pass information from the dynamic linker to
        // libc.so when the C library is loaded in to memory. The C runtime init
        // function will then clear it. Since its use is extremely temporary,
        // we reuse an existing location that isn't needed during libc startup.
                TLS_SLOT_BIONIC_PREINIT = TLS_SLOT_OPENGL_API,

        TLS_SLOT_STACK_GUARD = 5,
        // GCC requires this specific slot for x86.
                TLS_SLOT_DLERROR,

        // Fast storage for Thread::Current() in ART.
                TLS_SLOT_ART_THREAD_SELF,

        // Lets TSAN avoid using pthread_getspecific for finding the current thread
        // state.
                TLS_SLOT_TSAN,

        BIONIC_TLS_SLOTS // Must come last!
    };
    if (sdk_version >= Nougat) {
        //get thread form asm code
        void *thread = __get_tls()[TLS_SLOT_ART_THREAD_SELF];
        return thread;
    } else {
        if (pthread_key_self_handle == nullptr) {
            pthread_key_self_handle = fake_dlsym(vm_handle, pthread_key_self_Symbol);
        }
        pthread_key_t key = *(pthread_key_t *) pthread_key_self_handle;
        void *thread = pthread_getspecific(key);
        return thread;
    }
}




