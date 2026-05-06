#include "system/CxxABI.hpp"
#include "system/SysCalls.hpp"

namespace cmn::system
{
    extern "C"
    {
        static AtExitDtor atExitDtors[64] = { };
        static long       atExitDtorCount = 0;

        void* __dso_handle = &__dso_handle;

        int __cxa_atexit(func _function, void* _argument, void* _sharedObj)
        {
            if (atExitDtorCount >= 64)
            {
                return -1;
            }
            atExitDtors[atExitDtorCount++] = {_function, _argument, _sharedObj, true};
            return 0;
        }
        void __cxa_finalize(void* _sharedObj)
        {
            for (long _i = atExitDtorCount - 1; _i >= 0; --_i)
            {
                AtExitDtor& _destructor = atExitDtors[_i];
                if (_destructor.valid && (_sharedObj == nullptr || _sharedObj == _destructor.sharedObj))
                {
                    _destructor.valid = false;
                    _destructor.function(_destructor.argument);
                }
            }
        }

        int __cxa_guard_acquire(unsigned long long* _guard)
        {
            if (*_guard)
            {
                return 0;
            }
            *_guard = 1;
            return 1;
        }
        void __cxa_guard_release(unsigned long long* _guard)
        {
            *_guard = 1;
        }
        void __cxa_guard_abort(unsigned long long* _guard)
        {
            *_guard = 0;
        }

        void __cxa_pure_virtual()
        {
            exit(127);
        }
    }
}