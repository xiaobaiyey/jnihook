#ifndef DEXPOSED_DLFCN_H
#define DEXPOSED_DLFCN_H

#include <cstdlib>
#include <string.h>
#include <unistd.h>

extern "C" {

void *fake_dlopen(const char *libpath, int flags);
void *fake_dlsym(void *handle, const char *name);

};
#endif //DEXPOSED_DLFCN_H