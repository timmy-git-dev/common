// AUTO-GENERATED SCRIPT //
#pragma once
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <linux/fs.h>
#include <linux/signal.h>
#include <asm-generic/posix_types.h>
#include <asm/stat.h>

namespace cmn::system
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

    #ifdef ARCH_ARM__
    constexpr long syscall(long _type, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
        {
            register long x8 __asm__("x8") = _type;
            register long x0 __asm__("x0") = _arg0;
            register long x1 __asm__("x1") = _arg1;
            register long x2 __asm__("x2") = _arg2;
            register long x3 __asm__("x3") = _arg3;
            register long x4 __asm__("x4") = _arg4;
            register long x5 __asm__("x5") = _arg5;

            asm volatile
            (
                "svc #0"
                : "+r"(x0)
                : "r"(x8),
                  "r"(x1),
                  "r"(x2),
                  "r"(x3),
                  "r"(x4),
                  "r"(x5)
                : "memory"
            );

            return x0;
        }
    #endif
    #ifdef ARCH_X86__
    constexpr long syscall(long _type, long _arg0 = 0, long _arg1 = 0, long _arg2 = 0, long _arg3 = 0, long _arg4 = 0, long _arg5 = 0)
    {
        long _returnValue;
        register long _rax __asm__("rax") = _type;
        register long _rdi __asm__("rdi") = _arg0;
        register long _rsi __asm__("rsi") = _arg1;
        register long _rdx __asm__("rdx") = _arg2;
        register long _r10 __asm__("r10") = _arg3;
        register long _r8  __asm__("r8")  = _arg4;
        register long _r9  __asm__("r9")  = _arg5;
        asm volatile
        (
            "syscall"
            : "=a"(_returnValue)
            : "r"(_rax),
                "r"(_rdi),
                "r"(_rsi),
                "r"(_rdx),
                "r"(_r10),
                "r"(_r8 ),
                "r"(_r9 )
            : "rcx", "r11", "memory"
        );
        return _returnValue;
    }
    #endif

    #ifdef ARCH_ARM__
    #define ACCEPT                   202
    #define ACCEPT4                  242
    #define ACCT                      89
    #define ADD_KEY                  217
    #define ADJTIMEX                 171
    #define BIND                     200
    #define BPF                      280
    #define BRK                      214
    #define CACHESTAT                451
    #define CAPGET                    90
    #define CAPSET                    91
    #define CHDIR                     49
    #define CHROOT                    51
    #define CLOCK_ADJTIME            266
    #define CLOCK_GETRES             114
    #define CLOCK_GETTIME            113
    #define CLOCK_NANOSLEEP          115
    #define CLOCK_SETTIME            112
    #define CLONE                    220
    #define CLONE3                   435
    #define CLOSE                     57
    #define CLOSE_RANGE              436
    #define CONNECT                  203
    #define COPY_FILE_RANGE          285
    #define DELETE_MODULE            106
    #define DUP                       23
    #define DUP3                      24
    #define EPOLL_CREATE1             20
    #define EPOLL_CTL                 21
    #define EPOLL_PWAIT               22
    #define EPOLL_PWAIT2             441
    #define EVENTFD2                  19
    #define EXECVE                   221
    #define EXECVEAT                 281
    #define EXIT                      93
    #define EXIT_GROUP                94
    #define FACCESSAT2               439
    #define FACCESSAT                 48
    #define FALLOCATE                 47
    #define FANOTIFY_INIT            262
    #define FANOTIFY_MARK            263
    #define FCHDIR                    50
    #define FCHMOD                    52
    #define FCHMODAT2                452
    #define FCHMODAT                  53
    #define FCHOWN                    55
    #define FCHOWNAT                  54
    #define FCNTL                     25
    #define FDATASYNC                 83
    #define FGETXATTR                 10
    #define FILE_GETATTR             468
    #define FILE_SETATTR             469
    #define FINIT_MODULE             273
    #define FLISTXATTR                13
    #define FLOCK                     32
    #define FREMOVEXATTR              16
    #define FSCONFIG                 431
    #define FSETXATTR                  7
    #define FSMOUNT                  432
    #define FSOPEN                   430
    #define FSPICK                   433
    #define FSTATFS                   44
    #define FSYNC                     82
    #define FTRUNCATE                 46
    #define FUTEX                     98
    #define FUTEX_REQUEUE            456
    #define FUTEX_WAIT               455
    #define FUTEX_WAITV              449
    #define FUTEX_WAKE               454
    #define GETCPU                   168
    #define GETCWD                    17
    #define GETDENTS64                61
    #define GETEGID                  177
    #define GETEUID                  175
    #define GETGID                   176
    #define GETGROUPS                158
    #define GETITIMER                102
    #define GET_MEMPOLICY            236
    #define GETPEERNAME              205
    #define GETPGID                  155
    #define GETPID                   172
    #define GETPPID                  173
    #define GETPRIORITY              141
    #define GETRANDOM                278
    #define GETRESGID                150
    #define GETRESUID                148
    #define GETRLIMIT                163
    #define GET_ROBUST_LIST          100
    #define GETRUSAGE                165
    #define GETSID                   156
    #define GETSOCKNAME              204
    #define GETSOCKOPT               209
    #define GETTID                   178
    #define GETTIMEOFDAY             169
    #define GETUID                   174
    #define GETXATTR                   8
    #define GETXATTRAT               464
    #define INIT_MODULE              105
    #define INOTIFY_ADD_WATCH         27
    #define INOTIFY_INIT1             26
    #define INOTIFY_RM_WATCH          28
    #define IO_CANCEL                  3
    #define IOCTL                     29
    #define IO_DESTROY                 1
    #define IO_GETEVENTS               4
    #define IO_PGETEVENTS            292
    #define IOPRIO_GET                31
    #define IOPRIO_SET                30
    #define IO_SETUP                   0
    #define IO_SUBMIT                  2
    #define IO_URING_ENTER           426
    #define IO_URING_REGISTER        427
    #define IO_URING_SETUP           425
    #define KCMP                     272
    #define KEXEC_FILE_LOAD          294
    #define KEXEC_LOAD               104
    #define KEYCTL                   219
    #define KILL                     129
    #define LANDLOCK_ADD_RULE        445
    #define LANDLOCK_CREATE_RULESET  444
    #define LANDLOCK_RESTRICT_SELF   446
    #define LGETXATTR                  9
    #define LINKAT                    37
    #define LISTEN                   201
    #define LISTMOUNT                458
    #define LISTXATTR                 11
    #define LISTXATTRAT              465
    #define LLISTXATTR                12
    #define LREMOVEXATTR              15
    #define LSEEK                     62
    #define LSETXATTR                  6
    #define LSM_GET_SELF_ATTR        459
    #define LSM_LIST_MODULES         461
    #define LSM_SET_SELF_ATTR        460
    #define MADVISE                  233
    #define MAP_SHADOW_STACK         453
    #define MBIND                    235
    #define MEMBARRIER               283
    #define MEMFD_CREATE             279
    #define MEMFD_SECRET             447
    #define MIGRATE_PAGES            238
    #define MINCORE                  232
    #define MKDIRAT                   34
    #define MKNODAT                   33
    #define MLOCK2                   284
    #define MLOCK                    228
    #define MLOCKALL                 230
    #define MMAP                     222
    #define MOUNT                     40
    #define MOUNT_SETATTR            442
    #define MOVE_MOUNT               429
    #define MOVE_PAGES               239
    #define MPROTECT                 226
    #define MQ_GETSETATTR            185
    #define MQ_NOTIFY                184
    #define MQ_OPEN                  180
    #define MQ_TIMEDRECEIVE          183
    #define MQ_TIMEDSEND             182
    #define MQ_UNLINK                181
    #define MREMAP                   216
    #define MSEAL                    462
    #define MSGCTL                   187
    #define MSGGET                   186
    #define MSGRCV                   188
    #define MSGSND                   189
    #define MSYNC                    227
    #define MUNLOCK                  229
    #define MUNLOCKALL               231
    #define MUNMAP                   215
    #define NAME_TO_HANDLE_AT        264
    #define NANOSLEEP                101
    #define NEWFSTAT                  80
    #define NEWFSTATAT                79
    #define NEWUNAME                 160
    #define OPENAT2                  437
    #define OPENAT                    56
    #define OPEN_BY_HANDLE_AT        265
    #define OPEN_TREE                428
    #define OPEN_TREE_ATTR           467
    #define PERF_EVENT_OPEN          241
    #define PERSONALITY               92
    #define PIDFD_GETFD              438
    #define PIDFD_OPEN               434
    #define PIDFD_SEND_SIGNAL        424
    #define PIPE2                     59
    #define PIVOT_ROOT                41
    #define PKEY_ALLOC               289
    #define PKEY_FREE                290
    #define PKEY_MPROTECT            288
    #define PPOLL                     73
    #define PRCTL                    167
    #define PREAD64                   67
    #define PREADV2                  286
    #define PREADV                    69
    #define PRLIMIT64                261
    #define PROCESS_MADVISE          440
    #define PROCESS_MRELEASE         448
    #define PROCESS_VM_READV         270
    #define PROCESS_VM_WRITEV        271
    #define PSELECT6                  72
    #define PTRACE                   117
    #define PWRITE64                  68
    #define PWRITEV2                 287
    #define PWRITEV                   70
    #define QUOTACTL                  60
    #define QUOTACTL_FD              443
    #define READ                      63
    #define READAHEAD                213
    #define READLINKAT                78
    #define READV                     65
    #define REBOOT                   142
    #define RECVFROM                 207
    #define RECVMMSG                 243
    #define RECVMSG                  212
    #define REMAP_FILE_PAGES         234
    #define REMOVEXATTR               14
    #define REMOVEXATTRAT            466
    #define RENAMEAT2                276
    #define RENAMEAT                  38
    #define REQUEST_KEY              218
    #define RESTART_SYSCALL          128
    #define RSEQ                     293
    #define RT_SIGACTION             134
    #define RT_SIGPENDING            136
    #define RT_SIGPROCMASK           135
    #define RT_SIGQUEUEINFO          138
    #define RT_SIGRETURN             139
    #define RT_SIGSUSPEND            133
    #define RT_SIGTIMEDWAIT          137
    #define RT_TGSIGQUEUEINFO        240
    #define SCHED_GETAFFINITY        123
    #define SCHED_GETATTR            275
    #define SCHED_GETPARAM           121
    #define SCHED_GET_PRIORITY_MAX   125
    #define SCHED_GET_PRIORITY_MIN   126
    #define SCHED_GETSCHEDULER       120
    #define SCHED_RR_GET_INTERVAL    127
    #define SCHED_SETAFFINITY        122
    #define SCHED_SETATTR            274
    #define SCHED_SETPARAM           118
    #define SCHED_SETSCHEDULER       119
    #define SCHED_YIELD              124
    #define SECCOMP                  277
    #define SEMCTL                   191
    #define SEMGET                   190
    #define SEMOP                    193
    #define SEMTIMEDOP               192
    #define SENDFILE64                71
    #define SENDMMSG                 269
    #define SENDMSG                  211
    #define SENDTO                   206
    #define SETDOMAINNAME            162
    #define SETFSGID                 152
    #define SETFSUID                 151
    #define SETGID                   144
    #define SETGROUPS                159
    #define SETHOSTNAME              161
    #define SETITIMER                103
    #define SET_MEMPOLICY            237
    #define SET_MEMPOLICY_HOME_NODE  450
    #define SETNS                    268
    #define SETPGID                  154
    #define SETPRIORITY              140
    #define SETREGID                 143
    #define SETRESGID                149
    #define SETRESUID                147
    #define SETREUID                 145
    #define SETRLIMIT                164
    #define SET_ROBUST_LIST           99
    #define SETSID                   157
    #define SETSOCKOPT               208
    #define SET_TID_ADDRESS           96
    #define SETTIMEOFDAY             170
    #define SETUID                   146
    #define SETXATTR                   5
    #define SETXATTRAT               463
    #define SHMAT                    196
    #define SHMCTL                   195
    #define SHMDT                    197
    #define SHMGET                   194
    #define SHUTDOWN                 210
    #define SIGALTSTACK              132
    #define SIGNALFD4                 74
    #define SOCKET                   198
    #define SOCKETPAIR               199
    #define SPLICE                    76
    #define STATFS                    43
    #define STATMOUNT                457
    #define STATX                    291
    #define SWAPOFF                  225
    #define SWAPON                   224
    #define SYMLINKAT                 36
    #define SYNC                      81
    #define SYNC_FILE_RANGE           84
    #define SYNCFS                   267
    #define SYSINFO                  179
    #define SYSLOG                   116
    #define TEE                       77
    #define TGKILL                   131
    #define TIMER_CREATE             107
    #define TIMER_DELETE             111
    #define TIMERFD_CREATE            85
    #define TIMERFD_GETTIME           87
    #define TIMERFD_SETTIME           86
    #define TIMER_GETOVERRUN         109
    #define TIMER_GETTIME            108
    #define TIMER_SETTIME            110
    #define TIMES                    153
    #define TKILL                    130
    #define TRUNCATE                  45
    #define UMASK                    166
    #define UMOUNT                    39
    #define UNLINKAT                  35
    #define UNSHARE                   97
    #define USERFAULTFD              282
    #define UTIMENSAT                 88
    #define VHANGUP                   58
    #define VMSPLICE                  75
    #define WAIT4                    260
    #define WAITID                    95
    #define WRITE                     64
    #define WRITEV                    66
    #endif
    #ifdef ARCH_X86__
    #define ACCEPT4                  288
    #define ACCEPT                    43
    #define ACCESS                    21
    #define ACCT                     163
    #define ADD_KEY                  248
    #define ADJTIMEX                 159
    #define BIND                      49
    #define BPF                      321
    #define BRK                       12
    #define CACHESTAT                451
    #define CAPGET                   125
    #define CAPSET                   126
    #define CHDIR                     80
    #define CHROOT                   161
    #define CLOCK_ADJTIME            305
    #define CLOCK_GETRES             229
    #define CLOCK_GETTIME            228
    #define CLOCK_NANOSLEEP          230
    #define CLOCK_SETTIME            227
    #define CLONE3                   435
    #define CLONE                     56
    #define CLOSE                      3
    #define CLOSE_RANGE              436
    #define CONNECT                   42
    #define COPY_FILE_RANGE          326
    #define DELETE_MODULE            176
    #define DUP3                     292
    #define DUP                       32
    #define EPOLL_CREATE1            291
    #define EPOLL_CTL                233
    #define EPOLL_PWAIT2             441
    #define EPOLL_PWAIT              281
    #define EVENTFD2                 290
    #define EXECVE                    59
    #define EXECVEAT                 322
    #define EXIT                      60
    #define EXIT_GROUP               231
    #define FACCESSAT2               439
    #define FACCESSAT                269
    #define FALLOCATE                285
    #define FANOTIFY_INIT            300
    #define FANOTIFY_MARK            301
    #define FCHDIR                    81
    #define FCHMOD                    91
    #define FCHMODAT2                452
    #define FCHMODAT                 268
    #define FCHOWN                    93
    #define FCHOWNAT                 260
    #define FCNTL                     72
    #define FDATASYNC                 75
    #define FGETXATTR                193
    #define FILE_GETATTR             468
    #define FILE_SETATTR             469
    #define FINIT_MODULE             313
    #define FLISTXATTR               196
    #define FLOCK                     73
    #define FREMOVEXATTR             199
    #define FSCONFIG                 431
    #define FSETXATTR                190
    #define FSMOUNT                  432
    #define FSOPEN                   430
    #define FSPICK                   433
    #define FSTATFS                  138
    #define FSYNC                     74
    #define FTRUNCATE                 77
    #define FUTEX                    202
    #define FUTEX_REQUEUE            456
    #define FUTEX_WAIT               455
    #define FUTEX_WAITV              449
    #define FUTEX_WAKE               454
    #define GETCPU                   309
    #define GETCWD                    79
    #define GETDENTS64               217
    #define GETEGID                  108
    #define GETEUID                  107
    #define GETGID                   104
    #define GETGROUPS                115
    #define GETITIMER                 36
    #define GET_MEMPOLICY            239
    #define GETPEERNAME               52
    #define GETPGID                  121
    #define GETPID                    39
    #define GETPPID                  110
    #define GETPRIORITY              140
    #define GETRANDOM                318
    #define GETRESGID                120
    #define GETRESUID                118
    #define GETRLIMIT                 97
    #define GET_ROBUST_LIST          274
    #define GETRUSAGE                 98
    #define GETSID                   124
    #define GETSOCKNAME               51
    #define GETSOCKOPT                55
    #define GETTID                   186
    #define GETTIMEOFDAY              96
    #define GETUID                   102
    #define GETXATTR                 191
    #define GETXATTRAT               464
    #define INIT_MODULE              175
    #define INOTIFY_ADD_WATCH        254
    #define INOTIFY_INIT1            294
    #define INOTIFY_RM_WATCH         255
    #define IO_CANCEL                210
    #define IOCTL                     16
    #define IO_DESTROY               207
    #define IO_GETEVENTS             208
    #define IO_PGETEVENTS            333
    #define IOPRIO_GET               252
    #define IOPRIO_SET               251
    #define IO_SETUP                 206
    #define IO_SUBMIT                209
    #define IO_URING_ENTER           426
    #define IO_URING_REGISTER        427
    #define IO_URING_SETUP           425
    #define KCMP                     312
    #define KEXEC_FILE_LOAD          320
    #define KEXEC_LOAD               246
    #define KEYCTL                   250
    #define KILL                      62
    #define LANDLOCK_ADD_RULE        445
    #define LANDLOCK_CREATE_RULESET  444
    #define LANDLOCK_RESTRICT_SELF   446
    #define LGETXATTR                192
    #define LINKAT                   265
    #define LISTEN                    50
    #define LISTMOUNT                458
    #define LISTXATTR                194
    #define LISTXATTRAT              465
    #define LLISTXATTR               195
    #define LREMOVEXATTR             198
    #define LSEEK                      8
    #define LSETXATTR                189
    #define LSM_GET_SELF_ATTR        459
    #define LSM_LIST_MODULES         461
    #define LSM_SET_SELF_ATTR        460
    #define MADVISE                   28
    #define MAP_SHADOW_STACK         453
    #define MBIND                    237
    #define MEMBARRIER               324
    #define MEMFD_CREATE             319
    #define MEMFD_SECRET             447
    #define MIGRATE_PAGES            256
    #define MINCORE                   27
    #define MKDIRAT                  258
    #define MKNODAT                  259
    #define MLOCK                    149
    #define MLOCK2                   325
    #define MLOCKALL                 151
    #define MMAP                       9
    #define MOUNT                    165
    #define MOUNT_SETATTR            442
    #define MOVE_MOUNT               429
    #define MOVE_PAGES               279
    #define MPROTECT                  10
    #define MQ_GETSETATTR            245
    #define MQ_NOTIFY                244
    #define MQ_OPEN                  240
    #define MQ_TIMEDRECEIVE          243
    #define MQ_TIMEDSEND             242
    #define MQ_UNLINK                241
    #define MREMAP                    25
    #define MSEAL                    462
    #define MSGCTL                    71
    #define MSGGET                    68
    #define MSGRCV                    70
    #define MSGSND                    69
    #define MSYNC                     26
    #define MUNLOCK                  150
    #define MUNLOCKALL               152
    #define MUNMAP                    11
    #define NAME_TO_HANDLE_AT        303
    #define NANOSLEEP                 35
    #define NEWFSTAT                   5
    #define NEWFSTATAT               262
    #define NEWUNAME                  63
    #define OPENAT2                  437
    #define OPENAT                   257
    #define OPEN_BY_HANDLE_AT        304
    #define OPEN_TREE                428
    #define OPEN_TREE_ATTR           467
    #define PERF_EVENT_OPEN          298
    #define PERSONALITY              135
    #define PIDFD_GETFD              438
    #define PIDFD_OPEN               434
    #define PIDFD_SEND_SIGNAL        424
    #define PIPE2                    293
    #define PIVOT_ROOT               155
    #define PKEY_ALLOC               330
    #define PKEY_FREE                331
    #define PKEY_MPROTECT            329
    #define PPOLL                    271
    #define PRCTL                    157
    #define PREAD64                   17
    #define PREADV2                  327
    #define PREADV                   295
    #define PRLIMIT64                302
    #define PROCESS_MADVISE          440
    #define PROCESS_MRELEASE         448
    #define PROCESS_VM_READV         310
    #define PROCESS_VM_WRITEV        311
    #define PSELECT6                 270
    #define PTRACE                   101
    #define PWRITE64                  18
    #define PWRITEV2                 328
    #define PWRITEV                  296
    #define QUOTACTL                 179
    #define QUOTACTL_FD              443
    #define READ                       0
    #define READAHEAD                187
    #define READLINKAT               267
    #define READV                     19
    #define REBOOT                   169
    #define RECVFROM                  45
    #define RECVMMSG                 299
    #define RECVMSG                   47
    #define REMAP_FILE_PAGES         216
    #define REMOVEXATTR              197
    #define REMOVEXATTRAT            466
    #define RENAMEAT2                316
    #define RENAMEAT                 264
    #define REQUEST_KEY              249
    #define RESTART_SYSCALL          219
    #define RSEQ                     334
    #define RT_SIGACTION              13
    #define RT_SIGPENDING            127
    #define RT_SIGPROCMASK            14
    #define RT_SIGQUEUEINFO          129
    #define RT_SIGRETURN              15
    #define RT_SIGSUSPEND            130
    #define RT_SIGTIMEDWAIT          128
    #define RT_TGSIGQUEUEINFO        297
    #define SCHED_GETAFFINITY        204
    #define SCHED_GETATTR            315
    #define SCHED_GETPARAM           143
    #define SCHED_GET_PRIORITY_MAX   146
    #define SCHED_GET_PRIORITY_MIN   147
    #define SCHED_GETSCHEDULER       145
    #define SCHED_RR_GET_INTERVAL    148
    #define SCHED_SETAFFINITY        203
    #define SCHED_SETATTR            314
    #define SCHED_SETPARAM           142
    #define SCHED_SETSCHEDULER       144
    #define SCHED_YIELD               24
    #define SECCOMP                  317
    #define SEMCTL                    66
    #define SEMGET                    64
    #define SEMOP                     65
    #define SEMTIMEDOP               220
    #define SENDFILE64                40
    #define SENDMMSG                 307
    #define SENDMSG                   46
    #define SENDTO                    44
    #define SETDOMAINNAME            171
    #define SETFSGID                 123
    #define SETFSUID                 122
    #define SETGID                   106
    #define SETGROUPS                116
    #define SETHOSTNAME              170
    #define SETITIMER                 38
    #define SET_MEMPOLICY            238
    #define SET_MEMPOLICY_HOME_NODE  450
    #define SETNS                    308
    #define SETPGID                  109
    #define SETPRIORITY              141
    #define SETREGID                 114
    #define SETRESGID                119
    #define SETRESUID                117
    #define SETREUID                 113
    #define SETRLIMIT                160
    #define SET_ROBUST_LIST          273
    #define SETSID                   112
    #define SETSOCKOPT                54
    #define SET_TID_ADDRESS          218
    #define SETTIMEOFDAY             164
    #define SETUID                   105
    #define SETXATTR                 188
    #define SETXATTRAT               463
    #define SHMAT                     30
    #define SHMCTL                    31
    #define SHMDT                     67
    #define SHMGET                    29
    #define SHUTDOWN                  48
    #define SIGALTSTACK              131
    #define SIGNALFD4                289
    #define SOCKET                    41
    #define SOCKETPAIR                53
    #define SPLICE                   275
    #define STATFS                   137
    #define STATMOUNT                457
    #define STATX                    332
    #define SWAPOFF                  168
    #define SWAPON                   167
    #define SYMLINKAT                266
    #define SYNC                     162
    #define SYNC_FILE_RANGE          277
    #define SYNCFS                   306
    #define SYSINFO                   99
    #define SYSLOG                   103
    #define TEE                      276
    #define TGKILL                   234
    #define TIMER_CREATE             222
    #define TIMER_DELETE             226
    #define TIMERFD_CREATE           283
    #define TIMERFD_GETTIME          287
    #define TIMERFD_SETTIME          286
    #define TIMER_GETOVERRUN         225
    #define TIMER_GETTIME            224
    #define TIMER_SETTIME            223
    #define TIMES                    100
    #define TKILL                    200
    #define TRUNCATE                  76
    #define UMASK                     95
    #define UMOUNT                   166
    #define UNLINKAT                 263
    #define UNSHARE                  272
    #define USERFAULTFD              323
    #define UTIMENSAT                280
    #define VFORK                     58
    #define VHANGUP                  153
    #define VMSPLICE                 278
    #define WAIT4                     61
    #define WAITID                   247
    #define WRITE                      1
    #define WRITEV                    20
    #endif

    constexpr long accept                  (int fd, struct sockaddr *upeer_sockaddr, int *upeer_addrlen) {return syscall(ACCEPT, (long)fd, (long)upeer_sockaddr, (long)upeer_addrlen);};
    constexpr long accept4                 (int fd, struct sockaddr *upeer_sockaddr, int *upeer_addrlen, int flags) {return syscall(ACCEPT4, (long)fd, (long)upeer_sockaddr, (long)upeer_addrlen, (long)flags);};
    constexpr long acct                    (const char *name) {return syscall(ACCT, (long)name);};
    constexpr long add_key                 (const char *_type, const char *_description, const void *_payload, size_t plen, key_serial_t ringid) {return syscall(ADD_KEY, (long)_type, (long)_description, (long)_payload, (long)plen, (long)ringid);};
    constexpr long adjtimex                (struct __kernel_timex *txc_p) {return syscall(ADJTIMEX, (long)txc_p);};
    constexpr long bind                    (int fd, struct sockaddr *umyaddr, int addrlen) {return syscall(BIND, (long)fd, (long)umyaddr, (long)addrlen);};
    constexpr long bpf                     (int cmd, union bpf_attr *uattr, unsigned int size) {return syscall(BPF, (long)cmd, (long)uattr, (long)size);};
    constexpr long brk                     (unsigned long brk) {return syscall(BRK, (long)brk);};
    constexpr long cachestat               (unsigned int fd, struct cachestat_range *cstat_range, struct cachestat *cstat, unsigned int flags) {return syscall(CACHESTAT, (long)fd, (long)cstat_range, (long)cstat, (long)flags);};
    constexpr long capget                  (cap_user_header_t header, cap_user_data_t dataptr) {return syscall(CAPGET, (long)header, (long)dataptr);};
    constexpr long capset                  (cap_user_header_t header, const cap_user_data_t data) {return syscall(CAPSET, (long)header, (long)data);};
    constexpr long chdir                   (const char *filename) {return syscall(CHDIR, (long)filename);};
    constexpr long chroot                  (const char *filename) {return syscall(CHROOT, (long)filename);};
    constexpr long clock_adjtime           (const clockid_t which_clock, struct __kernel_timex *utx) {return syscall(CLOCK_ADJTIME, (long)which_clock, (long)utx);};
    constexpr long clock_getres            (const clockid_t which_clock, struct __kernel_timespec *tp) {return syscall(CLOCK_GETRES, (long)which_clock, (long)tp);};
    constexpr long clock_gettime           (const clockid_t which_clock, struct __kernel_timespec *tp) {return syscall(CLOCK_GETTIME, (long)which_clock, (long)tp);};
    constexpr long clock_nanosleep         (const clockid_t which_clock, int flags, const struct __kernel_timespec *rqtp, struct __kernel_timespec *rmtp) {return syscall(CLOCK_NANOSLEEP, (long)which_clock, (long)flags, (long)rqtp, (long)rmtp);};
    constexpr long clock_settime           (const clockid_t which_clock, const struct __kernel_timespec *tp) {return syscall(CLOCK_SETTIME, (long)which_clock, (long)tp);};
    constexpr long clone                   (unsigned long clone_flags, unsigned long newsp, int *parent_tidptr, unsigned long tls, int *child_tidptr) {return syscall(CLONE, (long)clone_flags, (long)newsp, (long)parent_tidptr, (long)tls, (long)child_tidptr);};
    constexpr long clone3                  (struct clone_args *uargs, size_t size) {return syscall(CLONE3, (long)uargs, (long)size);};
    constexpr long close                   (unsigned int fd) {return syscall(CLOSE, (long)fd);};
    constexpr long close_range             (unsigned int fd, unsigned int max_fd, unsigned int flags) {return syscall(CLOSE_RANGE, (long)fd, (long)max_fd, (long)flags);};
    constexpr long connect                 (int fd, struct sockaddr *uservaddr, int addrlen) {return syscall(CONNECT, (long)fd, (long)uservaddr, (long)addrlen);};
    constexpr long copy_file_range         (int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, size_t len, unsigned int flags) {return syscall(COPY_FILE_RANGE, (long)fd_in, (long)off_in, (long)fd_out, (long)off_out, (long)len, (long)flags);};
    constexpr long delete_module           (const char *name_user, unsigned int flags) {return syscall(DELETE_MODULE, (long)name_user, (long)flags);};
    constexpr long dup                     (unsigned int fildes) {return syscall(DUP, (long)fildes);};
    constexpr long dup3                    (unsigned int oldfd, unsigned int newfd, int flags) {return syscall(DUP3, (long)oldfd, (long)newfd, (long)flags);};
    constexpr long epoll_create1           (int flags) {return syscall(EPOLL_CREATE1, (long)flags);};
    constexpr long epoll_ctl               (int epfd, int op, int fd, struct epoll_event *event) {return syscall(EPOLL_CTL, (long)epfd, (long)op, (long)fd, (long)event);};
    constexpr long epoll_pwait             (int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask, size_t sigsetsize) {return syscall(EPOLL_PWAIT, (long)epfd, (long)events, (long)maxevents, (long)timeout, (long)sigmask, (long)sigsetsize);};
    constexpr long epoll_pwait2            (int epfd, struct epoll_event *events, int maxevents, const struct __kernel_timespec *timeout, const sigset_t *sigmask, size_t sigsetsize) {return syscall(EPOLL_PWAIT2, (long)epfd, (long)events, (long)maxevents, (long)timeout, (long)sigmask, (long)sigsetsize);};
    constexpr long eventfd2                (unsigned int count, int flags) {return syscall(EVENTFD2, (long)count, (long)flags);};
    constexpr long execve                  (const char *filename, const char *const *argv, const char *const *envp) {return syscall(EXECVE, (long)filename, (long)argv, (long)envp);};
    constexpr long execveat                (int fd, const char *filename, const char *const *argv, const char *const *envp, int flags) {return syscall(EXECVEAT, (long)fd, (long)filename, (long)argv, (long)envp, (long)flags);};
    constexpr long exit                    (int error_code) {return syscall(EXIT, (long)error_code);};
    constexpr long exit_group              (int error_code) {return syscall(EXIT_GROUP, (long)error_code);};
    constexpr long faccessat2              (int dfd, const char *filename, int mode, int flags) {return syscall(FACCESSAT2, (long)dfd, (long)filename, (long)mode, (long)flags);};
    constexpr long faccessat               (int dfd, const char *filename, int mode) {return syscall(FACCESSAT, (long)dfd, (long)filename, (long)mode);};
    constexpr long fallocate               (int fd, int mode, loff_t offset, loff_t len) {return syscall(FALLOCATE, (long)fd, (long)mode, (long)offset, (long)len);};
    constexpr long fanotify_init           (unsigned int flags, unsigned int event_f_flags) {return syscall(FANOTIFY_INIT, (long)flags, (long)event_f_flags);};
    constexpr long fanotify_mark           (int fanotify_fd, unsigned int flags, __u64 mask, int dfd, const char *pathname) {return syscall(FANOTIFY_MARK, (long)fanotify_fd, (long)flags, (long)mask, (long)dfd, (long)pathname);};
    constexpr long fchdir                  (unsigned int fd) {return syscall(FCHDIR, (long)fd);};
    constexpr long fchmod                  (unsigned int fd, umode_t mode) {return syscall(FCHMOD, (long)fd, (long)mode);};
    constexpr long fchmodat2               (int dfd, const char *filename, umode_t mode, unsigned int flags) {return syscall(FCHMODAT2, (long)dfd, (long)filename, (long)mode, (long)flags);};
    constexpr long fchmodat                (int dfd, const char *filename, umode_t mode) {return syscall(FCHMODAT, (long)dfd, (long)filename, (long)mode);};
    constexpr long fchown                  (unsigned int fd, uid_t user, gid_t group) {return syscall(FCHOWN, (long)fd, (long)user, (long)group);};
    constexpr long fchownat                (int dfd, const char *filename, uid_t user, gid_t group, int flag) {return syscall(FCHOWNAT, (long)dfd, (long)filename, (long)user, (long)group, (long)flag);};
    constexpr long fcntl                   (unsigned int fd, unsigned int cmd, unsigned long arg) {return syscall(FCNTL, (long)fd, (long)cmd, (long)arg);};
    constexpr long fdatasync               (unsigned int fd) {return syscall(FDATASYNC, (long)fd);};
    constexpr long fgetxattr               (int fd, const char *name, void *value, size_t size) {return syscall(FGETXATTR, (long)fd, (long)name, (long)value, (long)size);};
    constexpr long file_getattr            (int dfd, const char *filename, struct file_attr *ufattr, size_t usize, unsigned int at_flags) {return syscall(FILE_GETATTR, (long)dfd, (long)filename, (long)ufattr, (long)usize, (long)at_flags);};
    constexpr long file_setattr            (int dfd, const char *filename, struct file_attr *ufattr, size_t usize, unsigned int at_flags) {return syscall(FILE_SETATTR, (long)dfd, (long)filename, (long)ufattr, (long)usize, (long)at_flags);};
    constexpr long finit_module            (int fd, const char *uargs, int flags) {return syscall(FINIT_MODULE, (long)fd, (long)uargs, (long)flags);};
    constexpr long flistxattr              (int fd, char *list, size_t size) {return syscall(FLISTXATTR, (long)fd, (long)list, (long)size);};
    constexpr long flock                   (unsigned int fd, unsigned int cmd) {return syscall(FLOCK, (long)fd, (long)cmd);};
    constexpr long fremovexattr            (int fd, const char *name) {return syscall(FREMOVEXATTR, (long)fd, (long)name);};
    constexpr long fsconfig                (int fd, unsigned int cmd, const char *_key, const void *_value, int aux) {return syscall(FSCONFIG, (long)fd, (long)cmd, (long)_key, (long)_value, (long)aux);};
    constexpr long fsetxattr               (int fd, const char *name, const void *value, size_t size, int flags) {return syscall(FSETXATTR, (long)fd, (long)name, (long)value, (long)size, (long)flags);};
    constexpr long fsmount                 (int fs_fd, unsigned int flags, unsigned int attr_flags) {return syscall(FSMOUNT, (long)fs_fd, (long)flags, (long)attr_flags);};
    constexpr long fsopen                  (const char *_fs_name, unsigned int flags) {return syscall(FSOPEN, (long)_fs_name, (long)flags);};
    constexpr long fspick                  (int dfd, const char *path, unsigned int flags) {return syscall(FSPICK, (long)dfd, (long)path, (long)flags);};
    constexpr long fstatfs                 (unsigned int fd, struct statfs *buf) {return syscall(FSTATFS, (long)fd, (long)buf);};
    constexpr long fsync                   (unsigned int fd) {return syscall(FSYNC, (long)fd);};
    constexpr long ftruncate               (unsigned int fd, off_t length) {return syscall(FTRUNCATE, (long)fd, (long)length);};
    constexpr long futex                   (u32 *uaddr, int op, u32 val, const struct __kernel_timespec *utime, u32 *uaddr2, u32 val3) {return syscall(FUTEX, (long)uaddr, (long)op, (long)val, (long)utime, (long)uaddr2, (long)val3);};
    constexpr long futex_requeue           (struct futex_waitv *waiters, unsigned int flags, int nr_wake, int nr_requeue) {return syscall(FUTEX_REQUEUE, (long)waiters, (long)flags, (long)nr_wake, (long)nr_requeue);};
    constexpr long futex_wait              (void *uaddr, unsigned long val, unsigned long mask, unsigned int flags, struct __kernel_timespec *timeout, clockid_t clockid) {return syscall(FUTEX_WAIT, (long)uaddr, (long)val, (long)mask, (long)flags, (long)timeout, (long)clockid);};
    constexpr long futex_waitv             (struct futex_waitv *waiters, unsigned int nr_futexes, unsigned int flags, struct __kernel_timespec *timeout, clockid_t clockid) {return syscall(FUTEX_WAITV, (long)waiters, (long)nr_futexes, (long)flags, (long)timeout, (long)clockid);};
    constexpr long futex_wake              (void *uaddr, unsigned long mask, int nr, unsigned int flags) {return syscall(FUTEX_WAKE, (long)uaddr, (long)mask, (long)nr, (long)flags);};
    constexpr long getcpu                  (unsigned *cpup, unsigned *nodep, struct getcpu_cache *unused) {return syscall(GETCPU, (long)cpup, (long)nodep, (long)unused);};
    constexpr long getcwd                  (char *buf, unsigned long size) {return syscall(GETCWD, (long)buf, (long)size);};
    constexpr long getdents64              (unsigned int fd, struct linux_dirent64 *dirent, unsigned int count) {return syscall(GETDENTS64, (long)fd, (long)dirent, (long)count);};
    constexpr long getegid                 () {return syscall(GETEGID);};
    constexpr long geteuid                 () {return syscall(GETEUID);};
    constexpr long getgid                  () {return syscall(GETGID);};
    constexpr long getgroups               (int gidsetsize, gid_t *grouplist) {return syscall(GETGROUPS, (long)gidsetsize, (long)grouplist);};
    constexpr long getitimer               (int which, struct __kernel_old_itimerval *value) {return syscall(GETITIMER, (long)which, (long)value);};
    constexpr long get_mempolicy           (int *policy, unsigned long *nmask, unsigned long maxnode, unsigned long addr, unsigned long flags) {return syscall(GET_MEMPOLICY, (long)policy, (long)nmask, (long)maxnode, (long)addr, (long)flags);};
    constexpr long getpeername             (int fd, struct sockaddr *usockaddr, int *usockaddr_len) {return syscall(GETPEERNAME, (long)fd, (long)usockaddr, (long)usockaddr_len);};
    constexpr long getpgid                 (pid_t pid) {return syscall(GETPGID, (long)pid);};
    constexpr long getpid                  () {return syscall(GETPID);};
    constexpr long getppid                 () {return syscall(GETPPID);};
    constexpr long getpriority             (int which, int who) {return syscall(GETPRIORITY, (long)which, (long)who);};
    constexpr long getrandom               (char *ubuf, size_t len, unsigned int flags) {return syscall(GETRANDOM, (long)ubuf, (long)len, (long)flags);};
    constexpr long getresgid               (gid_t *rgidp, gid_t *egidp, gid_t *sgidp) {return syscall(GETRESGID, (long)rgidp, (long)egidp, (long)sgidp);};
    constexpr long getresuid               (uid_t *ruidp, uid_t *euidp, uid_t *suidp) {return syscall(GETRESUID, (long)ruidp, (long)euidp, (long)suidp);};
    constexpr long getrlimit               (unsigned int resource, struct rlimit *rlim) {return syscall(GETRLIMIT, (long)resource, (long)rlim);};
    constexpr long get_robust_list         (int pid, struct robust_list_head **head_ptr, size_t *len_ptr) {return syscall(GET_ROBUST_LIST, (long)pid, (long)head_ptr, (long)len_ptr);};
    constexpr long getrusage               (int who, struct rusage *ru) {return syscall(GETRUSAGE, (long)who, (long)ru);};
    constexpr long getsid                  (pid_t pid) {return syscall(GETSID, (long)pid);};
    constexpr long getsockname             (int fd, struct sockaddr *usockaddr, int *usockaddr_len) {return syscall(GETSOCKNAME, (long)fd, (long)usockaddr, (long)usockaddr_len);};
    constexpr long getsockopt              (int fd, int level, int optname, char *optval, int *optlen) {return syscall(GETSOCKOPT, (long)fd, (long)level, (long)optname, (long)optval, (long)optlen);};
    constexpr long gettid                  () {return syscall(GETTID);};
    constexpr long gettimeofday            (struct __kernel_old_timeval *tv, struct timezone *tz) {return syscall(GETTIMEOFDAY, (long)tv, (long)tz);};
    constexpr long getuid                  () {return syscall(GETUID);};
    constexpr long getxattr                (const char *pathname, const char *name, void *value, size_t size) {return syscall(GETXATTR, (long)pathname, (long)name, (long)value, (long)size);};
    constexpr long getxattrat              (int dfd, const char *pathname, unsigned int at_flags, const char *name, struct xattr_args *uargs, size_t usize) {return syscall(GETXATTRAT, (long)dfd, (long)pathname, (long)at_flags, (long)name, (long)uargs, (long)usize);};
    constexpr long init_module             (void *umod, unsigned long len, const char *uargs) {return syscall(INIT_MODULE, (long)umod, (long)len, (long)uargs);};
    constexpr long inotify_add_watch       (int fd, const char *pathname, u32 mask) {return syscall(INOTIFY_ADD_WATCH, (long)fd, (long)pathname, (long)mask);};
    constexpr long inotify_init1           (int flags) {return syscall(INOTIFY_INIT1, (long)flags);};
    constexpr long inotify_rm_watch        (int fd, __s32 wd) {return syscall(INOTIFY_RM_WATCH, (long)fd, (long)wd);};
    constexpr long io_cancel               (aio_context_t ctx_id, struct iocb *iocb, struct io_event *result) {return syscall(IO_CANCEL, (long)ctx_id, (long)iocb, (long)result);};
    constexpr long ioctl                   (unsigned int fd, unsigned int cmd, unsigned long arg) {return syscall(IOCTL, (long)fd, (long)cmd, (long)arg);};
    constexpr long io_destroy              (aio_context_t ctx) {return syscall(IO_DESTROY, (long)ctx);};
    constexpr long io_getevents            (aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct __kernel_timespec *timeout) {return syscall(IO_GETEVENTS, (long)ctx_id, (long)min_nr, (long)nr, (long)events, (long)timeout);};
    constexpr long io_pgetevents           (aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct __kernel_timespec *timeout, const struct __aio_sigset *usig) {return syscall(IO_PGETEVENTS, (long)ctx_id, (long)min_nr, (long)nr, (long)events, (long)timeout, (long)usig);};
    constexpr long ioprio_get              (int which, int who) {return syscall(IOPRIO_GET, (long)which, (long)who);};
    constexpr long ioprio_set              (int which, int who, int ioprio) {return syscall(IOPRIO_SET, (long)which, (long)who, (long)ioprio);};
    constexpr long io_setup                (unsigned nr_events, aio_context_t *ctxp) {return syscall(IO_SETUP, (long)nr_events, (long)ctxp);};
    constexpr long io_submit               (aio_context_t ctx_id, long nr, struct iocb **iocbpp) {return syscall(IO_SUBMIT, (long)ctx_id, (long)nr, (long)iocbpp);};
    constexpr long io_uring_enter          (unsigned int fd, u32 to_submit, u32 min_complete, u32 flags, const void *argp, size_t argsz) {return syscall(IO_URING_ENTER, (long)fd, (long)to_submit, (long)min_complete, (long)flags, (long)argp, (long)argsz);};
    constexpr long io_uring_register       (unsigned int fd, unsigned int opcode, void *arg, unsigned int nr_args) {return syscall(IO_URING_REGISTER, (long)fd, (long)opcode, (long)arg, (long)nr_args);};
    constexpr long io_uring_setup          (u32 entries, struct io_uring_params *params) {return syscall(IO_URING_SETUP, (long)entries, (long)params);};
    constexpr long kcmp                    (pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2) {return syscall(KCMP, (long)pid1, (long)pid2, (long)type, (long)idx1, (long)idx2);};
    constexpr long kexec_file_load         (int kernel_fd, int initrd_fd, unsigned long cmdline_len, const char *cmdline_ptr, unsigned long flags) {return syscall(KEXEC_FILE_LOAD, (long)kernel_fd, (long)initrd_fd, (long)cmdline_len, (long)cmdline_ptr, (long)flags);};
    constexpr long kexec_load              (unsigned long entry, unsigned long nr_segments, struct kexec_segment *segments, unsigned long flags) {return syscall(KEXEC_LOAD, (long)entry, (long)nr_segments, (long)segments, (long)flags);};
    constexpr long keyctl                  (int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5) {return syscall(KEYCTL, (long)option, (long)arg2, (long)arg3, (long)arg4, (long)arg5);};
    constexpr long kill                    (pid_t pid, int sig) {return syscall(KILL, (long)pid, (long)sig);};
    constexpr long landlock_add_rule       (const int ruleset_fd, const enum landlock_rule_type rule_type, const void *const rule_attr, const __u32 flags) {return syscall(LANDLOCK_ADD_RULE, (long)ruleset_fd, (long)rule_type, (long)rule_attr, (long)flags);};
    constexpr long landlock_create_ruleset (const struct landlock_ruleset_attr *const attr, const size_t size, const __u32 flags) {return syscall(LANDLOCK_CREATE_RULESET, (long)attr, (long)size, (long)flags);};
    constexpr long landlock_restrict_self  (const int ruleset_fd, const __u32 flags) {return syscall(LANDLOCK_RESTRICT_SELF, (long)ruleset_fd, (long)flags);};
    constexpr long lgetxattr               (const char *pathname, const char *name, void *value, size_t size) {return syscall(LGETXATTR, (long)pathname, (long)name, (long)value, (long)size);};
    constexpr long linkat                  (int olddfd, const char *oldname, int newdfd, const char *newname, int flags) {return syscall(LINKAT, (long)olddfd, (long)oldname, (long)newdfd, (long)newname, (long)flags);};
    constexpr long listen                  (int fd, int backlog) {return syscall(LISTEN, (long)fd, (long)backlog);};
    constexpr long listmount               (const struct mnt_id_req *req, u64 *mnt_ids, size_t nr_mnt_ids, unsigned int flags) {return syscall(LISTMOUNT, (long)req, (long)mnt_ids, (long)nr_mnt_ids, (long)flags);};
    constexpr long listxattr               (const char *pathname, char *list, size_t size) {return syscall(LISTXATTR, (long)pathname, (long)list, (long)size);};
    constexpr long listxattrat             (int dfd, const char *pathname, unsigned int at_flags, char *list, size_t size) {return syscall(LISTXATTRAT, (long)dfd, (long)pathname, (long)at_flags, (long)list, (long)size);};
    constexpr long llistxattr              (const char *pathname, char *list, size_t size) {return syscall(LLISTXATTR, (long)pathname, (long)list, (long)size);};
    constexpr long lremovexattr            (const char *pathname, const char *name) {return syscall(LREMOVEXATTR, (long)pathname, (long)name);};
    constexpr long lseek                   (unsigned int fd, off_t offset, unsigned int whence) {return syscall(LSEEK, (long)fd, (long)offset, (long)whence);};
    constexpr long lsetxattr               (const char *pathname, const char *name, const void *value, size_t size, int flags) {return syscall(LSETXATTR, (long)pathname, (long)name, (long)value, (long)size, (long)flags);};
    constexpr long lsm_get_self_attr       (unsigned int attr, struct lsm_ctx *ctx, u32 *size, u32 flags) {return syscall(LSM_GET_SELF_ATTR, (long)attr, (long)ctx, (long)size, (long)flags);};
    constexpr long lsm_list_modules        (u64 *ids, u32 *size, u32 flags) {return syscall(LSM_LIST_MODULES, (long)ids, (long)size, (long)flags);};
    constexpr long lsm_set_self_attr       (unsigned int attr, struct lsm_ctx *ctx, u32 size, u32 flags) {return syscall(LSM_SET_SELF_ATTR, (long)attr, (long)ctx, (long)size, (long)flags);};
    constexpr long madvise                 (unsigned long start, size_t len_in, int behavior) {return syscall(MADVISE, (long)start, (long)len_in, (long)behavior);};
    constexpr long map_shadow_stack        (unsigned long addr, unsigned long size, unsigned int flags) {return syscall(MAP_SHADOW_STACK, (long)addr, (long)size, (long)flags);};
    constexpr long mbind                   (unsigned long start, unsigned long len, unsigned long mode, const unsigned long *nmask, unsigned long maxnode, unsigned int flags) {return syscall(MBIND, (long)start, (long)len, (long)mode, (long)nmask, (long)maxnode, (long)flags);};
    constexpr long membarrier              (int cmd, unsigned int flags, int cpu_id) {return syscall(MEMBARRIER, (long)cmd, (long)flags, (long)cpu_id);};
    constexpr long memfd_create            (const char *uname, unsigned int flags) {return syscall(MEMFD_CREATE, (long)uname, (long)flags);};
    constexpr long memfd_secret            (unsigned int flags) {return syscall(MEMFD_SECRET, (long)flags);};
    constexpr long migrate_pages           (pid_t pid, unsigned long maxnode, const unsigned long *old_nodes, const unsigned long *new_nodes) {return syscall(MIGRATE_PAGES, (long)pid, (long)maxnode, (long)old_nodes, (long)new_nodes);};
    constexpr long mincore                 (unsigned long start, size_t len, unsigned char *vec) {return syscall(MINCORE, (long)start, (long)len, (long)vec);};
    constexpr long mkdirat                 (int dfd, const char *pathname, umode_t mode) {return syscall(MKDIRAT, (long)dfd, (long)pathname, (long)mode);};
    constexpr long mknodat                 (int dfd, const char *filename, umode_t mode, unsigned int dev) {return syscall(MKNODAT, (long)dfd, (long)filename, (long)mode, (long)dev);};
    constexpr long mlock2                  (unsigned long start, size_t len, int flags) {return syscall(MLOCK2, (long)start, (long)len, (long)flags);};
    constexpr long mlock                   (unsigned long start, size_t len) {return syscall(MLOCK, (long)start, (long)len);};
    constexpr long mlockall                (int flags) {return syscall(MLOCKALL, (long)flags);};
    constexpr long mmap                    (unsigned long addr, unsigned long len, unsigned long prot, unsigned long flags, unsigned long fd, unsigned long off) {return syscall(MMAP, (long)addr, (long)len, (long)prot, (long)flags, (long)fd, (long)off);};
    constexpr long mount                   (char *dev_name, char *dir_name, char *type, unsigned long flags, void *data) {return syscall(MOUNT, (long)dev_name, (long)dir_name, (long)type, (long)flags, (long)data);};
    constexpr long mount_setattr           (int dfd, const char *path, unsigned int flags, struct mount_attr *uattr, size_t usize) {return syscall(MOUNT_SETATTR, (long)dfd, (long)path, (long)flags, (long)uattr, (long)usize);};
    constexpr long move_mount              (int from_dfd, const char *from_pathname, int to_dfd, const char *to_pathname, unsigned int flags) {return syscall(MOVE_MOUNT, (long)from_dfd, (long)from_pathname, (long)to_dfd, (long)to_pathname, (long)flags);};
    constexpr long move_pages              (pid_t pid, unsigned long nr_pages, const void **pages, const int *nodes, int *status, int flags) {return syscall(MOVE_PAGES, (long)pid, (long)nr_pages, (long)pages, (long)nodes, (long)status, (long)flags);};
    constexpr long mprotect                (unsigned long start, size_t len, unsigned long prot) {return syscall(MPROTECT, (long)start, (long)len, (long)prot);};
    constexpr long mq_getsetattr           (mqd_t mqdes, const struct mq_attr *u_mqstat, struct mq_attr *u_omqstat) {return syscall(MQ_GETSETATTR, (long)mqdes, (long)u_mqstat, (long)u_omqstat);};
    constexpr long mq_notify               (mqd_t mqdes, const struct sigevent *u_notification) {return syscall(MQ_NOTIFY, (long)mqdes, (long)u_notification);};
    constexpr long mq_open                 (const char *u_name, int oflag, umode_t mode, struct mq_attr *u_attr) {return syscall(MQ_OPEN, (long)u_name, (long)oflag, (long)mode, (long)u_attr);};
    constexpr long mq_timedreceive         (mqd_t mqdes, char *u_msg_ptr, size_t msg_len, unsigned int *u_msg_prio, const struct __kernel_timespec *u_abs_timeout) {return syscall(MQ_TIMEDRECEIVE, (long)mqdes, (long)u_msg_ptr, (long)msg_len, (long)u_msg_prio, (long)u_abs_timeout);};
    constexpr long mq_timedsend            (mqd_t mqdes, const char *u_msg_ptr, size_t msg_len, unsigned int msg_prio, const struct __kernel_timespec *u_abs_timeout) {return syscall(MQ_TIMEDSEND, (long)mqdes, (long)u_msg_ptr, (long)msg_len, (long)msg_prio, (long)u_abs_timeout);};
    constexpr long mq_unlink               (const char *u_name) {return syscall(MQ_UNLINK, (long)u_name);};
    constexpr long mremap                  (unsigned long addr, unsigned long old_len, unsigned long new_len, unsigned long flags, unsigned long new_addr) {return syscall(MREMAP, (long)addr, (long)old_len, (long)new_len, (long)flags, (long)new_addr);};
    constexpr long mseal                   (unsigned long start, size_t len, unsigned long flags) {return syscall(MSEAL, (long)start, (long)len, (long)flags);};
    constexpr long msgctl                  (int msqid, int cmd, struct msqid_ds *buf) {return syscall(MSGCTL, (long)msqid, (long)cmd, (long)buf);};
    constexpr long msgget                  (key_t key, int msgflg) {return syscall(MSGGET, (long)key, (long)msgflg);};
    constexpr long msgrcv                  (int msqid, struct msgbuf *msgp, size_t msgsz, long msgtyp, int msgflg) {return syscall(MSGRCV, (long)msqid, (long)msgp, (long)msgsz, (long)msgtyp, (long)msgflg);};
    constexpr long msgsnd                  (int msqid, struct msgbuf *msgp, size_t msgsz, int msgflg) {return syscall(MSGSND, (long)msqid, (long)msgp, (long)msgsz, (long)msgflg);};
    constexpr long msync                   (unsigned long start, size_t len, int flags) {return syscall(MSYNC, (long)start, (long)len, (long)flags);};
    constexpr long munlock                 (unsigned long start, size_t len) {return syscall(MUNLOCK, (long)start, (long)len);};
    constexpr long munlockall              () {return syscall(MUNLOCKALL);};
    constexpr long munmap                  (unsigned long addr, size_t len) {return syscall(MUNMAP, (long)addr, (long)len);};
    constexpr long name_to_handle_at       (int dfd, const char *name, struct file_handle *handle, void *mnt_id, int flag) {return syscall(NAME_TO_HANDLE_AT, (long)dfd, (long)name, (long)handle, (long)mnt_id, (long)flag);};
    constexpr long nanosleep               (struct __kernel_timespec *rqtp, struct __kernel_timespec *rmtp) {return syscall(NANOSLEEP, (long)rqtp, (long)rmtp);};
    constexpr long newfstat                (unsigned int fd, struct stat *statbuf) {return syscall(NEWFSTAT, (long)fd, (long)statbuf);};
    constexpr long newfstatat              (int dfd, const char *filename, struct stat *statbuf, int flag) {return syscall(NEWFSTATAT, (long)dfd, (long)filename, (long)statbuf, (long)flag);};
    constexpr long newuname                (struct new_utsname *name) {return syscall(NEWUNAME, (long)name);};
    constexpr long openat2                 (int dfd, const char *filename, struct open_how *how, size_t usize) {return syscall(OPENAT2, (long)dfd, (long)filename, (long)how, (long)usize);};
    constexpr long openat                  (int dfd, const char *filename, int flags, umode_t mode) {return syscall(OPENAT, (long)dfd, (long)filename, (long)flags, (long)mode);};
    constexpr long open_by_handle_at       (int mountdirfd, struct file_handle *handle, int flags) {return syscall(OPEN_BY_HANDLE_AT, (long)mountdirfd, (long)handle, (long)flags);};
    constexpr long open_tree               (int dfd, const char *filename, unsigned flags) {return syscall(OPEN_TREE, (long)dfd, (long)filename, (long)flags);};
    constexpr long open_tree_attr          (int dfd, const char *filename, unsigned flags, struct mount_attr *uattr, size_t usize) {return syscall(OPEN_TREE_ATTR, (long)dfd, (long)filename, (long)flags, (long)uattr, (long)usize);};
    constexpr long perf_event_open         (struct perf_event_attr *attr_uptr, pid_t pid, int cpu, int group_fd, unsigned long flags) {return syscall(PERF_EVENT_OPEN, (long)attr_uptr, (long)pid, (long)cpu, (long)group_fd, (long)flags);};
    constexpr long personality             (unsigned int personality) {return syscall(PERSONALITY, (long)personality);};
    constexpr long pidfd_getfd             (int pidfd, int fd, unsigned int flags) {return syscall(PIDFD_GETFD, (long)pidfd, (long)fd, (long)flags);};
    constexpr long pidfd_open              (pid_t pid, unsigned int flags) {return syscall(PIDFD_OPEN, (long)pid, (long)flags);};
    constexpr long pidfd_send_signal       (int pidfd, int sig, siginfo_t *info, unsigned int flags) {return syscall(PIDFD_SEND_SIGNAL, (long)pidfd, (long)sig, (long)info, (long)flags);};
    constexpr long pipe2                   (int *fildes, int flags) {return syscall(PIPE2, (long)fildes, (long)flags);};
    constexpr long pivot_root              (const char *new_root, const char *put_old) {return syscall(PIVOT_ROOT, (long)new_root, (long)put_old);};
    constexpr long pkey_alloc              (unsigned long flags, unsigned long init_val) {return syscall(PKEY_ALLOC, (long)flags, (long)init_val);};
    constexpr long pkey_free               (int pkey) {return syscall(PKEY_FREE, (long)pkey);};
    constexpr long pkey_mprotect           (unsigned long start, size_t len, unsigned long prot, int pkey) {return syscall(PKEY_MPROTECT, (long)start, (long)len, (long)prot, (long)pkey);};
    constexpr long ppoll                   (struct pollfd *ufds, unsigned int nfds, struct __kernel_timespec *tsp, const sigset_t *sigmask, size_t sigsetsize) {return syscall(PPOLL, (long)ufds, (long)nfds, (long)tsp, (long)sigmask, (long)sigsetsize);};
    constexpr long prctl                   (int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5) {return syscall(PRCTL, (long)option, (long)arg2, (long)arg3, (long)arg4, (long)arg5);};
    constexpr long pread64                 (unsigned int fd, char *buf, size_t count, loff_t pos) {return syscall(PREAD64, (long)fd, (long)buf, (long)count, (long)pos);};
    constexpr long preadv2                 (unsigned long fd, const struct iovec *vec, unsigned long vlen, unsigned long pos_l, unsigned long pos_h, rwf_t flags) {return syscall(PREADV2, (long)fd, (long)vec, (long)vlen, (long)pos_l, (long)pos_h, (long)flags);};
    constexpr long preadv                  (unsigned long fd, const struct iovec *vec, unsigned long vlen, unsigned long pos_l, unsigned long pos_h) {return syscall(PREADV, (long)fd, (long)vec, (long)vlen, (long)pos_l, (long)pos_h);};
    constexpr long prlimit64               (pid_t pid, unsigned int resource, const struct rlimit64 *new_rlim, struct rlimit64 *old_rlim) {return syscall(PRLIMIT64, (long)pid, (long)resource, (long)new_rlim, (long)old_rlim);};
    constexpr long process_madvise         (int pidfd, const struct iovec *vec, size_t vlen, int behavior, unsigned int flags) {return syscall(PROCESS_MADVISE, (long)pidfd, (long)vec, (long)vlen, (long)behavior, (long)flags);};
    constexpr long process_mrelease        (int pidfd, unsigned int flags) {return syscall(PROCESS_MRELEASE, (long)pidfd, (long)flags);};
    constexpr long process_vm_readv        (pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags) {return syscall(PROCESS_VM_READV, (long)pid, (long)lvec, (long)liovcnt, (long)rvec, (long)riovcnt, (long)flags);};
    constexpr long process_vm_writev       (pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags) {return syscall(PROCESS_VM_WRITEV, (long)pid, (long)lvec, (long)liovcnt, (long)rvec, (long)riovcnt, (long)flags);};
    constexpr long pselect6                (int n, fd_set *inp, fd_set *outp, fd_set *exp, struct __kernel_timespec *tsp, void *sig) {return syscall(PSELECT6, (long)n, (long)inp, (long)outp, (long)exp, (long)tsp, (long)sig);};
    constexpr long ptrace                  (long request, long pid, unsigned long addr, unsigned long data) {return syscall(PTRACE, (long)request, (long)pid, (long)addr, (long)data);};
    constexpr long pwrite64                (unsigned int fd, const char *buf, size_t count, loff_t pos) {return syscall(PWRITE64, (long)fd, (long)buf, (long)count, (long)pos);};
    constexpr long pwritev2                (unsigned long fd, const struct iovec *vec, unsigned long vlen, unsigned long pos_l, unsigned long pos_h, rwf_t flags) {return syscall(PWRITEV2, (long)fd, (long)vec, (long)vlen, (long)pos_l, (long)pos_h, (long)flags);};
    constexpr long pwritev                 (unsigned long fd, const struct iovec *vec, unsigned long vlen, unsigned long pos_l, unsigned long pos_h) {return syscall(PWRITEV, (long)fd, (long)vec, (long)vlen, (long)pos_l, (long)pos_h);};
    constexpr long quotactl                (unsigned int cmd, const char *special, qid_t id, void *addr) {return syscall(QUOTACTL, (long)cmd, (long)special, (long)id, (long)addr);};
    constexpr long quotactl_fd             (unsigned int fd, unsigned int cmd, qid_t id, void *addr) {return syscall(QUOTACTL_FD, (long)fd, (long)cmd, (long)id, (long)addr);};
    constexpr long read                    (unsigned int fd, char *buf, size_t count) {return syscall(READ, (long)fd, (long)buf, (long)count);};
    constexpr long readahead               (int fd, loff_t offset, size_t count) {return syscall(READAHEAD, (long)fd, (long)offset, (long)count);};
    constexpr long readlinkat              (int dfd, const char *pathname, char *buf, int bufsiz) {return syscall(READLINKAT, (long)dfd, (long)pathname, (long)buf, (long)bufsiz);};
    constexpr long readv                   (unsigned long fd, const struct iovec *vec, unsigned long vlen) {return syscall(READV, (long)fd, (long)vec, (long)vlen);};
    constexpr long reboot                  (int magic1, int magic2, unsigned int cmd, void *arg) {return syscall(REBOOT, (long)magic1, (long)magic2, (long)cmd, (long)arg);};
    constexpr long recvfrom                (int fd, void *ubuf, size_t size, unsigned int flags, struct sockaddr *addr, int *addr_len) {return syscall(RECVFROM, (long)fd, (long)ubuf, (long)size, (long)flags, (long)addr, (long)addr_len);};
    constexpr long recvmmsg                (int fd, struct mmsghdr *mmsg, unsigned int vlen, unsigned int flags, struct __kernel_timespec *timeout) {return syscall(RECVMMSG, (long)fd, (long)mmsg, (long)vlen, (long)flags, (long)timeout);};
    constexpr long recvmsg                 (int fd, struct user_msghdr *msg, unsigned int flags) {return syscall(RECVMSG, (long)fd, (long)msg, (long)flags);};
    constexpr long remap_file_pages        (unsigned long start, unsigned long size, unsigned long prot, unsigned long pgoff, unsigned long flags) {return syscall(REMAP_FILE_PAGES, (long)start, (long)size, (long)prot, (long)pgoff, (long)flags);};
    constexpr long removexattr             (const char *pathname, const char *name) {return syscall(REMOVEXATTR, (long)pathname, (long)name);};
    constexpr long removexattrat           (int dfd, const char *pathname, unsigned int at_flags, const char *name) {return syscall(REMOVEXATTRAT, (long)dfd, (long)pathname, (long)at_flags, (long)name);};
    constexpr long renameat2               (int olddfd, const char *oldname, int newdfd, const char *newname, unsigned int flags) {return syscall(RENAMEAT2, (long)olddfd, (long)oldname, (long)newdfd, (long)newname, (long)flags);};
    constexpr long renameat                (int olddfd, const char *oldname, int newdfd, const char *newname) {return syscall(RENAMEAT, (long)olddfd, (long)oldname, (long)newdfd, (long)newname);};
    constexpr long request_key             (const char *_type, const char *_description, const char *_callout_info, key_serial_t destringid) {return syscall(REQUEST_KEY, (long)_type, (long)_description, (long)_callout_info, (long)destringid);};
    constexpr long restart_syscall         () {return syscall(RESTART_SYSCALL);};
    constexpr long rseq                    (struct rseq *rseq, u32 rseq_len, int flags, u32 sig) {return syscall(RSEQ, (long)rseq, (long)rseq_len, (long)flags, (long)sig);};
    constexpr long rt_sigaction            (int sig, const struct sigaction *act, struct sigaction *oact, size_t sigsetsize) {return syscall(RT_SIGACTION, (long)sig, (long)act, (long)oact, (long)sigsetsize);};
    constexpr long rt_sigpending           (sigset_t *uset, size_t sigsetsize) {return syscall(RT_SIGPENDING, (long)uset, (long)sigsetsize);};
    constexpr long rt_sigprocmask          (int how, sigset_t *nset, sigset_t *oset, size_t sigsetsize) {return syscall(RT_SIGPROCMASK, (long)how, (long)nset, (long)oset, (long)sigsetsize);};
    constexpr long rt_sigqueueinfo         (pid_t pid, int sig, siginfo_t *uinfo) {return syscall(RT_SIGQUEUEINFO, (long)pid, (long)sig, (long)uinfo);};
    constexpr long rt_sigreturn            () {return syscall(RT_SIGRETURN);};
    constexpr long rt_sigsuspend           (sigset_t *unewset, size_t sigsetsize) {return syscall(RT_SIGSUSPEND, (long)unewset, (long)sigsetsize);};
    constexpr long rt_sigtimedwait         (const sigset_t *uthese, siginfo_t *uinfo, const struct __kernel_timespec *uts, size_t sigsetsize) {return syscall(RT_SIGTIMEDWAIT, (long)uthese, (long)uinfo, (long)uts, (long)sigsetsize);};
    constexpr long rt_tgsigqueueinfo       (pid_t tgid, pid_t pid, int sig, siginfo_t *uinfo) {return syscall(RT_TGSIGQUEUEINFO, (long)tgid, (long)pid, (long)sig, (long)uinfo);};
    constexpr long sched_getaffinity       (pid_t pid, unsigned int len, unsigned long *user_mask_ptr) {return syscall(SCHED_GETAFFINITY, (long)pid, (long)len, (long)user_mask_ptr);};
    constexpr long sched_getattr           (pid_t pid, struct sched_attr *uattr, unsigned int usize, unsigned int flags) {return syscall(SCHED_GETATTR, (long)pid, (long)uattr, (long)usize, (long)flags);};
    constexpr long sched_getparam          (pid_t pid, struct sched_param *param) {return syscall(SCHED_GETPARAM, (long)pid, (long)param);};
    constexpr long sched_get_priority_max  (int policy) {return syscall(SCHED_GET_PRIORITY_MAX, (long)policy);};
    constexpr long sched_get_priority_min  (int policy) {return syscall(SCHED_GET_PRIORITY_MIN, (long)policy);};
    constexpr long sched_getscheduler      (pid_t pid) {return syscall(SCHED_GETSCHEDULER, (long)pid);};
    constexpr long sched_rr_get_interval   (pid_t pid, struct __kernel_timespec *interval) {return syscall(SCHED_RR_GET_INTERVAL, (long)pid, (long)interval);};
    constexpr long sched_setaffinity       (pid_t pid, unsigned int len, unsigned long *user_mask_ptr) {return syscall(SCHED_SETAFFINITY, (long)pid, (long)len, (long)user_mask_ptr);};
    constexpr long sched_setattr           (pid_t pid, struct sched_attr *uattr, unsigned int flags) {return syscall(SCHED_SETATTR, (long)pid, (long)uattr, (long)flags);};
    constexpr long sched_setparam          (pid_t pid, struct sched_param *param) {return syscall(SCHED_SETPARAM, (long)pid, (long)param);};
    constexpr long sched_setscheduler      (pid_t pid, int policy, struct sched_param *param) {return syscall(SCHED_SETSCHEDULER, (long)pid, (long)policy, (long)param);};
    constexpr long sched_yield             () {return syscall(SCHED_YIELD);};
    constexpr long seccomp                 (unsigned int op, unsigned int flags, void *uargs) {return syscall(SECCOMP, (long)op, (long)flags, (long)uargs);};
    constexpr long semctl                  (int semid, int semnum, int cmd, unsigned long arg) {return syscall(SEMCTL, (long)semid, (long)semnum, (long)cmd, (long)arg);};
    constexpr long semget                  (key_t key, int nsems, int semflg) {return syscall(SEMGET, (long)key, (long)nsems, (long)semflg);};
    constexpr long semop                   (int semid, struct sembuf *tsops, unsigned nsops) {return syscall(SEMOP, (long)semid, (long)tsops, (long)nsops);};
    constexpr long semtimedop              (int semid, struct sembuf *tsops, unsigned int nsops, const struct __kernel_timespec *timeout) {return syscall(SEMTIMEDOP, (long)semid, (long)tsops, (long)nsops, (long)timeout);};
    constexpr long sendfile64              (int out_fd, int in_fd, loff_t *offset, size_t count) {return syscall(SENDFILE64, (long)out_fd, (long)in_fd, (long)offset, (long)count);};
    constexpr long sendmmsg                (int fd, struct mmsghdr *mmsg, unsigned int vlen, unsigned int flags) {return syscall(SENDMMSG, (long)fd, (long)mmsg, (long)vlen, (long)flags);};
    constexpr long sendmsg                 (int fd, struct user_msghdr *msg, unsigned int flags) {return syscall(SENDMSG, (long)fd, (long)msg, (long)flags);};
    constexpr long sendto                  (int fd, void *buff, size_t len, unsigned int flags, struct sockaddr *addr, int addr_len) {return syscall(SENDTO, (long)fd, (long)buff, (long)len, (long)flags, (long)addr, (long)addr_len);};
    constexpr long setdomainname           (char *name, int len) {return syscall(SETDOMAINNAME, (long)name, (long)len);};
    constexpr long setfsgid                (gid_t gid) {return syscall(SETFSGID, (long)gid);};
    constexpr long setfsuid                (uid_t uid) {return syscall(SETFSUID, (long)uid);};
    constexpr long setgid                  (gid_t gid) {return syscall(SETGID, (long)gid);};
    constexpr long setgroups               (int gidsetsize, gid_t *grouplist) {return syscall(SETGROUPS, (long)gidsetsize, (long)grouplist);};
    constexpr long sethostname             (char *name, int len) {return syscall(SETHOSTNAME, (long)name, (long)len);};
    constexpr long setitimer               (int which, struct __kernel_old_itimerval *value, struct __kernel_old_itimerval *ovalue) {return syscall(SETITIMER, (long)which, (long)value, (long)ovalue);};
    constexpr long set_mempolicy           (int mode, const unsigned long *nmask, unsigned long maxnode) {return syscall(SET_MEMPOLICY, (long)mode, (long)nmask, (long)maxnode);};
    constexpr long set_mempolicy_home_node (unsigned long start, unsigned long len, unsigned long home_node, unsigned long flags) {return syscall(SET_MEMPOLICY_HOME_NODE, (long)start, (long)len, (long)home_node, (long)flags);};
    constexpr long setns                   (int fd, int flags) {return syscall(SETNS, (long)fd, (long)flags);};
    constexpr long setpgid                 (pid_t pid, pid_t pgid) {return syscall(SETPGID, (long)pid, (long)pgid);};
    constexpr long setpriority             (int which, int who, int niceval) {return syscall(SETPRIORITY, (long)which, (long)who, (long)niceval);};
    constexpr long setregid                (gid_t rgid, gid_t egid) {return syscall(SETREGID, (long)rgid, (long)egid);};
    constexpr long setresgid               (gid_t rgid, gid_t egid, gid_t sgid) {return syscall(SETRESGID, (long)rgid, (long)egid, (long)sgid);};
    constexpr long setresuid               (uid_t ruid, uid_t euid, uid_t suid) {return syscall(SETRESUID, (long)ruid, (long)euid, (long)suid);};
    constexpr long setreuid                (uid_t ruid, uid_t euid) {return syscall(SETREUID, (long)ruid, (long)euid);};
    constexpr long setrlimit               (unsigned int resource, struct rlimit *rlim) {return syscall(SETRLIMIT, (long)resource, (long)rlim);};
    constexpr long set_robust_list         (struct robust_list_head *head, size_t len) {return syscall(SET_ROBUST_LIST, (long)head, (long)len);};
    constexpr long setsid                  () {return syscall(SETSID);};
    constexpr long setsockopt              (int fd, int level, int optname, char *optval, int optlen) {return syscall(SETSOCKOPT, (long)fd, (long)level, (long)optname, (long)optval, (long)optlen);};
    constexpr long set_tid_address         (int *tidptr) {return syscall(SET_TID_ADDRESS, (long)tidptr);};
    constexpr long settimeofday            (struct __kernel_old_timeval *tv, struct timezone *tz) {return syscall(SETTIMEOFDAY, (long)tv, (long)tz);};
    constexpr long setuid                  (uid_t uid) {return syscall(SETUID, (long)uid);};
    constexpr long setxattr                (const char *pathname, const char *name, const void *value, size_t size, int flags) {return syscall(SETXATTR, (long)pathname, (long)name, (long)value, (long)size, (long)flags);};
    constexpr long setxattrat              (int dfd, const char *pathname, unsigned int at_flags, const char *name, const struct xattr_args *uargs, size_t usize) {return syscall(SETXATTRAT, (long)dfd, (long)pathname, (long)at_flags, (long)name, (long)uargs, (long)usize);};
    constexpr long shmat                   (int shmid, char *shmaddr, int shmflg) {return syscall(SHMAT, (long)shmid, (long)shmaddr, (long)shmflg);};
    constexpr long shmctl                  (int shmid, int cmd, struct shmid_ds *buf) {return syscall(SHMCTL, (long)shmid, (long)cmd, (long)buf);};
    constexpr long shmdt                   (char *shmaddr) {return syscall(SHMDT, (long)shmaddr);};
    constexpr long shmget                  (key_t key, size_t size, int shmflg) {return syscall(SHMGET, (long)key, (long)size, (long)shmflg);};
    constexpr long shutdown                (int fd, int how) {return syscall(SHUTDOWN, (long)fd, (long)how);};
    constexpr long sigaltstack             (const stack_t *uss, stack_t *uoss) {return syscall(SIGALTSTACK, (long)uss, (long)uoss);};
    constexpr long signalfd4               (int ufd, sigset_t *user_mask, size_t sizemask, int flags) {return syscall(SIGNALFD4, (long)ufd, (long)user_mask, (long)sizemask, (long)flags);};
    constexpr long socket                  (int family, int type, int protocol) {return syscall(SOCKET, (long)family, (long)type, (long)protocol);};
    constexpr long socketpair              (int family, int type, int protocol, int *usockvec) {return syscall(SOCKETPAIR, (long)family, (long)type, (long)protocol, (long)usockvec);};
    constexpr long splice                  (int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, size_t len, unsigned int flags) {return syscall(SPLICE, (long)fd_in, (long)off_in, (long)fd_out, (long)off_out, (long)len, (long)flags);};
    constexpr long statfs                  (const char *pathname, struct statfs *buf) {return syscall(STATFS, (long)pathname, (long)buf);};
    constexpr long statmount               (const struct mnt_id_req *req, struct statmount *buf, size_t bufsize, unsigned int flags) {return syscall(STATMOUNT, (long)req, (long)buf, (long)bufsize, (long)flags);};
    constexpr long statx                   (int dfd, const char *filename, unsigned flags, unsigned int mask, struct statx *buffer) {return syscall(STATX, (long)dfd, (long)filename, (long)flags, (long)mask, (long)buffer);};
    constexpr long swapoff                 (const char *specialfile) {return syscall(SWAPOFF, (long)specialfile);};
    constexpr long swapon                  (const char *specialfile, int swap_flags) {return syscall(SWAPON, (long)specialfile, (long)swap_flags);};
    constexpr long symlinkat               (const char *oldname, int newdfd, const char *newname) {return syscall(SYMLINKAT, (long)oldname, (long)newdfd, (long)newname);};
    constexpr long sync                    () {return syscall(SYNC);};
    constexpr long sync_file_range         (int fd, loff_t offset, loff_t nbytes, unsigned int flags) {return syscall(SYNC_FILE_RANGE, (long)fd, (long)offset, (long)nbytes, (long)flags);};
    constexpr long syncfs                  (int fd) {return syscall(SYNCFS, (long)fd);};
    constexpr long sysinfo                 (struct sysinfo *info) {return syscall(SYSINFO, (long)info);};
    constexpr long syslog                  (int type, char *buf, int len) {return syscall(SYSLOG, (long)type, (long)buf, (long)len);};
    constexpr long tee                     (int fdin, int fdout, size_t len, unsigned int flags) {return syscall(TEE, (long)fdin, (long)fdout, (long)len, (long)flags);};
    constexpr long tgkill                  (pid_t tgid, pid_t pid, int sig) {return syscall(TGKILL, (long)tgid, (long)pid, (long)sig);};
    constexpr long timer_create            (const clockid_t which_clock, struct sigevent *timer_event_spec, timer_t *created_timer_id) {return syscall(TIMER_CREATE, (long)which_clock, (long)timer_event_spec, (long)created_timer_id);};
    constexpr long timer_delete            (timer_t timer_id) {return syscall(TIMER_DELETE, (long)timer_id);};
    constexpr long timerfd_create          (int clockid, int flags) {return syscall(TIMERFD_CREATE, (long)clockid, (long)flags);};
    constexpr long timerfd_gettime         (int ufd, struct __kernel_itimerspec *otmr) {return syscall(TIMERFD_GETTIME, (long)ufd, (long)otmr);};
    constexpr long timerfd_settime         (int ufd, int flags, const struct __kernel_itimerspec *utmr, struct __kernel_itimerspec *otmr) {return syscall(TIMERFD_SETTIME, (long)ufd, (long)flags, (long)utmr, (long)otmr);};
    constexpr long timer_getoverrun        (timer_t timer_id) {return syscall(TIMER_GETOVERRUN, (long)timer_id);};
    constexpr long timer_gettime           (timer_t timer_id, struct __kernel_itimerspec *setting) {return syscall(TIMER_GETTIME, (long)timer_id, (long)setting);};
    constexpr long timer_settime           (timer_t timer_id, int flags, const struct __kernel_itimerspec *new_setting, struct __kernel_itimerspec *old_setting) {return syscall(TIMER_SETTIME, (long)timer_id, (long)flags, (long)new_setting, (long)old_setting);};
    constexpr long times                   (struct tms *tbuf) {return syscall(TIMES, (long)tbuf);};
    constexpr long tkill                   (pid_t pid, int sig) {return syscall(TKILL, (long)pid, (long)sig);};
    constexpr long truncate                (const char *path, long length) {return syscall(TRUNCATE, (long)path, (long)length);};
    constexpr long umask                   (int mask) {return syscall(UMASK, (long)mask);};
    constexpr long umount                  (char *name, int flags) {return syscall(UMOUNT, (long)name, (long)flags);};
    constexpr long unlinkat                (int dfd, const char *pathname, int flag) {return syscall(UNLINKAT, (long)dfd, (long)pathname, (long)flag);};
    constexpr long unshare                 (unsigned long unshare_flags) {return syscall(UNSHARE, (long)unshare_flags);};
    constexpr long userfaultfd             (int flags) {return syscall(USERFAULTFD, (long)flags);};
    constexpr long utimensat               (int dfd, const char *filename, struct __kernel_timespec *utimes, int flags) {return syscall(UTIMENSAT, (long)dfd, (long)filename, (long)utimes, (long)flags);};
    constexpr long vhangup                 () {return syscall(VHANGUP);};
    constexpr long vmsplice                (int fd, const struct iovec *uiov, unsigned long nr_segs, unsigned int flags) {return syscall(VMSPLICE, (long)fd, (long)uiov, (long)nr_segs, (long)flags);};
    constexpr long wait4                   (pid_t upid, int *stat_addr, int options, struct rusage *ru) {return syscall(WAIT4, (long)upid, (long)stat_addr, (long)options, (long)ru);};
    constexpr long waitid                  (int which, pid_t upid, struct siginfo *infop, int options, struct rusage *ru) {return syscall(WAITID, (long)which, (long)upid, (long)infop, (long)options, (long)ru);};
    constexpr long write                   (unsigned int fd, const char *buf, size_t count) {return syscall(WRITE, (long)fd, (long)buf, (long)count);};
    constexpr long writev                  (unsigned long fd, const struct iovec *vec, unsigned long vlen) {return syscall(WRITEV, (long)fd, (long)vec, (long)vlen);};
}