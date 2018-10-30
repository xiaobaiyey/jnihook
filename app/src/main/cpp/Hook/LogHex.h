#pragma once

#include <stdlib.h>

class LogHex {
public:
    static void PrintHex(const void *vdata, size_t size, const char *mark);

    static void PrintHexEx(const void *vdata, size_t size, size_t stride, const char *mark);

    static void DumpHex(const void *vdata, size_t size);
};