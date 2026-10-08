#pragma once
// #include "type/Alias.hpp"

namespace cmn::syscall
{
    void dir_create (); // NtCreateFile                 : mkdirat                      : mkdirat
    void dir_open   (); // NtCreateFile                 : openat                       : openat(O_DIRECTORY)
    void dir_close  (); // NtClose                      : close                        : close
    void dir_remove (); // NtSetInformationFile         : unlinkat(REMOVEDIR)          : unlinkat(REMOVEDIR)

    void dir_query  (); // NtQueryInformationFile       : fstat                        : fstat
    void dir_entries(); // NtQueryDirectoryFile         : getdents64                   : getdirentries64
}