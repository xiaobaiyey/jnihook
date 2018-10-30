//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/6/9.
//                   Copyright (c) 2017. All rights reserved.
//===--------------------------------------------------------------------------
// Save hook func information
//===----------------------------------------------------------------------===//

#ifndef FAINHOOK_HOOKINFO_H
#define FAINHOOK_HOOKINFO_H


#include <cstdint>

enum HookStatus {
    ERRSTATUS = 0,
    REGISTERED,
    HOOKED,
};

enum FunctionType {
    ERRTYPE = 0,
    ARM,
    THUMB,
    ARM64,
    X86,
    X64,
    MIPS,
    MIPS64,
};

class HookInfo {
public:
    HookInfo(void *originalAddr, void *hookAddr)
            : original_addr_(originalAddr), hook_addr_(hookAddr),
              original_stub_back_(nullptr), back_len_(0), call_original_ins_(nullptr),
              hook_status_(ERRSTATUS),
              original_function_type_(ERRTYPE), hook_function_type_(ERRTYPE) {}

    ~HookInfo() {
        if (jump_stub_back_ != nullptr) {
            delete[] (uint8_t *) jump_stub_back_;
        }
        if (original_stub_back_ != nullptr) {
            delete[] (uint8_t *) original_stub_back_;
        }
    }

private:
    void *original_addr_;
    void *hook_addr_;

    // used for hook, to store jump stub
    uint8_t *jump_stub_back_ = nullptr;         // record jump opcode
    uint32_t stub_len_;

    // used for unhook, to restore opcodes.
    uint8_t *original_stub_back_ = nullptr;           // record original opcode
    uint32_t back_len_;                     // orginal opcode size
    uint8_t *call_original_ins_;            // new opcode, to jump into hookAddr

    HookStatus hook_status_;
    FunctionType original_function_type_;
    FunctionType hook_function_type_;

public:
    void *getOriginalAddr() { return original_addr_; }

    void *getHookAddr() { return hook_addr_; }

    void setJumpStubBack(uint8_t *addr) { jump_stub_back_ = addr; }

    uint8_t *getJumpStubBack() { return jump_stub_back_; }

    void setJumpStubLen(uint32_t len) { stub_len_ = len; }

    uint32_t getJumpStubLen() { return stub_len_; }

    void setOriginalStubBack(uint8_t *addr) { original_stub_back_ = addr; }

    uint8_t *getOriginalStubBack() { return original_stub_back_; }

    void setBackLen(uint32_t len) { back_len_ = len; }

    uint32_t getBackLen() { return back_len_; }

    void setCallOriginalIns(uint8_t *addr) { call_original_ins_ = addr; }

    uint8_t *getCallOriginalIns() { return call_original_ins_; }

    void setHookStatus(HookStatus status) { hook_status_ = status; }

    HookStatus getHookStatus() { return hook_status_; }

    void setOriginalFunctionType(FunctionType type) { original_function_type_ = type; }

    FunctionType getOriginalFunctionType() { return original_function_type_; }

    void setHookFunctionType(FunctionType type) { hook_function_type_ = type; }

    FunctionType getHookFunctionType() { return hook_function_type_; }
};


#endif //FAINHOOK_HOOKINFO_H
