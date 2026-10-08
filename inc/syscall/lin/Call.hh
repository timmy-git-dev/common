#pragma once
#include "error/Result.hh"
#include "syscall/lin/Errno.hh"
#include "syscall/lin/Type.hh"
namespace cmn::syscall
{
    /// Removes one pending connection from a listening socket and returns a new connected socket descriptor.
    error::Result<i64, ERRNO> accept                 (i32 _fileDescriptor, SocketAddress* _peerSocketAddress, i32* _peerAddressLength);
    /// Accepts a pending socket connection while atomically applying flags to the returned socket.
    error::Result<i64, ERRNO> accept4                (i32 _fileDescriptor, SocketAddress* _peerSocketAddress, i32* _peerAddressLength, i32 _flags);
    /// Adds or updates an inotify watch for a filesystem path.
    error::Result<i64, ERRNO> inotify_add_watch      (i32 _fileDescriptor, const c08* _pathName, u32 _mask);
    /// Creates or updates a kernel key and links it into the specified keyring.
    error::Result<i64, ERRNO> add_key                (const c08* _type, const c08* _description, const void* _payload, s64 _payloadLength, i32 _keyringId);
    /// Adds a restriction rule to an existing Landlock ruleset.
    error::Result<i64, ERRNO> landlock_add_rule      (const i32 _rulesetFileDescriptor, const LandlockRulesetType _ruleType, const void* const _ruleAttributes, const u32 _flags);
    /// Reads or modifies synchronization and adjustment parameters for a selected kernel clock.
    error::Result<i64, ERRNO> clock_adjtime          (const i32 _clockId, KernelTimeAdjustment* _timeAdjustment);
    /// Reads or modifies the kernel's CLOCK_REALTIME synchronization and adjustment parameters.
    error::Result<i64, ERRNO> adjtimex               (KernelTimeAdjustment* _timeAdjustment);
    /// Provides the kernel with expected access behavior for a virtual-memory range.
    error::Result<i64, ERRNO> madvise                (u64 _startAddress, s64 _length, i32 _behavior);
    /// Provides memory-use advice for ranges in another process referenced by a process descriptor.
    error::Result<i64, ERRNO> process_madvise        (i32 _processFileDescriptor, const IoVector* _vectors, s64 _vectorCount, i32 _behavior, u32 _flags);
    /// Allocates, deallocates, or otherwise manipulates storage space within a file.
    error::Result<i64, ERRNO> fallocate              (i32 _fileDescriptor, i32 _mode, i64 _offset, i64 _length);
    /// Allocates a hardware memory-protection key and initializes its access rights.
    error::Result<i64, ERRNO> pkey_alloc             (u64 _flags, u64 _initialRights);
    /// Applies a Landlock ruleset to the calling thread and its subsequently created children.
    error::Result<i64, ERRNO> landlock_restrict_self (const i32 _rulesetFileDescriptor, const u32 _flags);
    /// Attaches a System V shared-memory segment to the calling process's address space.
    error::Result<i64, ERRNO> shmat                  (i32 _sharedMemoryId, c08* _sharedMemoryAddress, i32 _flags);
    /// Applies a NUMA memory-placement policy to a virtual-memory range.
    error::Result<i64, ERRNO> mbind                  (u64 _startAddress, u64 _length, u64 _mode, const u64* _nodeMask, u64 _maximumNode, u32 _flags);
    /// Assigns a local address to a socket.
    error::Result<i64, ERRNO> bind                   (i32 _fileDescriptor, SocketAddress* _socketAddress, i32 _addressLength);
    /// OBSOLETE
    error::Result<i64, ERRNO> brk                    (u64 _programBreak);
    /// Attempts to cancel an outstanding Linux AIO request and returns its completion event when successful.
    error::Result<i64, ERRNO> io_cancel              (u64 _contextId, IoControlBlock* _ioControlBlock, IoCompletionEvent* _result);
    /// Changes permission and mode bits of an object referenced by a file descriptor.
    error::Result<i64, ERRNO> fchmod                 (u32 _fileDescriptor, u16 _mode);
    /// Changes permission and mode bits of a path relative to a directory descriptor.
    error::Result<i64, ERRNO> fchmodat               (i32 _directoryFileDescriptor, const c08* _fileName, u16 _mode);
    /// Changes permission and mode bits of a path relative to a directory descriptor with additional path-handling flags.
    error::Result<i64, ERRNO> fchmodat2              (i32 _directoryFileDescriptor, const c08* _fileName, u16 _mode, u32 _flags);
    /// Changes the owner and group of an object referenced by a file descriptor.
    error::Result<i64, ERRNO> fchown                 (u32 _fileDescriptor, u32 _userId, u32 _groupId);
    /// Changes the owner and group of a path relative to a directory descriptor.
    error::Result<i64, ERRNO> fchownat               (i32 _directoryFileDescriptor, const c08* _fileName, u32 _userId, u32 _groupId, i32 _flags);
    /// Changes the root directory used when resolving absolute paths for the calling process.
    error::Result<i64, ERRNO> chroot                 (const c08* _fileName);
    /// Replaces the process's root mount with another mount and moves the previous root underneath it.
    error::Result<i64, ERRNO> pivot_root             (const c08* _newRoot, const c08* _oldRootLocation);
    /// Changes the calling process's current working directory.
    error::Result<i64, ERRNO> chdir                  (const c08* _fileName);
    /// Changes the calling process's working directory to the directory referenced by a descriptor.
    error::Result<i64, ERRNO> fchdir                 (u32 _fileDescriptor);
    /// Checks whether a file resolved relative to a directory descriptor is accessible.
    error::Result<i64, ERRNO> faccessat              (i32 _directoryFileDescriptor, const c08* _fileName, i32 _mode);
    /// Checks whether a file is accessible using credentials and path-resolution behavior controlled by flags.
    error::Result<i64, ERRNO> faccessat2             (i32 _directoryFileDescriptor, const c08* _fileName, i32 _mode, i32 _flags);
    /// Releases a file descriptor from the calling process.
    error::Result<i64, ERRNO> close                  (u32 _fileDescriptor);
    /// Closes, marks close-on-exec, or unshares a contiguous range of file descriptors according to flags.
    error::Result<i64, ERRNO> close_range            (u32 _firstFileDescriptor, u32 _maximumFileDescriptor, u32 _flags);
    /// Compares a selected kernel resource belonging to two processes.
    error::Result<i64, ERRNO> kcmp                   (i32 _processId1, i32 _processId2, i32 _type, u64 _index1, u64 _index2);
    /// Adds, modifies, or removes a file descriptor from an epoll instance.
    error::Result<i64, ERRNO> epoll_ctl              (i32 _epollFileDescriptor, i32 _operation, i32 _fileDescriptor, EpollEventData* _event);
    /// Applies configuration commands to a filesystem context.
    error::Result<i64, ERRNO> fsconfig               (i32 _fileDescriptor, u32 _command, const c08* _key, const void* _value, i32 _auxiliary);
    /// Registers, unregisters, updates, or queries resources and features associated with an io_uring instance.
    error::Result<i64, ERRNO> io_uring_register      (u32 _fileDescriptor, u32 _operationCode, void* _argument, u32 _argumentCount);
    /// Retrieves message-queue attributes and optionally replaces mutable queue flags.
    error::Result<i64, ERRNO> mq_getsetattr          (i32 _messageQueueDescriptor, const MessageQueueAttributes* _newAttributes, MessageQueueAttributes* _oldAttributes);
    /// Registers or removes asynchronous notification for a POSIX message queue.
    error::Result<i64, ERRNO> mq_notify              (i32 _messageQueueDescriptor, const SignalEvent* _notification);
    /// Enables process accounting to a specified file, or disables it when given a null path.
    error::Result<i64, ERRNO> acct                   (const c08* _fileName);
    /// Retrieves and optionally changes execution-domain compatibility behavior for the calling process.
    error::Result<i64, ERRNO> personality            (u32 _personality);
    /// Retrieves and optionally replaces a resource limit for a specified process.
    error::Result<i64, ERRNO> prlimit64              (i32 _processId, u32 _resource, const ResourceLimit64* _newLimit, ResourceLimit64* _oldLimit);
    /// Registers or unregisters a userspace restartable-sequence area for the calling thread.
    error::Result<i64, ERRNO> rseq                   (RestartableSequence* _restartableSequence, u32 _restartableSequenceLength, i32 _flags, u32 _signature);
    /// Retrieves or changes the action performed when a signal is delivered.
    error::Result<i64, ERRNO> rt_sigaction           (i32 _signal, const SignalAction* _action, SignalAction* _oldAction, s64 _signalSetSize);
    /// Creates or reconfigures a file descriptor that reports selected signals as readable records.
    error::Result<i64, ERRNO> signalfd4              (i32 _fileDescriptor, SignalSet* _signalMask, s64 _signalMaskSize, i32 _flags);
    /// Retrieves or changes the calling thread's blocked signal set.
    error::Result<i64, ERRNO> rt_sigprocmask         (i32 _how, SignalSet* _newSignalSet, SignalSet* _oldSignalSet, s64 _signalSetSize);
    /// Retrieves or changes the alternate stack used for signal handlers.
    error::Result<i64, ERRNO> sigaltstack            (const SignalStack* _newStack, SignalStack* _oldStack);
    /// Configures syscall filtering or retrieves seccomp-related capabilities for the calling thread.
    error::Result<i64, ERRNO> seccomp                (u32 _operation, u32 _flags, void* _arguments);
    /// Associates a socket with a peer address, initiating a connection where required by the socket type.
    error::Result<i64, ERRNO> connect                (i32 _fileDescriptor, SocketAddress* _serverAddress, i32 _addressLength);
    /// Performs a command-specific operation on an open file descriptor.
    error::Result<i64, ERRNO> fcntl                  (u32 _fileDescriptor, u32 _command, u64 _argument);
    /// Performs a filesystem quota-management operation using a filesystem path or special device.
    error::Result<i64, ERRNO> quotactl               (u32 _command, const c08* _specialDevice, u32 _quotaId, void* _address);
    /// Performs a filesystem quota-management operation using an open file descriptor.
    error::Result<i64, ERRNO> quotactl_fd            (u32 _fileDescriptor, u32 _command, u32 _quotaId, void* _address);
    /// Performs a command-specific operation on the kernel key-management facility.
    error::Result<i64, ERRNO> keyctl                 (i32 _option, u64 _argument2, u64 _argument3, u64 _argument4, u64 _argument5);
    /// Reads or controls the kernel logging buffer according to an operation code.
    error::Result<i64, ERRNO> syslog                 (i32 _type, c08* _buffer, i32 _length);
    /// Queries or modifies a System V message queue.
    error::Result<i64, ERRNO> msgctl                 (i32 _messageQueueId, i32 _command, MessageQueueStatus* _buffer);
    /// Performs a process- or thread-specific control operation selected by an option code.
    error::Result<i64, ERRNO> prctl                  (i32 _option, u64 _argument2, u64 _argument3, u64 _argument4, u64 _argument5);
    /// Performs a tracing, debugging, or inspection operation on another thread.
    error::Result<i64, ERRNO> ptrace                 (i64 _request, i64 _processId, u64 _address, u64 _data);
    /// Performs a control or metadata operation on a System V semaphore set.
    error::Result<i64, ERRNO> semctl                 (i32 _semaphoreId, i32 _semaphoreNumber, i32 _command, u64 _argument);
    /// Queries or modifies a System V shared-memory segment.
    error::Result<i64, ERRNO> shmctl                 (i32 _sharedMemoryId, i32 _command, SharedMemoryStatus* _buffer);
    /// Performs a privileged system reboot, shutdown, suspend, or related control operation.
    error::Result<i64, ERRNO> reboot                 (i32 _magic1, i32 _magic2, u32 _command, void* _argument);
    /// Copies file data between descriptors inside the kernel without routing the data through userspace.
    error::Result<i64, ERRNO> copy_file_range        (i32 _inputFileDescriptor, i64* _inputOffset, i32 _outputFileDescriptor, i64* _outputOffset, s64 _length, u32 _flags);
    /// Copies file data directly between file descriptors without routing the payload through userspace.
    error::Result<i64, ERRNO> sendfile64             (i32 _outputFileDescriptor, i32 _inputFileDescriptor, i64* _offset, s64 _count);
    /// Creates a Linux asynchronous-I/O context.
    error::Result<i64, ERRNO> io_setup               (u32 _eventCount, u64* _context);
    /// Creates a child task while controlling which execution resources are shared with the caller.
    error::Result<i64, ERRNO> clone                  (u64 _cloneFlags, u64 _newStackPointer, i32* _parentThreadId, u64 _threadLocalStorage, i32* _childThreadId);
    /// Creates a child task using an extensible argument structure with capabilities beyond clone                  .
    error::Result<i64, ERRNO> clone3                 (CloneArguments* _arguments, s64 _size);
    /// Creates a detached mount from a configured filesystem context and returns a mount file descriptor.
    error::Result<i64, ERRNO> fsmount                (i32 _fileSystemFileDescriptor, u32 _flags, u32 _attributeFlags);
    /// Creates a directory using a path resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> mkdirat                (i32 _directoryFileDescriptor, const c08* _pathName, u16 _mode);
    /// Creates a new epoll instance and returns its file descriptor.
    error::Result<i64, ERRNO> epoll_create1          (i32 _flags);
    /// Creates a kernel-maintained 64-bit event counter accessible through a file descriptor.
    error::Result<i64, ERRNO> eventfd2               (u32 _initialValue, i32 _flags);
    /// Creates a fanotify notification group and returns its file descriptor.
    error::Result<i64, ERRNO> fanotify_init          (u32 _flags, u32 _eventFileFlags);
    /// Creates a filesystem configuration context for a named filesystem type.
    error::Result<i64, ERRNO> fsopen                 (const c08* _fileSystemName, u32 _flags);
    /// Creates a filesystem node using a path resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> mknodat                (i32 _directoryFileDescriptor, const c08* _fileName, u16 _mode, u32 _device);
    /// Creates a hard link between paths resolved relative to independently specified directory descriptors.
    error::Result<i64, ERRNO> linkat                 (i32 _oldDirectoryFileDescriptor, const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName, i32 _flags);
    /// Creates an inotify instance and returns its file descriptor.
    error::Result<i64, ERRNO> inotify_init1          (i32 _flags);
    /// Creates an io_uring instance and returns its file descriptor.
    error::Result<i64, ERRNO> io_uring_setup         (u32 _entries, IoUringParameters* _parameters);
    /// Creates a Landlock ruleset or queries the supported Landlock ABI according to flags.
    error::Result<i64, ERRNO> landlock_create_ruleset(const LandlockRulesetAttributes* const _attributes, const u64 _size, const u32 _flags);
    /// Creates an anonymous RAM-backed file and returns its descriptor.
    error::Result<i64, ERRNO> memfd_create           (const c08* _name, u32 _flags);
    /// Creates a unidirectional pipe and atomically applies descriptor flags.
    error::Result<i64, ERRNO> pipe2                  (i32* _fileDescriptors, i32 _flags);
    /// Creates a new session and process group with the caller as leader.
    error::Result<i64, ERRNO> setsid                 ();
    /// Creates a POSIX per-process timer using a specified clock.
    error::Result<i64, ERRNO> timer_create           (const i32 _clockId, SignalEvent* _timerEventSpecification, i32* _createdTimerId);
    /// Creates a file descriptor representing memory isolated from ordinary kernel mappings.
    error::Result<i64, ERRNO> memfd_secret           (i32 _flags);
    /// Creates a userspace shadow-stack memory mapping for architectures that support shadow stacks.
    error::Result<i64, ERRNO> map_shadow_stack       (u64 _address, u64 _size, u32 _flags);
    /// Creates a socket endpoint and returns its file descriptor.
    error::Result<i64, ERRNO> socket                 (i32 _family, i32 _type, i32 _protocol);
    /// Creates a connected pair of sockets.
    error::Result<i64, ERRNO> socketpair             (i32 _family, i32 _type, i32 _protocol, i32* _socketDescriptors);
    /// Creates a symbolic link at a path resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> symlinkat              (const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName);
    /// Creates a timer exposed through a readable file descriptor.
    error::Result<i64, ERRNO> timerfd_create         (i32 _clockId, i32 _flags);
    /// Creates a descriptor through which userspace can handle selected page faults.
    error::Result<i64, ERRNO> userfaultfd            (i32 _flags);
    /// Deletes a POSIX per-process timer.
    error::Result<i64, ERRNO> timer_delete           (i32 _timerId);
    /// Destroys a Linux AIO context and handles any outstanding requests associated with it.
    error::Result<i64, ERRNO> io_destroy             (u64 _context);
    /// Detaches a System V shared-memory segment from the calling process.
    error::Result<i64, ERRNO> shmdt                  (c08* _sharedMemoryAddress);
    /// Disables swapping to a specified swap file or device.
    error::Result<i64, ERRNO> swapoff                (const c08* _specialFile);
    /// Creates a copy of a file descriptor using the lowest available descriptor number.
    error::Result<i64, ERRNO> dup                    (u32 _fileDescriptor);
    /// Duplicates a file descriptor into a specific descriptor number while optionally applying flags.
    error::Result<i64, ERRNO> dup3                   (u32 _oldFileDescriptor, u32 _newFileDescriptor, i32 _flags);
    /// Duplicates data between pipes without consuming it from the source pipe.
    error::Result<i64, ERRNO> tee                    (i32 _inputFileDescriptor, i32 _outputFileDescriptor, s64 _length, u32 _flags);
    /// Duplicates a file descriptor from another process referenced by a process descriptor.
    error::Result<i64, ERRNO> pidfd_getfd            (i32 _processFileDescriptor, i32 _fileDescriptor, u32 _flags);
    /// Enables swapping to a specified file or device.
    error::Result<i64, ERRNO> swapon                 (const c08* _specialFile, i32 _swapFlags);
    /// Executes a command against Linux eBPF programs, maps, links, or other BPF objects.
    error::Result<i64, ERRNO> bpf                    (i32 _command, union bpf_attr* _attributes, u32 _size);
    /// Replaces the calling process image with a specified executable.
    error::Result<i64, ERRNO> execve                 (const c08* _fileName, const c08* const* _arguments, const c08* const* _environment);
    /// Replaces the calling process image with an executable resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> execveat               (i32 _fileDescriptor, const c08* _fileName, const c08* const* _arguments, const c08* const* _environment, i32 _flags);
    /// Terminates every thread in the calling process and records its exit status.
    error::Result<i64, ERRNO> exit_group             (i32 _errorCode);
    /// Terminates only the calling thread and records its exit status.
    error::Result<i64, ERRNO> exit                   (i32 _errorCode);
    /// Releases a previously allocated memory-protection key.
    error::Result<i64, ERRNO> pkey_free              (i32 _protectionKey);
    /// Retrieves completed operations from a Linux AIO completion queue.
    error::Result<i64, ERRNO> io_getevents           (u64 _contextId, i64 _minimumEvents, i64 _eventCount, IoCompletionEvent* _events, KernelTimeSpecification* _timeout);
    /// Retrieves Linux AIO completions while temporarily applying a specified signal mask during the wait.
    error::Result<i64, ERRNO> io_pgetevents          (u64 _contextId, i64 _minimumEvents, i64 _eventCount, IoCompletionEvent* _events, KernelTimeSpecification* _timeout, const AioSignalSet* _signalSet);
    /// Retrieves the resolution of a selected clock.
    error::Result<i64, ERRNO> clock_getres           (const i32 _clockId, KernelTimeSpecification* _resolution);
    /// Retrieves the current value of a selected clock.
    error::Result<i64, ERRNO> clock_gettime          (const i32 _clockId, KernelTimeSpecification* _time);
    /// Retrieves the CPUs on which a thread is permitted to execute.
    error::Result<i64, ERRNO> sched_getaffinity      (i32 _processId, u32 _length, u64* _cpuMask);
    /// Returns the CPU and NUMA node on which the calling thread is currently executing.
    error::Result<i64, ERRNO> getcpu                 (u32* _cpu, u32* _node, void* _unused);
    /// Retrieves filesystem metadata for an object referenced by a file descriptor.
    error::Result<i64, ERRNO> newfstat               (u32 _fileDescriptor, DescriptorStatus* _statusBuffer);
    /// Returns the effective group ID of the calling thread.
    error::Result<i64, ERRNO> getegid                ();
    /// Returns the effective user ID of the calling thread.
    error::Result<i64, ERRNO> geteuid                ();
    /// Retrieves an extended attribute from an object referenced by a file descriptor.
    error::Result<i64, ERRNO> fgetxattr              (i32 _fileDescriptor, const c08* _name, void* _value, u64 _size);
    /// Retrieves a named extended attribute from a filesystem object referenced by a path.
    error::Result<i64, ERRNO> getxattr               (const c08* _pathName, const c08* _name, void* _value, u64 _size);
    /// Retrieves a named extended attribute using directory-relative path resolution and extended argument options.
    error::Result<i64, ERRNO> getxattrat             (i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, const c08* _name, ExtendedAttributeArguments* _arguments, u64 _size);
    /// Retrieves a named extended attribute from a path without following the final symbolic link.
    error::Result<i64, ERRNO> lgetxattr              (const c08* _pathName, const c08* _name, void* _value, u64 _size);
    /// Retrieves extended filesystem metadata for a path with explicit control over lookup and requested fields.
    error::Result<i64, ERRNO> statx                  (i32 _directoryFileDescriptor, const c08* _fileName, u32 _flags, u32 _mask, ExtendedFileStatus* _buffer);
    /// Converts a filesystem path into an opaque persistent file handle and mount identifier.
    error::Result<i64, ERRNO> name_to_handle_at      (i32 _directoryFileDescriptor, const c08* _name, FileHandleInfo* _fileHandle, void* _mountId, i32 _flags);
    /// Retrieves filesystem-specific attributes for a path.
    error::Result<i64, ERRNO> file_getattr           (i32 _directoryFileDescriptor, const c08* _fileName, FileAttributes* _fileAttributes, u64 _size, u32 _lookupFlags);
    /// Retrieves filesystem-wide statistics for the filesystem containing a path.
    error::Result<i64, ERRNO> statfs                 (const c08* _pathName, FilesystemStatistics* _buffer);
    /// Retrieves filesystem-wide statistics for the filesystem containing an open object.
    error::Result<i64, ERRNO> fstatfs                (u32 _fileDescriptor, FilesystemStatistics* _buffer);
    /// Retrieves the real, effective, and saved group IDs of the calling thread.
    error::Result<i64, ERRNO> getresgid              (u32* _realGroupId, u32* _effectiveGroupId, u32* _savedGroupId);
    /// Retrieves the current state of a process interval timer.
    error::Result<i64, ERRNO> getitimer              (i32 _timerType, LegacyIntervalTimerValue* _value);
    /// Retrieves the I/O scheduling priority of a process, process group, or user.
    error::Result<i64, ERRNO> ioprio_get             (i32 _which, i32 _who);
    /// Retrieves the local address currently associated with a socket.
    error::Result<i64, ERRNO> getsockname            (i32 _fileDescriptor, SocketAddress* _socketAddress, i32* _socketAddressLength);
    /// Returns the highest static priority supported by a scheduling policy.
    error::Result<i64, ERRNO> sched_get_priority_max (i32 _policy);
    /// Retrieves NUMA memory-policy information for the calling thread or a specified memory address.
    error::Result<i64, ERRNO> get_mempolicy          (i32* _policy, u64* _nodeMask, u64 _maximumNode, u64 _address, u64 _flags);
    /// Opens an existing System V message queue or creates one for a specified key.
    error::Result<i64, ERRNO> msgget                 (i32 _key, i32 _messageFlags);
    /// Returns the lowest static priority supported by a scheduling policy.
    error::Result<i64, ERRNO> sched_get_priority_min (i32 _policy);
    /// Retrieves detailed information about a mount identified by a mount request.
    error::Result<i64, ERRNO> statmount              (const MountIdentifierRequest* _request, MountStatistics* _buffer, s64 _bufferSize, u32 _flags);
    /// Retrieves the highest scheduling nice priority among the selected processes, process group, or user.
    error::Result<i64, ERRNO> getpriority            (i32 _which, i32 _who);
    /// Returns the process ID of the caller's parent process.
    error::Result<i64, ERRNO> getppid                ();
    /// Retrieves filesystem metadata for a path resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> newfstatat             (i32 _directoryFileDescriptor, const c08* _fileName, DescriptorStatus* _statusBuffer, i32 _flags);
    /// Retrieves the remote address associated with a connected socket.
    error::Result<i64, ERRNO> getpeername            (i32 _fileDescriptor, SocketAddress* _socketAddress, i32* _socketAddressLength);
    /// Retrieves signals that are blocked and currently pending.
    error::Result<i64, ERRNO> rt_sigpending          (SignalSet* _signalSet, s64 _signalSetSize);
    /// Returns the process-group ID of a specified process.
    error::Result<i64, ERRNO> getpgid                (i32 _processId);
    /// Returns the process ID of the calling process.
    error::Result<i64, ERRNO> getpid                 ();
    /// Retrieves the remaining expiration time and repeat interval of a POSIX timer.
    error::Result<i64, ERRNO> timer_gettime          (i32 _timerId, KernelIntervalTimerSpecification* _setting);
    /// Retrieves CPU execution-time statistics for the calling process and its waited-for children.
    error::Result<i64, ERRNO> times                  (ProcessTimeStatistics* _timesBuffer);
    /// Fills a buffer with random bytes provided by the kernel random subsystem.
    error::Result<i64, ERRNO> getrandom              (c08* _buffer, u64 _length, u32 _flags);
    /// Returns the real group ID of the calling thread.
    error::Result<i64, ERRNO> getgid                 ();
    /// Returns the real user ID of the calling thread.
    error::Result<i64, ERRNO> getuid                 ();
    /// Retrieves the soft and hard limits for a process resource.
    error::Result<i64, ERRNO> getrlimit              (u32 _resource, ResourceLimit* _resourceLimit);
    /// Retrieves resource-consumption statistics for the selected execution scope.
    error::Result<i64, ERRNO> getrusage              (i32 _who, ResourceUsage* _resourceUsage);
    /// Retrieves the round-robin scheduling quantum for a thread.
    error::Result<i64, ERRNO> sched_rr_get_interval  (i32 _processId, KernelTimeSpecification* _interval);
    /// Retrieves extended scheduler attributes for a thread.
    error::Result<i64, ERRNO> sched_getattr          (i32 _processId, SchedulerAttributes* _attributes, u32 _size, u32 _flags);
    /// Retrieves scheduler parameters for a thread.
    error::Result<i64, ERRNO> sched_getparam         (i32 _processId, SchedulerParameters* _parameters);
    /// Returns the scheduling policy currently assigned to a thread.
    error::Result<i64, ERRNO> sched_getscheduler     (i32 _processId);
    /// Retrieves Linux Security Module attributes associated with the calling task.
    error::Result<i64, ERRNO> lsm_get_self_attr      (u32 _attribute, SecurityModuleContext* _context, u32* _size, u32 _flags);
    /// Opens an existing System V semaphore set or creates one for a key.
    error::Result<i64, ERRNO> semget                 (i32 _key, i32 _semaphoreCount, i32 _flags);
    /// Returns the session ID of a specified process.
    error::Result<i64, ERRNO> getsid                 (i32 _processId);
    /// Opens an existing System V shared-memory segment or creates one for a key.
    error::Result<i64, ERRNO> shmget                 (i32 _key, s64 _size, i32 _flags);
    /// Retrieves the current value of a socket option.
    error::Result<i64, ERRNO> getsockopt             (i32 _fileDescriptor, i32 _level, i32 _optionName, c08* _optionValue, i32* _optionLength);
    /// Retrieves the supplementary group IDs of the calling thread.
    error::Result<i64, ERRNO> getgroups              (i32 _groupSetSize, u32* _groupList);
    /// Retrieves identifying information about the running Linux system.
    error::Result<i64, ERRNO> newuname               (SystemIdentification* _systemName);
    /// Retrieves system-wide memory, swap, uptime, and process statistics.
    error::Result<i64, ERRNO> sysinfo                (SystemInformation* _information);
    /// Retrieves Linux capability sets for the thread identified by the capability header.
    error::Result<i64, ERRNO> capget                 (cap_user_header_t _capabilityHeader, cap_user_data_t _capabilityData);
    /// Returns the thread ID of the calling thread.
    error::Result<i64, ERRNO> gettid                 ();
    /// Retrieves the robust-futex list registered by a specified thread.
    error::Result<i64, ERRNO> get_robust_list        (i32 _processId, RobustFutexListHead** _headPointer, u64* _lengthPointer);
    /// Retrieves the current expiration and interval settings of a timer descriptor.
    error::Result<i64, ERRNO> timerfd_gettime        (i32 _fileDescriptor, KernelIntervalTimerSpecification* _currentTimer);
    /// Returns the number of additional timer expirations that occurred before the most recent notification was delivered.
    error::Result<i64, ERRNO> timer_getoverrun       (i32 _timerId);
    /// Retrieves the real, effective, and saved user IDs of the calling thread.
    error::Result<i64, ERRNO> getresuid              (u32* _realUserId, u32* _effectiveUserId, u32* _savedUserId);
    /// Retrieves the current wall-clock time and optionally legacy timezone information.
    error::Result<i64, ERRNO> gettimeofday           (LegacyTimeValue* _timeValue, TimezoneInformation* _timezone);
    /// Copies the calling process's absolute current working directory into a userspace buffer.
    error::Result<i64, ERRNO> getcwd                 (c08* _buffer, u64 _size);
    /// Simulates a terminal hangup on the calling process's controlling terminal.
    error::Result<i64, ERRNO> vhangup                ();
    /// Issues a process-wide or expedited memory-ordering barrier operation.
    error::Result<i64, ERRNO> membarrier             (i32 _command, u32 _flags, i32 _cpuId);
    /// Moves the calling thread into one or more namespaces referenced by a file descriptor.
    error::Result<i64, ERRNO> setns                  (i32 _fileDescriptor, i32 _flags);
    /// Retrieves the names of all extended attributes on an object referenced by a file descriptor.
    error::Result<i64, ERRNO> flistxattr             (i32 _fileDescriptor, c08* _list, u64 _size);
    /// Retrieves the names of extended attributes associated with a filesystem object.
    error::Result<i64, ERRNO> listxattr              (const c08* _pathName, c08* _list, u64 _size);
    /// Retrieves extended-attribute names using directory-relative path resolution and lookup flags.
    error::Result<i64, ERRNO> listxattrat            (i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, c08* _list, u64 _size);
    /// Retrieves extended-attribute names from a path without following the final symbolic link.
    error::Result<i64, ERRNO> llistxattr             (const c08* _pathName, c08* _list, u64 _size);
    /// Retrieves mount IDs beneath a specified mount for mount-tree enumeration.
    error::Result<i64, ERRNO> listmount              (const MountIdentifierRequest* _request, u64* _mountIds, u64 _mountIdCount, u32 _flags);
    /// Retrieves the identifiers of active Linux Security Modules.
    error::Result<i64, ERRNO> lsm_list_modules       (u64* _moduleIds, u32* _size, u32 _flags);
    /// Marks a socket as passive and configures the queue limit for pending connection requests.
    error::Result<i64, ERRNO> listen                 (i32 _fileDescriptor, i32 _backlog);
    /// Loads kernel memory segments and an entry point for later execution through kexec.
    error::Result<i64, ERRNO> kexec_load             (u64 _entryPoint, u64 _segmentCount, KernelExecutionSegment* _segments, u64 _flags);
    /// Loads a kernel and optional initramfs from file descriptors for later execution through kexec.
    error::Result<i64, ERRNO> kexec_file_load        (i32 _kernelFileDescriptor, i32 _initialRamdiskFileDescriptor, u64 _commandLineLength, const c08* _commandLine, u64 _flags);
    /// Loads a kernel module from an already-open file descriptor.
    error::Result<i64, ERRNO> finit_module           (i32 _fileDescriptor, const c08* _arguments, i32 _flags);
    /// Loads a kernel module directly from an image held in userspace memory.
    error::Result<i64, ERRNO> init_module            (void* _moduleImage, u64 _length, const c08* _arguments);
    /// Locks pages of a virtual-memory range into RAM.
    error::Result<i64, ERRNO> mlock                  (u64 _startAddress, s64 _length);
    /// Locks pages of a virtual-memory range into RAM with additional locking behavior controlled by flags.
    error::Result<i64, ERRNO> mlock2                 (u64 _startAddress, s64 _length, i32 _flags);
    /// Locks some or all current and future mappings of the calling process into RAM.
    error::Result<i64, ERRNO> mlockall               (i32 _flags);
    /// Applies or removes an advisory whole-file lock associated with an open file description.
    error::Result<i64, ERRNO> flock                  (u32 _fileDescriptor, u32 _command);
    /// Creates a virtual-memory mapping backed by a file or anonymous memory.
    error::Result<i64, ERRNO> mmap                   (u64 _address, u64 _length, u64 _protection, u64 _flags, u64 _fileDescriptor, u64 _offset);
    /// Moves a process's pages from one set of NUMA nodes to another.
    error::Result<i64, ERRNO> migrate_pages          (i32 _processId, u64 _maximumNode, const u64* _oldNodes, const u64* _newNodes);
    /// Adds, modifies, removes, or flushes fanotify marks on filesystem objects.
    error::Result<i64, ERRNO> fanotify_mark          (i32 _fanotifyFileDescriptor, u32 _flags, u64 _mask, i32 _directoryFileDescriptor, const c08* _pathName);
    /// Attaches a filesystem or modifies an existing mount according to the supplied flags.
    error::Result<i64, ERRNO> mount                  (c08* _deviceName, c08* _directoryName, c08* _fileSystemType, u64 _flags, void* _data);
    /// Moves or attaches a detached mount from one location to another.
    error::Result<i64, ERRNO> move_mount             (i32 _sourceDirectoryFileDescriptor, const c08* _sourcePathName, i32 _destinationDirectoryFileDescriptor, const c08* _destinationPathName, u32 _flags);
    /// Queries or changes the NUMA-node placement of individual pages belonging to a process.
    error::Result<i64, ERRNO> move_pages             (i32 _processId, u64 _pageCount, const void** _pages, const i32* _nodes, i32* _status, i32 _flags);
    /// Opens or creates a filesystem object using a path resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> openat                 (i32 _directoryFileDescriptor, const c08* _fileName, i32 _flags, u16 _mode);
    /// Opens a filesystem object relative to a directory descriptor using extensible path-resolution and open options.
    error::Result<i64, ERRNO> openat2                (i32 _directoryFileDescriptor, const c08* _fileName, OpenOptions* _openHow, s64 _size);
    /// Opens a filesystem object identified by an opaque file handle relative to a mount descriptor.
    error::Result<i64, ERRNO> open_by_handle_at      (i32 _mountDirectoryFileDescriptor, FileHandleInfo* _fileHandle, i32 _flags);
    /// Opens or creates a POSIX message queue and returns its descriptor.
    error::Result<i64, ERRNO> mq_open                (const c08* _name, i32 _openFlags, u16 _mode, MessageQueueAttributes* _attributes);
    /// Creates a filesystem configuration context from an existing mount for reconfiguration.
    error::Result<i64, ERRNO> fspick                 (i32 _directoryFileDescriptor, const c08* _path, u32 _flags);
    /// Opens or clones a mount subtree and returns a mount file descriptor.
    error::Result<i64, ERRNO> open_tree              (i32 _directoryFileDescriptor, const c08* _fileName, u32 _flags);
    /// Opens or clones a mount subtree while applying supplied mount attributes.
    error::Result<i64, ERRNO> open_tree_attr         (i32 _directoryFileDescriptor, const c08* _fileName, u32 _flags, MountAttributes* _attributes, s64 _size);
    /// Creates a kernel performance-monitoring event and returns its descriptor.
    error::Result<i64, ERRNO> perf_event_open        (PerformanceEventAttributes* _attributes, i32 _processId, i32 _cpu, i32 _groupFileDescriptor, u64 _flags);
    /// Opens a file descriptor referring to a process.
    error::Result<i64, ERRNO> pidfd_open             (i32 _processId, u32 _flags);
    /// Performs a selected operation on one or more 32-bit userspace futex words.
    error::Result<i64, ERRNO> futex                  (u32* _userAddress, i32 _operation, u32 _value, const KernelTimeSpecification* _timeout, u32* _secondaryUserAddress, u32 _value3);
    /// Executes a driver- or subsystem-specific control operation on a file descriptor.
    error::Result<i64, ERRNO> ioctl                  (u32 _fileDescriptor, u32 _command, u64 _argument);
    /// Atomically performs one or more operations on a System V semaphore set.
    error::Result<i64, ERRNO> semop                  (i32 _semaphoreId, SemaphoreOperation* _operations, u32 _operationCount);
    /// Atomically performs System V semaphore operations with a relative timeout.
    error::Result<i64, ERRNO> semtimedop             (i32 _semaphoreId, SemaphoreOperation* _operations, u32 _operationCount, const KernelTimeSpecification* _timeout);
    /// Waits for events on multiple file descriptors with nanosecond timeout precision and an optional temporary signal mask.
    error::Result<i64, ERRNO> ppoll                  (PollFileDescriptor* _fileDescriptors, u32 _fileDescriptorCount, KernelTimeSpecification* _timeout, const SignalSet* _signalMask, s64 _signalSetSize);
    /// Requests that file data be loaded into the page cache before it is needed.
    error::Result<i64, ERRNO> readahead              (i32 _fileDescriptor, i64 _offset, s64 _count);
    /// Submits io_uring requests, waits for completions, or performs other ring-enter operations according to flags.
    error::Result<i64, ERRNO> io_uring_enter         (u32 _fileDescriptor, u32 _submitCount, u32 _minimumCompletions, u32 _flags, const void* _arguments, u64 _argumentSize);
    /// Reports whether pages in a virtual-memory range are currently resident in physical memory.
    error::Result<i64, ERRNO> mincore                (u64 _startAddress, s64 _length, u08* _vector);
    /// Queries page-cache statistics for a byte range of a file.
    error::Result<i64, ERRNO> cachestat              (u32 _fileDescriptor, CacheStatisticsRange* _cacheStatusRange, CacheStatistics* _cacheStatus, u32 _flags);
    /// Sends a signal with explicitly supplied signal information to a process.
    error::Result<i64, ERRNO> rt_sigqueueinfo        (i32 _processId, i32 _signal, SignalInformation* _signalInfo);
    /// Sends a signal with explicit signal information to a specific thread within a thread group.
    error::Result<i64, ERRNO> rt_tgsigqueueinfo      (i32 _threadGroupId, i32 _processId, i32 _signal, SignalInformation* _signalInfo);
    /// Reads bytes from an open file descriptor into a buffer.
    error::Result<i64, ERRNO> read                   (u32 _fileDescriptor, c08* _buffer, s64 _count);
    /// Reads data from a descriptor into multiple buffers in a single operation.
    error::Result<i64, ERRNO> readv                  (u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount);
    /// Reads directory entries from an open directory descriptor into a buffer.
    error::Result<i64, ERRNO> getdents64             (u32 _fileDescriptor, LinuxDirectoryEntry* _directoryEntry, u32 _count);
    /// Reads bytes from a file at an explicit offset without changing the shared file position.
    error::Result<i64, ERRNO> pread64                (u32 _fileDescriptor, c08* _buffer, s64 _count, i64 _position);
    /// Reads into multiple buffers from an explicit file offset without changing the shared file position.
    error::Result<i64, ERRNO> preadv                 (u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh);
    /// Reads into multiple buffers from an explicit file offset with per-operation behavior flags.
    error::Result<i64, ERRNO> preadv2                (u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh, i32 _flags);
    /// Copies memory directly from another process into local buffers.
    error::Result<i64, ERRNO> process_vm_readv       (i32 _processId, const IoVector* _localVectors, u64 _localVectorCount, const IoVector* _remoteVectors, u64 _remoteVectorCount, u64 _flags);
    /// Reads the target path stored in a symbolic link resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> readlinkat             (i32 _directoryFileDescriptor, const c08* _pathName, c08* _buffer, i32 _bufferSize);
    /// Receives the oldest eligible message from a POSIX message queue with an absolute timeout.
    error::Result<i64, ERRNO> mq_timedreceive        (i32 _messageQueueDescriptor, c08* _messageBuffer, s64 _messageLength, u32* _messagePriority, const KernelTimeSpecification* _absoluteTimeout);
    /// Receives a message from a System V message queue.
    error::Result<i64, ERRNO> msgrcv                 (i32 _messageQueueId, MessageBuffer* _messageBuffer, s64 _messageSize, i64 _messageType, i32 _messageFlags);
    /// Receives data from a socket and optionally returns the sender's address.
    error::Result<i64, ERRNO> recvfrom               (i32 _fileDescriptor, void* _buffer, s64 _size, u32 _flags, SocketAddress* _address, i32* _addressLength);
    /// Receives a socket message including payload, address, and ancillary data.
    error::Result<i64, ERRNO> recvmsg                (i32 _fileDescriptor, UserMessageHeader* _message, u32 _flags);
    /// Receives multiple socket messages in one operation with an optional timeout.
    error::Result<i64, ERRNO> recvmmsg               (i32 _fileDescriptor, MultiMessageHeader* _messages, u32 _messageCount, u32 _flags, KernelTimeSpecification* _timeout);
    /// Reclaims memory belonging to a process that is exiting and referenced by a process descriptor.
    error::Result<i64, ERRNO> process_mrelease       (i32 _processFileDescriptor, u32 _flags);
    /// Reassigns pages within a nonlinear file-backed memory mapping.
    error::Result<i64, ERRNO> remap_file_pages       (u64 _startAddress, u64 _size, u64 _protection, u64 _pageOffset, u64 _flags);
    /// Resizes or relocates an existing virtual-memory mapping.
    error::Result<i64, ERRNO> mremap                 (u64 _address, u64 _oldLength, u64 _newLength, u64 _flags, u64 _newAddress);
    /// Removes a named extended attribute from a filesystem object.
    error::Result<i64, ERRNO> removexattr            (const c08* _pathName, const c08* _name);
    /// Removes an extended attribute from an object referenced by a file descriptor.
    error::Result<i64, ERRNO> fremovexattr           (i32 _fileDescriptor, const c08* _name);
    /// Removes a named extended attribute using directory-relative path resolution.
    error::Result<i64, ERRNO> removexattrat          (i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, const c08* _name);
    /// Removes a named extended attribute from a path without following the final symbolic link.
    error::Result<i64, ERRNO> lremovexattr           (const c08* _pathName, const c08* _name);
    /// Removes a watch from an inotify instance.
    error::Result<i64, ERRNO> inotify_rm_watch       (i32 _fileDescriptor, i32 _watchDescriptor);
    /// Removes a filesystem object using a path resolved relative to a directory descriptor.
    error::Result<i64, ERRNO> unlinkat               (i32 _directoryFileDescriptor, const c08* _pathName, i32 _flags);
    /// Renames a filesystem object using directory-relative source and destination paths.
    error::Result<i64, ERRNO> renameat               (i32 _oldDirectoryFileDescriptor, const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName);
    /// Renames or exchanges filesystem objects using directory-relative paths and operation flags.
    error::Result<i64, ERRNO> renameat2              (i32 _oldDirectoryFileDescriptor, const c08* _oldName, i32 _newDirectoryFileDescriptor, const c08* _newName, u32 _flags);
    /// Finds an existing kernel key or requests that one be constructed.
    error::Result<i64, ERRNO> request_key            (const c08* _type, const c08* _description, const c08* _calloutInfo, i32 _destinationKeyringId);
    /// Wakes some waiters and moves additional waiters between futexes described by the supplied waiter structures.
    error::Result<i64, ERRNO> futex_requeue          (FutexWaitRequest* _waiters, u32 _flags, i32 _wakeCount, i32 _requeueCount);
    /// Changes the size of an open regular file.
    error::Result<i64, ERRNO> ftruncate              (u32 _fileDescriptor, i64 _length);
    /// Changes the size of a regular file identified by path.
    error::Result<i64, ERRNO> truncate               (const c08* _path, i64 _length);
    /// Restarts a previously interrupted restartable system call.
    error::Result<i64, ERRNO> restart_syscall        ();
    /// Restores execution state saved by the kernel when entering a signal handler.
    error::Result<i64, ERRNO> rt_sigreturn           ();
    /// Permanently prevents selected classes of future changes to a virtual-memory range.
    error::Result<i64, ERRNO> mseal                  (u64 _startAddress, s64 _length, u64 _flags);
    /// Changes the current file offset associated with an open file description.
    error::Result<i64, ERRNO> lseek                  (i32 _fileDescriptor, i64 _offset, u32 _whence);
    /// Sends a message to a POSIX message queue with an absolute timeout.
    error::Result<i64, ERRNO> mq_timedsend           (i32 _messageQueueDescriptor, const c08* _messageBuffer, s64 _messageLength, u32 _messagePriority, const KernelTimeSpecification* _absoluteTimeout);
    /// Sends a message to a System V message queue.
    error::Result<i64, ERRNO> msgsnd                 (i32 _messageQueueId, MessageBuffer* _messageBuffer, s64 _messageSize, i32 _messageFlags);
    /// Sends a signal to a process or process group selected by a process-ID value.
    error::Result<i64, ERRNO> kill                   (i32 _processId, i32 _signal);
    /// Sends a signal directly to a thread identified by its thread ID.
    error::Result<i64, ERRNO> tkill                  (i32 _threadId, i32 _signal);
    /// Sends data through a socket, optionally specifying the destination address.
    error::Result<i64, ERRNO> sendto                 (i32 _fileDescriptor, void* _buffer, s64 _length, u32 _flags, SocketAddress* _address, i32 _addressLength);
    /// Sends a socket message containing payload, destination, and optional ancillary data.
    error::Result<i64, ERRNO> sendmsg                (i32 _fileDescriptor, UserMessageHeader* _message, u32 _flags);
    /// Sends multiple socket messages in a single operation.
    error::Result<i64, ERRNO> sendmmsg               (i32 _fileDescriptor, MultiMessageHeader* _messages, u32 _messageCount, u32 _flags);
    /// Sends a signal to a specific thread within a specific thread group.
    error::Result<i64, ERRNO> tgkill                 (i32 _threadGroupId, i32 _threadId, i32 _signal);
    /// Sets the current value of a settable kernel clock.
    error::Result<i64, ERRNO> clock_settime          (const i32 _clockId, const KernelTimeSpecification* _time);
    /// Restricts the CPUs on which a thread may execute.
    error::Result<i64, ERRNO> sched_setaffinity      (i32 _processId, u32 _length, u64* _cpuMask);
    /// Creates or replaces a named extended attribute on a filesystem object.
    error::Result<i64, ERRNO> setxattr               (const c08* _pathName, const c08* _name, const void* _value, s64 _size, i32 _flags);
    /// Creates or replaces an extended attribute on an object referenced by a file descriptor.
    error::Result<i64, ERRNO> fsetxattr              (i32 _fileDescriptor, const c08* _name, const void* _value, u64 _size, i32 _flags);
    /// Creates or replaces an extended attribute using directory-relative path resolution and extended arguments.
    error::Result<i64, ERRNO> setxattrat             (i32 _directoryFileDescriptor, const c08* _pathName, u32 _lookupFlags, const c08* _name, const ExtendedAttributeArguments* _arguments, s64 _size);
    /// Creates or replaces a named extended attribute without following the final symbolic link.
    error::Result<i64, ERRNO> lsetxattr              (const c08* _pathName, const c08* _name, const void* _value, u64 _size, i32 _flags);
    /// Replaces the calling process's file-creation permission mask and returns the previous mask.
    error::Result<i64, ERRNO> umask                  (i32 _mask);
    /// Sets access and modification timestamps for a filesystem object using directory-relative path resolution.
    error::Result<i64, ERRNO> utimensat              (i32 _directoryFileDescriptor, const c08* _fileName, KernelTimeSpecification* _times, i32 _flags);
    /// Changes filesystem-specific attributes for a path.
    error::Result<i64, ERRNO> file_setattr           (i32 _directoryFileDescriptor, const c08* _fileName, FileAttributes* _fileAttributes, u64 _size, u32 _lookupFlags);
    /// Changes the calling thread's filesystem group ID.
    error::Result<i64, ERRNO> setfsgid               (u32 _groupId);
    /// Changes the calling thread's filesystem user ID.
    error::Result<i64, ERRNO> setfsuid               (u32 _userId);
    /// Changes the real, effective, and saved group IDs of the calling thread.
    error::Result<i64, ERRNO> setresgid              (u32 _realGroupId, u32 _effectiveGroupId, u32 _savedGroupId);
    /// Changes the calling thread's group identity according to its privileges.
    error::Result<i64, ERRNO> setgid                 (u32 _groupId);
    /// Configures a process interval timer and optionally returns its previous state.
    error::Result<i64, ERRNO> setitimer              (i32 _timerType, LegacyIntervalTimerValue* _newValue, LegacyIntervalTimerValue* _oldValue);
    /// Sets the I/O scheduling priority of a process, process group, or user.
    error::Result<i64, ERRNO> ioprio_set             (i32 _which, i32 _who, i32 _ioPriority);
    /// Sets the preferred home NUMA node for a virtual-memory range.
    error::Result<i64, ERRNO> set_mempolicy_home_node(u64 _startAddress, u64 _length, u64 _homeNode, u64 _flags);
    /// Sets the calling thread's default NUMA memory-allocation policy.
    error::Result<i64, ERRNO> set_mempolicy          (i32 _mode, const u64* _nodeMask, u64 _maximumNode);
    /// Changes access permissions for a virtual-memory range.
    error::Result<i64, ERRNO> mprotect               (u64 _startAddress, s64 _length, u64 _protection);
    /// Changes memory permissions and associates a protection key with a virtual-memory range.
    error::Result<i64, ERRNO> pkey_mprotect          (u64 _startAddress, s64 _length, u64 _protection, i32 _protectionKey);
    /// Changes mount attributes for a mount selected relative to a directory descriptor.
    error::Result<i64, ERRNO> mount_setattr          (i32 _directoryFileDescriptor, const c08* _path, u32 _flags, MountAttributes* _attributes, s64 _size);
    /// Changes the scheduling nice value of selected processes, process groups, or users.
    error::Result<i64, ERRNO> setpriority            (i32 _which, i32 _who, i32 _niceValue);
    /// Changes the process-group membership of a process.
    error::Result<i64, ERRNO> setpgid                (i32 _processId, i32 _processGroupId);
    /// Arms, disarms, or reconfigures a POSIX per-process timer.
    error::Result<i64, ERRNO> timer_settime          (i32 _timerId, i32 _flags, const KernelIntervalTimerSpecification* _newSetting, KernelIntervalTimerSpecification* _oldSetting);
    /// Changes the real and effective group IDs of the calling thread.
    error::Result<i64, ERRNO> setregid               (u32 _realGroupId, u32 _effectiveGroupId);
    /// Changes the real and effective user IDs of the calling thread.
    error::Result<i64, ERRNO> setreuid               (u32 _realUserId, u32 _effectiveUserId);
    /// Changes the soft and hard limits for a process resource.
    error::Result<i64, ERRNO> setrlimit              (u32 _resource, ResourceLimit* _resourceLimit);
    /// Changes extended scheduler attributes for a thread.
    error::Result<i64, ERRNO> sched_setattr          (i32 _processId, SchedulerAttributes* _attributes, u32 _flags);
    /// Changes scheduler parameters for a thread without changing its scheduling policy.
    error::Result<i64, ERRNO> sched_setparam         (i32 _processId, SchedulerParameters* _parameters);
    /// Changes a thread's scheduling policy and associated parameters.
    error::Result<i64, ERRNO> sched_setscheduler     (i32 _processId, i32 _policy, SchedulerParameters* _parameters);
    /// Sets a Linux Security Module attribute for the calling task.
    error::Result<i64, ERRNO> lsm_set_self_attr      (u32 _attribute, SecurityModuleContext* _context, u32 _size, u32 _flags);
    /// Changes a socket option at a specified protocol level.
    error::Result<i64, ERRNO> setsockopt             (i32 _fileDescriptor, i32 _level, i32 _optionName, c08* _optionValue, i32 _optionLength);
    /// Replaces the calling thread's supplementary group list.
    error::Result<i64, ERRNO> setgroups              (i32 _groupSetSize, u32* _groupList);
    /// Changes the calling process's UTS namespace domain name.
    error::Result<i64, ERRNO> setdomainname          (c08* _name, i32 _length);
    /// Changes the hostname of the calling process's UTS namespace.
    error::Result<i64, ERRNO> sethostname            (c08* _name, i32 _length);
    /// Replaces Linux capability sets for the thread identified by the capability header.
    error::Result<i64, ERRNO> capset                 (cap_user_header_t _capabilityHeader, const cap_user_data_t _capabilityData);
    /// Registers the userspace address that the kernel clears when the calling thread exits.
    error::Result<i64, ERRNO> set_tid_address        (i32* _threadIdAddress);
    /// Registers the calling thread's robust-futex list with the kernel.
    error::Result<i64, ERRNO> set_robust_list        (RobustFutexListHead* _head, s64 _length);
    /// Arms, disarms, or reconfigures a timer descriptor.
    error::Result<i64, ERRNO> timerfd_settime        (i32 _fileDescriptor, i32 _flags, const KernelIntervalTimerSpecification* _newTimer, KernelIntervalTimerSpecification* _oldTimer);
    /// Changes the real, effective, and saved user IDs of the calling thread.
    error::Result<i64, ERRNO> setresuid              (u32 _realUserId, u32 _effectiveUserId, u32 _savedUserId);
    /// Changes the calling thread's user identity according to its privileges.
    error::Result<i64, ERRNO> setuid                 (u32 _userId);
    /// Sets the system wall-clock time and optionally legacy timezone information.
    error::Result<i64, ERRNO> settimeofday           (LegacyTimeValue* _timeValue, TimezoneInformation* _timezone);
    /// Disables receiving, sending, or both directions of communication on a socket.
    error::Result<i64, ERRNO> shutdown               (i32 _fileDescriptor, i32 _how);
    /// Sends a signal to a process referenced by a process descriptor.
    error::Result<i64, ERRNO> pidfd_send_signal      (i32 _processFileDescriptor, i32 _signal, SignalInformation* _signalInfo, u32 _flags);
    /// Suspends the calling thread for a requested relative duration.
    error::Result<i64, ERRNO> nanosleep              (KernelTimeSpecification* _requestedTime, KernelTimeSpecification* _remainingTime);
    /// Suspends the calling thread relative to or until a time measured by a selected clock.
    error::Result<i64, ERRNO> clock_nanosleep        (const i32 _clockId, i32 _flags, const KernelTimeSpecification* _requestedTime, KernelTimeSpecification* _remainingTime);
    /// Transfers data between two file descriptors through a kernel pipe without copying the payload through userspace.
    error::Result<i64, ERRNO> splice                 (i32 _inputFileDescriptor, i64* _inputOffset, i32 _outputFileDescriptor, i64* _outputOffset, s64 _length, u32 _flags);
    /// Maps userspace memory buffers into a pipe for splice-based data transfer.
    error::Result<i64, ERRNO> vmsplice               (i32 _fileDescriptor, const IoVector* _vectors, u64 _segmentCount, u32 _flags);
    /// Submits one or more asynchronous-I/O requests to a Linux AIO context.
    error::Result<i64, ERRNO> io_submit              (u64 _contextId, i64 _count, IoControlBlock** _ioControlBlocks);
    /// Temporarily replaces the signal mask and sleeps until a signal is delivered.
    error::Result<i64, ERRNO> rt_sigsuspend          (SignalSet* _newSignalSet, s64 _signalSetSize);
    /// Flushes modified file data and associated metadata to persistent storage.
    error::Result<i64, ERRNO> fsync                  (u32 _fileDescriptor);
    /// Flushes modified file data and metadata required for subsequent data access to persistent storage.
    error::Result<i64, ERRNO> fdatasync              (u32 _fileDescriptor);
    /// Initiates or waits for writeback of a selected byte range of an open file.
    error::Result<i64, ERRNO> sync_file_range        (i32 _fileDescriptor, i64 _offset, i64 _byteCount, u32 _flags);
    /// Synchronizes pending writes for the filesystem containing an open file descriptor.
    error::Result<i64, ERRNO> syncfs                 (i32 _fileDescriptor);
    /// Schedules all pending filesystem data and metadata writes system-wide.
    error::Result<i64, ERRNO> sync                   ();
    /// Synchronizes changes in a memory-mapped file range with its backing storage.
    error::Result<i64, ERRNO> msync                  (u64 _startAddress, s64 _length, i32 _flags);
    /// Removes a POSIX message-queue name while allowing existing open descriptors to remain usable.
    error::Result<i64, ERRNO> mq_unlink              (const c08* _name);
    /// Unloads a loaded kernel module.
    error::Result<i64, ERRNO> delete_module          (const c08* _moduleName, u32 _flags);
    /// Removes a memory lock from pages in a virtual-memory range.
    error::Result<i64, ERRNO> munlock                (u64 _startAddress, s64 _length);
    /// Removes all memory locks established by the calling process.
    error::Result<i64, ERRNO> munlockall             ();
    /// Removes virtual-memory mappings from an address range.
    error::Result<i64, ERRNO> munmap                 (u64 _address, s64 _length);
    /// Detaches a mounted filesystem according to the supplied unmount flags.
    error::Result<i64, ERRNO> umount                 (c08* _name, i32 _flags);
    /// Detaches selected execution resources from those shared with other processes or threads.
    error::Result<i64, ERRNO> unshare                (u64 _unshareFlags);
    /// Waits for a child process to change state and optionally retrieves its resource usage.
    error::Result<i64, ERRNO> wait4                  (i32 _processId, i32* _statusAddress, i32 _options, ResourceUsage* _resourceUsage);
    /// Waits for a selected child to change state and returns detailed signal-style status information.
    error::Result<i64, ERRNO> waitid                 (i32 _which, i32 _processId, SignalInformation* _signalInfo, i32 _options, ResourceUsage* _resourceUsage);
    /// Waits until descriptors become ready, a timeout expires, or a signal arrives while optionally replacing the signal mask.
    error::Result<i64, ERRNO> pselect6               (i32 _descriptorRange, DescriptorSet* _readFileDescriptors, DescriptorSet* _writeFileDescriptors, DescriptorSet* _exceptionFileDescriptors, KernelTimeSpecification* _timeout, void* _signalMaskData);
    /// Waits for epoll events with millisecond timeout precision while temporarily replacing the signal mask.
    error::Result<i64, ERRNO> epoll_pwait            (i32 _epollFileDescriptor, EpollEventData* _events, i32 _maximumEvents, i32 _timeout, const SignalSet* _signalMask, u64 _signalSetSize);
    /// Waits for epoll events with high-resolution timeout precision while temporarily replacing the signal mask.
    error::Result<i64, ERRNO> epoll_pwait2           (i32 _epollFileDescriptor, EpollEventData* _events, i32 _maximumEvents, const KernelTimeSpecification* _timeout, const SignalSet* _signalMask, u64 _signalSetSize);
    /// Waits synchronously for one of a selected set of signals with an optional timeout.
    error::Result<i64, ERRNO> rt_sigtimedwait        (const SignalSet* _signalSet, SignalInformation* _signalInfo, const KernelTimeSpecification* _timeout, s64 _signalSetSize);
    /// Sleeps while a futex contains an expected value and satisfies the supplied bit mask.
    error::Result<i64, ERRNO> futex_wait             (void* _userAddress, u64 _value, u64 _mask, u32 _flags, KernelTimeSpecification* _timeout, i32 _clockId);
    /// Waits until at least one futex in a vector becomes eligible to wake.
    error::Result<i64, ERRNO> futex_waitv            (FutexWaitRequest* _waiters, u32 _futexCount, u32 _flags, KernelTimeSpecification* _timeout, i32 _clockId);
    /// Wakes threads waiting on a futex whose waiter masks intersect the supplied mask.
    error::Result<i64, ERRNO> futex_wake             (void* _userAddress, u64 _mask, i32 _wakeCount, u32 _flags);
    /// Writes bytes from a buffer to an open file descriptor.
    error::Result<i64, ERRNO> write                  (u32 _fileDescriptor, const c08* _buffer, s64 _count);
    /// Writes data from multiple buffers to a descriptor in a single operation.
    error::Result<i64, ERRNO> writev                 (u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount);
    /// Writes bytes to a file at an explicit offset without changing the shared file position.
    error::Result<i64, ERRNO> pwrite64               (u32 _fileDescriptor, const c08* _buffer, s64 _count, i64 _position);
    /// Writes from multiple buffers at an explicit file offset without changing the shared file position.
    error::Result<i64, ERRNO> pwritev                (u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh);
    /// Writes from multiple buffers at an explicit file offset with per-operation behavior flags.
    error::Result<i64, ERRNO> pwritev2               (u64 _fileDescriptor, const IoVector* _vectors, u64 _vectorCount, u64 _positionLow, u64 _positionHigh, i32 _flags);
    /// Copies memory directly from local buffers into another process.
    error::Result<i64, ERRNO> process_vm_writev      (i32 _processId, const IoVector* _localVectors, u64 _localVectorCount, const IoVector* _remoteVectors, u64 _remoteVectorCount, u64 _flags);
    /// Voluntarily yields execution so another runnable thread may be scheduled.
    error::Result<i64, ERRNO> sched_yield            ();
}