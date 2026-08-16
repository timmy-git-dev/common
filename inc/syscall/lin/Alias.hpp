#pragma once
#include "type/Alias.hpp"
#include "sys/platform/Arch.hpp"

namespace cmn::syscall
{
    using __u16  = u16;
    using __u32  = u32;
    using __u64  = u64;

    using __i16  = i16;
    using __i32  = i32;
    using __i64  = i64;

    using __s16  = i16;
    using __s32  = i32;
    using __s64  = i64;

    using size_t = s64;

    #if CMN_SYS_ARCH_X64
        using __kernel_long_t       = long;
        using __kernel_ulong_t      = unsigned long;
        using __kernel_mode_t       = unsigned int;
        using __kernel_umode_t      = unsigned short;
        using __kernel_off_t        = long;
        using __kernel_loff_t       = long long;
        using __kernel_pid_t        = int;
        using __kernel_key_t        = int;
        using __kernel_timer_t      = int;
        using __kernel_clockid_t    = int;
        using __kernel_mqd_t        = int;
        using __kernel_uid_t        = unsigned int;
        using __kernel_gid_t        = unsigned int;
        using __kernel_key_serial_t = int;
        using __kernel_rwf_t        = int;
        using __kernel_qid_t        = unsigned int;
        using __kernel_dev_t        = unsigned int;
        using __kernel_ino_t        = unsigned long;
        using __kernel_nlink_t      = unsigned long;
        using __kernel_blksize_t    = long;
        using __kernel_blkcnt_t     = long;
        using __kernel_old_time_t   = __kernel_long_t;
    #elif CMN_SYS_ARCH_ARM64
        using __kernel_long_t       = long;
        using __kernel_ulong_t      = unsigned long;
        using __kernel_mode_t       = unsigned int;
        using __kernel_umode_t      = unsigned short;
        using __kernel_off_t        = long;
        using __kernel_loff_t       = long long;
        using __kernel_pid_t        = int;
        using __kernel_key_t        = int;
        using __kernel_timer_t      = int;
        using __kernel_clockid_t    = int;
        using __kernel_mqd_t        = int;
        using __kernel_uid_t        = unsigned int;
        using __kernel_gid_t        = unsigned int;
        using __kernel_key_serial_t = int;
        using __kernel_rwf_t        = int;
        using __kernel_qid_t        = unsigned int;
        using __kernel_dev_t        = unsigned int;
        using __kernel_ino_t        = unsigned long;
        using __kernel_nlink_t      = unsigned int;
        using __kernel_blksize_t    = int;
        using __kernel_blkcnt_t     = long;
        using __kernel_old_time_t   = __kernel_long_t;
    #endif


    using aio_context_t = __kernel_ulong_t;
    using ulong_t       = __kernel_ulong_t;
    using mode_t        = __kernel_mode_t;
    using umode_t       = __kernel_umode_t;
    using off_t         = __kernel_off_t;
    using loff_t        = __kernel_loff_t;
    using pid_t         = __kernel_pid_t;
    using key_t         = __kernel_key_t;
    using timer_t       = __kernel_timer_t;
    using clockid_t     = __kernel_clockid_t;
    using mqd_t         = __kernel_mqd_t;
    using uid_t         = __kernel_uid_t;
    using gid_t         = __kernel_gid_t;
    using key_serial_t  = __kernel_key_serial_t;
    using rwf_t         = __kernel_rwf_t;
    using qid_t         = __kernel_qid_t;
    using dev_t         = __kernel_dev_t;
    using ino_t         = __kernel_ino_t;
    using nlink_t       = __kernel_nlink_t;
    using blksize_t     = __kernel_blksize_t;
    using blkcnt_t      = __kernel_blkcnt_t;
}