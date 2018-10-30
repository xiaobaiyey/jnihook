//===------------------------------------------------------------*- C++ -*-===//
//
//                     Created by F8LEFT on 2017/6/19.
//                   Copyright (c) 2017. All rights reserved.
//===----------------------------------------------------------------------===//
//
//===----------------------------------------------------------------------===//


#include <cstring>
#include "ThumbInstruction.h"
#include "../Helper.h"


bool ThumbInstruction::createStub(HookInfo *info) {
    auto stubSize = 0;
    uint8_t *stub = nullptr;

    uint32_t addr = (uint32_t) info->getOriginalAddr();
    auto clearBit0 = addr & 0xFFFFFFFE;

    if (clearBit0 % 4 != 0) {                       // need to align 4, just patch with nop
        stub = new uint8_t[10];
        ((uint16_t *) stub)[stubSize++] = 0xBF00;     //NOP
    } else {
        stub = new uint8_t[8];
    }
    ((uint16_t *) stub)[stubSize++] = 0xF8DF;
    ((uint16_t *) stub)[stubSize++] = 0xF000; // LDR.W PC, [PC]
    ((uint16_t *) stub)[stubSize++] = (uint32_t) info->getHookAddr() & 0xFFFF;
    ((uint16_t *) stub)[stubSize++] = (uint32_t) info->getHookAddr() >> 16;

    info->setJumpStubLen(stubSize * 2);
    info->setJumpStubBack(stub);
    return true;
}

bool ThumbInstruction::createCallOriginalStub(HookInfo *info) {
    uint16_t *area(reinterpret_cast<uint16_t *>(getOriginalAddr(info)));


    uint16_t *trail(reinterpret_cast<uint16_t *>(
                            reinterpret_cast<uintptr_t >(area) + info->getJumpStubLen()));

    if (T$pcrel$ldrw(area[0]) &&
        area[1] == 0xF000
            ) {
        uint32_t *arm(reinterpret_cast<uint32_t *>(area));
        info->setCallOriginalIns(reinterpret_cast<uint8_t *>(arm[1]));
        return true;
    }

    size_t required((trail - area) * sizeof(uint16_t));

    size_t used(0);
    while (used < required)
        used += MSGetInstructionWidthThumb(reinterpret_cast<uint8_t *>(area) + used);
    used = (used + sizeof(uint16_t) - 1) / sizeof(uint16_t) * sizeof(uint16_t);

    size_t blank((used - required) / sizeof(uint16_t));

    uint16_t backup[used / sizeof(uint16_t)];
    memcpy(backup, area, used);


    size_t length(used);
    for (unsigned offset(0); offset != used / sizeof(uint16_t); ++offset)
        if (T$pcrel$ldr(backup[offset]))
            length += 3 * sizeof(uint16_t);
        else if (T$pcrel$b(backup[offset]))
            length += 6 * sizeof(uint16_t);
        else if (T2$pcrel$b(backup + offset)) {
            length += 5 * sizeof(uint16_t);
            ++offset;
        } else if (T$pcrel$bl(backup + offset)) {
            length += 5 * sizeof(uint16_t);
            ++offset;
        } else if (T$pcrel$cbz(backup[offset])) {
            length += 16 * sizeof(uint16_t);
        } else if (T$pcrel$ldrw(backup[offset])) {
            length += 4 * sizeof(uint16_t);
            ++offset;
        } else if (T$pcrel$add(backup[offset]))
            length += 6 * sizeof(uint16_t);
        else if (T$32bit$i(backup[offset]))
            ++offset;

    unsigned pad((length & 0x2) == 0 ? 0 : 1);
    length += (pad + 2) * sizeof(uint16_t) + 2 * sizeof(uint32_t);

    uint16_t *buffer = (uint16_t *) Helper::createExecMemory(length);
    if (buffer == nullptr) {
        return false;
    }

    size_t start(pad), end(length / sizeof(uint16_t));
    uint32_t *trailer(reinterpret_cast<uint32_t *>(buffer + end));
    for (unsigned offset(0); offset != used / sizeof(uint16_t); ++offset) {
        if (T$pcrel$ldr(backup[offset])) {
            union {
                uint16_t value;

                struct {
                    uint16_t immediate : 8;
                    uint16_t rd : 3;
                    uint16_t : 5;
                };
            } bits = {backup[offset + 0]};

            buffer[start + 0] = T$ldr_rd_$pc_im_4$(bits.rd, T$Label(start + 0, end - 2) / 4);
            buffer[start + 1] = T$ldr_rd_$rn_im_4$(bits.rd, bits.rd, 0);

            // XXX: this code "works", but is "wrong": the mechanism is more complex than this
            *--trailer =
                    ((reinterpret_cast<uint32_t>(area + offset) + 4) & ~0x2) + bits.immediate * 4;

            start += 2;
            end -= 2;
        } else if (T$pcrel$b(backup[offset])) {
            union {
                uint16_t value;

                struct {
                    uint16_t imm8 : 8;
                    uint16_t cond : 4;
                    uint16_t /*1101*/ : 4;
                };
            } bits = {backup[offset + 0]};

            intptr_t jump(bits.imm8 << 1);
            jump |= 1;
            jump <<= 23;
            jump >>= 23;

            buffer[start + 0] = T$b$_$im(bits.cond, (end - 6 - (start + 0)) * 2 - 4);

            *--trailer = reinterpret_cast<uint32_t>(area + offset) + 4 + jump;
            *--trailer = A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8);
            *--trailer = T$nop << 16 | T$bx(A$pc);

            start += 1;
            end -= 6;
        } else if (T2$pcrel$b(backup + offset)) {
            union {
                uint16_t value;

                struct {
                    uint16_t imm6 : 6;
                    uint16_t cond : 4;
                    uint16_t s : 1;
                    uint16_t : 5;
                };
            } bits = {backup[offset + 0]};

            union {
                uint16_t value;

                struct {
                    uint16_t imm11 : 11;
                    uint16_t j2 : 1;
                    uint16_t a : 1;
                    uint16_t j1 : 1;
                    uint16_t : 2;
                };
            } exts = {backup[offset + 1]};

            intptr_t jump(1);
            jump |= exts.imm11 << 1;
            jump |= bits.imm6 << 12;

            if (exts.a) {
                jump |= bits.s << 24;
                jump |= (~(bits.s ^ exts.j1) & 0x1) << 23;
                jump |= (~(bits.s ^ exts.j2) & 0x1) << 22;
                jump |= bits.cond << 18;
                jump <<= 7;
                jump >>= 7;
            } else {
                jump |= bits.s << 20;
                jump |= exts.j2 << 19;
                jump |= exts.j1 << 18;
                jump <<= 11;
                jump >>= 11;
            }

            buffer[start + 0] = T$b$_$im(exts.a ? A$al : bits.cond,
                                         (end - 6 - (start + 0)) * 2 - 4);

            *--trailer = reinterpret_cast<uint32_t>(area + offset) + 4 + jump;
            *--trailer = A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8);
            *--trailer = T$nop << 16 | T$bx(A$pc);

            ++offset;
            start += 1;
            end -= 6;
        } else if (T$pcrel$bl(backup + offset)) {
            union {
                uint16_t value;

                struct {
                    uint16_t immediate : 10;
                    uint16_t s : 1;
                    uint16_t : 5;
                };
            } bits = {backup[offset + 0]};

            union {
                uint16_t value;

                struct {
                    uint16_t immediate : 11;
                    uint16_t j2 : 1;
                    uint16_t x : 1;
                    uint16_t j1 : 1;
                    uint16_t : 2;
                };
            } exts = {backup[offset + 1]};

            int32_t jump(0);
            jump |= bits.s << 24;
            jump |= (~(bits.s ^ exts.j1) & 0x1) << 23;
            jump |= (~(bits.s ^ exts.j2) & 0x1) << 22;
            jump |= bits.immediate << 12;
            jump |= exts.immediate << 1;
            jump |= exts.x;
            jump <<= 7;
            jump >>= 7;

            buffer[start + 0] = T$push_r(1 << A$r7);
            buffer[start + 1] = T$ldr_rd_$pc_im_4$(A$r7, ((end - 2 - (start + 1)) * 2 - 4 + 2) / 4);
            buffer[start + 2] = T$mov_rd_rm(A$lr, A$r7);
            buffer[start + 3] = T$pop_r(1 << A$r7);
            buffer[start + 4] = T$blx(A$lr);

            *--trailer = reinterpret_cast<uint32_t>(area + offset) + 4 + jump;

            ++offset;
            start += 5;
            end -= 2;
        } else if (T$pcrel$cbz(backup[offset])) {
            union {
                uint16_t value;

                struct {
                    uint16_t rn : 3;
                    uint16_t immediate : 5;
                    uint16_t : 1;
                    uint16_t i : 1;
                    uint16_t : 1;
                    uint16_t op : 1;
                    uint16_t : 4;
                };
            } bits = {backup[offset + 0]};

            intptr_t jump(1);
            jump |= bits.i << 6;
            jump |= bits.immediate << 1;

            //jump <<= 24;
            //jump >>= 24;

            unsigned rn(bits.rn);
            unsigned rt(rn == A$r7 ? A$r6 : A$r7);

            buffer[start + 0] = T$push_r(1 << rt);
            buffer[start + 1] = T1$mrs_rd_apsr(rt);
            buffer[start + 2] = T2$mrs_rd_apsr(rt);
            buffer[start + 3] = T$cbz$_rn_$im(bits.op, rn, (end - 10 - (start + 3)) * 2 - 4);
            buffer[start + 4] = T1$msr_apsr_nzcvqg_rn(rt);
            buffer[start + 5] = T2$msr_apsr_nzcvqg_rn(rt);
            buffer[start + 6] = T$pop_r(1 << rt);

            *--trailer = reinterpret_cast<uint32_t>(area + offset) + 4 + jump;
            *--trailer = A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8);
            *--trailer = T$nop << 16 | T$bx(A$pc);
            *--trailer = T$nop << 16 | T$pop_r(1 << rt);
            *--trailer = T$msr_apsr_nzcvqg_rn(rt);

#if 0
            if ((start & 0x1) == 0)
                buffer[start++] = T$nop;
            buffer[start++] = T$bx(A$pc);
            buffer[start++] = T$nop;

            uint32_t *arm(reinterpret_cast<uint32_t *>(buffer + start));
            arm[0] = A$add(A$lr, A$pc, 1);
            arm[1] = A$ldr_rd_$rn_im$(A$pc, A$pc, (trailer - arm) * sizeof(uint32_t) - 8);
#endif

            start += 7;
            end -= 10;
        } else if (T$pcrel$ldrw(backup[offset])) {
            union {
                uint16_t value;

                struct {
                    uint16_t : 7;
                    uint16_t u : 1;
                    uint16_t : 8;
                };
            } bits = {backup[offset + 0]};

            union {
                uint16_t value;

                struct {
                    uint16_t immediate : 12;
                    uint16_t rt : 4;
                };
            } exts = {backup[offset + 1]};

            buffer[start + 0] = T1$ldr_rt_$rn_im$(exts.rt, A$pc, T$Label(start + 0, end - 2));
            buffer[start + 1] = T2$ldr_rt_$rn_im$(exts.rt, A$pc, T$Label(start + 0, end - 2));

            buffer[start + 2] = T1$ldr_rt_$rn_im$(exts.rt, exts.rt, 0);
            buffer[start + 3] = T2$ldr_rt_$rn_im$(exts.rt, exts.rt, 0);

            // XXX: this code "works", but is "wrong": the mechanism is more complex than this
            *--trailer = ((reinterpret_cast<uint32_t>(area + offset) + 4) & ~0x2) +
                         (bits.u == 0 ? -exts.immediate : exts.immediate);

            ++offset;
            start += 4;
            end -= 2;
        } else if (T$pcrel$add(backup[offset])) {
            union {
                uint16_t value;

                struct {
                    uint16_t rd : 3;
                    uint16_t rm : 3;
                    uint16_t h2 : 1;
                    uint16_t h1 : 1;
                    uint16_t : 8;
                };
            } bits = {backup[offset + 0]};

            if (bits.h1) {
                return false;
            }

            unsigned rt(bits.rd == A$r7 ? A$r6 : A$r7);

            buffer[start + 0] = T$push_r(1 << rt);
            buffer[start + 1] = T$mov_rd_rm(rt, (bits.h1 << 3) | bits.rd);
            buffer[start + 2] = T$ldr_rd_$pc_im_4$(bits.rd, T$Label(start + 2, end - 2) / 4);
            buffer[start + 3] = T$add_rd_rm((bits.h1 << 3) | bits.rd, rt);
            buffer[start + 4] = T$pop_r(1 << rt);
            *--trailer = reinterpret_cast<uint32_t>(area + offset) + 4;

            start += 5;
            end -= 2;
        } else if (T$32bit$i(backup[offset])) {
            buffer[start++] = backup[offset];
            buffer[start++] = backup[++offset];
        } else {
            buffer[start++] = backup[offset];
        }
    }

    buffer[start++] = T$bx(A$pc);
    buffer[start++] = T$nop;

    uint32_t *transfer = reinterpret_cast<uint32_t *>(buffer + start);
    transfer[0] = A$ldr_rd_$rn_im$(A$pc, A$pc, 4 - 8);
    transfer[1] = reinterpret_cast<uint32_t>(area + used / sizeof(uint16_t)) + 1;

    info->setCallOriginalIns(reinterpret_cast<uint8_t *>(buffer + pad) + 1);

    return true;
}
