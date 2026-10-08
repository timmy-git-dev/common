#include "error/Result.hh"
namespace cmn::syscall
{
    // TODO: Use different enums values based on OS errnos (same abi).
    enum class MEMORY : cmn::error::ERROR
    {
        NONE = 0,
        // EACCES A file descriptor refers to a non-regular file.  Or a file
        //         mapping was requested, but fd is not open for reading.  Or
        //         MAP_SHARED was requested and PROT_WRITE is set, but fd is
        //         not open in read/write (O_RDWR) mode.  Or PROT_WRITE is
        //         set, but the file is append-only.


        // EAGAIN The file has been locked, or too much memory has been
        //         locked (see setrlimit(2)).

        // EBADF  fd is not a valid file descriptor (and MAP_ANONYMOUS was
        //         not set).

        // EEXIST MAP_FIXED_NOREPLACE was specified in flags, and the range
        //         covered by addr and length clashes with an existing
        //         mapping.

        // EINVAL We don't like addr, length, or offset (e.g., they are too
        //         large, or not aligned on a page boundary).

        // EINVAL (since Linux 2.6.12) length was 0.

        // EINVAL flags contained none of MAP_PRIVATE, MAP_SHARED, or
        //         MAP_SHARED_VALIDATE.

        // ENFILE The system-wide limit on the total number of open files has
        //         been reached.

        // ENODEV The underlying filesystem of the specified file does not
        //         support memory mapping.

        // ENOMEM No memory is available.

        // ENOMEM The process's maximum number of mappings would have been
        //         exceeded.  This error can also occur for munmap(), when
        //         unmapping a region in the middle of an existing mapping,
        //         since this results in two smaller mappings on either side
        //         of the region being unmapped.

        // ENOMEM (since Linux 4.7) The process's RLIMIT_DATA limit,
        //         described in getrlimit(2), would have been exceeded.

        // ENOMEM We don't like addr, because it exceeds the virtual address
        //         space of the CPU.

        // EOVERFLOW
        //         On 32-bit architecture together with the large file
        //         extension (i.e., using 64-bit off_t): the number of pages
        //         used for length plus number of pages used for offset would
        //         overflow unsigned long (32 bits).

        // EPERM  The prot argument asks for PROT_EXEC but the mapped area
        //         belongs to a file on a filesystem that was mounted no-exec.

        // EPERM  The operation was prevented by a file seal; see fcntl(2).

        // EPERM  The MAP_HUGETLB flag was specified, but the caller was not
        //         privileged (did not have the CAP_IPC_LOCK capability) and
        //         is not a member of the hugetlb_shm_group group; see the
        //         description of /proc/sys/vm/hugetlb_shm_group in
        //         proc_sys_vm(5).

        // ETXTBSY
        //         MAP_DENYWRITE was set but the object specified by fd is
        //         open for writing.

        // Use of a mapped region can result in these signals:

        // SIGSEGV
        //         Attempted write into a region mapped as read-only.

        // SIGBUS Attempted access to a page of the buffer that lies beyond
        //         the end of the mapped file.  For an explanation of the
        //         treatment of the bytes in the page that corresponds to the
        //         end of a mapped file that is not a multiple of the page
        //         size, see NOTES.
    };

    /// mmap
    cmn::error::Result<void*, MEMORY> allocate  (s64 _size);
    /// munmap
    cmn::error::Result<void , MEMORY> deallocate(s64 _size, void *_address);
}