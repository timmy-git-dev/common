#pragma once
#include "type/Alias.hpp"

namespace cmn::system::abi_
{
    extern "C" void _start();
}

i32 main (const i32 _argCount, const c08 **_argValues);