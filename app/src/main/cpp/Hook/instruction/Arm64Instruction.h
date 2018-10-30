//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/6/19.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// instruction helper for arm64
//===----------------------------------------------------------------------===//


#ifndef FAINHOOK_ARM64INSTRUCTION_H
#define FAINHOOK_ARM64INSTRUCTION_H

#include "Instruction.h"
#include <stdint.h>
#include <android/log.h>
#include <sys/mman.h>

#define FLOG_TAG "ARM64"

#include <android/log.h>

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, FLOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, FLOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, FLOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, FLOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, FLOG_TAG, __VA_ARGS__)
#define A64_MAX_BACKUPS 256

class Arm64Instruction : public Instruction {
public:
    ~Arm64Instruction() {}

    bool createStub(HookInfo *info);

    bool createCallOriginalStub(HookInfo *info);

private:

    bool repairCallOriginIns(HookInfo *info, uint8_t repair[], uint32_t &repairLen);


};


#endif //FAINHOOK_ARM64INSTRUCTION_H
