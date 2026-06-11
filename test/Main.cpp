#include "error/Print.hpp"
#include "Main.hpp"

i08 main(const u32 _argCount, const c08 **_args)
{
    cmn::error::print_("Hello, world!\n");

    return 0;
}