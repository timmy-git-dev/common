#include "system/CxxABI.hpp"
#include "system/EntryExit.hpp"
#include "system/SysCalls.hpp"

struct Demo
{
      Demo() { cmn::system::write(1, "ctor\n", 5); }
     ~Demo() { cmn::system::write(1, "dtor\n", 5); }
} demo;


int main()
{
    // write: stdout
    const char msg[] = "hello\n";
    cmn::system::write(1, msg, 6);

    // read: stdin
    char buf[64];
    long n = cmn::system::read(0, buf, sizeof(buf));
    cmn::system::write(1, buf, n);

    // openat: open file (cwd = AT_FDCWD = -100)
    int fd = cmn::system::openat(-100, "file.txt", /*O_RDONLY*/2, 0);
    n = cmn::system::read(fd, buf, sizeof(buf));
    cmn::system::write(1, buf, n);
    // lseek: rewind to start
    cmn::system::lseek(fd, 3, /*SEEK_SET*/0);
    cmn::system::write(fd, "nope\n", 5);

    // close
    cmn::system::close(fd);


    // stat
    struct stat {
        unsigned long dev;
        unsigned long ino;
        unsigned long nlink;
        unsigned int  mode;
        unsigned int  uid;
        unsigned int  gid;
        unsigned int  __pad0;
        unsigned long rdev;
        long          size;
        long          blksize;
        long          blocks;
        long          atime;
        unsigned long atime_nsec;
        long          mtime;
        unsigned long mtime_nsec;
        long          ctime;
        unsigned long ctime_nsec;
        long          __unused[3];
    } st;
    n = cmn::system::stat("file.txt", &st);
    // cmn::system::write(1, st.size, 144);



    return 0;
}

extern "C" void _start()
{
    cmn::system::run_global_ctors();
    int _exitCode = main();
    cmn::system::__cxa_finalize(nullptr);
    cmn::system::run_global_dtors();
    cmn::system::exit(_exitCode);
}