#pragma once
#include "syscall/lin/Type.hpp"

namespace cmn::syscall
{
    /// accept : Removes one pending connection from a listening socket and returns a new connected socket descriptor.
    /// _fileDescriptor : Identifies the listening socket.
    /// _peerSocketAddress : Receives the connected peer's address, or may be null.
    /// _peerAddressLength : Supplies the address buffer size and receives the actual peer address size.
    i64 accept_connection(i32 _fileDescriptor, SocketAddress* _peerSocketAddress, i32* _peerAddressLength);

    /// accept4 : Accepts a pending socket connection while atomically applying flags to the returned socket.
    /// _fileDescriptor : Identifies the listening socket.
    /// _peerSocketAddress : Receives the connected peer's address, or may be null.
    /// _peerAddressLength : Supplies the address buffer size and receives the actual peer address size.
    /// _flags : Controls properties such as nonblocking and close-on-exec.
    i64 accept_connection_with_flags(i32 _fileDescriptor, SocketAddress* _peerSocketAddress, i32* _peerAddressLength, i32 _flags);

    /// acct : Enables process accounting to a specified file, or disables it when given a null path.
    /// _fileName : Specifies the accounting output file, or null to disable accounting.
    i64 configure_process_accounting(const c08* _fileName);

    /// add_key : Creates or updates a kernel key and links it into the specified keyring.
    /// _type : Specifies the key type.
    /// _description : Identifies the key within its type.
    /// _payload : Contains the key's type-specific data.
    /// _payloadLength : Specifies the payload size in bytes.
    /// _keyringId : Identifies the destination keyring.
    i64 add_key_to_keyring(const c08* _type, const c08* _description, const void* _payload, s64 _payloadLength, i32 _keyringId);

    /// adjtimex : Reads or modifies the kernel's CLOCK_REALTIME synchronization and adjustment parameters.
    /// _timeAdjustment : Supplies requested adjustments and receives the resulting clock state.
    i64 adjust_system_clock(KernelTimeAdjustment* _timeAdjustment);

    /// bind : Assigns a local address to a socket.
    /// _fileDescriptor : Identifies the socket.
    /// _socketAddress : Specifies the local address to assign.
    /// _addressLength : Specifies the address structure size in bytes.
    i64 bind_socket(i32 _fileDescriptor, SocketAddress* _socketAddress, i32 _addressLength);

    /// bpf : Executes a command against Linux eBPF programs, maps, links, or other BPF objects.
    /// _command : Selects the BPF operation to perform.
    /// _attributes : Supplies command-specific arguments and receives command-specific results.
    /// _size : Specifies the size of the attribute structure supplied.
    i64 execute_bpf_command(i32 _command, union bpf_attr* _attributes, u32 _size);

    /// brk : OBSOLETE
    i64 brk(u64 _programBreak);

    /// cachestat : Queries page-cache statistics for a byte range of a file.
    /// _fileDescriptor : Identifies the file to inspect.
    /// _cacheStatusRange : Specifies the file byte range to inspect.
    /// _cacheStatus : Receives page-cache statistics for the requested range.
    /// _flags : Reserved for future use and currently must be zero.
    i64 query_page_cache(u32 _fileDescriptor, CacheStatisticsRange* _cacheStatusRange, CacheStatistics* _cacheStatus, u32 _flags);

    /// capget : Retrieves Linux capability sets for the thread identified by the capability header.
    /// _capabilityHeader : Specifies the capability ABI version and target thread.
    /// _capabilityData : Receives the effective, permitted, and inheritable capability sets.
    i64 get_thread_capabilities(cap_user_header_t _capabilityHeader, cap_user_data_t _capabilityData);

    /// capset : Replaces Linux capability sets for the thread identified by the capability header.
    /// _capabilityHeader : Specifies the capability ABI version and target thread.
    /// _capabilityData : Supplies the effective, permitted, and inheritable capability sets.
    i64 set_thread_capabilities(cap_user_header_t _capabilityHeader, const cap_user_data_t _capabilityData);

    /// chdir : Changes the calling process's current working directory.
    /// _fileName : Specifies the new working directory.
    i64 change_working_directory(const c08* _fileName);

    /// chroot : Changes the root directory used when resolving absolute paths for the calling process.
    /// _fileName : Specifies the new root directory.
    i64 change_root_directory(const c08* _fileName);

    /// clock_adjtime : Reads or modifies synchronization and adjustment parameters for a selected kernel clock.
    /// _clockId : Identifies the clock to adjust.
    /// _timeAdjustment : Supplies requested adjustments and receives the resulting clock state.
    i64 adjust_clock(const i32 _clockId, KernelTimeAdjustment* _timeAdjustment);

    /// clock_getres : Retrieves the resolution of a selected clock.
    /// _clockId : Identifies the clock.
    /// _resolution : Receives the clock's resolution.
    i64 get_clock_resolution(const i32 _clockId, KernelTimeSpecification* _resolution);

    /// clock_gettime : Retrieves the current value of a selected clock.
    /// _clockId : Identifies the clock.
    /// _time : Receives the current clock value.
    i64 get_clock_time(const i32 _clockId, KernelTimeSpecification* _time);

    /// clock_nanosleep : Suspends the calling thread relative to or until a time measured by a selected clock.
    /// _clockId : Identifies the clock used for the sleep.
    /// _flags : Selects relative or absolute-time behavior.
    /// _requestedTime : Specifies the requested duration or absolute wake time.
    /// _remainingTime : Receives the unslept duration after interruption for relative sleeps.
    i64 sleep_on_clock(const i32 _clockId, i32 _flags, const KernelTimeSpecification* _requestedTime, KernelTimeSpecification* _remainingTime);

    /// clock_settime : Sets the current value of a settable kernel clock.
    /// _clockId : Identifies the clock to modify.
    /// _time : Specifies the new clock value.
    i64 set_clock_time(const i32 _clockId, const KernelTimeSpecification* _time);

    /// clone : Creates a child task while controlling which execution resources are shared with the caller.
    /// _cloneFlags : Controls resource sharing, task behavior, and the child termination signal.
    /// _newStackPointer : Specifies the child's initial stack pointer.
    /// _parentThreadId : Optionally receives the child thread ID in parent memory.
    /// _threadLocalStorage : Supplies the child's thread-local-storage value when requested.
    /// _childThreadId : Optionally stores or clears the child thread ID in child memory.
    i64 create_child_task(u64 _cloneFlags, u64 _newStackPointer, i32* _parentThreadId, u64 _threadLocalStorage, i32* _childThreadId);

    /// clone3 : Creates a child task using an extensible argument structure with capabilities beyond clone().
    /// _arguments : Specifies resource sharing, stack, IDs, cgroup placement, and other child configuration.
    /// _size : Specifies the size of the supplied argument structure.
    i64 create_child_task_with_options(CloneArguments* _arguments, s64 _size);

    /// close : Releases a file descriptor from the calling process.
    /// _fileDescriptor : Identifies the descriptor to close.
    i64 close_file_descriptor(u32 _fileDescriptor);

    /// close_range : Closes, marks close-on-exec, or unshares a contiguous range of file descriptors according to flags.
    /// _firstFileDescriptor : Specifies the first descriptor in the inclusive range.
    /// _maximumFileDescriptor : Specifies the last descriptor in the inclusive range.
    /// _flags : Controls close-on-exec and descriptor-table unsharing behavior.
    i64 close_file_descriptor_range(u32 _firstFileDescriptor, u32 _maximumFileDescriptor, u32 _flags);

    /// connect : Associates a socket with a peer address, initiating a connection where required by the socket type.
    /// _fileDescriptor : Identifies the socket.
    /// _serverAddress : Specifies the peer address.
    /// _addressLength : Specifies the address structure size in bytes.
    i64 connect_socket(i32 _fileDescriptor, SocketAddress* _serverAddress, i32 _addressLength);

    /// copy_file_range : Copies file data between descriptors inside the kernel without routing the data through userspace.
    /// _inputFileDescriptor : Identifies the source file.
    /// _inputOffset : Optionally specifies and updates the source offset instead of changing the descriptor's file position.
    /// _outputFileDescriptor : Identifies the destination file.
    /// _outputOffset : Optionally specifies and updates the destination offset instead of changing the descriptor's file position.
    /// _length : Specifies the maximum number of bytes to copy.
    /// _flags : Reserved for future use and currently must be zero.
    i64 copy_file_data(i32 _inputFileDescriptor, i64* _inputOffset, i32 _outputFileDescriptor, i64* _outputOffset, s64 _length, u32 _flags);

    /// delete_module : Unloads a loaded kernel module.
    /// _moduleName : Specifies the module to unload.
    /// _flags : Controls unloading behavior such as forced or nonblocking removal.
    i64 unload_kernel_module(const c08* _moduleName, u32 _flags);

    /// dup : Creates a copy of a file descriptor using the lowest available descriptor number.
    /// _fileDescriptor : Identifies the descriptor to duplicate.
    i64 duplicate_file_descriptor(u32 _fileDescriptor);

    /// dup3 : Duplicates a file descriptor into a specific descriptor number while optionally applying flags.
    /// _oldFileDescriptor : Identifies the descriptor to duplicate.
    /// _newFileDescriptor : Specifies the descriptor number to replace.
    /// _flags : Controls properties such as close-on-exec.
    i64 duplicate_file_descriptor_to(u32 _oldFileDescriptor, u32 _newFileDescriptor, i32 _flags);

    /// epoll_create1 : Creates a new epoll instance and returns its file descriptor.
    /// _flags : Controls properties of the returned epoll descriptor.
    i64 create_epoll(i32 _flags);

    /// epoll_ctl : Adds, modifies, or removes a file descriptor from an epoll instance.
    /// _epollFileDescriptor : Identifies the epoll instance.
    /// _operation : Selects whether to add, modify, or remove the descriptor.
    /// _fileDescriptor : Identifies the descriptor being monitored.
    /// _event : Specifies the events and user data associated with the descriptor.
    i64 configure_epoll_watch(i32 _epollFileDescriptor, i32 _operation, i32 _fileDescriptor, EpollEventData* _event);

    /// epoll_pwait : Waits for epoll events with millisecond timeout precision while temporarily replacing the signal mask.
    /// _epollFileDescriptor : Identifies the epoll instance.
    /// _events : Receives triggered events.
    /// _maximumEvents : Specifies the maximum number of events that may be returned.
    /// _timeout : Specifies the timeout in milliseconds.
    /// _signalMask : Specifies the temporary signal mask, or null to leave it unchanged.
    /// _signalSetSize : Specifies the size of the supplied signal set.
    i64 wait_for_epoll_events(i32 _epollFileDescriptor, EpollEventData* _events, i32 _maximumEvents, i32 _timeout, const SignalSet* _signalMask, u64 _signalSetSize);

    /// epoll_pwait2 : Waits for epoll events with high-resolution timeout precision while temporarily replacing the signal mask.
    /// _epollFileDescriptor : Identifies the epoll instance.
    /// _events : Receives triggered events.
    /// _maximumEvents : Specifies the maximum number of events that may be returned.
    /// _timeout : Specifies the high-resolution timeout, or null to wait indefinitely.
    /// _signalMask : Specifies the temporary signal mask, or null to leave it unchanged.
    /// _signalSetSize : Specifies the size of the supplied signal set.
    i64 wait_for_epoll_events_precise(i32 _epollFileDescriptor, EpollEventData* _events, i32 _maximumEvents, const KernelTimeSpecification* _timeout, const SignalSet* _signalMask, u64 _signalSetSize);

    /// eventfd2 : Creates a kernel-maintained 64-bit event counter accessible through a file descriptor.
    /// _initialValue : Specifies the counter's initial value.
    /// _flags : Controls nonblocking, semaphore, and close-on-exec behavior.
    i64 create_event_counter(u32 _initialValue, i32 _flags);

    /// execve : Replaces the calling process image with a specified executable.
    /// _fileName : Specifies the executable path.
    /// _arguments : Supplies the new program's argument vector.
    /// _environment : Supplies the new program's environment variables.
    i64 execute_program(const c08* _fileName, const c08* const* _arguments, const c08* const* _environment);

    /// execveat : Replaces the calling process image with an executable resolved relative to a directory descriptor.
    /// _fileDescriptor : Specifies the base directory or executable descriptor.
    /// _fileName : Specifies the executable path relative to the base descriptor.
    /// _arguments : Supplies the new program's argument vector.
    /// _environment : Supplies the new program's environment variables.
    /// _flags : Controls path resolution and descriptor-based execution.
    i64 execute_program_at(i32 _fileDescriptor, const c08* _fileName, const c08* const* _arguments, const c08* const* _environment, i32 _flags);

    /// exit : Terminates only the calling thread and records its exit status.
    /// _errorCode : Specifies the thread's exit status.
    i64 exit_thread(i32 _errorCode);

    /// exit_group : Terminates every thread in the calling process and records its exit status.
    /// _errorCode : Specifies the process's exit status.
    i64 exit_process(i32 _errorCode);

    /// faccessat2 : Checks whether a file is accessible using credentials and path-resolution behavior controlled by flags.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the file to check.
    /// _mode : Specifies which access permissions to test.
    /// _flags : Controls credential and symbolic-link handling.
    i64 check_file_access_at_with_flags(i32 _directoryFileDescriptor, const c08* _fileName, i32 _mode, i32 _flags);

    /// faccessat : Checks whether a file resolved relative to a directory descriptor is accessible.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the file to check.
    /// _mode : Specifies which access permissions to test.
    i64 check_file_access_at(i32 _directoryFileDescriptor, const c08* _fileName, i32 _mode);

    /// fallocate : Allocates, deallocates, or otherwise manipulates storage space within a file.
    /// _fileDescriptor : Identifies the file.
    /// _mode : Selects the allocation or range-manipulation operation.
    /// _offset : Specifies the starting byte offset.
    /// _length : Specifies the affected byte length.
    i64 allocate_file_space(i32 _fileDescriptor, i32 _mode, i64 _offset, i64 _length);

    /// fanotify_init : Creates a fanotify notification group and returns its file descriptor.
    /// _flags : Configures the fanotify group.
    /// _eventFileFlags : Configures descriptors opened for reported filesystem objects.
    i64 create_fanotify_group(u32 _flags, u32 _eventFileFlags);

    /// fanotify_mark : Adds, modifies, removes, or flushes fanotify marks on filesystem objects.
    /// _fanotifyFileDescriptor : Identifies the fanotify group.
    /// _flags : Selects the mark operation and target interpretation.
    /// _mask : Specifies filesystem events to monitor or ignore.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the filesystem object to mark.
    i64 modify_fanotify_mark(i32 _fanotifyFileDescriptor, u32 _flags, u64 _mask, i32 _directoryFileDescriptor, const c08* _pathName);

    /// fchdir : Changes the calling process's working directory to the directory referenced by a descriptor.
    /// _fileDescriptor : Identifies the directory that becomes the working directory.
    i64 change_working_directory_from_descriptor(u32 _fileDescriptor);

    /// fchmod : Changes permission and mode bits of an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _mode : Specifies the new permission and mode bits.
    i64 change_file_mode(u32 _fileDescriptor, u16 _mode);

    /// fchmodat2 : Changes permission and mode bits of a path relative to a directory descriptor with additional path-handling flags.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _mode : Specifies the new permission and mode bits.
    /// _flags : Controls symbolic-link and path-resolution behavior.
    i64 change_file_mode_at_with_flags(i32 _directoryFileDescriptor, const c08* _fileName, u16 _mode, u32 _flags);

    /// fchmodat : Changes permission and mode bits of a path relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _mode : Specifies the new permission and mode bits.
    i64 change_file_mode_at(i32 _directoryFileDescriptor, const c08* _fileName, u16 _mode);

    /// fchown : Changes the owner and group of an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _userId : Specifies the new owner user ID.
    /// _groupId : Specifies the new owner group ID.
    i64 change_file_owner(u32 _fileDescriptor, u32 _userId, u32 _groupId);

    /// fchownat : Changes the owner and group of a path relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _userId : Specifies the new owner user ID.
    /// _groupId : Specifies the new owner group ID.
    /// _flags : Controls symbolic-link and path handling.
    i64 change_file_owner_at(i32 _directoryFileDescriptor, const c08* _fileName, u32 _userId, u32 _groupId, i32 _flags);

    /// fcntl : Performs a command-specific operation on an open file descriptor.
    /// _fileDescriptor : Identifies the descriptor.
    /// _command : Selects the descriptor or file operation.
    /// _argument : Supplies command-specific data or a userspace address.
    i64 control_file_descriptor(u32 _fileDescriptor, u32 _command, u64 _argument);

    /// fdatasync : Flushes modified file data and metadata required for subsequent data access to persistent storage.
    /// _fileDescriptor : Identifies the file to synchronize.
    i64 synchronize_file_data(u32 _fileDescriptor);

    /// fgetxattr : Retrieves an extended attribute from an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _name : Specifies the extended attribute name.
    /// _value : Receives the extended attribute value.
    /// _size : Specifies the available output buffer size.
    i64 get_extended_attribute(i32 _fileDescriptor, const c08* _name, void* _value, u64 _size);

    /// file_getattr : Retrieves filesystem-specific attributes for a path.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _fileAttributes : Receives the filesystem-specific attributes.
    /// _size : Specifies the size of the attribute structure.
    /// _lookupFlags : Controls path lookup behavior.
    i64 get_filesystem_file_attributes(i32 _directoryFileDescriptor, const c08* _fileName, FileAttributes* _fileAttributes, u64 _size, u32 _lookupFlags);

    /// file_setattr : Changes filesystem-specific attributes for a path.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _fileAttributes : Supplies the filesystem-specific attributes to apply.
    /// _size : Specifies the size of the attribute structure.
    /// _lookupFlags : Controls path lookup behavior.
    i64 set_filesystem_file_attributes(i32 _directoryFileDescriptor, const c08* _fileName, FileAttributes* _fileAttributes, u64 _size, u32 _lookupFlags);

    /// finit_module : Loads a kernel module from an already-open file descriptor.
    /// _fileDescriptor : Identifies the module image.
    /// _arguments : Supplies module parameters as a string.
    /// _flags : Controls module loading behavior.
    i64 load_kernel_module_from_descriptor(i32 _fileDescriptor, const c08* _arguments, i32 _flags);

    /// flistxattr : Retrieves the names of all extended attributes on an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _list : Receives the null-separated attribute names.
    /// _size : Specifies the available output buffer size.
    i64 list_extended_attributes(i32 _fileDescriptor, c08* _list, u64 _size);

    /// flock : Applies or removes an advisory whole-file lock associated with an open file description.
    /// _fileDescriptor : Identifies the open file.
    /// _command : Selects shared, exclusive, unlock, and nonblocking behavior.
    i64 manage_file_lock(u32 _fileDescriptor, u32 _command);

    /// fremovexattr : Removes an extended attribute from an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _name : Specifies the extended attribute to remove.
    i64 remove_extended_attribute(i32 _fileDescriptor, const c08* _name);

    /// fsconfig : Applies configuration commands to a filesystem context.
    /// _fileDescriptor : Identifies the filesystem context.
    /// _command : Selects the configuration operation.
    /// _key : Specifies the configuration parameter name when required.
    /// _value : Supplies command-specific configuration data.
    /// _auxiliary : Supplies command-specific auxiliary data.
    i64 configure_filesystem_context(i32 _fileDescriptor, u32 _command, const c08* _key, const void* _value, i32 _auxiliary);

    /// fsetxattr : Creates or replaces an extended attribute on an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _name : Specifies the extended attribute name.
    /// _value : Supplies the extended attribute value.
    /// _size : Specifies the value size in bytes.
    /// _flags : Controls creation and replacement behavior.
    i64 set_extended_attribute(i32 _fileDescriptor, const c08* _name, const void* _value, u64 _size, i32 _flags);

    /// fsmount : Creates a detached mount from a configured filesystem context and returns a mount file descriptor.
    /// _fileSystemFileDescriptor : Identifies the configured filesystem context.
    /// _flags : Controls creation of the mount descriptor.
    /// _attributeFlags : Specifies mount attribute flags applied to the new mount.
    i64 create_detached_mount(i32 _fileSystemFileDescriptor, u32 _flags, u32 _attributeFlags);

    /// fsopen : Creates a filesystem configuration context for a named filesystem type.
    /// _fileSystemName : Specifies the filesystem type.
    /// _flags : Controls creation of the filesystem context.
    i64 create_filesystem_context(const c08* _fileSystemName, u32 _flags);

    /// fspick : Creates a filesystem configuration context from an existing mount for reconfiguration.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _path : Specifies the existing mount to select.
    /// _flags : Controls path lookup and reconfiguration behavior.
    i64 open_mount_configuration(i32 _directoryFileDescriptor, const c08* _path, u32 _flags);

    /// fstatfs : Retrieves filesystem-wide statistics for the filesystem containing an open object.
    /// _fileDescriptor : Identifies an object within the filesystem.
    /// _buffer : Receives filesystem statistics.
    i64 get_filesystem_statistics(u32 _fileDescriptor, FilesystemStatistics* _buffer);

    /// fsync : Flushes modified file data and associated metadata to persistent storage.
    /// _fileDescriptor : Identifies the file to synchronize.
    i64 synchronize_file(u32 _fileDescriptor);

    /// ftruncate : Changes the size of an open regular file.
    /// _fileDescriptor : Identifies the file.
    /// _length : Specifies the new file size in bytes.
    i64 resize_file(u32 _fileDescriptor, i64 _length);

    /// futex : Performs a selected operation on one or more 32-bit userspace futex words.
    /// _userAddress : Identifies the primary futex word.
    /// _operation : Selects the futex operation and option flags.
    /// _value : Supplies operation-specific data.
    /// _timeout : Supplies operation-specific timeout data.
    /// _secondaryUserAddress : Identifies a secondary futex word for operations that require one.
    /// _value3 : Supplies additional operation-specific data.
    i64 perform_futex_operation(u32* _userAddress, i32 _operation, u32 _value, const KernelTimeSpecification* _timeout, u32* _secondaryUserAddress, u32 _value3);

    /// futex_requeue : Wakes some waiters and moves additional waiters between futexes described by the supplied waiter structures.
    /// _waiters : Describes the source and destination futexes.
    /// _flags : Controls futex interpretation and sharing behavior.
    /// _wakeCount : Specifies the maximum number of waiters to wake.
    /// _requeueCount : Specifies the maximum number of additional waiters to requeue.
    i64 requeue_futex_waiters(FutexWaitRequest* _waiters, u32 _flags, i32 _wakeCount, i32 _requeueCount);

    /// futex_wait : Sleeps while a futex contains an expected value and satisfies the supplied bit mask.
    /// _userAddress : Identifies the futex word.
    /// _value : Specifies the value expected before sleeping.
    /// _mask : Selects which wake operations may wake this waiter.
    /// _flags : Controls futex size and sharing behavior.
    /// _timeout : Specifies the optional timeout.
    /// _clockId : Selects the clock used for timeout measurement.
    i64 wait_on_futex(void* _userAddress, u64 _value, u64 _mask, u32 _flags, KernelTimeSpecification* _timeout, i32 _clockId);

    /// futex_waitv : Waits until at least one futex in a vector becomes eligible to wake.
    /// _waiters : Describes the futexes and expected values to wait on.
    /// _futexCount : Specifies the number of waiter entries.
    /// _flags : Supplies operation-wide flags.
    /// _timeout : Specifies the optional timeout.
    /// _clockId : Selects the clock used for timeout measurement.
    i64 wait_on_futex_set(FutexWaitRequest* _waiters, u32 _futexCount, u32 _flags, KernelTimeSpecification* _timeout, i32 _clockId);

    /// futex_wake : Wakes threads waiting on a futex whose waiter masks intersect the supplied mask.
    /// _userAddress : Identifies the futex word.
    /// _mask : Selects which waiters are eligible to wake.
    /// _wakeCount : Specifies the maximum number of waiters to wake.
    /// _flags : Controls futex size and sharing behavior.
    i64 wake_futex_waiters(void* _userAddress, u64 _mask, i32 _wakeCount, u32 _flags);

    /// getcpu : Returns the CPU and NUMA node on which the calling thread is currently executing.
    /// _cpu : Optionally receives the current CPU number.
    /// _node : Optionally receives the current NUMA node number.
    /// _unused : Obsolete cache argument that should be null.
    i64 get_current_cpu(u32* _cpu, u32* _node, void* _unused);

    /// getcwd : Copies the calling process's absolute current working directory into a userspace buffer.
    /// _buffer : Receives the current working directory string.
    /// _size : Specifies the available buffer size.
    i64 get_working_directory(c08* _buffer, u64 _size);

    /// getdents64 : Reads directory entries from an open directory descriptor into a buffer.
    /// _fileDescriptor : Identifies the open directory.
    /// _directoryEntry : Receives packed directory entry records.
    /// _count : Specifies the available output buffer size in bytes.
    i64 read_directory_entries(u32 _fileDescriptor, LinuxDirectoryEntry* _directoryEntry, u32 _count);

    /// getegid : Returns the effective group ID of the calling thread.
    i64 get_effective_group_id();

    /// geteuid : Returns the effective user ID of the calling thread.
    i64 get_effective_user_id();

    /// getgid : Returns the real group ID of the calling thread.
    i64 get_real_group_id();

    /// getgroups : Retrieves the supplementary group IDs of the calling thread.
    /// _groupSetSize : Specifies the number of group IDs that can fit in the output array, or zero to query the required count.
    /// _groupList : Receives the supplementary group IDs.
    i64 get_supplementary_groups(i32 _groupSetSize, u32* _groupList);

    /// getitimer : Retrieves the current state of a process interval timer.
    /// _timerType : Selects which interval timer to query.
    /// _value : Receives the timer's remaining time and reload interval.
    i64 get_interval_timer(i32 _timerType, LegacyIntervalTimerValue* _value);

    /// get_mempolicy : Retrieves NUMA memory-policy information for the calling thread or a specified memory address.
    /// _policy : Optionally receives the memory-policy mode.
    /// _nodeMask : Optionally receives the policy's NUMA node mask.
    /// _maximumNode : Specifies the maximum node number representable by the node-mask buffer.
    /// _address : Specifies an address when querying the policy governing a particular memory location.
    /// _flags : Controls what policy information is queried and how the address is interpreted.
    i64 get_memory_policy(i32* _policy, u64* _nodeMask, u64 _maximumNode, u64 _address, u64 _flags);

    /// getpeername : Retrieves the remote address associated with a connected socket.
    /// _fileDescriptor : Identifies the socket.
    /// _socketAddress : Receives the peer socket address.
    /// _socketAddressLength : Supplies the address-buffer size and receives the actual address size.
    i64 get_peer_socket_address(i32 _fileDescriptor, SocketAddress* _socketAddress, i32* _socketAddressLength);

    /// getpgid : Returns the process-group ID of a specified process.
    /// _processId : Identifies the process, or zero to select the caller.
    i64 get_process_group_id(i32 _processId);

    /// getpid : Returns the process ID of the calling process.
    i64 get_process_id();

    /// getppid : Returns the process ID of the caller's parent process.
    i64 get_parent_process_id();

    /// getpriority : Retrieves the highest scheduling nice priority among the selected processes, process group, or user.
    /// _which : Selects whether _who identifies a process, process group, or user.
    /// _who : Identifies the target within the selected category, with zero selecting the caller's corresponding identity.
    i64 get_nice_priority(i32 _which, i32 _who);

    /// getrandom : Fills a buffer with random bytes provided by the kernel random subsystem.
    /// _buffer : Receives the generated random bytes.
    /// _length : Specifies the maximum number of bytes to generate.
    /// _flags : Controls random-source and blocking behavior.
    i64 get_random_bytes(c08* _buffer, u64 _length, u32 _flags);

    /// getresgid : Retrieves the real, effective, and saved group IDs of the calling thread.
    /// _realGroupId : Receives the real group ID.
    /// _effectiveGroupId : Receives the effective group ID.
    /// _savedGroupId : Receives the saved group ID.
    i64 get_group_credentials(u32* _realGroupId, u32* _effectiveGroupId, u32* _savedGroupId);

    /// getresuid : Retrieves the real, effective, and saved user IDs of the calling thread.
    /// _realUserId : Receives the real user ID.
    /// _effectiveUserId : Receives the effective user ID.
    /// _savedUserId : Receives the saved user ID.
    i64 get_user_credentials(u32* _realUserId, u32* _effectiveUserId, u32* _savedUserId);

    /// getrlimit : Retrieves the soft and hard limits for a process resource.
    /// _resource : Selects the resource whose limits are queried.
    /// _resourceLimit : Receives the current soft and hard limits.
    i64 get_resource_limit(u32 _resource, ResourceLimit* _resourceLimit);

    /// get_robust_list : Retrieves the robust-futex list registered by a specified thread.
    /// _processId : Identifies the thread, or zero to select the caller.
    /// _headPointer : Receives the address of the robust-futex list head.
    /// _lengthPointer : Receives the size of the robust-list-head structure.
    i64 get_thread_robust_futex_list(i32 _processId, RobustFutexListHead** _headPointer, u64* _lengthPointer);

    /// getrusage : Retrieves resource-consumption statistics for the selected execution scope.
    /// _who : Selects the caller, its children, or the calling thread.
    /// _resourceUsage : Receives CPU-time and resource-usage statistics.
    i64 get_resource_usage(i32 _who, ResourceUsage* _resourceUsage);

    /// getsid : Returns the session ID of a specified process.
    /// _processId : Identifies the process, or zero to select the caller.
    i64 get_session_id(i32 _processId);

    /// getsockname : Retrieves the local address currently associated with a socket.
    /// _fileDescriptor : Identifies the socket.
    /// _socketAddress : Receives the local socket address.
    /// _socketAddressLength : Supplies the address-buffer size and receives the actual address size.
    i64 get_local_socket_address(i32 _fileDescriptor, SocketAddress* _socketAddress, i32* _socketAddressLength);

    /// getsockopt : Retrieves the current value of a socket option.
    /// _fileDescriptor : Identifies the socket.
    /// _level : Selects the protocol level defining the option.
    /// _optionName : Selects the option to retrieve.
    /// _optionValue : Receives the option value.
    /// _optionLength : Supplies the output-buffer size and receives the actual option size.
    i64 get_socket_option(i32 _fileDescriptor, i32 _level, i32 _optionName, c08* _optionValue, i32* _optionLength);

    /// gettid : Returns the thread ID of the calling thread.
    i64 get_thread_id();

    /// gettimeofday : Retrieves the current wall-clock time and optionally legacy timezone information.
    /// _timeValue : Receives the current time since the Unix epoch.
    /// _timezone : Optionally receives legacy timezone information.
    i64 get_wall_clock_time(LegacyTimeValue* _timeValue, TimezoneInformation* _timezone);

    /// getuid : Returns the real user ID of the calling thread.
    i64 get_real_user_id();

    /// getxattr : Retrieves a named extended attribute from a filesystem object referenced by a path.
    /// _pathName : Specifies the filesystem object.
    /// _name : Specifies the extended attribute name.
    /// _value : Receives the attribute value.
    /// _size : Specifies the available output-buffer size.
    i64 get_extended_attribute(const c08* _pathName, const c08* _name, void* _value, u64 _size);

    /// getxattrat : Retrieves a named extended attribute using directory-relative path resolution and extended argument options.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the filesystem object.
    /// _lookupFlags : Controls path resolution, including symbolic-link and empty-path handling.
    /// _name : Specifies the extended attribute name.
    /// _arguments : Supplies the value buffer, value-buffer size, and operation flags.
    /// _size : Specifies the size of the extended-attribute argument structure.
    i64 get_extended_attribute_at(i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, const c08* _name, ExtendedAttributeArguments* _arguments, u64 _size);

    /// init_module : Loads a kernel module directly from an image held in userspace memory.
    /// _moduleImage : Points to the kernel module image.
    /// _length : Specifies the module-image size in bytes.
    /// _arguments : Supplies module parameters as a string.
    i64 load_kernel_module_from_memory(void* _moduleImage, u64 _length, const c08* _arguments);

    /// inotify_add_watch : Adds or updates an inotify watch for a filesystem path.
    /// _fileDescriptor : Identifies the inotify instance.
    /// _pathName : Specifies the path to monitor.
    /// _mask : Specifies the filesystem events and watch options to monitor.
    i64 add_inotify_watch(i32 _fileDescriptor, const c08* _pathName, u32 _mask);

    /// inotify_init1 : Creates an inotify instance and returns its file descriptor.
    /// _flags : Controls nonblocking and close-on-exec behavior.
    i64 create_inotify(i32 _flags);

    /// inotify_rm_watch : Removes a watch from an inotify instance.
    /// _fileDescriptor : Identifies the inotify instance.
    /// _watchDescriptor : Identifies the watch to remove.
    i64 remove_inotify_watch(i32 _fileDescriptor, i32 _watchDescriptor);

    /// io_cancel : Attempts to cancel an outstanding Linux AIO request and returns its completion event when successful.
    /// _contextId : Identifies the asynchronous-I/O context.
    /// _ioControlBlock : Identifies the submitted request to cancel.
    /// _result : Receives the cancelled request's completion information.
    i64 cancel_async_io(u64 _contextId, IoControlBlock* _ioControlBlock, IoCompletionEvent* _result);

    /// ioctl : Executes a driver- or subsystem-specific control operation on a file descriptor.
    /// _fileDescriptor : Identifies the object to control.
    /// _command : Selects the control operation.
    /// _argument : Supplies command-specific data or a userspace address.
    i64 perform_io_control(u32 _fileDescriptor, u32 _command, u64 _argument);

    /// io_destroy : Destroys a Linux AIO context and handles any outstanding requests associated with it.
    /// _context : Identifies the asynchronous-I/O context.
    i64 destroy_async_io_context(u64 _context);

    /// io_getevents : Retrieves completed operations from a Linux AIO completion queue.
    /// _contextId : Identifies the asynchronous-I/O context.
    /// _minimumEvents : Specifies the minimum number of completions to wait for.
    /// _eventCount : Specifies the maximum number of completions to return.
    /// _events : Receives the completion events.
    /// _timeout : Specifies the maximum relative time to wait, or null to wait indefinitely.
    i64 get_async_io_completions(u64 _contextId, i64 _minimumEvents, i64 _eventCount, IoCompletionEvent* _events, KernelTimeSpecification* _timeout);

    /// io_pgetevents : Retrieves Linux AIO completions while temporarily applying a specified signal mask during the wait.
    /// _contextId : Identifies the asynchronous-I/O context.
    /// _minimumEvents : Specifies the minimum number of completions to wait for.
    /// _eventCount : Specifies the maximum number of completions to return.
    /// _events : Receives the completion events.
    /// _timeout : Specifies the maximum relative time to wait, or null to wait indefinitely.
    /// _signalSet : Specifies the temporary signal mask and its size.
    i64 get_async_io_completions_with_signal_mask(u64 _contextId, i64 _minimumEvents, i64 _eventCount, IoCompletionEvent* _events, KernelTimeSpecification* _timeout, const AioSignalSet* _signalSet);

    /// ioprio_get : Retrieves the I/O scheduling priority of a process, process group, or user.
    /// _which : Selects the category identified by _who.
    /// _who : Identifies the process, process group, or user whose I/O priority is queried.
    i64 get_io_priority(i32 _which, i32 _who);

    /// ioprio_set : Sets the I/O scheduling priority of a process, process group, or user.
    /// _which : Selects the category identified by _who.
    /// _who : Identifies the process, process group, or user whose I/O priority is modified.
    /// _ioPriority : Specifies the I/O scheduling class and priority.
    i64 set_io_priority(i32 _which, i32 _who, i32 _ioPriority);

    /// io_setup : Creates a Linux asynchronous-I/O context.
    /// _eventCount : Specifies the maximum number of concurrent events the context should support.
    /// _context : Receives the newly created asynchronous-I/O context identifier.
    i64 create_async_io_context(u32 _eventCount, u64* _context);

    /// io_submit : Submits one or more asynchronous-I/O requests to a Linux AIO context.
    /// _contextId : Identifies the asynchronous-I/O context.
    /// _count : Specifies the number of request pointers in the array.
    /// _ioControlBlocks : Points to the asynchronous-I/O requests to submit.
    i64 submit_async_io(u64 _contextId, i64 _count, IoControlBlock** _ioControlBlocks);

    /// io_uring_enter : Submits io_uring requests, waits for completions, or performs other ring-enter operations according to flags.
    /// _fileDescriptor : Identifies the io_uring instance.
    /// _submitCount : Specifies how many submission-queue entries should be submitted.
    /// _minimumCompletions : Specifies the minimum number of completions to wait for when requested.
    /// _flags : Controls submission, waiting, SQ-polling, and extended-argument behavior.
    /// _arguments : Supplies an optional signal mask or extended argument structure depending on flags.
    /// _argumentSize : Specifies the size of the supplied argument data.
    i64 process_io_uring_queue(u32 _fileDescriptor, u32 _submitCount, u32 _minimumCompletions, u32 _flags, const void* _arguments, u64 _argumentSize);

    /// io_uring_register : Registers, unregisters, updates, or queries resources and features associated with an io_uring instance.
    /// _fileDescriptor : Identifies the io_uring instance.
    /// _operationCode : Selects the registration operation.
    /// _argument : Supplies operation-specific data.
    /// _argumentCount : Supplies the operation-specific number of entries or arguments.
    i64 configure_io_uring(u32 _fileDescriptor, u32 _operationCode, void* _argument, u32 _argumentCount);

    /// io_uring_setup : Creates an io_uring instance and returns its file descriptor.
    /// _entries : Requests the number of submission-queue entries.
    /// _parameters : Supplies setup options and receives the resulting ring configuration.
    i64 create_io_uring(u32 _entries, IoUringParameters* _parameters);

    /// kcmp : Compares a selected kernel resource belonging to two processes.
    /// _processId1 : Identifies the first process.
    /// _processId2 : Identifies the second process.
    /// _type : Selects which kernel resource is compared.
    /// _index1 : Supplies the first resource index or descriptor when required.
    /// _index2 : Supplies the second resource index or descriptor when required.
    i64 compare_process_resources(i32 _processId1, i32 _processId2, i32 _type, u64 _index1, u64 _index2);

    /// kexec_file_load : Loads a kernel and optional initramfs from file descriptors for later execution through kexec.
    /// _kernelFileDescriptor : Identifies the kernel image.
    /// _initialRamdiskFileDescriptor : Identifies the initial RAM disk, or indicates that none is supplied.
    /// _commandLineLength : Specifies the kernel command-line length.
    /// _commandLine : Supplies the kernel command line.
    /// _flags : Controls loading and execution behavior.
    i64 load_kernel_image_from_files(i32 _kernelFileDescriptor, i32 _initialRamdiskFileDescriptor, u64 _commandLineLength, const c08* _commandLine, u64 _flags);

    /// kexec_load : Loads kernel memory segments and an entry point for later execution through kexec.
    /// _entryPoint : Specifies the physical entry address of the new kernel.
    /// _segmentCount : Specifies the number of memory segments.
    /// _segments : Describes the userspace source data and destination physical memory regions.
    /// _flags : Controls loading and execution behavior.
    i64 load_kernel_image(u64 _entryPoint, u64 _segmentCount, KernelExecutionSegment* _segments, u64 _flags);

    /// keyctl : Performs a command-specific operation on the kernel key-management facility.
    /// _option : Selects the key-management operation.
    /// _argument2 : Supplies operation-specific data.
    /// _argument3 : Supplies operation-specific data.
    /// _argument4 : Supplies operation-specific data.
    /// _argument5 : Supplies operation-specific data.
    i64 control_kernel_keys(i32 _option, u64 _argument2, u64 _argument3, u64 _argument4, u64 _argument5);

    /// kill : Sends a signal to a process or process group selected by a process-ID value.
    /// _processId : Selects the target process, process group, or set of processes.
    /// _signal : Specifies the signal to send, or zero to perform permission and existence checks without delivering one.
    i64 send_signal(i32 _processId, i32 _signal);

    /// landlock_add_rule : Adds a restriction rule to an existing Landlock ruleset.
    /// _rulesetFileDescriptor : Identifies the Landlock ruleset.
    /// _ruleType : Selects the structure and semantics of the supplied rule.
    /// _ruleAttributes : Supplies attributes describing the rule.
    /// _flags : Reserved operation flags.
    i64 add_landlock_rule(const i32 _rulesetFileDescriptor, const LandlockRulesetType _ruleType, const void* const _ruleAttributes, const u32 _flags);

    /// landlock_create_ruleset : Creates a Landlock ruleset or queries the supported Landlock ABI according to flags.
    /// _attributes : Describes the accesses handled by the ruleset.
    /// _size : Specifies the size of the ruleset-attribute structure.
    /// _flags : Controls ruleset creation or ABI-version querying.
    i64 create_landlock_ruleset(const LandlockRulesetAttributes* const _attributes, const u64 _size, const u32 _flags);

    /// landlock_restrict_self : Applies a Landlock ruleset to the calling thread and its subsequently created children.
    /// _rulesetFileDescriptor : Identifies the Landlock ruleset to enforce.
    /// _flags : Reserved operation flags.
    i64 apply_landlock_ruleset(const i32 _rulesetFileDescriptor, const u32 _flags);

    /// lgetxattr : Retrieves a named extended attribute from a path without following the final symbolic link.
    /// _pathName : Specifies the filesystem object.
    /// _name : Specifies the extended attribute name.
    /// _value : Receives the attribute value.
    /// _size : Specifies the available output-buffer size.
    i64 get_extended_attribute_no_follow(const c08* _pathName, const c08* _name, void* _value, u64 _size);

    /// linkat : Creates a hard link between paths resolved relative to independently specified directory descriptors.
    /// _oldDirectoryFileDescriptor : Specifies the base directory for the existing path.
    /// _oldName : Specifies the existing filesystem object.
    /// _newDirectoryFileDescriptor : Specifies the base directory for the new path.
    /// _newName : Specifies the new hard-link path.
    /// _flags : Controls symbolic-link and empty-path handling.
    i64 create_hard_link_at(i32 _oldDirectoryFileDescriptor, const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName, i32 _flags);

    /// listen : Marks a socket as passive and configures the queue limit for pending connection requests.
    /// _fileDescriptor : Identifies the socket.
    /// _backlog : Specifies the maximum pending-connection queue length.
    i64 listen_for_connections(i32 _fileDescriptor, i32 _backlog);

    /// listmount : Retrieves mount IDs beneath a specified mount for mount-tree enumeration.
    /// _request : Specifies the parent mount and enumeration position.
    /// _mountIds : Receives mount IDs.
    /// _mountIdCount : Specifies the maximum number of IDs that may be returned.
    /// _flags : Controls mount enumeration behavior.
    i64 list_mount_ids(const MountIdentifierRequest* _request, u64* _mountIds, u64 _mountIdCount, u32 _flags);

    /// listxattr : Retrieves the names of extended attributes associated with a filesystem object.
    /// _pathName : Specifies the filesystem object.
    /// _list : Receives null-terminated attribute names packed consecutively.
    /// _size : Specifies the available output-buffer size.
    i64 list_extended_attributes(const c08* _pathName, c08* _list, u64 _size);

    /// listxattrat : Retrieves extended-attribute names using directory-relative path resolution and lookup flags.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the filesystem object.
    /// _lookupFlags : Controls symbolic-link and empty-path handling.
    /// _list : Receives null-terminated attribute names packed consecutively.
    /// _size : Specifies the available output-buffer size.
    i64 list_extended_attributes_at(i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, c08* _list, u64 _size);

    /// llistxattr : Retrieves extended-attribute names from a path without following the final symbolic link.
    /// _pathName : Specifies the filesystem object.
    /// _list : Receives null-terminated attribute names packed consecutively.
    /// _size : Specifies the available output-buffer size.
    i64 list_extended_attributes_no_follow(const c08* _pathName, c08* _list, u64 _size);

    /// lremovexattr : Removes a named extended attribute from a path without following the final symbolic link.
    /// _pathName : Specifies the filesystem object.
    /// _name : Specifies the extended attribute to remove.
    i64 remove_extended_attribute_no_follow(const c08* _pathName, const c08* _name);

    /// lseek : Changes the current file offset associated with an open file description.
    /// _fileDescriptor : Identifies the open object.
    /// _offset : Specifies an offset interpreted according to _whence.
    /// _whence : Selects the reference point from which the offset is calculated.
    i64 seek_file(i32 _fileDescriptor, i64 _offset, u32 _whence);

    /// lsetxattr : Creates or replaces a named extended attribute without following the final symbolic link.
    /// _pathName : Specifies the filesystem object.
    /// _name : Specifies the extended attribute name.
    /// _value : Supplies the attribute value.
    /// _size : Specifies the attribute-value size.
    /// _flags : Controls create-only or replace-only behavior.
    i64 set_extended_attribute_no_follow(const c08* _pathName, const c08* _name, const void* _value, u64 _size, i32 _flags);

    /// lsm_get_self_attr : Retrieves Linux Security Module attributes associated with the calling task.
    /// _attribute : Selects the security attribute to retrieve.
    /// _context : Receives one or more security-module context records.
    /// _size : Supplies the available context-buffer size and receives the required or consumed size.
    /// _flags : Controls special retrieval behavior such as selecting a single security module.
    i64 get_security_attributes(u32 _attribute, SecurityModuleContext* _context, u32* _size, u32 _flags);

    /// lsm_list_modules : Retrieves the identifiers of active Linux Security Modules.
    /// _moduleIds : Receives the active security-module identifiers.
    /// _size : Supplies the available buffer size and receives the required size.
    /// _flags : Reserved and currently required to be zero.
    i64 list_security_modules(u64* _moduleIds, u32* _size, u32 _flags);

    /// lsm_set_self_attr : Sets a Linux Security Module attribute for the calling task.
    /// _attribute : Selects the security attribute to modify.
    /// _context : Supplies the security-module context.
    /// _size : Specifies the size of the supplied context data.
    /// _flags : Reserved for operation-specific behavior.
    i64 set_security_attribute(u32 _attribute, SecurityModuleContext* _context, u32 _size, u32 _flags);

    /// madvise : Provides the kernel with expected access behavior for a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _behavior : Selects the advice or memory-management operation.
    i64 advise_memory(u64 _startAddress, s64 _length, i32 _behavior);

    /// map_shadow_stack : Creates a userspace shadow-stack memory mapping for architectures that support shadow stacks.
    /// _address : Supplies the requested mapping address or zero for automatic placement.
    /// _size : Specifies the mapping size.
    /// _flags : Controls shadow-stack creation behavior.
    i64 create_shadow_stack(u64 _address, u64 _size, u32 _flags);

    /// mbind : Applies a NUMA memory-placement policy to a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _mode : Selects the NUMA placement policy.
    /// _nodeMask : Specifies the NUMA nodes used by the policy.
    /// _maximumNode : Specifies the highest node representable by the node mask.
    /// _flags : Controls policy application and page migration behavior.
    i64 bind_memory_policy(u64 _startAddress, u64 _length, u64 _mode, const u64* _nodeMask, u64 _maximumNode, u32 _flags);

    /// membarrier : Issues a process-wide or expedited memory-ordering barrier operation.
    /// _command : Selects the barrier operation.
    /// _flags : Supplies command-specific flags.
    /// _cpuId : Selects a CPU for commands that require one.
    i64 issue_memory_barrier(i32 _command, u32 _flags, i32 _cpuId);

    /// memfd_create : Creates an anonymous RAM-backed file and returns its descriptor.
    /// _name : Supplies a descriptive name for the anonymous file.
    /// _flags : Controls sealing, huge-page, and close-on-exec behavior.
    i64 create_memory_file(const c08* _name, u32 _flags);

    /// memfd_secret : Creates a file descriptor representing memory isolated from ordinary kernel mappings.
    /// _flags : Controls secret-memory creation behavior.
    i64 create_secret_memory(i32 _flags);

    /// migrate_pages : Moves a process's pages from one set of NUMA nodes to another.
    /// _processId : Identifies the target process.
    /// _maximumNode : Specifies the highest node representable by the node masks.
    /// _oldNodes : Specifies source NUMA nodes.
    /// _newNodes : Specifies corresponding destination NUMA nodes.
    i64 migrate_process_pages(i32 _processId, u64 _maximumNode, const u64* _oldNodes, const u64* _newNodes);

    /// mincore : Reports whether pages in a virtual-memory range are currently resident in physical memory.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _vector : Receives one residency byte for each page.
    i64 query_memory_residency(u64 _startAddress, s64 _length, u08* _vector);

    /// mkdirat : Creates a directory using a path resolved relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the directory to create.
    /// _mode : Specifies the initial permission bits.
    i64 create_directory_at(i32 _directoryFileDescriptor, const c08* _pathName, u16 _mode);

    /// mknodat : Creates a filesystem node using a path resolved relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the node to create.
    /// _mode : Specifies the node type and permission bits.
    /// _device : Specifies the device identifier when creating a device node.
    i64 create_filesystem_node_at(i32 _directoryFileDescriptor, const c08* _fileName, u16 _mode, u32 _device);

    /// mlock2 : Locks pages of a virtual-memory range into RAM with additional locking behavior controlled by flags.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _flags : Controls how pages are locked.
    i64 lock_memory_with_flags(u64 _startAddress, s64 _length, i32 _flags);

    /// mlock : Locks pages of a virtual-memory range into RAM.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    i64 lock_memory(u64 _startAddress, s64 _length);

    /// mlockall : Locks some or all current and future mappings of the calling process into RAM.
    /// _flags : Selects which mappings are locked.
    i64 lock_process_memory(i32 _flags);

    /// mmap : Creates a virtual-memory mapping backed by a file or anonymous memory.
    /// _address : Supplies the requested mapping address or an address hint.
    /// _length : Specifies the mapping size.
    /// _protection : Specifies permitted memory accesses.
    /// _flags : Controls mapping type and creation behavior.
    /// _fileDescriptor : Identifies the backing file when the mapping is not anonymous.
    /// _offset : Specifies the byte offset within the backing file.
    i64 map_memory(u64 _address, u64 _length, u64 _protection, u64 _flags, u64 _fileDescriptor, u64 _offset);

    /// mount : Attaches a filesystem or modifies an existing mount according to the supplied flags.
    /// _deviceName : Specifies the source device or filesystem-specific source.
    /// _directoryName : Specifies the mount point.
    /// _fileSystemType : Specifies the filesystem type.
    /// _flags : Controls mounting and remount behavior.
    /// _data : Supplies filesystem-specific mount options.
    i64 mount_filesystem(c08* _deviceName, c08* _directoryName, c08* _fileSystemType, u64 _flags, void* _data);

    /// mount_setattr : Changes mount attributes for a mount selected relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _path : Specifies the target mount.
    /// _flags : Controls path resolution and recursive application.
    /// _attributes : Supplies the mount attributes to change.
    /// _size : Specifies the size of the attribute structure.
    i64 set_mount_attributes(i32 _directoryFileDescriptor, const c08* _path, u32 _flags, MountAttributes* _attributes, s64 _size);

    /// move_mount : Moves or attaches a detached mount from one location to another.
    /// _sourceDirectoryFileDescriptor : Specifies the base directory for the source path.
    /// _sourcePathName : Specifies the source mount.
    /// _destinationDirectoryFileDescriptor : Specifies the base directory for the destination path.
    /// _destinationPathName : Specifies the destination location.
    /// _flags : Controls source and destination interpretation.
    i64 move_mount(i32 _sourceDirectoryFileDescriptor, const c08* _sourcePathName, i32 _destinationDirectoryFileDescriptor, const c08* _destinationPathName, u32 _flags);

    /// move_pages : Queries or changes the NUMA-node placement of individual pages belonging to a process.
    /// _processId : Identifies the target process.
    /// _pageCount : Specifies the number of page addresses.
    /// _pages : Specifies the virtual addresses of the pages.
    /// _nodes : Specifies destination nodes, or may be null when only querying.
    /// _status : Receives the resulting node or error for each page.
    /// _flags : Controls page-migration behavior.
    i64 move_process_pages(i32 _processId, u64 _pageCount, const void** _pages, const i32* _nodes, i32* _status, i32 _flags);

    /// mprotect : Changes access permissions for a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _protection : Specifies the new access permissions.
    i64 set_memory_protection(u64 _startAddress, s64 _length, u64 _protection);

    /// mq_getsetattr : Retrieves message-queue attributes and optionally replaces mutable queue flags.
    /// _messageQueueDescriptor : Identifies the POSIX message queue.
    /// _newAttributes : Supplies new queue flags, or may be null to only query.
    /// _oldAttributes : Receives the previous queue attributes, or may be null.
    i64 configure_message_queue_attributes(i32 _messageQueueDescriptor, const MessageQueueAttributes* _newAttributes, MessageQueueAttributes* _oldAttributes);

    /// mq_notify : Registers or removes asynchronous notification for a POSIX message queue.
    /// _messageQueueDescriptor : Identifies the POSIX message queue.
    /// _notification : Specifies notification behavior, or null to unregister.
    i64 configure_message_queue_notification(i32 _messageQueueDescriptor, const SignalEvent* _notification);

    /// mq_open : Opens or creates a POSIX message queue and returns its descriptor.
    /// _name : Specifies the message-queue name.
    /// _openFlags : Controls opening and creation behavior.
    /// _mode : Specifies permissions when creating the queue.
    /// _attributes : Specifies queue limits when creating the queue.
    i64 open_message_queue(const c08* _name, i32 _openFlags, u16 _mode, MessageQueueAttributes* _attributes);

    /// mq_timedreceive : Receives the oldest eligible message from a POSIX message queue with an absolute timeout.
    /// _messageQueueDescriptor : Identifies the POSIX message queue.
    /// _messageBuffer : Receives the message contents.
    /// _messageLength : Specifies the available message-buffer size.
    /// _messagePriority : Optionally receives the message priority.
    /// _absoluteTimeout : Specifies the absolute time at which waiting stops.
    i64 receive_message_until(i32 _messageQueueDescriptor, c08* _messageBuffer, s64 _messageLength, u32* _messagePriority, const KernelTimeSpecification* _absoluteTimeout);

    /// mq_timedsend : Sends a message to a POSIX message queue with an absolute timeout.
    /// _messageQueueDescriptor : Identifies the POSIX message queue.
    /// _messageBuffer : Supplies the message contents.
    /// _messageLength : Specifies the message size.
    /// _messagePriority : Specifies the message priority.
    /// _absoluteTimeout : Specifies the absolute time at which waiting stops.
    i64 send_message_until(i32 _messageQueueDescriptor, const c08* _messageBuffer, s64 _messageLength, u32 _messagePriority, const KernelTimeSpecification* _absoluteTimeout);

    /// mq_unlink : Removes a POSIX message-queue name while allowing existing open descriptors to remain usable.
    /// _name : Specifies the message queue to unlink.
    i64 unlink_message_queue(const c08* _name);

    /// mremap : Resizes or relocates an existing virtual-memory mapping.
    /// _address : Specifies the beginning of the existing mapping.
    /// _oldLength : Specifies the current mapping size.
    /// _newLength : Specifies the desired mapping size.
    /// _flags : Controls relocation and mapping-preservation behavior.
    /// _newAddress : Specifies the destination address when explicitly requested.
    i64 remap_memory(u64 _address, u64 _oldLength, u64 _newLength, u64 _flags, u64 _newAddress);

    /// mseal : Permanently prevents selected classes of future changes to a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _flags : Reserved for sealing options.
    i64 seal_memory(u64 _startAddress, s64 _length, u64 _flags);

    /// msgctl : Queries or modifies a System V message queue.
    /// _messageQueueId : Identifies the message queue.
    /// _command : Selects the operation to perform.
    /// _buffer : Supplies or receives queue metadata depending on the command.
    i64 control_message_queue(i32 _messageQueueId, i32 _command, MessageQueueStatus* _buffer);

    /// msgget : Opens an existing System V message queue or creates one for a specified key.
    /// _key : Identifies the queue namespace key.
    /// _messageFlags : Controls creation and permissions.
    i64 get_message_queue(i32 _key, i32 _messageFlags);

    /// msgrcv : Receives a message from a System V message queue.
    /// _messageQueueId : Identifies the message queue.
    /// _messageBuffer : Receives the message type and contents.
    /// _messageSize : Specifies the maximum message payload size.
    /// _messageType : Selects which queued messages are eligible.
    /// _messageFlags : Controls blocking, truncation, and selection behavior.
    i64 receive_queue_message(i32 _messageQueueId, MessageBuffer* _messageBuffer, s64 _messageSize, i64 _messageType, i32 _messageFlags);

    /// msgsnd : Sends a message to a System V message queue.
    /// _messageQueueId : Identifies the message queue.
    /// _messageBuffer : Supplies the message type and contents.
    /// _messageSize : Specifies the message payload size.
    /// _messageFlags : Controls blocking behavior.
    i64 send_queue_message(i32 _messageQueueId, MessageBuffer* _messageBuffer, s64 _messageSize, i32 _messageFlags);

    /// msync : Synchronizes changes in a memory-mapped file range with its backing storage.
    /// _startAddress : Specifies the beginning of the mapped range.
    /// _length : Specifies the size of the mapped range.
    /// _flags : Controls synchronous, asynchronous, and invalidation behavior.
    i64 synchronize_memory_mapping(u64 _startAddress, s64 _length, i32 _flags);

    /// munlock : Removes a memory lock from pages in a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    i64 unlock_memory(u64 _startAddress, s64 _length);

    /// munlockall : Removes all memory locks established by the calling process.
    i64 unlock_process_memory();

    /// munmap : Removes virtual-memory mappings from an address range.
    /// _address : Specifies the beginning of the mapped range.
    /// _length : Specifies the size of the range to unmap.
    i64 unmap_memory(u64 _address, s64 _length);

    /// name_to_handle_at : Converts a filesystem path into an opaque persistent file handle and mount identifier.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _name : Specifies the filesystem object.
    /// _fileHandle : Receives the opaque file handle.
    /// _mountId : Receives the mount identifier.
    /// _flags : Controls path-resolution behavior.
    i64 get_file_handle_at(i32 _directoryFileDescriptor, const c08* _name, FileHandleInfo* _fileHandle, void* _mountId, i32 _flags);

    /// nanosleep : Suspends the calling thread for a requested relative duration.
    /// _requestedTime : Specifies the requested sleep duration.
    /// _remainingTime : Receives the remaining duration if the sleep is interrupted.
    i64 sleep_for_duration(KernelTimeSpecification* _requestedTime, KernelTimeSpecification* _remainingTime);

    /// newfstat : Retrieves filesystem metadata for an object referenced by a file descriptor.
    /// _fileDescriptor : Identifies the filesystem object.
    /// _statusBuffer : Receives its filesystem metadata.
    i64 get_descriptor_status(u32 _fileDescriptor, DescriptorStatus* _statusBuffer);

    /// newfstatat : Retrieves filesystem metadata for a path resolved relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _statusBuffer : Receives its filesystem metadata.
    /// _flags : Controls symbolic-link and empty-path handling.
    i64 get_path_status_at(i32 _directoryFileDescriptor, const c08* _fileName, DescriptorStatus* _statusBuffer, i32 _flags);

    /// newuname : Retrieves identifying information about the running Linux system.
    /// _systemName : Receives kernel, hostname, machine, and related system-identification strings.
    i64 get_system_identification(SystemIdentification* _systemName);

    /// openat2 : Opens a filesystem object relative to a directory descriptor using extensible path-resolution and open options.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object to open.
    /// _openHow : Specifies open flags, creation mode, and path-resolution restrictions.
    /// _size : Specifies the size of the options structure.
    i64 open_file_at_with_options(i32 _directoryFileDescriptor, const c08* _fileName, OpenOptions* _openHow, s64 _size);

    /// openat : Opens or creates a filesystem object using a path resolved relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _flags : Controls opening and creation behavior.
    /// _mode : Specifies permissions when creating an object.
    i64 open_file_at(i32 _directoryFileDescriptor, const c08* _fileName, i32 _flags, u16 _mode);

    /// open_by_handle_at : Opens a filesystem object identified by an opaque file handle relative to a mount descriptor.
    /// _mountDirectoryFileDescriptor : Identifies a descriptor within the target mount.
    /// _fileHandle : Specifies the opaque file handle.
    /// _flags : Controls how the resulting descriptor is opened.
    i64 open_file_by_handle(i32 _mountDirectoryFileDescriptor, FileHandleInfo* _fileHandle, i32 _flags);

    /// open_tree : Opens or clones a mount subtree and returns a mount file descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the mount or subtree.
    /// _flags : Controls cloning and path resolution.
    i64 open_mount_tree(i32 _directoryFileDescriptor, const c08* _fileName, u32 _flags);

    /// open_tree_attr : Opens or clones a mount subtree while applying supplied mount attributes.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the mount or subtree.
    /// _flags : Controls cloning and path resolution.
    /// _attributes : Specifies attributes applied to the opened tree.
    /// _size : Specifies the size of the attribute structure.
    i64 open_mount_tree_with_attributes(i32 _directoryFileDescriptor, const c08* _fileName, u32 _flags, MountAttributes* _attributes, s64 _size);

    /// perf_event_open : Creates a kernel performance-monitoring event and returns its descriptor.
    /// _attributes : Specifies the event type and monitoring configuration.
    /// _processId : Selects the process or thread to monitor.
    /// _cpu : Selects the CPU to monitor.
    /// _groupFileDescriptor : Optionally places the event in an existing event group.
    /// _flags : Controls descriptor and grouping behavior.
    i64 open_performance_event(PerformanceEventAttributes* _attributes, i32 _processId, i32 _cpu, i32 _groupFileDescriptor, u64 _flags);

    /// personality : Retrieves and optionally changes execution-domain compatibility behavior for the calling process.
    /// _personality : Specifies the new personality, or the query value to leave it unchanged.
    i64 configure_process_personality(u32 _personality);

    /// pidfd_getfd : Duplicates a file descriptor from another process referenced by a process descriptor.
    /// _processFileDescriptor : Identifies the source process.
    /// _fileDescriptor : Specifies the source descriptor within that process.
    /// _flags : Reserved operation flags.
    i64 duplicate_process_descriptor(i32 _processFileDescriptor, i32 _fileDescriptor, u32 _flags);

    /// pidfd_open : Opens a file descriptor referring to a process.
    /// _processId : Identifies the process.
    /// _flags : Controls descriptor creation behavior.
    i64 open_process_descriptor(i32 _processId, u32 _flags);

    /// pidfd_send_signal : Sends a signal to a process referenced by a process descriptor.
    /// _processFileDescriptor : Identifies the target process.
    /// _signal : Specifies the signal to send.
    /// _signalInfo : Optionally supplies explicit signal information.
    /// _flags : Reserved operation flags.
    i64 signal_process(i32 _processFileDescriptor, i32 _signal, SignalInformation* _signalInfo, u32 _flags);

    /// pipe2 : Creates a unidirectional pipe and atomically applies descriptor flags.
    /// _fileDescriptors : Receives the read and write file descriptors.
    /// _flags : Controls nonblocking and close-on-exec behavior.
    i64 create_pipe(i32* _fileDescriptors, i32 _flags);

    /// pivot_root : Replaces the process's root mount with another mount and moves the previous root underneath it.
    /// _newRoot : Specifies the new root mount.
    /// _oldRootLocation : Specifies where the previous root mount is moved.
    i64 change_root_mount(const c08* _newRoot, const c08* _oldRootLocation);

    /// pkey_alloc : Allocates a hardware memory-protection key and initializes its access rights.
    /// _flags : Reserved allocation flags.
    /// _initialRights : Specifies the initial access restrictions.
    i64 allocate_memory_protection_key(u64 _flags, u64 _initialRights);

    /// pkey_free : Releases a previously allocated memory-protection key.
    /// _protectionKey : Identifies the protection key to release.
    i64 free_memory_protection_key(i32 _protectionKey);

    /// pkey_mprotect : Changes memory permissions and associates a protection key with a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _protection : Specifies the ordinary memory-access permissions.
    /// _protectionKey : Specifies the hardware protection key.
    i64 set_memory_protection_key(u64 _startAddress, s64 _length, u64 _protection, i32 _protectionKey);

    /// ppoll : Waits for events on multiple file descriptors with nanosecond timeout precision and an optional temporary signal mask.
    /// _fileDescriptors : Specifies descriptors and requested events and receives resulting events.
    /// _fileDescriptorCount : Specifies the number of descriptor entries.
    /// _timeout : Specifies the maximum relative wait time, or null for no timeout.
    /// _signalMask : Specifies the temporary signal mask, or null to leave it unchanged.
    /// _signalSetSize : Specifies the size of the signal mask.
    i64 poll_file_descriptors(PollFileDescriptor* _fileDescriptors, u32 _fileDescriptorCount, KernelTimeSpecification* _timeout, const SignalSet* _signalMask, s64 _signalSetSize);

    /// prctl : Performs a process- or thread-specific control operation selected by an option code.
    /// _option : Selects the operation.
    /// _argument2 : Supplies operation-specific data.
    /// _argument3 : Supplies operation-specific data.
    /// _argument4 : Supplies operation-specific data.
    /// _argument5 : Supplies operation-specific data.
    i64 control_process(i32 _option, u64 _argument2, u64 _argument3, u64 _argument4, u64 _argument5);

    /// pread64 : Reads bytes from a file at an explicit offset without changing the shared file position.
    /// _fileDescriptor : Identifies the file.
    /// _buffer : Receives the data.
    /// _count : Specifies the maximum number of bytes to read.
    /// _position : Specifies the file offset at which reading begins.
    i64 read_file_at_offset(u32 _fileDescriptor, c08* _buffer, s64 _count, i64 _position);

    /// preadv2 : Reads into multiple buffers from an explicit file offset with per-operation behavior flags.
    /// _fileDescriptor : Identifies the file.
    /// _vectors : Specifies the destination buffers.
    /// _vectorCount : Specifies the number of vectors.
    /// _positionLow : Supplies the low portion of the file offset.
    /// _positionHigh : Supplies the high portion of the file offset.
    /// _flags : Controls per-operation read behavior.
    i64 read_file_vectors_at_offset_with_flags(u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh, i32 _flags);

    /// preadv : Reads into multiple buffers from an explicit file offset without changing the shared file position.
    /// _fileDescriptor : Identifies the file.
    /// _vectors : Specifies the destination buffers.
    /// _vectorCount : Specifies the number of vectors.
    /// _positionLow : Supplies the low portion of the file offset.
    /// _positionHigh : Supplies the high portion of the file offset.
    i64 read_file_vectors_at_offset(u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh);

    /// prlimit64 : Retrieves and optionally replaces a resource limit for a specified process.
    /// _processId : Identifies the target process, or zero to select the caller.
    /// _resource : Selects the resource limit.
    /// _newLimit : Supplies a replacement limit, or null to leave it unchanged.
    /// _oldLimit : Receives the previous limit, or may be null.
    i64 configure_process_resource_limit(i32 _processId, u32 _resource, const ResourceLimit64* _newLimit, ResourceLimit64* _oldLimit);

    /// process_madvise : Provides memory-use advice for ranges in another process referenced by a process descriptor.
    /// _processFileDescriptor : Identifies the target process.
    /// _vectors : Specifies the target memory ranges.
    /// _vectorCount : Specifies the number of ranges.
    /// _behavior : Selects the memory advice.
    /// _flags : Supplies operation-specific flags.
    i64 advise_process_memory(i32 _processFileDescriptor, const IoVector* _vectors, s64 _vectorCount, i32 _behavior, u32 _flags);

    /// process_mrelease : Reclaims memory belonging to a process that is exiting and referenced by a process descriptor.
    /// _processFileDescriptor : Identifies the dying process.
    /// _flags : Reserved operation flags.
    i64 release_process_memory(i32 _processFileDescriptor, u32 _flags);

    /// process_vm_readv : Copies memory directly from another process into local buffers.
    /// _processId : Identifies the source process.
    /// _localVectors : Specifies local destination buffers.
    /// _localVectorCount : Specifies the number of local vectors.
    /// _remoteVectors : Specifies source ranges in the remote process.
    /// _remoteVectorCount : Specifies the number of remote vectors.
    /// _flags : Reserved operation flags.
    i64 read_process_memory(i32 _processId, const IoVector* _localVectors, u64 _localVectorCount, const IoVector* _remoteVectors, u64 _remoteVectorCount, u64 _flags);

    /// process_vm_writev : Copies memory directly from local buffers into another process.
    /// _processId : Identifies the destination process.
    /// _localVectors : Specifies local source buffers.
    /// _localVectorCount : Specifies the number of local vectors.
    /// _remoteVectors : Specifies destination ranges in the remote process.
    /// _remoteVectorCount : Specifies the number of remote vectors.
    /// _flags : Reserved operation flags.
    i64 write_process_memory(i32 _processId, const IoVector* _localVectors, u64 _localVectorCount, const IoVector* _remoteVectors, u64 _remoteVectorCount, u64 _flags);

    /// pselect6 : Waits until descriptors become ready, a timeout expires, or a signal arrives while optionally replacing the signal mask.
    /// _descriptorRange : Specifies one greater than the highest descriptor examined.
    /// _readFileDescriptors : Specifies and receives descriptors ready for reading.
    /// _writeFileDescriptors : Specifies and receives descriptors ready for writing.
    /// _exceptionFileDescriptors : Specifies and receives descriptors with exceptional conditions.
    /// _timeout : Specifies the maximum wait duration.
    /// _signalMaskData : Points to the kernel structure containing the temporary signal mask and its size.
    i64 wait_for_descriptor_events(i32 _descriptorRange, DescriptorSet* _readFileDescriptors, DescriptorSet* _writeFileDescriptors, DescriptorSet* _exceptionFileDescriptors, KernelTimeSpecification* _timeout, void* _signalMaskData);

    /// ptrace : Performs a tracing, debugging, or inspection operation on another thread.
    /// _request : Selects the tracing operation.
    /// _processId : Identifies the target thread.
    /// _address : Supplies an operation-specific target address.
    /// _data : Supplies operation-specific data or a userspace address.
    i64 control_process_trace(i64 _request, i64 _processId, u64 _address, u64 _data);

    /// pwrite64 : Writes bytes to a file at an explicit offset without changing the shared file position.
    /// _fileDescriptor : Identifies the file.
    /// _buffer : Supplies the data.
    /// _count : Specifies the number of bytes to write.
    /// _position : Specifies the file offset at which writing begins.
    i64 write_file_at_offset(u32 _fileDescriptor, const c08* _buffer, s64 _count, i64 _position);

    /// pwritev2 : Writes from multiple buffers at an explicit file offset with per-operation behavior flags.
    /// _fileDescriptor : Identifies the file.
    /// _vectors : Specifies the source buffers.
    /// _vectorCount : Specifies the number of vectors.
    /// _positionLow : Supplies the low portion of the file offset.
    /// _positionHigh : Supplies the high portion of the file offset.
    /// _flags : Controls per-operation write behavior.
    i64 write_file_vectors_at_offset_with_flags(u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh, i32 _flags);

    /// pwritev : Writes from multiple buffers at an explicit file offset without changing the shared file position.
    /// _fileDescriptor : Identifies the file.
    /// _vectors : Specifies the source buffers.
    /// _vectorCount : Specifies the number of vectors.
    /// _positionLow : Supplies the low portion of the file offset.
    /// _positionHigh : Supplies the high portion of the file offset.
    i64 write_file_vectors_at_offset(u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh);

    /// quotactl : Performs a filesystem quota-management operation using a filesystem path or special device.
    /// _command : Selects the quota operation and quota type.
    /// _specialDevice : Identifies the filesystem or quota-bearing device.
    /// _quotaId : Identifies the user, group, or project quota.
    /// _address : Supplies or receives command-specific quota data.
    i64 control_filesystem_quota(u32 _command, const c08* _specialDevice, u32 _quotaId, void* _address);

    /// quotactl_fd : Performs a filesystem quota-management operation using an open file descriptor.
    /// _fileDescriptor : Identifies an object on the target filesystem.
    /// _command : Selects the quota operation and quota type.
    /// _quotaId : Identifies the user, group, or project quota.
    /// _address : Supplies or receives command-specific quota data.
    i64 control_filesystem_quota_by_descriptor(u32 _fileDescriptor, u32 _command, u32 _quotaId, void* _address);
    /// read : Reads bytes from an open file descriptor into a buffer.
    /// _fileDescriptor : Identifies the source descriptor.
    /// _buffer : Receives the bytes read.
    /// _count : Specifies the maximum number of bytes to read.
    i64 read_data(u32 _fileDescriptor, c08* _buffer, s64 _count);

    /// readahead : Requests that file data be loaded into the page cache before it is needed.
    /// _fileDescriptor : Identifies the source file.
    /// _offset : Specifies the starting file offset.
    /// _count : Specifies the number of bytes to preload.
    i64 preload_file_data(i32 _fileDescriptor, i64 _offset, s64 _count);

    /// readlinkat : Reads the target path stored in a symbolic link resolved relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the symbolic link.
    /// _buffer : Receives the link target without an added null terminator.
    /// _bufferSize : Specifies the available buffer size.
    i64 read_symbolic_link_at(i32 _directoryFileDescriptor, const c08* _pathName, c08* _buffer, i32 _bufferSize);

    /// readv : Reads data from a descriptor into multiple buffers in a single operation.
    /// _fileDescriptor : Identifies the source descriptor.
    /// _vectors : Specifies the destination buffers.
    /// _vectorCount : Specifies the number of buffers.
    i64 read_data_vectors(u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount);

    /// reboot : Performs a privileged system reboot, shutdown, suspend, or related control operation.
    /// _magic1 : Supplies the first required safety magic value.
    /// _magic2 : Supplies the second required safety magic value.
    /// _command : Selects the reboot operation.
    /// _argument : Supplies optional command-specific data.
    i64 control_system_power(i32 _magic1, i32 _magic2, u32 _command, void* _argument);

    /// recvfrom : Receives data from a socket and optionally returns the sender's address.
    /// _fileDescriptor : Identifies the socket.
    /// _buffer : Receives the incoming data.
    /// _size : Specifies the available buffer size.
    /// _flags : Controls receive behavior.
    /// _address : Optionally receives the sender's address.
    /// _addressLength : Supplies the address-buffer size and receives the actual address size.
    i64 receive_socket_data(i32 _fileDescriptor, void* _buffer, s64 _size, u32 _flags, SocketAddress* _address, i32* _addressLength);

    /// recvmmsg : Receives multiple socket messages in one operation with an optional timeout.
    /// _fileDescriptor : Identifies the socket.
    /// _messages : Supplies message buffers and receives per-message results.
    /// _messageCount : Specifies the maximum number of messages.
    /// _flags : Controls receive behavior.
    /// _timeout : Specifies the maximum wait duration.
    i64 receive_socket_messages(i32 _fileDescriptor, MultiMessageHeader* _messages, u32 _messageCount, u32 _flags, KernelTimeSpecification* _timeout);

    /// recvmsg : Receives a socket message including payload, address, and ancillary data.
    /// _fileDescriptor : Identifies the socket.
    /// _message : Describes destination buffers and receives message metadata.
    /// _flags : Controls receive behavior.
    i64 receive_socket_message(i32 _fileDescriptor, UserMessageHeader* _message, u32 _flags);

    /// remap_file_pages : Reassigns pages within a nonlinear file-backed memory mapping.
    /// _startAddress : Specifies the beginning of the mapping.
    /// _size : Specifies the affected mapping size.
    /// _protection : Supplies protection information.
    /// _pageOffset : Specifies the new file-page offset.
    /// _flags : Controls remapping behavior.
    i64 remap_file_pages(u64 _startAddress, u64 _size, u64 _protection, u64 _pageOffset, u64 _flags);

    /// removexattr : Removes a named extended attribute from a filesystem object.
    /// _pathName : Specifies the filesystem object.
    /// _name : Specifies the extended attribute to remove.
    i64 remove_extended_attribute(const c08* _pathName, const c08* _name);

    /// removexattrat : Removes a named extended attribute using directory-relative path resolution.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the filesystem object.
    /// _lookupFlags : Controls path-resolution behavior.
    /// _name : Specifies the extended attribute to remove.
    i64 remove_extended_attribute_at(i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, const c08* _name);

    /// renameat2 : Renames or exchanges filesystem objects using directory-relative paths and operation flags.
    /// _oldDirectoryFileDescriptor : Specifies the base directory for the existing path.
    /// _oldName : Specifies the existing path.
    /// _newDirectoryFileDescriptor : Specifies the base directory for the destination path.
    /// _newName : Specifies the destination path.
    /// _flags : Controls replacement, exchange, and whiteout behavior.
    i64 rename_path_at_with_flags(i32 _oldDirectoryFileDescriptor, const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName, u32 _flags);

    /// renameat : Renames a filesystem object using directory-relative source and destination paths.
    /// _oldDirectoryFileDescriptor : Specifies the base directory for the existing path.
    /// _oldName : Specifies the existing path.
    /// _newDirectoryFileDescriptor : Specifies the base directory for the destination path.
    /// _newName : Specifies the destination path.
    i64 rename_path_at(i32 _oldDirectoryFileDescriptor, const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName);

    /// request_key : Finds an existing kernel key or requests that one be constructed.
    /// _type : Specifies the key type.
    /// _description : Specifies the key description to search for.
    /// _calloutInfo : Supplies data used by a userspace key-construction helper.
    /// _destinationKeyringId : Specifies the keyring into which a constructed key should be linked.
    i64 request_kernel_key(const c08* _type, const c08* _description, const c08* _calloutInfo, i32 _destinationKeyringId);

    /// restart_syscall : Restarts a previously interrupted restartable system call.
    i64 restart_interrupted_syscall();

    /// rseq : Registers or unregisters a userspace restartable-sequence area for the calling thread.
    /// _restartableSequence : Specifies the userspace restartable-sequence state.
    /// _restartableSequenceLength : Specifies the structure size.
    /// _flags : Controls registration behavior.
    /// _signature : Specifies the architecture-specific restart signature.
    i64 configure_restartable_sequence(RestartableSequence* _restartableSequence, u32 _restartableSequenceLength, i32 _flags, u32 _signature);

    /// rt_sigaction : Retrieves or changes the action performed when a signal is delivered.
    /// _signal : Identifies the signal.
    /// _action : Supplies the new signal action, or null to leave it unchanged.
    /// _oldAction : Receives the previous signal action, or may be null.
    /// _signalSetSize : Specifies the size of the signal mask representation.
    i64 configure_signal_action(i32 _signal, const SignalAction* _action, SignalAction* _oldAction, s64 _signalSetSize);

    /// rt_sigpending : Retrieves signals that are blocked and currently pending.
    /// _signalSet : Receives the pending signal set.
    /// _signalSetSize : Specifies the size of the signal-set representation.
    i64 get_pending_signals(SignalSet* _signalSet, s64 _signalSetSize);

    /// rt_sigprocmask : Retrieves or changes the calling thread's blocked signal set.
    /// _how : Specifies how the new mask is combined with the current mask.
    /// _newSignalSet : Supplies the new signal set, or null to only query.
    /// _oldSignalSet : Receives the previous signal set, or may be null.
    /// _signalSetSize : Specifies the size of the signal-set representation.
    i64 configure_signal_mask(i32 _how, SignalSet* _newSignalSet, SignalSet* _oldSignalSet, s64 _signalSetSize);

    /// rt_sigqueueinfo : Sends a signal with explicitly supplied signal information to a process.
    /// _processId : Identifies the target process.
    /// _signal : Specifies the signal to send.
    /// _signalInfo : Supplies accompanying signal information.
    i64 queue_process_signal(i32 _processId, i32 _signal, SignalInformation* _signalInfo);

    /// rt_sigreturn : Restores execution state saved by the kernel when entering a signal handler.
    i64 return_from_signal_handler();

    /// rt_sigsuspend : Temporarily replaces the signal mask and sleeps until a signal is delivered.
    /// _newSignalSet : Specifies the temporary signal mask.
    /// _signalSetSize : Specifies the size of the signal-set representation.
    i64 suspend_until_signal(SignalSet* _newSignalSet, s64 _signalSetSize);

    /// rt_sigtimedwait : Waits synchronously for one of a selected set of signals with an optional timeout.
    /// _signalSet : Specifies the signals to wait for.
    /// _signalInfo : Receives information about the delivered signal.
    /// _timeout : Specifies the maximum wait duration.
    /// _signalSetSize : Specifies the size of the signal-set representation.
    i64 wait_for_signal(const SignalSet* _signalSet, SignalInformation* _signalInfo, const KernelTimeSpecification* _timeout, s64 _signalSetSize);

    /// rt_tgsigqueueinfo : Sends a signal with explicit signal information to a specific thread within a thread group.
    /// _threadGroupId : Identifies the target thread group.
    /// _processId : Identifies the target thread.
    /// _signal : Specifies the signal to send.
    /// _signalInfo : Supplies accompanying signal information.
    i64 queue_thread_signal(i32 _threadGroupId, i32 _processId, i32 _signal, SignalInformation* _signalInfo);

    /// sched_getaffinity : Retrieves the CPUs on which a thread is permitted to execute.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _length : Specifies the CPU-mask buffer size.
    /// _cpuMask : Receives the permitted CPU mask.
    i64 get_cpu_affinity(i32 _processId, u32 _length, u64* _cpuMask);

    /// sched_getattr : Retrieves extended scheduler attributes for a thread.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _attributes : Receives scheduler configuration.
    /// _size : Specifies the attribute-structure size.
    /// _flags : Supplies operation flags.
    i64 get_scheduler_attributes(i32 _processId, SchedulerAttributes* _attributes, u32 _size, u32 _flags);

    /// sched_getparam : Retrieves scheduler parameters for a thread.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _parameters : Receives scheduler parameters.
    i64 get_scheduler_parameters(i32 _processId, SchedulerParameters* _parameters);

    /// sched_get_priority_max : Returns the highest static priority supported by a scheduling policy.
    /// _policy : Selects the scheduling policy.
    i64 get_maximum_scheduler_priority(i32 _policy);

    /// sched_get_priority_min : Returns the lowest static priority supported by a scheduling policy.
    /// _policy : Selects the scheduling policy.
    i64 get_minimum_scheduler_priority(i32 _policy);

    /// sched_getscheduler : Returns the scheduling policy currently assigned to a thread.
    /// _processId : Identifies the target thread, or zero to select the caller.
    i64 get_scheduler_policy(i32 _processId);

    /// sched_rr_get_interval : Retrieves the round-robin scheduling quantum for a thread.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _interval : Receives the scheduling quantum.
    i64 get_round_robin_interval(i32 _processId, KernelTimeSpecification* _interval);

    /// sched_setaffinity : Restricts the CPUs on which a thread may execute.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _length : Specifies the CPU-mask buffer size.
    /// _cpuMask : Specifies the permitted CPU mask.
    i64 set_cpu_affinity(i32 _processId, u32 _length, u64* _cpuMask);

    /// sched_setattr : Changes extended scheduler attributes for a thread.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _attributes : Specifies the scheduler configuration.
    /// _flags : Supplies operation flags.
    i64 set_scheduler_attributes(i32 _processId, SchedulerAttributes* _attributes, u32 _flags);

    /// sched_setparam : Changes scheduler parameters for a thread without changing its scheduling policy.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _parameters : Specifies the new scheduler parameters.
    i64 set_scheduler_parameters(i32 _processId, SchedulerParameters* _parameters);

    /// sched_setscheduler : Changes a thread's scheduling policy and associated parameters.
    /// _processId : Identifies the target thread, or zero to select the caller.
    /// _policy : Specifies the new scheduling policy.
    /// _parameters : Specifies policy-dependent scheduler parameters.
    i64 set_scheduler_policy(i32 _processId, i32 _policy, SchedulerParameters* _parameters);

    /// sched_yield : Voluntarily yields execution so another runnable thread may be scheduled.
    i64 yield_processor();

    /// seccomp : Configures syscall filtering or retrieves seccomp-related capabilities for the calling thread.
    /// _operation : Selects the seccomp operation.
    /// _flags : Controls operation-specific behavior.
    /// _arguments : Supplies operation-specific data.
    i64 configure_syscall_filtering(u32 _operation, u32 _flags, void* _arguments);

    /// semctl : Performs a control or metadata operation on a System V semaphore set.
    /// _semaphoreId : Identifies the semaphore set.
    /// _semaphoreNumber : Selects a semaphore within the set when required.
    /// _command : Selects the operation.
    /// _argument : Supplies command-specific data or a userspace address.
    i64 control_semaphore_set(i32 _semaphoreId, i32 _semaphoreNumber, i32 _command, u64 _argument);

    /// semget : Opens an existing System V semaphore set or creates one for a key.
    /// _key : Identifies the semaphore-set namespace key.
    /// _semaphoreCount : Specifies the number of semaphores when creating a set.
    /// _flags : Controls creation and permissions.
    i64 get_semaphore_set(i32 _key, i32 _semaphoreCount, i32 _flags);

    /// semop : Atomically performs one or more operations on a System V semaphore set.
    /// _semaphoreId : Identifies the semaphore set.
    /// _operations : Specifies the semaphore operations.
    /// _operationCount : Specifies the number of operations.
    i64 perform_semaphore_operations(i32 _semaphoreId, SemaphoreOperation* _operations, u32 _operationCount);

    /// semtimedop : Atomically performs System V semaphore operations with a relative timeout.
    /// _semaphoreId : Identifies the semaphore set.
    /// _operations : Specifies the semaphore operations.
    /// _operationCount : Specifies the number of operations.
    /// _timeout : Specifies the maximum wait duration.
    i64 perform_semaphore_operations_until(i32 _semaphoreId, SemaphoreOperation* _operations, u32 _operationCount, const KernelTimeSpecification* _timeout);

    /// sendfile64 : Copies file data directly between file descriptors without routing the payload through userspace.
    /// _outputFileDescriptor : Identifies the destination descriptor.
    /// _inputFileDescriptor : Identifies the source descriptor.
    /// _offset : Optionally supplies and receives the source offset.
    /// _count : Specifies the maximum number of bytes to copy.
    i64 copy_file_to_descriptor(i32 _outputFileDescriptor, i32 _inputFileDescriptor, i64* _offset, s64 _count);

    /// sendmmsg : Sends multiple socket messages in a single operation.
    /// _fileDescriptor : Identifies the socket.
    /// _messages : Specifies the messages and receives per-message byte counts.
    /// _messageCount : Specifies the number of messages.
    /// _flags : Controls send behavior.
    i64 send_socket_messages(i32 _fileDescriptor, MultiMessageHeader* _messages, u32 _messageCount, u32 _flags);

    /// sendmsg : Sends a socket message containing payload, destination, and optional ancillary data.
    /// _fileDescriptor : Identifies the socket.
    /// _message : Describes the message to send.
    /// _flags : Controls send behavior.
    i64 send_socket_message(i32 _fileDescriptor, UserMessageHeader* _message, u32 _flags);

    /// sendto : Sends data through a socket, optionally specifying the destination address.
    /// _fileDescriptor : Identifies the socket.
    /// _buffer : Supplies the data to send.
    /// _length : Specifies the number of bytes to send.
    /// _flags : Controls send behavior.
    /// _address : Optionally specifies the destination address.
    /// _addressLength : Specifies the address structure size.
    i64 send_socket_data(i32 _fileDescriptor, void* _buffer, s64 _length, u32 _flags, SocketAddress* _address, i32 _addressLength);

    /// setdomainname : Changes the calling process's UTS namespace domain name.
    /// _name : Supplies the new domain name.
    /// _length : Specifies its length in bytes.
    i64 set_system_domain_name(c08* _name, i32 _length);

    /// setfsgid : Changes the calling thread's filesystem group ID.
    /// _groupId : Specifies the requested filesystem group ID.
    i64 set_filesystem_group_id(u32 _groupId);

    /// setfsuid : Changes the calling thread's filesystem user ID.
    /// _userId : Specifies the requested filesystem user ID.
    i64 set_filesystem_user_id(u32 _userId);

    /// setgid : Changes the calling thread's group identity according to its privileges.
    /// _groupId : Specifies the requested group ID.
    i64 set_group_id(u32 _groupId);

    /// setgroups : Replaces the calling thread's supplementary group list.
    /// _groupSetSize : Specifies the number of group IDs.
    /// _groupList : Supplies the new supplementary group IDs.
    i64 set_supplementary_groups(i32 _groupSetSize, u32* _groupList);

    /// sethostname : Changes the hostname of the calling process's UTS namespace.
    /// _name : Supplies the new hostname.
    /// _length : Specifies its length in bytes.
    i64 set_system_host_name(c08* _name, i32 _length);

    /// setitimer : Configures a process interval timer and optionally returns its previous state.
    /// _timerType : Selects the interval timer.
    /// _newValue : Specifies the new timer duration and reload interval.
    /// _oldValue : Optionally receives the previous timer state.
    i64 set_interval_timer(i32 _timerType, LegacyIntervalTimerValue* _newValue, LegacyIntervalTimerValue* _oldValue);

    /// set_mempolicy : Sets the calling thread's default NUMA memory-allocation policy.
    /// _mode : Selects the NUMA policy.
    /// _nodeMask : Specifies eligible NUMA nodes.
    /// _maximumNode : Specifies the highest node representable by the mask.
    i64 set_memory_policy(i32 _mode, const u64* _nodeMask, u64 _maximumNode);

    /// set_mempolicy_home_node : Sets the preferred home NUMA node for a virtual-memory range.
    /// _startAddress : Specifies the beginning of the memory range.
    /// _length : Specifies the size of the memory range.
    /// _homeNode : Specifies the preferred NUMA node.
    /// _flags : Supplies operation flags.
    i64 set_memory_home_node(u64 _startAddress, u64 _length, u64 _homeNode, u64 _flags);

    /// setns : Moves the calling thread into one or more namespaces referenced by a file descriptor.
    /// _fileDescriptor : Identifies the namespace or process namespace set.
    /// _flags : Selects the namespace type or types to join.
    i64 join_namespace(i32 _fileDescriptor, i32 _flags);

    /// setpgid : Changes the process-group membership of a process.
    /// _processId : Identifies the target process.
    /// _processGroupId : Specifies the destination process group.
    i64 set_process_group(i32 _processId, i32 _processGroupId);

    /// setpriority : Changes the scheduling nice value of selected processes, process groups, or users.
    /// _which : Selects what kind of entity _who identifies.
    /// _who : Identifies the target.
    /// _niceValue : Specifies the requested nice value.
    i64 set_nice_priority(i32 _which, i32 _who, i32 _niceValue);

    /// setregid : Changes the real and effective group IDs of the calling thread.
    /// _realGroupId : Specifies the new real group ID.
    /// _effectiveGroupId : Specifies the new effective group ID.
    i64 set_real_effective_group_ids(u32 _realGroupId, u32 _effectiveGroupId);

    /// setresgid : Changes the real, effective, and saved group IDs of the calling thread.
    /// _realGroupId : Specifies the new real group ID.
    /// _effectiveGroupId : Specifies the new effective group ID.
    /// _savedGroupId : Specifies the new saved group ID.
    i64 set_group_credentials(u32 _realGroupId, u32 _effectiveGroupId, u32 _savedGroupId);

    /// setresuid : Changes the real, effective, and saved user IDs of the calling thread.
    /// _realUserId : Specifies the new real user ID.
    /// _effectiveUserId : Specifies the new effective user ID.
    /// _savedUserId : Specifies the new saved user ID.
    i64 set_user_credentials(u32 _realUserId, u32 _effectiveUserId, u32 _savedUserId);

    /// setreuid : Changes the real and effective user IDs of the calling thread.
    /// _realUserId : Specifies the new real user ID.
    /// _effectiveUserId : Specifies the new effective user ID.
    i64 set_real_effective_user_ids(u32 _realUserId, u32 _effectiveUserId);

    /// setrlimit : Changes the soft and hard limits for a process resource.
    /// _resource : Selects the resource.
    /// _resourceLimit : Specifies the new soft and hard limits.
    i64 set_resource_limit(u32 _resource, ResourceLimit* _resourceLimit);

    /// set_robust_list : Registers the calling thread's robust-futex list with the kernel.
    /// _head : Specifies the robust-list head.
    /// _length : Specifies the structure size.
    i64 set_thread_robust_futex_list(RobustFutexListHead* _head, s64 _length);

    /// setsid : Creates a new session and process group with the caller as leader.
    i64 create_process_session();

    /// setsockopt : Changes a socket option at a specified protocol level.
    /// _fileDescriptor : Identifies the socket.
    /// _level : Selects the protocol level defining the option.
    /// _optionName : Selects the option.
    /// _optionValue : Supplies the option value.
    /// _optionLength : Specifies the option-value size.
    i64 set_socket_option(i32 _fileDescriptor, i32 _level, i32 _optionName, c08* _optionValue, i32 _optionLength);

    /// set_tid_address : Registers the userspace address that the kernel clears when the calling thread exits.
    /// _threadIdAddress : Specifies the thread-ID storage address.
    i64 set_thread_id_address(i32* _threadIdAddress);

    /// settimeofday : Sets the system wall-clock time and optionally legacy timezone information.
    /// _timeValue : Specifies the new wall-clock time.
    /// _timezone : Optionally supplies legacy timezone information.
    i64 set_wall_clock_time(LegacyTimeValue* _timeValue, TimezoneInformation* _timezone);

    /// setuid : Changes the calling thread's user identity according to its privileges.
    /// _userId : Specifies the requested user ID.
    i64 set_user_id(u32 _userId);

    /// setxattr : Creates or replaces a named extended attribute on a filesystem object.
    /// _pathName : Specifies the filesystem object.
    /// _name : Specifies the extended attribute name.
    /// _value : Supplies the attribute value.
    /// _size : Specifies the attribute-value size.
    /// _flags : Controls create-only or replace-only behavior.
    i64 set_extended_attribute(const c08* _pathName, const c08* _name, const void* _value, s64 _size, i32 _flags);

    /// setxattrat : Creates or replaces an extended attribute using directory-relative path resolution and extended arguments.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the filesystem object.
    /// _lookupFlags : Controls path-resolution behavior.
    /// _name : Specifies the extended attribute name.
    /// _arguments : Supplies attribute value, size, and operation flags.
    /// _size : Specifies the size of the argument structure.
    i64 set_extended_attribute_at(i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, const c08* _name, const ExtendedAttributeArguments* _arguments, s64 _size);

    /// shmat : Attaches a System V shared-memory segment to the calling process's address space.
    /// _sharedMemoryId : Identifies the shared-memory segment.
    /// _sharedMemoryAddress : Supplies the requested attachment address or null for automatic placement.
    /// _flags : Controls attachment behavior.
    i64 attach_shared_memory(i32 _sharedMemoryId, c08* _sharedMemoryAddress, i32 _flags);

    /// shmctl : Queries or modifies a System V shared-memory segment.
    /// _sharedMemoryId : Identifies the shared-memory segment.
    /// _command : Selects the operation.
    /// _buffer : Supplies or receives segment metadata.
    i64 control_shared_memory(i32 _sharedMemoryId, i32 _command, SharedMemoryStatus* _buffer);

    /// shmdt : Detaches a System V shared-memory segment from the calling process.
    /// _sharedMemoryAddress : Specifies the attachment address to detach.
    i64 detach_shared_memory(c08* _sharedMemoryAddress);

    /// shmget : Opens an existing System V shared-memory segment or creates one for a key.
    /// _key : Identifies the shared-memory namespace key.
    /// _size : Specifies the requested segment size when creating it.
    /// _flags : Controls creation and permissions.
    i64 get_shared_memory(i32 _key, s64 _size, i32 _flags);

    /// shutdown : Disables receiving, sending, or both directions of communication on a socket.
    /// _fileDescriptor : Identifies the socket.
    /// _how : Selects which communication directions to disable.
    i64 shutdown_socket(i32 _fileDescriptor, i32 _how);

    /// sigaltstack : Retrieves or changes the alternate stack used for signal handlers.
    /// _newStack : Supplies the new alternate stack configuration, or null to only query.
    /// _oldStack : Receives the previous alternate stack configuration, or may be null.
    i64 configure_signal_stack(const SignalStack* _newStack, SignalStack* _oldStack);

    /// signalfd4 : Creates or reconfigures a file descriptor that reports selected signals as readable records.
    /// _fileDescriptor : Specifies an existing signal descriptor to reconfigure, or -1 to create one.
    /// _signalMask : Specifies which signals are reported.
    /// _signalMaskSize : Specifies the signal-set size.
    /// _flags : Controls nonblocking and close-on-exec behavior.
    i64 configure_signal_descriptor(i32 _fileDescriptor, SignalSet* _signalMask, s64 _signalMaskSize, i32 _flags);

    /// socket : Creates a socket endpoint and returns its file descriptor.
    /// _family : Selects the communication domain.
    /// _type : Selects the socket type and creation flags.
    /// _protocol : Selects the protocol.
    i64 create_socket(i32 _family, i32 _type, i32 _protocol);

    /// socketpair : Creates a connected pair of sockets.
    /// _family : Selects the communication domain.
    /// _type : Selects the socket type and creation flags.
    /// _protocol : Selects the protocol.
    /// _socketDescriptors : Receives the two socket descriptors.
    i64 create_socket_pair(i32 _family, i32 _type, i32 _protocol, i32* _socketDescriptors);

    /// splice : Transfers data between two file descriptors through a kernel pipe without copying the payload through userspace.
    /// _inputFileDescriptor : Identifies the source descriptor.
    /// _inputOffset : Optionally supplies and receives the source offset.
    /// _outputFileDescriptor : Identifies the destination descriptor.
    /// _outputOffset : Optionally supplies and receives the destination offset.
    /// _length : Specifies the maximum number of bytes to transfer.
    /// _flags : Controls transfer behavior.
    i64 splice_data(i32 _inputFileDescriptor, i64* _inputOffset, i32 _outputFileDescriptor, i64* _outputOffset, s64 _length, u32 _flags);

    /// statfs : Retrieves filesystem-wide statistics for the filesystem containing a path.
    /// _pathName : Specifies a path within the filesystem.
    /// _buffer : Receives filesystem statistics.
    i64 get_filesystem_statistics(const c08* _pathName, FilesystemStatistics* _buffer);

    /// statmount : Retrieves detailed information about a mount identified by a mount request.
    /// _request : Identifies the mount and requested information.
    /// _buffer : Receives mount information.
    /// _bufferSize : Specifies the available output-buffer size.
    /// _flags : Controls the query.
    i64 get_mount_information(const MountIdentifierRequest* _request, MountStatistics* _buffer, s64 _bufferSize, u32 _flags);

    /// statx : Retrieves extended filesystem metadata for a path with explicit control over lookup and requested fields.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _flags : Controls path-resolution behavior.
    /// _mask : Specifies which metadata fields are requested.
    /// _buffer : Receives the resulting metadata.
    i64 get_extended_file_status(i32 _directoryFileDescriptor, const c08* _fileName, u32 _flags, u32 _mask, ExtendedFileStatus* _buffer);

    /// swapoff : Disables swapping to a specified swap file or device.
    /// _specialFile : Specifies the swap area to disable.
    i64 disable_swap(const c08* _specialFile);

    /// swapon : Enables swapping to a specified file or device.
    /// _specialFile : Specifies the swap area to enable.
    /// _swapFlags : Controls swap priority and discard behavior.
    i64 enable_swap(const c08* _specialFile, i32 _swapFlags);

    /// symlinkat : Creates a symbolic link at a path resolved relative to a directory descriptor.
    /// _oldName : Specifies the target text stored in the symbolic link.
    /// _newDirectoryFileDescriptor : Specifies the base directory for the new link path.
    /// _newName : Specifies the symbolic-link path to create.
    i64 create_symbolic_link_at(const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName);

    /// sync : Schedules all pending filesystem data and metadata writes system-wide.
    i64 synchronize_filesystems();

    /// sync_file_range : Initiates or waits for writeback of a selected byte range of an open file.
    /// _fileDescriptor : Identifies the file.
    /// _offset : Specifies the beginning of the byte range.
    /// _byteCount : Specifies the range length.
    /// _flags : Controls writeback and waiting behavior.
    i64 synchronize_file_range(i32 _fileDescriptor, i64 _offset, i64 _byteCount, u32 _flags);

    /// syncfs : Synchronizes pending writes for the filesystem containing an open file descriptor.
    /// _fileDescriptor : Identifies an object on the target filesystem.
    i64 synchronize_filesystem(i32 _fileDescriptor);

    /// sysinfo : Retrieves system-wide memory, swap, uptime, and process statistics.
    /// _information : Receives the system information.
    i64 get_system_information(SystemInformation* _information);

    /// syslog : Reads or controls the kernel logging buffer according to an operation code.
    /// _type : Selects the logging operation.
    /// _buffer : Supplies or receives operation-specific log data.
    /// _length : Specifies the buffer size or operation-specific length.
    /// control_kernel_log : Reads from or controls the kernel message buffer according to an operation code.
    /// _type : Selects the kernel-log operation.
    /// _buffer : Supplies or receives operation-specific log data.
    /// _length : Specifies the buffer size or operation-specific length.
    i64 control_kernel_log(i32 _type, c08* _buffer, i32 _length);

    /// tee : Duplicates data between pipes without consuming it from the source pipe.
    /// _inputFileDescriptor : Identifies the source pipe.
    /// _outputFileDescriptor : Identifies the destination pipe.
    /// _length : Specifies the maximum number of bytes to duplicate.
    /// _flags : Controls transfer behavior.
    i64 duplicate_pipe_data(i32 _inputFileDescriptor, i32 _outputFileDescriptor, s64 _length, u32 _flags);

    /// tgkill : Sends a signal to a specific thread within a specific thread group.
    /// _threadGroupId : Identifies the target thread group.
    /// _threadId : Identifies the target thread.
    /// _signal : Specifies the signal to send.
    i64 send_thread_signal(i32 _threadGroupId, i32 _threadId, i32 _signal);

    /// timer_create : Creates a POSIX per-process timer using a specified clock.
    /// _clockId : Selects the clock used by the timer.
    /// _timerEventSpecification : Specifies how timer expirations are reported.
    /// _createdTimerId : Receives the newly created timer identifier.
    i64 create_process_timer(const i32 _clockId, SignalEvent* _timerEventSpecification, i32* _createdTimerId);

    /// timer_delete : Deletes a POSIX per-process timer.
    /// _timerId : Identifies the timer to delete.
    i64 delete_process_timer(i32 _timerId);

    /// timerfd_create : Creates a timer exposed through a readable file descriptor.
    /// _clockId : Selects the clock used by the timer.
    /// _flags : Controls descriptor creation behavior.
    i64 create_timer_descriptor(i32 _clockId, i32 _flags);

    /// timerfd_gettime : Retrieves the current expiration and interval settings of a timer descriptor.
    /// _fileDescriptor : Identifies the timer descriptor.
    /// _currentTimer : Receives the current timer configuration.
    i64 get_timer_descriptor(i32 _fileDescriptor, KernelIntervalTimerSpecification* _currentTimer);

    /// timerfd_settime : Arms, disarms, or reconfigures a timer descriptor.
    /// _fileDescriptor : Identifies the timer descriptor.
    /// _flags : Controls absolute or relative expiration behavior.
    /// _newTimer : Specifies the new expiration and repeat interval.
    /// _oldTimer : Optionally receives the previous timer configuration.
    i64 set_timer_descriptor(i32 _fileDescriptor, i32 _flags, const KernelIntervalTimerSpecification* _newTimer, KernelIntervalTimerSpecification* _oldTimer);

    /// timer_getoverrun : Returns the number of additional timer expirations that occurred before the most recent notification was delivered.
    /// _timerId : Identifies the POSIX timer.
    i64 get_timer_overrun_count(i32 _timerId);

    /// timer_gettime : Retrieves the remaining expiration time and repeat interval of a POSIX timer.
    /// _timerId : Identifies the timer.
    /// _setting : Receives the current timer configuration.
    i64 get_process_timer(i32 _timerId, KernelIntervalTimerSpecification* _setting);

    /// timer_settime : Arms, disarms, or reconfigures a POSIX per-process timer.
    /// _timerId : Identifies the timer.
    /// _flags : Controls absolute or relative expiration behavior.
    /// _newSetting : Specifies the new expiration and repeat interval.
    /// _oldSetting : Optionally receives the previous timer configuration.
    i64 set_process_timer(i32 _timerId, i32 _flags, const KernelIntervalTimerSpecification* _newSetting, KernelIntervalTimerSpecification* _oldSetting);

    /// times : Retrieves CPU execution-time statistics for the calling process and its waited-for children.
    /// _timesBuffer : Receives process and child CPU-time statistics.
    i64 get_process_times(ProcessTimeStatistics* _timesBuffer);

    /// tkill : Sends a signal directly to a thread identified by its thread ID.
    /// _threadId : Identifies the target thread.
    /// _signal : Specifies the signal to send.
    i64 send_signal_to_thread(i32 _threadId, i32 _signal);

    /// truncate : Changes the size of a regular file identified by path.
    /// _path : Specifies the file.
    /// _length : Specifies the new file size in bytes.
    i64 resize_file_at_path(const c08* _path, i64 _length);

    /// umask : Replaces the calling process's file-creation permission mask and returns the previous mask.
    /// _mask : Specifies permission bits to suppress during file creation.
    i64 set_file_creation_mask(i32 _mask);

    /// umount : Detaches a mounted filesystem according to the supplied unmount flags.
    /// _name : Specifies the mount point or mounted filesystem.
    /// _flags : Controls normal, forced, lazy, or expiration-based unmounting.
    i64 unmount_filesystem(c08* _name, i32 _flags);

    /// unlinkat : Removes a filesystem object using a path resolved relative to a directory descriptor.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _pathName : Specifies the object to remove.
    /// _flags : Controls whether a file or directory is removed.
    i64 remove_path_at(i32 _directoryFileDescriptor, const c08* _pathName, i32 _flags);

    /// unshare : Detaches selected execution resources from those shared with other processes or threads.
    /// _unshareFlags : Selects which namespaces or resources become private.
    i64 unshare_process_resources(u64 _unshareFlags);

    /// userfaultfd : Creates a descriptor through which userspace can handle selected page faults.
    /// _flags : Controls descriptor creation and userfaultfd behavior.
    i64 create_user_fault_descriptor(i32 _flags);

    /// utimensat : Sets access and modification timestamps for a filesystem object using directory-relative path resolution.
    /// _directoryFileDescriptor : Specifies the base directory for relative paths.
    /// _fileName : Specifies the filesystem object.
    /// _times : Specifies the new access and modification timestamps.
    /// _flags : Controls symbolic-link and path handling.
    i64 set_file_times_at(i32 _directoryFileDescriptor, const c08* _fileName, KernelTimeSpecification* _times, i32 _flags);

    /// vhangup : Simulates a terminal hangup on the calling process's controlling terminal.
    i64 hangup_virtual_terminal();

    /// vmsplice : Maps userspace memory buffers into a pipe for splice-based data transfer.
    /// _fileDescriptor : Identifies the pipe.
    /// _vectors : Specifies userspace memory ranges.
    /// _segmentCount : Specifies the number of vectors.
    /// _flags : Controls transfer behavior.
    i64 splice_memory_to_pipe(i32 _fileDescriptor, const IoVector* _vectors, u64 _segmentCount, u32 _flags);

    /// wait4 : Waits for a child process to change state and optionally retrieves its resource usage.
    /// _processId : Selects which child or process group to wait for.
    /// _statusAddress : Optionally receives the child's wait status.
    /// _options : Controls which state changes are reported and whether waiting blocks.
    /// _resourceUsage : Optionally receives resource-usage statistics for the child.
    i64 wait_for_child(i32 _processId, i32* _statusAddress, i32 _options, ResourceUsage* _resourceUsage);

    /// waitid : Waits for a selected child to change state and returns detailed signal-style status information.
    /// _which : Selects how the child identifier is interpreted.
    /// _processId : Identifies the child or process group.
    /// _signalInfo : Receives detailed child-state information.
    /// _options : Selects which state changes are reported and whether waiting blocks.
    /// _resourceUsage : Optionally receives resource-usage statistics for the child.
    i64 wait_for_child_event(i32 _which, i32 _processId, SignalInformation* _signalInfo, i32 _options, ResourceUsage* _resourceUsage);

    /// write : Writes bytes from a buffer to an open file descriptor.
    /// _fileDescriptor : Identifies the destination descriptor.
    /// _buffer : Supplies the bytes to write.
    /// _count : Specifies the number of bytes to write.
    i64 write_data(u32 _fileDescriptor, const c08* _buffer, s64 _count);

    /// writev : Writes data from multiple buffers to a descriptor in a single operation.
    /// _fileDescriptor : Identifies the destination descriptor.
    /// _vectors : Specifies the source buffers.
    /// _vectorCount : Specifies the number of buffers.
    i64 write_data_vectors(u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount);
}