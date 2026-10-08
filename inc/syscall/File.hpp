#pragma once
// #include "type/Alias.hpp"

namespace cmn::syscall
{
    void file_create    (); // NtCreateFile(FILE_CREATE)    : openat(O_CREAT|O_EXCL)       : openat(O_CREAT|O_EXCL)
    void file_open      (); // NtCreateFile                 : openat                       : openat
    void file_close     (); // NtClose                      : close                        : close
    void file_remove    (); // NtSetInformationFile         : unlinkat                     : unlinkat

    void file_read      (); // NtReadFile                   : read                         : read
    void file_write     (); // NtWriteFile                  : write                        : write
    void file_seek      (); // NtSetInformationFile         : lseek                        : lseek

    void file_resize    (); // NtSetInformationFile         : ftruncate                    : ftruncate
    void file_allocate  (); // NtSetInformationFile*        : fallocate                    : fcntl(F_PREALLOCATE)
    void file_deallocate(); // NtSetInformationFile*        : fallocate                    : fcntl(F_PUNCHHOLE*) / ftruncate

    void file_query     (); // NtQueryInformationFile       : fstat                        : fstat

    void file_flush     (); // NtFlushBuffersFile           : fsync                        : fsync

    void file_lock      (); // NtLockFile                   : fcntl(F_SETLK)               : fcntl(F_SETLK)
    void file_unlock    (); // NtUnlockFile                 : fcntl(F_SETLK)               : fcntl(F_SETLK)
}