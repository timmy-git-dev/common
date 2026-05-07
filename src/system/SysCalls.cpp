#include "system/SysCalls.hpp"

namespace cmn::system
{
    long sys_call(long _type, long _arg0, long _arg1, long _arg2, long _arg3, long _arg4, long _arg5)
    {
        long _returnValue;
        register long _reg10 __asm__("r10") = _arg3;
        register long _reg08 __asm__("r8")  = _arg4;
        register long _reg09 __asm__("r9")  = _arg5;

        asm volatile
        (
            "syscall" :
            "=a"(_returnValue) :
            "a"(_type), "D" (_arg0), "S"(_arg1), "d"(_arg2), "r"(_reg10), "r"(_reg08), "r"(_reg09) :
            "rcx", "r11", "memory"
        );
        return _returnValue;
    }

    long read(int fd, void* buf, unsigned long count)
    {
        return sys_call(SYS_CALL::READ, fd, (long)buf, count);
    }
    long write(int fd, const void* buf, unsigned long count)
    {
        return sys_call(SYS_CALL::WRITE, fd, (long)buf, count);
    }
    long openat(int dirfd, const char* path, int flags, int mode)
    {
        return sys_call(SYS_CALL::OPENAT, dirfd, (long)path, flags, mode);
    }
    long close(int fd)
    {
        return sys_call(SYS_CALL::CLOSE, fd, 0, 0);
    }
    long lseek(int fd, long offset, int whence)
    {
        return sys_call(SYS_CALL::LSEEK, fd, offset, whence);
    }
    long stat(const char* path, void* statbuf)
    {
        return sys_call(SYS_CALL::STAT, (long)path, (long)statbuf, 0);
    }

    void* mmap(void* addr, unsigned long len, int prot, int flags, int fd, long off)
    {
        return (void*)sys_call(SYS_CALL::MMAP, (long)addr, len, prot, flags, fd, off);
    }
    long munmap(void* addr, unsigned long len)
    {
        return sys_call(SYS_CALL::MUNMAP, (long)addr, len);
    }
    long mprotect(void* addr, unsigned long len, int prot)
    {
        return sys_call(SYS_CALL::MPROTECT, (long)addr, len, prot);
    }
    long brk(void* addr)
    {
        return sys_call(SYS_CALL::BRK, (long)addr, 0, 0);
    }

    int fork()
    {
        return (int)sys_call(SYS_CALL::FORK, 0, 0, 0);
    }
    int execve(const char* path, char* const argv[], char* const envp[])
    {
        return (int)sys_call(SYS_CALL::EXECVE, (long)path, (long)argv, (long)envp);
    }
    int wait4(int pid, int* status, int options, void* rusage)
    {
        return (int)sys_call(SYS_CALL::WAIT4, pid, (long)status, options, (long)rusage);
    }
    [[noreturn]] void exit(int code)
    {
        sys_call(SYS_CALL::EXIT, code, 0, 0);
        __builtin_unreachable();
    }

    long rt_sigaction(int sig, const void* act, void* oldact, unsigned long size)
    {
        return sys_call(SYS_CALL::RT_SIGACTION, sig, (long)act, (long)oldact, size);
    }
    long rt_sigprocmask(int how, const void* set, void* oldset, unsigned long size)
    {
        return sys_call(SYS_CALL::RT_SIGPROCMASK, how, (long)set, (long)oldset, size);
    }

    long nanosleep(const void* req, void* rem)
    {
        return sys_call(SYS_CALL::NANOSLEEP, (long)req, (long)rem);
    }
    long clock_gettime(int clk_id, void* tp)
    {
        return sys_call(SYS_CALL::CLOCK_GETTIME, clk_id, (long)tp);
    }

    long ioctl(int fd, unsigned long req, void* arg)
    {
        return sys_call(SYS_CALL::IOCTL, fd, req, (long)arg);
    }
    long futex(int* uaddr, int op, int val, const void* timeout, int* uaddr2, int val3)
    {
        return sys_call(SYS_CALL::FUTEX, (long)uaddr, op, val, (long)timeout, (long)uaddr2, val3);
    }
}