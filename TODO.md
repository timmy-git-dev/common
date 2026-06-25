type:
├─ alias # compiler type aliases.
├─ cast  # explicit type conversions.
└─ trait
   ├─ characteristic # compile-time properties of types. (is ptr, ref, same, etc.)
   ├─ transform      # compile-time changes to types. (const, volatile, ref, ptr, etc.)
   ├─ util           # compile-time type diagnostics. (conditionals, underlying/identity, etc.)
   └─ value          # compile-time type specifications. (integral, floating-point, trivial, etc.)

    system
    ├─ platform
    │  ├─ os       # linux, windows, macos, bsd, freestanding
    │  ├─ compiler # gcc, clang, msvc
    │  ├─ arch     # x86, x64, arm32, arm64, riscv
    │  ├─ endian   # little, big
    │  └─ build    # debug, release
    ├─ errno # platform error constants
    ├─ syscall
    │  ├─ raw      # syscall ABI wrapper
    │  └─ numbers  # OS-specific syscall IDs
    ├─ abi
    │  ├─ cxx      # __cxa_* (exceptions, static init, terminate)
    │  └─ entry    # _start, main, init/fini, TLS bootstrap
    ├─ cpu
    │  ├─ features # SIMD, cache line, CPUID
    │  ├─ fence    # memory barriers
    │  └─ time     # rdtsc / counter
    └─ memory
       ├─ ops      # memcpy/memmove/memset/memcmp
       ├─ alloc    # sbrk/mmap/VirtualAlloc (optional layer)
       └─ layout   # alignment, pages, cache line utils

    error: type, system
    ├─ result
    ├─ panic
    ├─ abort
    ├─ debug
    └─ assert
    math: type
    ├─ scalar
    ├─ vec
    ├─ quat
    ├─ mat
    ├─ random
    ├─ noise
    ├─ color
    └─ geometry
    hash: type
    ├─ fnv1a
    └─ wyhash
    time: type, system
    ├─ duration
    ├─ clock
    ├─ timer
    ├─ sleep
    └─ date
    sync: type, system
    ├─ atomic
    ├─ thread
    ├─ mutex
    ├─ lock
    ├─ condition
    └─ semaphore
    process: type, system
    ├─ process
    ├─ env
    ├─ spawn
    ├─ exec
    ├─ exit
    └─ wait
    net: type, system
    ├─ address
    ├─ endpoint
    ├─ socket
    ├─ poll
    └─ dns

      allocator: type, system, error
      ├─ arena
      ├─ region
      ├─ pool
      └─ heap

        container: type, allocator
        ├─ span
        ├─ array
        ├─ view
        ├─ text
        ├─ string
        ├─ slice
        ├─ queue
        ├─ stack
        ├─ ring
        ├─ map
        ├─ set
        └─ bitset

          fs: type, system, container
          ├─ path
          ├─ file
          └─ directory
          io: type, container, fs
          └─ terminal