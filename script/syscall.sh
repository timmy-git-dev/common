set -e

# Set constants.
readonly LINK_REPO="https://syscalls.mebeim.net/db"
readonly LINK_ARM="$LINK_REPO/arm64/64/aarch64/latest/table.json"
readonly LINK_X86="$LINK_REPO/x86/64/x64/latest/table.json"

readonly PATH_OUT="inc/system/Syscall.hpp"
readonly PATH_BIN="script/bin"
readonly PATH_ARM="$PATH_BIN/arm.json"
readonly PATH_X86="$PATH_BIN/x86.json"

readonly DEF_ARM="ARCH_ARM__"
readonly DEF_X86="ARCH_X86__"

# Ensure paths & download syscall tables.
mkdir -p $PATH_BIN

curl -s -L "$LINK_ARM" -o $PATH_ARM
curl -s -L "$LINK_X86" -o $PATH_X86

# Define helper funcs.
parse_syscall_table()
{
    json="$1"

    jq -r '
        .syscalls[] |
        [
            .name,
            .index,
            (.signature | join(", ")),
            (.signature | map("(long)" + (sub("^.* "; "") | sub("^\\*+"; ""))) | join(", "))
        ] |
        join("|")
    ' "$json"
}
def_syscall_indices()
{
    syscalls="$1"
    abi="$2"

    printf "    #ifdef $2\n"
    while IFS= read -r syscall; do
        IFS='|' read -r name index _ _ <<< "$syscall"
        [[ "$ignored_names" == *$'\n'"$name"$'\n'* ]] && continue

        printf "    #define %-24s % 3s\n" "${name^^}" "$index"
    done <<< "$syscalls"
    printf "    #endif\n"
}
def_syscall_funcs()
{
    syscalls="$1"
    abi="$2"

    while IFS= read -r syscall; do
        IFS='|' read -r name _ signature params <<< "$syscall"
        [[ "$ignored_names" == *$'\n'"$name"$'\n'* ]] && continue

        if [[ "$params" == "" ]]; then
            printf "    constexpr long %-24s(%s) {return syscall(%s);};\n" "$name" "$signature" "${name^^}"
        else
            printf "    constexpr long %-24s(%s) {return syscall(%s, %s);};\n" "$name" "$signature" "${name^^}" "$params"
        fi

    done <<< "$syscalls"
}

# Parse syscalls.
readonly arm_syscalls="$(parse_syscall_table "$PATH_ARM" | sort)"
readonly x86_syscalls="$(parse_syscall_table "$PATH_X86" | sort)"
readonly ignored_names="$(cut -d '|' -f1 <<< "$arm_syscalls"$'\n'"$x86_syscalls" | sort | uniq -c | awk '$1 != 2 { print $2 }')"

# Write syscalls to file.
printf '// AUTO-GENERATED SCRIPT //
#pragma once
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <linux/fs.h>
#include <linux/signal.h>
#include <asm-generic/posix_types.h>

namespace cmn::system
{
    struct __aio_sigset;
    struct epoll_event;
    struct iattr;
    struct inode;
    struct iocb;
    struct io_event;
    struct iovec;
    struct __kernel_old_itimerval;
    struct kexec_segment;
    struct linux_dirent;
    struct linux_dirent64;
    struct list_head;
    struct mmap_arg_struct;
    struct msgbuf;
    struct user_msghdr;
    struct mmsghdr;
    struct msqid_ds;
    struct new_utsname;
    struct nfsctl_arg;
    struct __old_kernel_stat;
    struct oldold_utsname;
    struct old_utsname;
    struct pollfd;
    struct rlimit;
    struct rlimit64;
    struct rusage;
    struct sched_param;
    struct sched_attr;
    struct sel_arg_struct;
    struct semaphore;
    struct sembuf;
    struct shmid_ds;
    struct sockaddr;
    struct stat;
    struct stat64;
    struct statfs;
    struct statfs64;
    struct statx;
    struct sysinfo;
    struct timespec;
    struct __kernel_old_timeval;
    struct __kernel_timex;
    struct timezone;
    struct tms;
    struct utimbuf;
    struct mq_attr;
    struct compat_stat;
    struct old_timeval32;
    struct robust_list_head;
    struct futex_waitv;
    struct old_linux_dirent;
    struct perf_event_attr;
    struct file_handle;
    struct sigaltstack;
    struct rseq;
    union bpf_attr;
    struct io_uring_params;
    struct clone_args;
    struct open_how;
    struct mount_attr;
    struct landlock_ruleset_attr;
    struct lsm_ctx;
    struct cachestat_range;
    struct cachestat;
    struct statmount;
    struct mnt_id_req;
    struct ns_id_req;
    struct xattr_args;
    struct file_attr;
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
' > "$PATH_OUT"

printf "
#ifdef $DEF_ARM
constexpr long syscall(long _type, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
    {
        register long x8 __asm__(\"x8\") = _type;
        register long x0 __asm__(\"x0\") = _arg0;
        register long x1 __asm__(\"x1\") = _arg1;
        register long x2 __asm__(\"x2\") = _arg2;
        register long x3 __asm__(\"x3\") = _arg3;
        register long x4 __asm__(\"x4\") = _arg4;
        register long x5 __asm__(\"x5\") = _arg5;

        asm volatile
        (
            \"svc #0\"
            : \"+r\"(x0)
            : \"r\"(x8),
              \"r\"(x1),
              \"r\"(x2),
              \"r\"(x3),
              \"r\"(x4),
              \"r\"(x5)
            : \"memory\"
        );

        return x0;
    }
#endif
#ifdef $DEF_X86
constexpr long syscall(long _type, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
{
    long _returnValue;
    register long _rax __asm__(\"rax\") = _type;
    register long _rdi __asm__(\"rdi\") = _arg0;
    register long _rsi __asm__(\"rsi\") = _arg1;
    register long _rdx __asm__(\"rdx\") = _arg2;
    register long _r10 __asm__(\"r10\") = _arg3;
    register long _r8  __asm__(\"r8\")  = _arg4;
    register long _r9  __asm__(\"r9\")  = _arg5;
    asm volatile
    (
        \"syscall\"
        : \"=a\"(_returnValue)
        : \"r\"(_rax),
            \"r\"(_rdi),
            \"r\"(_rsi),
            \"r\"(_rdx),
            \"r\"(_r10),
            \"r\"(_r8 ),
            \"r\"(_r9 )
        : \"rcx\", \"r11\", \"memory\"
    );
    return _returnValue;
}
#endif

" >> "$PATH_OUT"

def_syscall_indices "$arm_syscalls" "$DEF_ARM" >> "$PATH_OUT"
def_syscall_indices "$x86_syscalls" "$DEF_X86" >> "$PATH_OUT"
printf '\n' >> "$PATH_OUT"
def_syscall_funcs "$arm_syscalls" >> "$PATH_OUT"

printf '}' >> "$PATH_OUT"