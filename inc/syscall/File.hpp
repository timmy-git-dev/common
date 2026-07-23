#pragma once
// #include "type/Alias.hpp"

// FUNC                         : WIN                          : LIN                          : MAC


/// PATH:
// cwd_get                      : NtQueryInformationProcess*   : getcwd                       : getcwd
// cwd_set                      : NtSetInformationProcess*     : chdir                        : chdir

// query                        : NtQueryAttributesFile        : stat                         : stat
// rename                       : NtSetInformationFile         : renameat                     : renameat


/// DIRECTORY:
// create                       : NtCreateFile                 : mkdirat                      : mkdirat
// open                         : NtCreateFile                 : openat                       : openat(O_DIRECTORY)
// close                        : NtClose                      : close                        : close
// remove                       : NtSetInformationFile         : unlinkat(REMOVEDIR)          : unlinkat(REMOVEDIR)

// query                        : NtQueryInformationFile       : fstat                        : fstat

// entries                      : NtQueryDirectoryFile         : getdents64                   : getdirentries64

// duplicate                    : NtDuplicateObject            : dup3                         : dup


/// FILE:
// create                       : NtCreateFile(FILE_CREATE)    : openat(O_CREAT|O_EXCL)       : openat(O_CREAT|O_EXCL)
// open                         : NtCreateFile                 : openat                       : openat
// close                        : NtClose                      : close                        : close
// remove                       : NtSetInformationFile         : unlinkat                     : unlinkat

// read                         : NtReadFile                   : read                         : read
// write                        : NtWriteFile                  : write                        : write
// seek                         : NtSetInformationFile         : lseek                        : lseek

// resize                       : NtSetInformationFile         : ftruncate                    : ftruncate
// allocate                     : NtSetInformationFile*        : fallocate                    : fcntl(F_PREALLOCATE)
// deallocate                   : NtSetInformationFile*        : fallocate                    : fcntl(F_PUNCHHOLE*) / ftruncate

// query                        : NtQueryInformationFile       : fstat                        : fstat

// flush                        : NtFlushBuffersFile           : fsync                        : fsync

// lock                         : NtLockFile                   : fcntl(F_SETLK)               : fcntl(F_SETLK)
// unlock                       : NtUnlockFile                 : fcntl(F_SETLK)               : fcntl(F_SETLK)

// duplicate                    : NtDuplicateObject            : dup3                         : dup