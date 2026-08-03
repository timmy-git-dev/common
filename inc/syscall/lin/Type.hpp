#pragma once
#include "sys/platform/Arch.hpp"
#include "type/Alias.hpp"

namespace cmn::syscall
{
    typedef u64             AsyncIoContext;
    typedef u08             FileMode;
    typedef i64             FileOffset;
    typedef i32             ProcessId;
    typedef i32             IpcKey;
    typedef i32             TimerId;
    typedef i32             ClockId;
    typedef i32             MessageQueueDescriptor;
    typedef u32             UserId;
    typedef u32             GroupId;
    typedef i64             FileOffset;
    typedef int             KeySerialId;
    typedef i32             ReadWriteFlags;
    typedef u32             QuotaId;

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
    struct FileDescriptorSet
    {
        unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
    };

    struct FileTime
    {
        i64 seconds;
        i64 nanoseconds;
    };

    struct FileStatus
    {
        #ifdef CMN_SYS_ARCH_X64
            u64      device;
            u64      inode;
            u64      linkCount;
            u32      mode;
            u32      user;
            u32      group;
            u32 : 32;
            u64      rawDevice;
            i64      size;
            i64      blockSize;
            i64      blockCount;
            FileTime accessTime;
            FileTime modificationTime;
            FileTime changeTime;
            u64 : 64;
            u64 : 64;
            u64 : 64;
        #elif CMN_SYS_ARCH_ARM
            u64      device;
            u64      inode;
            u32      mode;
            u32      linkCount;
            u32      user;
            u32      group;
            u64      rawDevice;
            u64 : 64;
            i64      size;
            i32      blockSize;
            u32 : 32;
            i64      blockCount;
            FileTime accessTime;
            FileTime modificationTime;
            FileTime changeTime;
            u32 : 32;
            u32 : 32;
        #endif
    };
    // struct stat
    // {
    //     #ifdef CMN_SYS_ARCH_X64
    //         u64    st_dev;
    //         u64    st_ino;
    //         u64    st_nlink;
    //         unsigned int        st_mode;
    //         unsigned int        st_uid;
    //         unsigned int        st_gid;
    //         unsigned int        padding_;
    //         u64    st_rdev;
    //         i64     st_size;
    //         i64     st_blksize;
    //         i64     st_blocks;
    //         timespec            st_atime;
    //         timespec            st_mtime;
    //         timespec            st_ctime;
    //         long                __pad3;
    //         long                __pad4;
    //         long                __pad5;
    //     #elif CMN_SYS_ARCH_ARM
    //         unsigned long       st_dev;
    //         unsigned long       st_ino;
    //         unsigned int        st_mode;
    //         unsigned int        st_nlink;
    //         unsigned int        st_uid;
    //         unsigned int        st_gid;
    //         unsigned long       st_rdev;
    //         unsigned long       __pad1;
    //         long                st_size;
    //         int                 st_blksize;
    //         int                 __pad2;
    //         long                st_blocks;
    //         timespec            st_atime;
    //         timespec            st_mtime;
    //         timespec            st_ctime;
    //         unsigned int        __pad3;
    //         unsigned int        __pad4;
    //     #endif
    // };

    #define EPERM            1 // Operation not permitted.
    #define ENOENT           2 // No such file or directory.
    #define ESRCH            3 // No such process.
    #define EINTR            4 // Interrupted system call.
    #define EIO              5 // I/O error.
    #define ENXIO            6 // No such device or address.
    #define E2BIG            7 // Argument list too long.
    #define ENOEXEC          8 // Exec format error.
    #define EBADF            9 // Bad file number.
    #define ECHILD          10 // No child processes.
    #define EAGAIN          11 // Try again.
    #define ENOMEM          12 // Out of memory.
    #define EACCES          13 // Permission denied.
    #define EFAULT          14 // Bad address.
    #define ENOTBLK         15 // Block device required.
    #define EBUSY           16 // Device or resource busy.
    #define EEXIST          17 // File exists.
    #define EXDEV           18 // Cross-device link.
    #define ENODEV          19 // No such device.
    #define ENOTDIR         20 // Not a directory.
    #define EISDIR          21 // Is a directory.
    #define EINVAL          22 // Invalid argument.
    #define ENFILE          23 // File table overflow.
    #define EMFILE          24 // Too many open files.
    #define ENOTTY          25 // Not a typewriter.
    #define ETXTBSY         26 // Text file busy.
    #define EFBIG           27 // File too large.
    #define ENOSPC          28 // No space left on device.
    #define ESPIPE          29 // Illegal seek.
    #define EROFS           30 // Read-only file system.
    #define EMLINK          31 // Too many links.
    #define EPIPE           32 // Broken pipe.
    #define EDOM            33 // Math argument out of domain of func.
    #define ERANGE          34 // Math result not representable.
    #define EDEADLK         35 // Resource deadlock would occur.
    #define ENAMETOOLONG    36 // File name too long.
    #define ENOLCK          37 // No record locks available.
    #define ENOSYS          38 // Invalid system call number.
    #define ENOTEMPTY       39 // Directory not empty.
    #define ELOOP           40 // Too many symbolic links encountered.
    #define ENOMSG          42 // No message of desired type.
    #define EIDRM           43 // Identifier removed.
    #define ECHRNG          44 // Channel number out of range.
    #define EL2NSYNC        45 // Level 2 not synchronized.
    #define EL3HLT          46 // Level 3 halted.
    #define EL3RST          47 // Level 3 reset.
    #define ELNRNG          48 // Link number out of range.
    #define EUNATCH         49 // Protocol driver not attached.
    #define ENOCSI          50 // No CSI structure available.
    #define EL2HLT          51 // Level 2 halted.
    #define EBADE           52 // Invalid exchange.
    #define EBADR           53 // Invalid request descriptor.
    #define EXFULL          54 // Exchange full.
    #define ENOANO          55 // No anode.
    #define EBADRQC         56 // Invalid request code.
    #define EBADSLT         57 // Invalid slot.
    #define EBFONT          59 // Bad font file format.
    #define ENOSTR          60 // Device not a stream.
    #define ENODATA         61 // No data available.
    #define ETIME           62 // Timer expired.
    #define ENOSR           63 // Out of streams resources.
    #define ENONET          64 // Machine is not on the network.
    #define ENOPKG          65 // Package not installed.
    #define EREMOTE         66 // Object is remote.
    #define ENOLINK         67 // Link has been severed.
    #define EADV            68 // Advertise error.
    #define ESRMNT          69 // Srmount error.
    #define ECOMM           70 // Communication error on send.
    #define EPROTO          71 // Protocol error.
    #define EMULTIHOP       72 // Multihop attempted.
    #define EDOTDOT         73 // RFS specific error.
    #define EBADMSG         74 // Not a data message.
    #define EOVERFLOW       75 // Value too large for defined data type.
    #define ENOTUNIQ        76 // Name not unique on network.
    #define EBADFD          77 // File descriptor in bad state.
    #define EREMCHG         78 // Remote address changed.
    #define ELIBACC         79 // Can not access a needed shared library.
    #define ELIBBAD         80 // Accessing a corrupted shared library.
    #define ELIBSCN         81 // .lib section in a.out corrupted.
    #define ELIBMAX         82 // Attempting to link in too many shared libraries.
    #define ELIBEXEC        83 // Cannot exec a shared library directly.
    #define EILSEQ          84 // Illegal byte sequence.
    #define ERESTART        85 // Interrupted system call should be restarted.
    #define ESTRPIPE        86 // Streams pipe error.
    #define EUSERS          87 // Too many users.
    #define ENOTSOCK        88 // Socket operation on non-socket.
    #define EDESTADDRREQ    89 // Destination address required.
    #define EMSGSIZE        90 // Message too long.
    #define EPROTOTYPE      91 // Protocol wrong type for socket.
    #define ENOPROTOOPT     92 // Protocol not available.
    #define EPROTONOSUPPORT 93 // Protocol not supported.
    #define ESOCKTNOSUPPORT 94 // Socket type not supported.
    #define EOPNOTSUPP      95 // Operation not supported on transport endpoint.
    #define EPFNOSUPPORT    96 // Protocol family not supported.
    #define EAFNOSUPPORT    97 // Address family not supported by protocol.
    #define EADDRINUSE      98 // Address already in use.
    #define EADDRNOTAVAIL   99 // Cannot assign requested address.
    #define ENETDOWN        100 // Network is down.
    #define ENETUNREACH     101 // Network is unreachable.
    #define ENETRESET       102 // Network dropped connection because of reset.
    #define ECONNABORTED    103 // Software caused connection abort.
    #define ECONNRESET      104 // Connection reset by peer.
    #define ENOBUFS         105 // No buffer space available.
    #define EISCONN         106 // Transport endpoint is already connected.
    #define ENOTCONN        107 // Transport endpoint is not connected.
    #define ESHUTDOWN       108 // Cannot send after transport endpoint shutdown.
    #define ETOOMANYREFS    109 // Too many references: cannot splice.
    #define ETIMEDOUT       110 // Connection timed out.
    #define ECONNREFUSED    111 // Connection refused.
    #define EHOSTDOWN       112 // Host is down.
    #define EHOSTUNREACH    113 // No route to host.
    #define EALREADY        114 // Operation already in progress.
    #define EINPROGRESS     115 // Operation now in progress.
    #define ESTALE          116 // Stale file handle.
    #define EUCLEAN         117 // Structure needs cleaning.
    #define ENOTNAM         118 // Not a XENIX named type file.
    #define ENAVAIL         119 // No XENIX semaphores available.
    #define EISNAM          120 // Is a named type file.
    #define EREMOTEIO       121 // Remote I/O error.
    #define EDQUOT          122 // Quota exceeded.
    #define ENOMEDIUM       123 // No medium found.
    #define EMEDIUMTYPE     124 // Wrong medium type.
    #define ECANCELED       125 // Operation Canceled.
    #define ENOKEY          126 // Required key not available.
    #define EKEYEXPIRED     127 // Key has expired.
    #define EKEYREVOKED     128 // Key has been revoked.
    #define EKEYREJECTED    129 // Key was rejected by service.
    #define EOWNERDEAD      130 // Owner died.
    #define ENOTRECOVERABLE 131 // State not recoverable.
    #define ERFKILL         132 // Operation not possible due to RF-kill.
    #define EHWPOISON       133 // Memory page has hardware error.

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