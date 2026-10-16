#pragma once

namespace cmn::syscall::uni::file
{
    void create    (); // NtCreateFile(FILE_CREATE)    : openat(O_CREAT|O_EXCL)       : openat(O_CREAT|O_EXCL)
    void open      (); // NtCreateFile                 : openat                       : openat
    void close     (); // NtClose                      : close                        : close
    void remove    (); // NtSetInformationFile         : unlinkat                     : unlinkat

    void read      (); // NtReadFile                   : read                         : read
    void write     (); // NtWriteFile                  : write                        : write
    void seek      (); // NtSetInformationFile         : lseek                        : lseek

    void resize    (); // NtSetInformationFile         : ftruncate                    : ftruncate
    void allocate  (); // NtSetInformationFile*        : fallocate                    : fcntl(F_PREALLOCATE)
    void deallocate(); // NtSetInformationFile*        : fallocate                    : fcntl(F_PUNCHHOLE*) / ftruncate

    void query     (); // NtQueryInformationFile       : fstat                        : fstat

    void flush     (); // NtFlushBuffersFile           : fsync                        : fsync

    void lock      (); // NtLockFile                   : fcntl(F_SETLK)               : fcntl(F_SETLK)
    void unlock    (); // NtUnlockFile                 : fcntl(F_SETLK)               : fcntl(F_SETLK)
}