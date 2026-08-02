#include "abi/Cxa.hpp"
#include "type/Alias.hpp"

using Destructor = void(*)(void*);

struct CxaEntry
{
    Destructor destructor;
    void*      instance;
    void*      library;
};

constexpr s64 MAX_CXA = 256;

CxaEntry entries[MAX_CXA]; // TODO: convert to dynamic-allocations instead of constant entry array.
s64      entryCount = 0;

extern "C"
{
    [[noreturn]]
    void __cxa_pure_virtual() {__builtin_trap();}

    i32 __cxa_atexit(Destructor _destructor, void *_instance, void *_library)
    {
        if (entryCount >= MAX_CXA)
        {
            return -1;
        }

        entries[entryCount++] =
        {
            _destructor,
            _instance,
            _library
        };

        return 0;
    }

    void __cxa_finalize(void* _dso)
    {
        for (s64 _i = entryCount; _i-- > 0;)
        {
            CxaEntry& _entry = entries[_i];

            if (_entry.destructor == nullptr || (_dso && _entry.library != _dso))
            {
                continue;
            }

            _entry.destructor(_entry.instance);
            _entry.destructor = nullptr;
        }
    }
}

namespace cmn::sys::abi
{
    void destruct_static_vars(void *_library)
    {
        __cxa_finalize(_library);
    }
}