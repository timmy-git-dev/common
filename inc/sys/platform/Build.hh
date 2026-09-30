#pragma once

namespace cmn::sys::platform
{
    #if defined(NDEBUG)
        #define CMN_SYS_BUILD_RELEASE 1
    #else
        #define CMN_SYS_BUILD_RELEASE 0
    #endif

    #if not defined(NDEBUG)
        #define CMN_SYS_BUILD_DEBUG 1
    #else
        #define CMN_SYS_BUILD_DEBUG 0
    #endif
}