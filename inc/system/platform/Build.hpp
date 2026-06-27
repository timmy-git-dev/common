#pragma once

namespace cmn::system::platform
{
    #if defined(NDEBUG)
        #define CMN_SYSTEM_BUILD_RELEASE 1
    #else
        #define CMN_SYSTEM_BUILD_RELEASE 0
    #endif

    #if not defined(NDEBUG)
        #define CMN_SYSTEM_BUILD_DEBUG 1
    #else
        #define CMN_SYSTEM_BUILD_DEBUG 0
    #endif
}