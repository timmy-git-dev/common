#pragma once
#include "sys/platform/Arch.hpp"
#include "syscall/lin/Alias.hpp"

namespace cmn::syscall
{
    // TODO: Remove all struct ptr-aliases.
    typedef struct __user_cap_header_struct
    {
        __u32 version;
        int   pid;
    } *cap_user_header_t;
    typedef struct __user_cap_data_struct
    {
        __u32 effective;
        __u32 permitted;
        __u32 inheritable;
    } *cap_user_data_t;

    enum landlock_rule_type
    {
        LANDLOCK_RULE_PATH_BENEATH = 1,
        LANDLOCK_RULE_NET_PORT     = 2,
    };

    #define __FD_SETSIZE 1024
    struct fd_set
    {
        unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
    };

    struct timespec
    {
        __kernel_old_time_t tv_sec;
        long                tv_nsec;
    };


    struct stat
    {
        #if CMN_SYS_ARCH_X64
            dev_t           st_dev;
            ino_t           st_ino;
            nlink_t         st_nlink;
            mode_t          st_mode;
            uid_t           st_uid;
            gid_t           st_gid;
            unsigned int    __pad0;
            dev_t           st_rdev;
            size_t          st_size;
            blksize_t       st_blksize;
            blkcnt_t        st_blocks;
            timespec        st_atim;
            timespec        st_mtim;
            timespec        st_ctim;
            __kernel_long_t __unused[3];
        #elif CMN_SYS_ARCH_ARM64
            dev_t           st_dev;
            ino_t           st_ino;
            mode_t          st_mode;
            nlink_t         st_nlink;
            uid_t           st_uid;
            gid_t           st_gid;
            dev_t           st_rdev;
            unsigned long   __pad1;
            size_t          st_size;
            blksize_t       st_blksize;
            int             __pad2;
            blkcnt_t        st_blocks;
            timespec        st_atim;
            timespec        st_mtim;
            timespec        st_ctim;
            unsigned int    __unused4;
            unsigned int    __unused5;
        #endif
    };

    struct __aio_sigset;
    struct cachestat;
    struct cachestat_range;
    struct clone_args;
    struct epoll_event;
    struct file_attr;
    struct file_handle;
    struct futex_waitv;
    struct getcpu_cache;
    struct iocb;
    struct io_event;
    struct io_uring_params;
    struct iovec;
    struct __kernel_old_itimerval;
    struct __kernel_old_timeval;
    struct __kernel_timespec;
    struct __kernel_itimerspec;
    struct __kernel_timex;
    struct kexec_segment;
    struct landlock_ruleset_attr;
    struct linux_dirent64;
    struct lsm_ctx;
    struct mmsghdr;
    struct mnt_id_req;
    struct mount_attr;
    struct mq_attr;
    struct msgbuf;
    struct msqid_ds;
    struct new_utsname;
    struct open_how;
    struct perf_event_attr;
    struct pollfd;
    struct rlimit;
    struct rlimit64;
    struct robust_list_head;
    struct rseq;
    struct rusage;
    struct sched_attr;
    struct sched_param;
    struct sembuf;
    struct shmid_ds;
    struct sigaction;
    struct sigevent;
    struct siginfo;
    struct siginfo_t;
    struct sigset_t;
    struct sockaddr;
    struct stack_t;
    struct statfs;
    struct statmount;
    struct statx;
    struct sysinfo;
    struct timezone;
    struct tms;
    struct user_msghdr;
    struct xattr_args;
}