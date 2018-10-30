//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/6/19.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
// Instruction helper for mips
//===----------------------------------------------------------------------===//


#ifndef FAINHOOK_MIPSINSTRUCTION_H
#define FAINHOOK_MIPSINSTRUCTION_H

#include "Instruction.h"

class MipsInstruction : public Instruction {
public:
    ~MipsInstruction() {}

    bool createStub(HookInfo *info);
};


#endif //FAINHOOK_MIPSINSTRUCTION_H
