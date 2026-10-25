// #include "error/Error.hh"
// // #include "error/Result.hh"
// #include "type/Alias.hh"

// namespace cmn::syscall::util::path
// {
//     enum class PATH : error::ERROR
//     {
//         NONE = 0,

//         INVALID_INPUT = 1,
//     };


//     /// takes exposed path and returns the expected size when converted to a native path.
//     s64 native_size (const c08 *_exposedPath, const s64 _exposedPathLength);
//     /// takes native path and returns the expected size when converted to an exposed path.
//     s64 exposed_size(const u32 *_nativePath , const s64 _nativePathLength );

//     /// takes exposed path and outputs native path to buffer, should be >= native_path_size().
//     void to_native   (const c08 *_exposedPath, u08 *_bufferNativePath);
//     /// takes native path and outputs exposed path to buffer, should be >= exposed_path_size().
//     void to_exposed  (const u08 *_nativePath , c08 *_bufferExposedPath);



//     // error::Result<s64, PATH> component_count(const c08 *_inputUTF8, const s64 _length, c16 *_outputUTF16);
//     // error::Result<s64, PATH> resolve_components(const c08 *_inputUTF8, const s64 _length, c16 *_outputUTF16);
//     // s64 to_lin(const c08 *_inputUTF16, const s64 _length, c16 *_outputUTF8 );
// }