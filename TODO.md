- implement universal syscalls for lin/win/mac. (exit, write, mmap, etc.)










<!--type:
├─ alias
├─ cast
└─ trait
   ├─ characteristic
   ├─ transform
   ├─ util
   └─ value

    sys
    ├─ platform
    │  ├─ os
    │  ├─ compiler
    │  ├─ arch
    │  ├─ endian
    │  └─ build
    ├─ errno
    ├─ syscall
    │  ├─ raw
    │  └─ numbers
    ├─ abi
    │  ├─ cxx
    │  └─ entry
    ├─ cpu
    │  ├─ features
    │  ├─ fence
    │  └─ time
    └─ memory
       ├─ ops
       ├─ alloc
       └─ layout

    error: type, sys
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
    └─ color
    hash: type
    ├─ fnv1a
    └─ wyhash
    time: type, sys
    ├─ duration
    ├─ clock
    ├─ timer
    ├─ sleep
    └─ date
    sync: type, sys
    ├─ atomic
    ├─ thread
    ├─ mutex
    ├─ lock
    ├─ condition
    └─ semaphore
    process: type, sys
    ├─ process
    ├─ env
    ├─ spawn
    ├─ exec
    ├─ exit
    └─ wait
    net: type, sys
    ├─ address
    ├─ endpoint
    ├─ socket
    ├─ poll
    └─ dns

      allocator: type, sys, error
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

          fs: type, sys, container
          ├─ path
          ├─ file
          └─ directory
          io: type, container, fs
          └─ terminal-->