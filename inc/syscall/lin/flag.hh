#pragma once

namespace cmn::syscall::mac
{
    // #define AT_FDCWD -2

    // #define F_GETPATH 50

    // #define O_RDONLY    0x00000000
    // #define O_DIRECTORY 0x00100000
    // #define O_CLOEXEC   0x01000000

    // #define AT_SYMLINK_NOFOLLOW 0x100

    // #define S_IFMT   0170000

    #define	S_IFIFO  0010000
    #define	S_IFCHR  0020000
    #define	S_IFDIR  0040000
    #define	S_IFBLK  0060000
    #define	S_IFREG  0100000
    #define	S_IFLNK  0120000
    #define	S_IFSOCK 0140000



    // #define PROT_NONE           0x0
    // #define PROT_READ           0x1
    // #define PROT_WRITE          0x2
    // #define PROT_EXEC           0x4
    // #define PROT_SEM            0x8
    // #define PROT_GROWSDOWN      0x01000000
    // #define PROT_GROWSUP        0x02000000

    // #define MAP_SHARED          0x01
    // #define MAP_PRIVATE         0x02
    // #define MAP_SHARED_VALIDATE 0x03
    // #define MAP_FIXED           0x10
    // #define MAP_ANONYMOUS       0x20
    // #define MAP_GROWSDOWN       0x0100
    // #define MAP_DENYWRITE       0x0800
    // #define MAP_EXECUTABLE      0x1000
    // #define MAP_LOCKED          0x2000
    // #define MAP_NORESERVE       0x4000
    // #define MAP_POPULATE        0x8000
    // #define MAP_NONBLOCK        0x10000
    // #define MAP_STACK           0x20000
    // #define MAP_HUGETLB         0x40000
    // #define MAP_SYNC            0x80000
    // #define MAP_FIXED_NOREPLACE 0x100000
}