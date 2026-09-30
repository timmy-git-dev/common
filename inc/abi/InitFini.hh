#pragma once
// TODO: name InitFini better.

namespace cmn::sys::abi
{
    void initialize_static_funcs();
    void destruct_static_funcs  ();
}