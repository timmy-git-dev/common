#pragma once
#include "error/Result.hh"
#include "syscall/uni/IO_Error.hh"

namespace cmn::syscall::uni::io
{
    // TODO: Maybe change this to a struct or something? Or maybe put usings in more places, not sure what kind of practice I should use yet.
    using Handle = s64;

    struct Path
    {
        s64 length = 0;
        c08 string[1024];
    };

    // TODO: Maybe set values based on returned values from exists for performance.
    enum class Type
    {
        NONE      = 0,
        UNKNOWN   = 1,
        FILE      = 2,
        DIRECTORY = 3,
        SYMLINK   = 4,
    };

    /// Obtains the current working directory, copies it into the specified _outputBuffer up to _capcity, and returns the length.
    /// If _capacity is < the length of the current working directory, the output buffer is only set up to _capacity.
    /// Upon error, _outputBuffer is untouched and the returned length is 0.
    cmn::error::Result<c08*, Cwd   > cwd   ();
    /// Determines if and what type of filesystem-object exists at a given path.
    /// Upon error, TYPE::NONE is returned.
    cmn::error::Result<Type, Exists> exists(const c08 *_path, const s64 _length);
    /// Obtains information on a given filesystem-object.
    cmn::error::Result<s64 , Query > query (const Handle _object); // TODO: Add info for query.

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