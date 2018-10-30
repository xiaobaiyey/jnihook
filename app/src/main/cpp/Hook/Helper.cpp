/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/9/5 上午4:30
* @ class describe
*/

#include <bits/sysconf.h>
#include <sys/mman.h>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include "Helper.h"

#define maps "/proc/self/maps"
#define MAX_BUF 128
Helper gMemHelper;
uint32_t Helper::page_size;

/**
 * Check if the target address is executable
 * @param addr target address to hook
 * @return nothing to do
 */
bool Helper::isFunctionAddr(void *addr) {
    char buf[MAX_BUF];
    auto fp = fopen(maps, "r");
    if (nullptr == fp) {
        return false;
    }
    while (fgets(buf, MAX_BUF, fp)) {
        if (strstr(buf, "r-xp") != nullptr) {
            void *startAddr = (void *) strtoul(strtok(buf, "-"), nullptr, 16);
            void *endAddr = (void *) strtoul(strtok(nullptr, " "), nullptr, 16);
            if (addr >= startAddr && addr <= endAddr) {
                fclose(fp);
                return true;
            }
        }
    }
    fclose(fp);
    return false;
}

/**
 * reomve a writable attribute to the target address
 * @param addr target address
 * @param size memory size to change
 * @return
 */
bool Helper::unProtectMemory(void *addr, uint32_t size) {
    //page align
    auto align = ((size_t) addr) % page_size;
    return mprotect((uint8_t *) addr - align, size + align, PROT_READ | PROT_WRITE | PROT_EXEC) !=
           -1;
}

/**
 * add a writable attribute to the target address
 * @param addr target address
 * @param size memory size to change
 * @return
 */
bool Helper::protectMemory(void *addr, uint32_t size) {
    auto align = ((size_t) addr) % page_size;
    return mprotect((uint8_t *) addr - align, size + align, PROT_READ | PROT_EXEC) != -1;
}

/**
 *
 * @param size
 * @return
 */
void *Helper::createExecMemory(uint32_t size) {
    if (size & 1) {
        size++;
    }
    if (size > page_size) {
        return nullptr;
    }
    if (gMemHelper.current_page != nullptr && page_size - gMemHelper.page_ptr_ >= size) {
        auto funPtr = (void *) ((size_t) gMemHelper.current_page + gMemHelper.page_ptr_);
        gMemHelper.page_ptr_ += size;
        // Align 4
        while (gMemHelper.page_ptr_ & 0x3) {
            gMemHelper.page_ptr_++;
        }
        return funPtr;
    }
    // scroll to next page
    auto newPage = mmap(nullptr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC,
                        MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
    if (newPage != MAP_FAILED) {
        gMemHelper.alloc_memory_page_.push_back(newPage);

        gMemHelper.current_page = newPage;
        gMemHelper.page_ptr_ = 0;
        return createExecMemory(size);
    }
    return nullptr;
}


Helper::Helper() {
    // get system page size
    page_size = sysconf(_SC_PAGESIZE);
}

Helper::~Helper() {
    for (auto *page : alloc_memory_page_) {
        munmap(page, page_size);
    }
}
