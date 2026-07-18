#pragma once
#include <linux/fs.h>
#include <linux/signal.h>
#include <asm-generic/posix_types.h>

namespace cmn::system::syscall
{
    struct __user_cap_header_struct;
    struct __user_cap_data_struct;

    enum landlock_rule_type {};

    typedef unsigned char      uint8_t;
    typedef unsigned short     uint16_t;
    typedef unsigned int       uint32_t;
    typedef unsigned long long uint64_t;

    typedef uint8_t   u8;
    typedef uint16_t  u16;
    typedef uint32_t  u32;
    typedef uint64_t  u64;

    typedef __user_cap_header_struct   *cap_user_header_t;
    typedef __user_cap_data_struct     *cap_user_data_t;
    typedef __kernel_ulong_t            aio_context_t;
    typedef __u32                       __kernel_dev_t;
    typedef __kernel_fd_set             fd_set;
    typedef unsigned short              umode_t;
    typedef __kernel_off_t              off_t;
    typedef __kernel_pid_t              pid_t;
    typedef __kernel_key_t              key_t;
    typedef __kernel_timer_t            timer_t;
    typedef __kernel_clockid_t          clockid_t;
    typedef __kernel_mqd_t              mqd_t;
    typedef __kernel_uid32_t            uid_t;
    typedef __kernel_gid32_t            gid_t;
    typedef __kernel_loff_t             loff_t;
    typedef __kernel_size_t             size_t;
    typedef __s32                       key_serial_t;
    typedef __kernel_rwf_t              rwf_t;
    typedef __kernel_uid32_t            qid_t;

    // TODO: maybe automate if possible/get all defines + maybe separate files.
    #define PROT_NONE           0x0
    #define PROT_READ           0x1
    #define PROT_WRITE          0x2
    #define PROT_EXEC           0x4
    #define PROT_SEM            0x8
    #define PROT_GROWSDOWN      0x01000000
    #define PROT_GROWSUP        0x02000000

    #define MAP_SHARED          0x01
    #define MAP_PRIVATE         0x02
    #define MAP_SHARED_VALIDATE 0x03
    #define MAP_FIXED           0x10
    #define MAP_ANONYMOUS       0x20
    #define MAP_GROWSDOWN       0x0100
    #define MAP_DENYWRITE       0x0800
    #define MAP_EXECUTABLE      0x1000
    #define MAP_LOCKED          0x2000
    #define MAP_NORESERVE       0x4000
    #define MAP_POPULATE        0x8000
    #define MAP_NONBLOCK        0x10000
    #define MAP_STACK           0x20000
    #define MAP_HUGETLB         0x40000
    #define MAP_SYNC            0x80000
    #define MAP_FIXED_NOREPLACE 0x100000
}