//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/6/19.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//


#include "ArmInstruction.h"
#include "../Helper.h"


bool ArmInstruction::createStub(HookInfo *info) {
    auto stubsize = 8;
    auto *stub = new uint32_t[2];
    *(uint32_t *) &stub[0] = 0xe51ff004; // ldr pc, addr
    *(uint32_t *) &stub[4] = (uint32_t) info->getHookAddr();

    stub[0] = A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8);  // ldr pc, pc, -4
    stub[1] = reinterpret_cast<uint32_t >(info->getHookAddr());

    info->setJumpStubLen(stubsize);
    info->setJumpStubBack((uint8_t *) stub);
    return true;
}

bool ArmInstruction::createCallOriginalStub(HookInfo *info) {
    uint32_t *area(reinterpret_cast<uint32_t *>(info->getOriginalAddr()));
    uint32_t *arm(area);

    const size_t used(8);

    uint32_t backup[used / sizeof(uint32_t)] = {arm[0], arm[1]};


    if (backup[0] == A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8)) { // ldr pc, pc, -4
        info->setCallOriginalIns(reinterpret_cast<uint8_t *>(backup[1]));
        return true;
    }

    size_t length(used);
    for (unsigned offset(0); offset != used / sizeof(uint32_t); ++offset)
        if (A$pcrel$r(backup[offset])) {
            if ((backup[offset] & 0x02000000) == 0 ||
                (backup[offset] & 0x0000f000 >> 12) != (backup[offset] & 0x0000000f))
                length += 2 * sizeof(uint32_t);
            else
                length += 4 * sizeof(uint32_t);
        }

    length += 2 * sizeof(uint32_t);

    uint32_t *buffer = (uint32_t *) Helper::createExecMemory(length);
    if (buffer == nullptr) {
        return false;
    }


    size_t start(0), end(length / sizeof(uint32_t));
    uint32_t *trailer(reinterpret_cast<uint32_t *>(buffer + end));
    for (unsigned offset(0); offset != used / sizeof(uint32_t); ++offset)
        if (A$pcrel$r(backup[offset])) {
            union {
                uint32_t value;

                struct {
                    uint32_t rm : 4;
                    uint32_t : 1;
                    uint32_t shift : 2;
                    uint32_t shiftamount : 5;
                    uint32_t rd : 4;
                    uint32_t rn : 4;
                    uint32_t l : 1;
                    uint32_t w : 1;
                    uint32_t b : 1;
                    uint32_t u : 1;
                    uint32_t p : 1;
                    uint32_t mode : 1;
                    uint32_t type : 2;
                    uint32_t cond : 4;
                };
            } bits = {backup[offset + 0]}, copy(bits);

            bool guard;
            if (bits.mode == 0 || bits.rd != bits.rm) {
                copy.rn = bits.rd;
                guard = false;
            } else {
                copy.rn = bits.rm != A$r0 ? A$r0 : A$r1;
                guard = true;
            }

            if (guard)
                buffer[start++] = A$stmdb_sp$_$rs$((1 << copy.rn));

            buffer[start + 0] = A$ldr_rd_$rn_im$(copy.rn, A$pc, (end - 1 - (start + 0)) * 4 - 8);
            buffer[start + 1] = copy.value;

            start += 2;

            if (guard)
                buffer[start++] = A$ldmia_sp$_$rs$((1 << copy.rn));

            *--trailer = reinterpret_cast<uint32_t>(area + offset) + 8;
            end -= 1;
        } else
            buffer[start++] = backup[offset];

    buffer[start + 0] = A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8);
    buffer[start + 1] = reinterpret_cast<uint32_t>(area + used / sizeof(uint32_t));

    info->setCallOriginalIns((uint8_t *) buffer);

    return true;
}
