#pragma once

namespace cmn::syscall::mac
{
    #define AT_FDCWD -2

    #define F_GETPATH 50

    #define O_RDONLY    0x00000000
    #define O_DIRECTORY 0x00100000
    #define O_CLOEXEC   0x01000000

    #define AT_SYMLINK_NOFOLLOW 0x100

    #define S_IFMT   0170000  /* type of file */

    #define	S_IFIFO  0010000  /* named pipe (fifo) */
    #define	S_IFCHR  0020000  /* character special */
    #define	S_IFDIR  0040000  /* directory */
    #define	S_IFBLK  0060000  /* block special */
    #define	S_IFREG  0100000  /* regular */
    #define	S_IFLNK  0120000  /* symbolic link */
    #define	S_IFSOCK 0140000  /* socket */
    #define	S_IFWHT  0160000  /* whiteout */
}