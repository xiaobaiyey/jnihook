#include "LogHex.h"
#include <stdio.h>
#include <android/log.h>

static char _MSHexChar(uint8_t value) {
    return value < 0x20 || value >= 0x80 ? '.' : value;
}

#define HexWidth_ 16
#define HexDepth_ 4
#define LOGDH(...) __android_log_print(ANDROID_LOG_ERROR,"LogHex.cpp" ,__VA_ARGS__)
#define MSLog(level, format, ...) do { \
    LOGDH(format, ## __VA_ARGS__); \
} while (false)

#define lprintf(format, ...) \
    MSLog(format, ## __VA_ARGS__)


void LogHex::PrintHex(const void *vdata, size_t size, const char *mark) {
    return PrintHexEx(vdata, size, 1, mark);
}

void LogHex::PrintHexEx(const void *vdata, size_t size, size_t stride, const char *mark) {
    const uint8_t *data((const uint8_t *) vdata);

    size_t i(0), j;

    char d[256];
    size_t b(0);
    d[0] = '\0';

    while (i != size) {
        if (i % HexWidth_ == 0) {
            if (mark != NULL)
                b += sprintf(d + b, "[%s] ", mark);
            b += sprintf(d + b, "0x%.3zx:", i);
        }

        b += sprintf(d + b, " ");

        for (size_t q(0); q != stride; ++q)
            b += sprintf(d + b, "%.2x", data[i + stride - q - 1]);

        i += stride;

        for (size_t q(1); q != stride; ++q)
            b += sprintf(d + b, " ");

        if (i % HexDepth_ == 0)
            b += sprintf(d + b, " ");

        if (i % HexWidth_ == 0) {
            b += sprintf(d + b, " ");
            for (j = i - HexWidth_; j != i; ++j)
                b += sprintf(d + b, "%c", _MSHexChar(data[j]));

            lprintf("%s", d);
            b = 0;
            d[0] = '\0';
        }
    }

    if (i % HexWidth_ != 0) {
        for (j = i % HexWidth_; j != HexWidth_; ++j)
            b += sprintf(d + b, "   ");
        for (j = 0; j != (HexWidth_ - i % HexWidth_ + HexDepth_ - 1) / HexDepth_; ++j)
            b += sprintf(d + b, " ");
        b += sprintf(d + b, " ");
        for (j = i / HexWidth_ * HexWidth_; j != i; ++j)
            b += sprintf(d + b, "%c", _MSHexChar(data[j]));

        lprintf("%s", d);
        b = 0;
        d[0] = '\0';
    }
}

void LogHex::DumpHex(const void *vdata, size_t size) {
    char name[16];
    sprintf(name, "%p", vdata);
    PrintHex(vdata, size, name);
}
