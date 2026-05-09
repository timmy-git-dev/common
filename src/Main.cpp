#include "system/CxxABI.hpp"
#include "system/EntryExit.hpp"
#include "system/SysCalls.hpp"
#include "type/Alias.hpp"
// #include "container/Span.hpp"

// Temp print func:
void print(const char* _text)
{
    s64 _length = 0;
    while (_text[_length] != '\0') ++_length;
    cmn::system::write(1, _text, _length);
}


int main()
{
    // cmn::container::Span<float, 4> _span = cmn::container::Span<float, 4>(0.0f, 1.0f, 2.0f, 3.0f);
    // _span[3] = 9.0f;

    return 0;
}

extern "C" void _start()
{
    cmn::system::run_global_ctors();
    int _exitCode = main();
    cmn::system::__cxa_finalize(nullptr);
    cmn::system::run_global_dtors();
    cmn::system::exit(_exitCode);
}