#include "syscall/util/Path.hh"
#include "error/Result.hh"
#include "syscall/util/UTF.hh"
#include "type/Alias.hh"
#include "sys/platform/OS.hh"

namespace cmn::syscall::util::path
{
    error::Result<s64, PATH> resolve(const c08 *_root, const c08 *_child, const s64 _length, c08 *_output)
    {
        #if CMN_SYS_OS_WIN
            // A:
            // root   = C:/abc/
            // child  = ./def/ghi.txt
            // output = C:/abc/def/ghi.txt

            // B:
            // root/cwd = C:/abc/
            // child    = /def/ghi.txt
            // output   = C:/def/def/ghi.txt
        #endif
    }

    #if CMN_SYS_OS_WIN

    // error::Result<s64, PATH> to_win(const c08 *_inputUTF8, const s64 _length, c16 *_outputUTF16)
    // {
    //     s64 _index = 0;
    //     while (_index < _length)
    //     {
    //         error::Result<u32, utf::UTF> _code = utf::str8_to_code(_inputUTF8, _index);
    //         if (_code.error.code != utf::UTF::NONE)
    //         {
    //             return error::Result<s64, PATH>(_index, PATH::INVALID_INPUT);
    //         }

    //         if (_code.value == '/')
    //         {
    //             _code.value = '\\';
    //         }

    //         utf::code_to_str16(_code.value, _outputUTF16, _index);
    //     }

    //     return error::Result<s64, PATH>(_index, PATH::NONE);
    // }

    #endif
}