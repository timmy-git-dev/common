#include "abi/entry.hh"
#include "syscall/uni/thread.hh"
#include "sys/platform/os.hh"

#if CMN_SYS_OS_WIN
    #include "syscall/win/loader.hh"
#endif


extern "C" void start__()
{
    // TODO: I really hate how this looks, perhaps make each OS/arch have their own "loader" so it's more clear, but as of
    // right now windows is the only one that needs to be done, other than potentially initializing the global arrays.
    #if CMN_SYS_OS_WIN
        cmn::syscall::win_::resolve_nt();
    #endif

    i32 _result = main(0, nullptr);
    cmn::syscall::uni::thread::exit(_result);
}

extern "C" void __main() { }