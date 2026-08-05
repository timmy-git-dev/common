#pragma once
#include "sys/platform/Arch.hpp"
#include "type/Alias.hpp"

namespace cmn::syscall
{
    using aio_context_t = u64;
    using mode_t        = u08;
    using off_t         = i64;
    using pid_t         = i32;
    using key_t         = i32;
    using timer_t       = i32;
    using clockid_t     = i32;
    using mqd_t         = i32;
    using uid_t         = u32;
    using gid_t         = u32;
    using key_serial_t  = int;
    using rwf_t         = i32;
    using qid_t         = u32;

    // TODO: Remove all struct ptr-aliases.
    typedef struct __user_cap_header_struct
    {
        u32 version;
        i32 pid;
    } *cap_user_header_t;
    typedef struct __user_cap_data_struct
    {
        u32 effective;
        u32 permitted;
        u32 inheritable;
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
        i64 tv_sec;
        i64 tv_nsec;
    };

    struct FileStatus
    {
        #ifdef CMN_SYS_ARCH_X64
            u64      st_dev;
            u64      st_ino;
            u64      st_nlink;
            u32      st_mode;
            u32      st_uid;
            u32      st_gid;
            u32 : 32;
            u64      st_rdev;
            i64      st_size;
            i64      st_blksize;
            i64      st_blocks;
            timespec st_atime;
            timespec st_mtime;
            timespec st_ctime;
            u64 : 64;
            u64 : 64;
            u64 : 64;
        #elif CMN_SYS_ARCH_ARM
            u64      st_dev;
            u64      st_ino;
            u32      st_mode;
            u32      st_nlink;
            u32      st_uid;
            u32      st_gid;
            u64      st_rdev;
            u64 : 64;
            i64      st_size;
            i32      st_blksize;
            u32 : 32;
            i64      st_blocks;
            timespec st_atime;
            timespec st_mtime;
            timespec st_ctime;
            u32 : 32;
            u32 : 32;
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