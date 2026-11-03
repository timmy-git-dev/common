#pragma once
#include "error/result.hh"
#include "syscall/uni/io-error.hh"

#if CMN_SYS_OS_LIN
    #include "syscall/lin/flag.hh"
#elif CMN_SYS_OS_MAC
    #include "syscall/mac/flag.hh"
#elif CMN_SYS_OS_WIN
    #include "syscall/win/flag.hh"
#endif

namespace cmn::syscall::uni::io
{
    // TODO: Maybe change this to a struct or something? Or maybe put usings in more places, not sure what kind of practice I should use yet.
    using Handle = s64;

    // TODO: Maybe set values based on returned values from exists for performance.
    enum class Type
    {
        #if CMN_SYS_OS_LIN

            /// A regular file.
            FILE             = S_IFREG,
            /// A directory/folder.
            DIRECTORY        = S_IFDIR,
            /// A symbolic-link pointing to some other path.
            SYMLINK          = S_IFLNK,

            /// A domain-socket for local communication via filesystem syscalls.
            SOCKET           = S_IFSOCK,

            /// A First-In-First-Out named pipe for inter-process communication.
            FIFO             = S_IFIFO,

            /// A block-device for fixed-size storage/transfer such as /dev/sda.
            BLOCK_DEVICE     = S_IFBLK,
            /// A character-device for communication with hardware like keyboards.
            CHARACTER_DEVICE = S_IFCHR,

            /// A whiteout file, indicating the file has been deleted in a union file system.
            WHITEOUT         = -1,

        #elif CMN_SYS_OS_MAC

            /// A regular file.
            FILE             = S_IFREG,
            /// A directory/folder.
            DIRECTORY        = S_IFDIR,
            /// A symbolic-link pointing to some other path.
            SYMLINK          = S_IFLNK,

            /// A domain-socket for local communication via filesystem syscalls.
            SOCKET           = S_IFSOCK,

            /// A First-In-First-Out named pipe for inter-process communication.
            FIFO             = S_IFIFO,

            /// A block-device for fixed-size storage/transfer such as /dev/sda.
            BLOCK_DEVICE     = S_IFBLK,
            /// A character-device for communication with hardware like keyboards.
            CHARACTER_DEVICE = S_IFCHR,

            /// A whiteout file, indicating the file has been deleted in a union file system.
            WHITEOUT         = S_IFWHT,

        #elif CMN_SYS_OS_WIN

            /// A domain-socket for local communication via filesystem syscalls.
            SOCKET           = -1,
            /// A symbolic-link pointing to some other path.
            // SYMLINK          = ???,
            /// A regular file.
            FILE             = 0,
            /// A directory/folder.
            DIRECTORY        = 16,
            /// A First-In-First-Out named pipe for inter-process communication.
            FIFO             = -1,
            /// A block-device for fixed-size storage/transfer such as /dev/sda.
            BLOCK_DEVICE     = -1,
            /// A character-device for communication with hardware like keyboards.
            CHARACTER_DEVICE = -1,

        #endif
    };

    /// The time for filesystem-objects since an epoch of 0000/00/00-00:00.
    struct Time
    {
        /// The seconds since 0000/00/00-00:00.
        i64 seconds;
        /// The floating-point part of the second, likely between [0, 1e9).
        u64 nanoseconds;
    };

    /// The info of a filesystem-object.
    struct Info
    {
        /// The type; file, directory, etc, of object at the given path.
        Type    type;

        /// The byte-length of the object's contents, such as EOF or symlink pathname length.
        /// Note that other than reporting storage, this likely shouldn't be used as it is unreliable across platforms and filesystems.
        s64     length;
        /// The total bytes allocated to the object storage.
        /// Note that other than reporting storage, this likely shouldn't be used as it is unreliable across platforms and filesystems.
        s64     allocated;

        /// The amount of hard-links pointing to this object.
        s64     linkCount;

        /// Unsure on proper sizes here:
        /// The ID of the object within the filesystem.
        u64     id;
        /// The ID of the filesystem containing the object.
        u64     filesystemID;

        /// The time at which the object was created.
        Time    created;
        /// The most recent time at which the object was accessed.
        Time    accessed;
        /// The most recent time at which the object's contents or entries was modified.
        Time    edited;
        /// The most recent time at which the object's metadata was changed.
        Time    updated;
    };

    /// Copies the current working directory into `_outputBuffer` and returns the length.
    cmn::error::Result<s64 , Cwd  > cwd  (c08 *_outputBuffer, const s64 _capacity);
    /// Obtains information on a given filesystem-object given it's string-path.
    cmn::error::Result<Info, Query> query(const c08 *_path, const s64 _length);
    /// Obtains information on a given filesystem-object given it's handle.
    cmn::error::Result<Info, Query> query(const Handle _object); // TODO: Might provide more info than query-by-path?

    namespace file
    {
        /// Creates and opens a file at a given path, and returns the handle.
        /// Overwrites the file if one already exists.
        /// Upon error, a null handle is returned.
        cmn::error::Result<Handle, Create > create (const c08 *_path, const s64 _length);
        /// Removes a file at a given path.
        cmn::error::Result<void  , Remove > remove (const c08 *_path, const s64 _length);
        /// Opens a file at a given path, and returns the handle.
        /// Upon error, a null handle is returned.
        cmn::error::Result<Handle, Open   > open   (const c08 *_path, const s64 _length);
        /// Closes a file from a given handle.
        cmn::error::Result<void  , Close  > close  (const Handle _file);

        /// Copies up to a specified amount of bytes from the _file starting from _offset, and returns the amount of copied bytes.
        /// Upon error, a length of 0 is returned and _outputBuffer is untouched.
        cmn::error::Result<s64   , Read   > read   (const Handle _file, c08 *_outputBuffer, const s64 _capacity, const s64 _offset);
        /// Writes a specified amount of bytes into the _file starting from _offset.
        /// Upon error, will the file be guaranteed not written to on each OS?
        cmn::error::Result<void  , Write  > write  (const Handle _file, const c08 *_inputBuffer, const s64 _length, const s64 _offset);
    }
    namespace dir
    {
        /// Creates and opens a directory at a given path, and returns the handle.
        /// Overwrites the directory if one already exists.
        /// Upon error, a null handle is returned.
        cmn::error::Result<Handle, Create > create (const c08 *_path, const s64 _length);
        /// Removes a directory at a given path.
        cmn::error::Result<void  , Remove > remove (const c08 *_path, const s64 _length);
        /// Opens a directory at a given path, and returns the handle.
        /// Upon error, a null handle is returned.
        cmn::error::Result<Handle, Open   > open   (const c08 *_path, const s64 _length);
        /// Closes a directory from a given handle.
        cmn::error::Result<void  , Close  > close  (const Handle _file);

        /// TODO: Unsure about how to do this yet, implement when decided lol.
        cmn::error::Result<s64, Entries> entries();
    }
}