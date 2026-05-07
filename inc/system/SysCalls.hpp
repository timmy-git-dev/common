#pragma once

namespace cmn::system
{
    enum SYS_CALL : long
    {
        READ    = 0,
        WRITE   = 1,
        OPENAT  = 257,
        CLOSE   = 3,
        LSEEK   = 8,
        STAT    = 4,

        MMAP     = 9,
        MPROTECT = 10,
        MUNMAP   = 11,
        BRK      = 12,

        FORK    = 57,
        EXECVE  = 59,
        EXIT    = 60,
        WAIT4   = 61,

        RT_SIGACTION   = 13,
        RT_SIGPROCMASK = 14,

        NANOSLEEP     = 35,
        CLOCK_GETTIME = 228,

        IOCTL = 16,
        FUTEX = 202,
    };

    long sys_call(long _type, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0);

    long read  (int fd, void* buf, unsigned long count);                                        // read bytes from fd into buffer
    long write (int fd, const void* buf, unsigned long count);                                  // write bytes from buffer to fd
    long openat(int dirfd, const char* path, int flags, int mode);                              // open file relative to dirfd
    long close (int fd);                                                                        // close file descriptor
    long lseek (int fd, long offset, int whence);                                               // reposition file offset
    long stat  (const char* path, void* statbuf);                                               // get file metadata

    void *mmap    (void* addr, unsigned long len, int prot, int flags, int fd, long off);       // map memory/pages into address space
    long  munmap  (void* addr, unsigned long len);                                              // unmap memory region
    long  mprotect(void* addr, unsigned long len, int prot);                                    // change memory protection flags
    long  brk     (void* addr);                                                                 // set program break (heap end)

                 int  fork  ();                                                                 // create child process
                 int  execve(const char* path, char* const argv[], char* const envp[]);         // replace process image
                 int  wait4 (int pid, int* status, int options, void* rusage);                  // wait for process state change
    [[noreturn]] void exit  (int code);                                                         // terminate process

    long rt_sigaction  (int sig, const void* act, void* oldact, unsigned long size);            // set/get signal handler
    long rt_sigprocmask(int how, const void* set, void* oldset, unsigned long size);            // change signal mask

    long nanosleep     (const void* req, void* rem);                                            // sleep for specified time
    long clock_gettime (int clk_id, void* tp);                                                  // get time from clock

    long ioctl(int fd, unsigned long req, void* arg);                                           // device-specific control operation
    long futex(int* uaddr, int op, int val, const void* timeout, int* uaddr2, int val3);        // fast userspace mutex/sync
}