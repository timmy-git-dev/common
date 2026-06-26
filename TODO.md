type:
├─ alias
├─ cast
└─ trait
   ├─ characteristic
   ├─ transform
   ├─ util
   └─ value

    system
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
    ├─ abi // Currently on:
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
    └─ color
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