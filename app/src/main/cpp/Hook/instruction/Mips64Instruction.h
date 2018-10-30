//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/6/19.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// Instruction Helper for mips64
//===----------------------------------------------------------------------===//


#ifndef FAINHOOK_MIPS64INSTRUCTION_H
#define FAINHOOK_MIPS64INSTRUCTION_H

#include "Instruction.h"

class Mips64Instruction : public Instruction {
public:
    ~Mips64Instruction() {}

    bool createStub(HookInfo *info);
};


#endif //FAINHOOK_MIPS64INSTRUCTION_H
