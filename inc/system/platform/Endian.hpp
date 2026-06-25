#pragma once

namespace cmn::system::platform
{
    #if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
        #define CMN_SYSTEM_ENDIAN_LITTLE 1
    #else
        #define CMN_SYSTEM_ENDIAN_LITTLE 0
    #endif

    #if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
        #define CMN_SYSTEM_ENDIAN_BIG 1
    #else
        #define CMN_SYSTEM_ENDIAN_BIG 0
    #endif
}