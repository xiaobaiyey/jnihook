cmake_minimum_required(VERSION 3.4.1)


# 添加hook库支持
if (ANDROID_ABI MATCHES "armeabi(-v7a)?")
    set(INSTRUCTION ./../Hook/instruction/Instruction.cpp
            ./../Hook/instruction/ThumbInstruction.cpp
            ./../Hook/instruction/ArmInstruction.cpp)
elseif (ANDROID_ABI STREQUAL "arm64-v8a")
    set(INSTRUCTION ./../Hook/instruction/Instruction.cpp
            ./../Hook/instruction/Arm64Instruction.cpp)
elseif (ANDROID_ABI MATCHES "x86(_64)?")

    set(INSTRUCTION ./../Hook/instruction/Instruction.cpp
            ./../Hook/instruction/IntelInstruction.cpp
            ./../Hook/instruction/IntelDisasm.cpp)
elseif (ANDROID_ABI STREQUAL "mips")
    set(INSTRUCTION ./../Hook/instruction/Instruction.cpp
            ./../Hook/instruction/MipsInstruction.cpp)
elseif (ANDROID_ABI STREQUAL "mips64")
    set(INSTRUCTION ./../Hook/instruction/Instruction.cpp
            ./../Hook/instruction/Mips64Instruction.cpp)
endif ()
#添加hook库头文件支持
include_directories(./../Hook)

set(HOOKSRC ./../Hook/Helper.cpp
        ./../Hook/HookHelper.cpp
        ${INSTRUCTION})


set(JNISRC JniHook.cpp main.cpp)

add_library(jnihook
        SHARED
        ${HOOKSRC}
        ${JNISRC}
        )
#添加系统库文件
find_library(log-lib
        log
        )
find_library(z-lib
        z
        )
#链接静态库

#生成文件
target_link_libraries(jnihook
        ${log-lib}
        ${z-lib}
        )
