/**
* @ name unpacker
* @ author xiaobaiyey
* @ email xiaobaiyey@outlook.com
* @ time 2018/9/5 上午4:30
* @ class this code copy from FAinline hook so just for study
*/

#ifndef UNPACKER_HELPER_H
#define UNPACKER_HELPER_H


#include <cstdint>
#include <vector>
#include <string.h>
#include <string>

class Helper {
public:
    static bool isFunctionAddr(void *addr);

    /* remove write protect*/
    static bool unProtectMemory(void *addr, uint32_t size);

    /* add write protect*/
    static bool protectMemory(void *addr, uint32_t size);

    /* get a executable memory*/
    static void *createExecMemory(uint32_t size);

    Helper();

    ~Helper();

private:
    std::vector<void *> alloc_memory_page_;
    void *current_page = nullptr;
    uint32_t page_ptr_ = 0;

    static uint32_t page_size;
};


#endif //UNPACKER_HELPER_H
