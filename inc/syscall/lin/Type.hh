#pragma once
#include "sys/platform/Arch.hh"
#include "type/Alias.hh"

namespace cmn::syscall
{

    typedef struct __user_cap_header_struct
    {
        u32 version;
        int   pid;
    } *cap_user_header_t;
    typedef struct __user_cap_data_struct
    {
        u32 effective;
        u32 permitted;
        u32 inheritable;
    } *cap_user_data_t;

    enum LandlockRulesetType
    {
        LANDLOCK_RULE_PATH_BENEATH = 1,
        LANDLOCK_RULE_NET_PORT     = 2,
    };

    #define __FD_SETSIZE 1024
    struct DescriptorSet
    {
        unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(long))];
    };

    struct DescriptorTime
    {
        long tv_sec;
        long tv_nsec;
    };

    struct DescriptorStatus
    {
        #if CMN_SYS_ARCH_X64
            u32      deviceId;
            u32      inodeNumber;
            u32      hardLinkCount;
            u32      fileMode;
            u32      userId;
            u32      groupId;
            u32      : 32;
            u32      deviceType;
            s64      fileSize;
            u32      blockSize;
            u32      allocatedBlockCount;
            DescriptorTime accessTime;
            DescriptorTime modificationTime;
            DescriptorTime statusChangeTime;
            u64      : 192;
        #elif CMN_SYS_ARCH_ARM64
            u32      deviceId;
            u32      inodeNumber;
            u32      fileMode;
            u32      hardLinkCount;
            u32      userId;
            u32      groupId;
            u32      deviceType;
            u64      : 64;
            s64       fileSize;
            u32      blockSize;
            u32      : 32;
            u32      allocatedBlockCount;
            timespec accessTime;
            timespec modificationTime;
            timespec statusChangeTime;
            u32      : 32;
            u32      : 32;
        #endif
    };

    struct AioSignalSet;                     // aio_signal_set
    struct CacheStatistics;                  // cache_statistics
    struct CacheStatisticsRange;             // cache_statistics_range
    struct CloneArguments;                   // clone_arguments
    struct EpollEventData;                   // epoll_event_data
    struct FileAttributes;                   // file_attributes
    struct FileHandleInfo;                   // file_handle_info
    struct FutexWaitRequest;                 // futex_wait_request
    struct GetcpuCacheData;                  // getcpu_cache_data
    struct IoControlBlock;                   // io_control_block
    struct IoCompletionEvent;                // io_completion_event
    struct IoUringParameters;                // io_uring_parameters
    struct IoVector;                         // io_vector
    struct LegacyIntervalTimerValue;         // legacy_interval_timer_value
    struct LegacyTimeValue;                  // legacy_time_value
    struct KernelTimeSpecification;          // kernel_time_specification
    struct KernelIntervalTimerSpecification; // kernel_interval_timer_specification
    struct KernelTimeAdjustment;             // kernel_time_adjustment
    struct KernelExecutionSegment;           // kernel_execution_segment
    struct LandlockRulesetAttributes;        // landlock_ruleset_attributes
    struct LinuxDirectoryEntry;              // linux_directory_entry
    struct SecurityModuleContext;            // security_module_context
    struct MultiMessageHeader;               // multi_message_header
    struct MountIdentifierRequest;           // mount_identifier_request
    struct MountAttributes;                  // mount_attributes
    struct MessageQueueAttributes;           // message_queue_attributes
    struct MessageBuffer;                    // message_buffer
    struct MessageQueueStatus;               // message_queue_status
    struct SystemIdentification;             // system_identification
    struct OpenOptions;                      // open_options
    struct PerformanceEventAttributes;       // performance_event_attributes
    struct PollFileDescriptor;               // poll_file_descriptor
    struct ResourceLimit;                    // resource_limit
    struct ResourceLimit64;                  // resource_limit_64
    struct RobustFutexListHead;              // robust_futex_list_head
    struct RestartableSequence;              // restartable_sequence
    struct ResourceUsage;                    // resource_usage
    struct SchedulerAttributes;              // scheduler_attributes
    struct SchedulerParameters;              // scheduler_parameters
    struct SemaphoreOperation;               // semaphore_operation
    struct SharedMemoryStatus;               // shared_memory_status
    struct SignalAction;                     // signal_action
    struct SignalEvent;                      // signal_event
    struct SignalInformation;                // signal_information_t
    struct SignalSet;                        // signal_set
    struct SocketAddress;                    // socket_address
    struct SignalStack;                      // signal_stack
    struct FilesystemStatistics;             // filesystem_statistics
    struct MountStatistics;                  // mount_statistics
    struct ExtendedFileStatus;               // extended_file_status
    struct SystemInformation;                // system_information
    struct TimezoneInformation;              // timezone_information
    struct ProcessTimeStatistics;            // process_time_statistics
    struct UserMessageHeader;                // user_message_header
    struct ExtendedAttributeArguments;       // extended_attribute_arguments
}