#pragma once

namespace cmn::system::platform
{
    #if defined(__linux__)
        #define CMN_SYSTEM_OS_LIN 1
    #else
        #define CMN_SYSTEM_OS_LIN 0
    #endif

    #if defined(_WIN32)
        #define CMN_SYSTEM_OS_WIN 1
    #else
        #define CMN_SYSTEM_OS_WIN 0
    #endif

    #if defined(__APPLE__)
        #define CMN_SYSTEM_OS_MAC 1
    #else
        #define CMN_SYSTEM_OS_MAC 0
    #endif
}