#pragma once
#include "error/Error.hh"
namespace cmn::syscall
{
    enum class ERRNO : error::ERROR
    {
        /// No error occurred.
        NONE            =  0,
        /// Operation was rejected because the caller lacks permission.
        EPERM           =  1,
        /// The requested file or directory does not exist.
        ENOENT          =  2,
        /// The requested process does not exist.
        ESRCH           =  3,
        /// The system call was interrupted by a signal.
        EINTR           =  4,
        /// A low-level input/output operation failed.
        EIO             =  5,
        /// The requested device or address does not exist.
        ENXIO           =  6,
        /// The process argument list exceeds the supported size.
        E2BIG           =  7,
        /// The executable has an invalid or unsupported format.
        ENOEXEC         =  8,
        /// The supplied file descriptor is invalid.
        EBADF           =  9,
        /// No matching child process exists.
        ECHILD          = 10,
        /// The operation cannot proceed now and may succeed if retried.
        EAGAIN          = 11,
        /// Insufficient memory is available to complete the operation.
        ENOMEM          = 12,
        /// Access to the requested resource was denied.
        EACCES          = 13,
        /// An invalid or inaccessible memory address was supplied.
        EFAULT          = 14,
        /// A block device was required for this operation.
        ENOTBLK         = 15,
        /// The requested device or resource is currently busy.
        EBUSY           = 16,
        /// The requested file or object already exists.
        EEXIST          = 17,
        /// The operation cannot cross filesystem or device boundaries.
        EXDEV           = 18,
        /// The requested device does not exist.
        ENODEV          = 19,
        /// A path component expected to be a directory is not one.
        ENOTDIR         = 20,
        /// The operation expected a non-directory object but found a directory.
        EISDIR          = 21,
        /// One or more supplied arguments are invalid.
        EINVAL          = 22,
        /// The system-wide limit for open files has been reached.
        ENFILE          = 23,
        /// The process has reached its limit for open file descriptors.
        EMFILE          = 24,
        /// The requested terminal operation was performed on a non-terminal.
        ENOTTY          = 25,
        /// The executable file is currently busy.
        ETXTBSY         = 26,
        /// The file exceeds the maximum supported size.
        EFBIG           = 27,
        /// The target device has insufficient free storage space.
        ENOSPC          = 28,
        /// Seeking is unsupported for this file or stream.
        ESPIPE          = 29,
        /// Modification was attempted on a read-only filesystem.
        EROFS           = 30,
        /// The maximum number of filesystem links has been exceeded.
        EMLINK          = 31,
        /// A pipe was written after its reading endpoint was closed.
        EPIPE           = 32,
        /// A mathematical argument lies outside the function's valid domain.
        EDOM            = 33,
        /// A mathematical result lies outside the representable range.
        ERANGE          = 34,
        /// The operation would cause or encounter a resource deadlock.
        EDEADLK         = 35,
        /// A filename or pathname exceeds the supported length.
        ENAMETOOLONG    = 36,
        /// No record-lock resources are currently available.
        ENOLCK          = 37,
        /// The requested system call or operation is not implemented.
        ENOSYS          = 38,
        /// The directory cannot be removed because it is not empty.
        ENOTEMPTY       = 39,
        /// Too many symbolic links were followed while resolving a path.
        ELOOP           = 40,
        /// No message matching the requested type exists.
        ENOMSG          = 42,
        /// The referenced IPC identifier has been removed.
        EIDRM           = 43,
        /// The specified channel number is outside the valid range.
        ECHRNG          = 44,
        /// Level-2 communication is not synchronized.
        EL2NSYNC        = 45,
        /// Level-3 communication has halted.
        EL3HLT          = 46,
        /// Level-3 communication has been reset.
        EL3RST          = 47,
        /// The specified link number is outside the valid range.
        ELNRNG          = 48,
        /// The required protocol driver is not attached.
        EUNATCH         = 49,
        /// No CSI structure is currently available.
        ENOCSI          = 50,
        /// Level-2 communication has halted.
        EL2HLT          = 51,
        /// An invalid exchange operation was requested.
        EBADE           = 52,
        /// The supplied request descriptor is invalid.
        EBADR           = 53,
        /// The exchange has reached its capacity.
        EXFULL          = 54,
        /// The requested anode does not exist.
        ENOANO          = 55,
        /// The supplied request code is invalid.
        EBADRQC         = 56,
        /// The specified slot is invalid.
        EBADSLT         = 57,
        /// The font file has an invalid or unsupported format.
        EBFONT          = 59,
        /// The specified device is not a STREAMS device.
        ENOSTR          = 60,
        /// No data is currently available.
        ENODATA         = 61,
        /// The requested timer has expired.
        ETIME           = 62,
        /// STREAMS resources have been exhausted.
        ENOSR           = 63,
        /// The machine is currently disconnected from the network.
        ENONET          = 64,
        /// A required software package is not installed.
        ENOPKG          = 65,
        /// The requested object resides on a remote system.
        EREMOTE         = 66,
        /// The communication link has been severed.
        ENOLINK         = 67,
        /// An error occurred while advertising a network resource.
        EADV            = 68,
        /// An error occurred during a remote mount operation.
        ESRMNT          = 69,
        /// A communication failure occurred while sending data.
        ECOMM           = 70,
        /// A protocol-level error occurred.
        EPROTO          = 71,
        /// An unsupported multihop operation was attempted.
        EMULTIHOP       = 72,
        /// A legacy Remote File Sharing protocol error occurred.
        EDOTDOT         = 73,
        /// The received message has an invalid format or type.
        EBADMSG         = 74,
        /// A value exceeds the range of its destination data type.
        EOVERFLOW       = 75,
        /// The specified network name is not unique.
        ENOTUNIQ        = 76,
        /// The file descriptor is in an invalid state for the operation.
        EBADFD          = 77,
        /// The remote endpoint's address has changed.
        EREMCHG         = 78,
        /// A required shared library could not be accessed.
        ELIBACC         = 79,
        /// A required shared library is corrupted or invalid.
        ELIBBAD         = 80,
        /// A shared-library section in the executable is corrupted.
        ELIBSCN         = 81,
        /// Too many shared libraries are being linked.
        ELIBMAX         = 82,
        /// A shared library cannot be executed directly.
        ELIBEXEC        = 83,
        /// The input contains an invalid byte or character sequence.
        EILSEQ          = 84,
        /// The interrupted system call should be restarted.
        ERESTART        = 85,
        /// A STREAMS pipe operation failed.
        ESTRPIPE        = 86,
        /// The system's supported user limit has been exceeded.
        EUSERS          = 87,
        /// A socket operation was attempted on a non-socket object.
        ENOTSOCK        = 88,
        /// The operation requires a destination address.
        EDESTADDRREQ    = 89,
        /// The message exceeds the supported size.
        EMSGSIZE        = 90,
        /// The socket uses an incompatible protocol type.
        EPROTOTYPE      = 91,
        /// The requested protocol option is unavailable.
        ENOPROTOOPT     = 92,
        /// The requested protocol is not supported.
        EPROTONOSUPPORT = 93,
        /// The requested socket type is not supported.
        ESOCKTNOSUPPORT = 94,
        /// The requested operation is unsupported by this endpoint.
        EOPNOTSUPP      = 95,
        /// The requested protocol family is not supported.
        EPFNOSUPPORT    = 96,
        /// The requested address family is unsupported by the protocol.
        EAFNOSUPPORT    = 97,
        /// The requested network address is already in use.
        EADDRINUSE      = 98,
        /// The requested network address cannot be assigned locally.
        EADDRNOTAVAIL   = 99,
        /// The network is currently unavailable.
        ENETDOWN        = 100,
        /// The destination network cannot be reached.
        ENETUNREACH     = 101,
        /// The network connection was lost because of a reset.
        ENETRESET       = 102,
        /// The connection was aborted by the local system.
        ECONNABORTED    = 103,
        /// The connection was forcibly reset by the remote endpoint.
        ECONNRESET      = 104,
        /// No network buffer space is currently available.
        ENOBUFS         = 105,
        /// The socket or endpoint is already connected.
        EISCONN         = 106,
        /// The socket or endpoint is not currently connected.
        ENOTCONN        = 107,
        /// Data cannot be sent after the connection has been shut down.
        ESHUTDOWN       = 108,
        /// The object has too many outstanding references.
        ETOOMANYREFS    = 109,
        /// The connection did not complete within the allowed time.
        ETIMEDOUT       = 110,
        /// The remote endpoint refused the connection.
        ECONNREFUSED    = 111,
        /// The destination host is currently unavailable.
        EHOSTDOWN       = 112,
        /// No route to the destination host is available.
        EHOSTUNREACH    = 113,
        /// The requested operation is already being performed.
        EALREADY        = 114,
        /// The requested asynchronous operation has started but is incomplete.
        EINPROGRESS     = 115,
        /// The referenced filesystem handle is no longer valid.
        ESTALE          = 116,
        /// A filesystem structure is inconsistent and requires repair.
        EUCLEAN         = 117,
        /// The object is not a legacy XENIX named-type file.
        ENOTNAM         = 118,
        /// No legacy XENIX semaphore resources are available.
        ENAVAIL         = 119,
        /// The object is a legacy XENIX named-type file.
        EISNAM          = 120,
        /// An input/output operation on a remote resource failed.
        EREMOTEIO       = 121,
        /// The user's filesystem storage quota has been exceeded.
        EDQUOT          = 122,
        /// No removable medium is present in the device.
        ENOMEDIUM       = 123,
        /// The inserted medium has an unsupported or incorrect type.
        EMEDIUMTYPE     = 124,
        /// The operation was explicitly canceled before completion.
        ECANCELED       = 125,
        /// A required cryptographic or authentication key is unavailable.
        ENOKEY          = 126,
        /// The required key has expired.
        EKEYEXPIRED     = 127,
        /// The required key has been revoked.
        EKEYREVOKED     = 128,
        /// The required key was rejected by the service.
        EKEYREJECTED    = 129,
        /// The previous owner of a robust synchronization object terminated.
        EOWNERDEAD      = 130,
        /// The protected state cannot be recovered after owner failure.
        ENOTRECOVERABLE = 131,
        /// The operation is blocked because the radio transmitter is disabled.
        ERFKILL         = 132,
        /// A hardware failure was detected in the referenced memory page.
        EHWPOISON       = 133
    };
}