set(ProjectName Hook)

if (ANDROID_ABI MATCHES "armeabi(-v7a)?")
    set(INSTRUCTION instruction/Instruction.cpp
            instruction/ThumbInstruction.cpp
            instruction/ArmInstruction.cpp)
elseif (ANDROID_ABI STREQUAL "arm64-v8a")
    set(INSTRUCTION instruction/Instruction.cpp
            instruction/Arm64Instruction.cpp)
elseif (ANDROID_ABI MATCHES "x86(_64)?")

    set(INSTRUCTION instruction/Instruction.cpp
            instruction/IntelInstruction.cpp
            instruction/IntelDisasm.cpp)
elseif (ANDROID_ABI STREQUAL "mips")
    set(INSTRUCTION instruction/Instruction.cpp
            instruction/MipsInstruction.cpp)
elseif (ANDROID_ABI STREQUAL "mips64")
    set(INSTRUCTION instruction/Instruction.cpp
            instruction/Mips64Instruction.cpp)
endif ()

set(HOOKSRC HookHelper.cpp Helper.cpp)

add_library(hooktest SHARED ${HOOKSRC} ${INSTRUCTION})

#if(CMAKE_BUILD_TYPE MATCHES "Debug")
#    set(FA_EXTLIB log)
#endif()


#添加系统库文件
find_library(log-lib
        log
        )
find_library(dl-lib
        dl
        )


target_link_libraries(hooktest

        ${log-lib}
        ${dl-lib}
        )
