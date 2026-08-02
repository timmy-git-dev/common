#pragma once
#include "syscall/mac/Func.hpp"
#include "syscall/mac/ID.hpp"
#include "syscall/mac/Type.hpp"

namespace cmn::syscall::mac
{
    inline void exit(int rval) {syscall(EXIT,(long)rval);}
    inline int fork(void) {return syscall(FORK);}
    inline user_ssize_t read(int fd,user_addr_t cbuf,user_size_t nbyte) {return syscall(READ,(long)fd,(long)cbuf,(long)nbyte);}
    inline user_ssize_t write(int fd,user_addr_t cbuf,user_size_t nbyte) {return syscall(WRITE,(long)fd,(long)cbuf,(long)nbyte);}
    inline int open(user_addr_t path,int flags,int mode) {return syscall(OPEN,(long)path,(long)flags,(long)mode);}
    inline int sys_close(int fd) {return syscall(SYS_CLOSE,(long)fd);}
    inline int wait4(int pid,user_addr_t status,int options,user_addr_t rusage) {return syscall(WAIT4,(long)pid,(long)status,(long)options,(long)rusage);}
    inline int link(user_addr_t path,user_addr_t link) {return syscall(LINK,(long)path,(long)link);}
    inline int unlink(user_addr_t path) {return syscall(UNLINK,(long)path);}
    inline int sys_chdir(user_addr_t path) {return syscall(SYS_CHDIR,(long)path);}
    inline int sys_fchdir(int fd) {return syscall(SYS_FCHDIR,(long)fd);}
    inline int mknod(user_addr_t path,int mode,int dev) {return syscall(MKNOD,(long)path,(long)mode,(long)dev);}
    inline int chmod(user_addr_t path,int mode) {return syscall(CHMOD,(long)path,(long)mode);}
    inline int chown(user_addr_t path,int uid,int gid) {return syscall(CHOWN,(long)path,(long)uid,(long)gid);}
    inline int getfsstat(user_addr_t buf,int bufsize,int flags) {return syscall(GETFSSTAT,(long)buf,(long)bufsize,(long)flags);}
    inline int getpid(void) {return syscall(GETPID);}
    inline int setuid(uid_t uid) {return syscall(SETUID,(long)uid);}
    inline int getuid(void) {return syscall(GETUID);}
    inline int geteuid(void) {return syscall(GETEUID);}
    inline int ptrace(int req,pid_t pid,caddr_t addr,int data) {return syscall(PTRACE,(long)req,(long)pid,(long)addr,(long)data);}
    inline int recvmsg(int s, msghdr *msg,int flags) {return syscall(RECVMSG,(long)s,(long)msg,(long)flags);}
    inline int sendmsg(int s,caddr_t msg,int flags) {return syscall(SENDMSG,(long)s,(long)msg,(long)flags);}
    inline int recvfrom(int s,void *buf,size_t len,int flags, sockaddr *from,int *fromlenaddr) {return syscall(RECVFROM,(long)s,(long)buf,(long)len,(long)flags,(long)from,(long)fromlenaddr);}
    inline int accept(int s,caddr_t name,socklen_t *anamelen) {return syscall(ACCEPT,(long)s,(long)name,(long)anamelen);}
    inline int getpeername(int fdes,caddr_t asa,socklen_t *alen) {return syscall(GETPEERNAME,(long)fdes,(long)asa,(long)alen);}
    inline int getsockname(int fdes,caddr_t asa,socklen_t *alen) {return syscall(GETSOCKNAME,(long)fdes,(long)asa,(long)alen);}
    inline int access(user_addr_t path,int flags) {return syscall(ACCESS,(long)path,(long)flags);}
    inline int chflags(char *path,int flags) {return syscall(CHFLAGS,(long)path,(long)flags);}
    inline int fchflags(int fd,int flags) {return syscall(FCHFLAGS,(long)fd,(long)flags);}
    inline int sync(void) {return syscall(SYNC);}
    inline int kill(int pid,int signum,int posix) {return syscall(KILL,(long)pid,(long)signum,(long)posix);}
    inline int sys_crossarch_trap(uint32_t name) {return syscall(SYS_CROSSARCH_TRAP,(long)name);}
    inline int getppid(void) {return syscall(GETPPID);}
    inline int sys_dup(u_int fd) {return syscall(SYS_DUP,(long)fd);}
    inline int pipe(void) {return syscall(PIPE);}
    inline int getegid(void) {return syscall(GETEGID);}
    inline int sigaction(int signum, __sigaction *nsa, sigaction *osa) {return syscall(SIGACTION,(long)signum,(long)nsa,(long)osa);}
    inline int getgid(void) {return syscall(GETGID);}
    inline int sigprocmask(int how,user_addr_t mask,user_addr_t omask) {return syscall(SIGPROCMASK,(long)how,(long)mask,(long)omask);}
    inline int getlogin(char *namebuf,u_int namelen) {return syscall(GETLOGIN,(long)namebuf,(long)namelen);}
    inline int setlogin(char *namebuf) {return syscall(SETLOGIN,(long)namebuf);}
    inline int acct(char *path) {return syscall(ACCT,(long)path);}
    inline int sigpending( sigvec *osv) {return syscall(SIGPENDING,(long)osv);}
    inline int sigaltstack( sigaltstack *nss, sigaltstack *oss)  {return syscall(SIGALTSTACK,(long)nss,(long)oss);}
    inline int ioctl(int fd,u_long com,caddr_t data) {return syscall(IOCTL,(long)fd,(long)com,(long)data);}
    inline int reboot(int opt,char *msg) {return syscall(REBOOT,(long)opt,(long)msg);}
    inline int revoke(char *path) {return syscall(REVOKE,(long)path);}
    inline int symlink(char *path,char *link) {return syscall(SYMLINK,(long)path,(long)link);}
    inline int readlink(char *path,char *buf,int count) {return syscall(READLINK,(long)path,(long)buf,(long)count);}
    inline int execve(char *fname,char **argp,char **envp) {return syscall(EXECVE,(long)fname,(long)argp,(long)envp);}
    inline int umask(int newmask) {return syscall(UMASK,(long)newmask);}
    inline int chroot(user_addr_t path) {return syscall(CHROOT,(long)path);}
    inline int msync(caddr_ut addr,size_ut len,int flags) {return syscall(MSYNC,(long)addr,(long)len,(long)flags);}
    inline int vfork(void) {return syscall(VFORK);}
    inline int oslog_coproc_reg(const char *uuid,const char *file_path,size_t file_path_len) {return syscall(OSLOG_COPROC_REG,(long)uuid,(long)file_path,(long)file_path_len);}
    inline int oslog_coproc(void *buff,uint64_t buff_len,uint32_t type,const char *uuid,uint64_t timestamp,uint32_t offset,uint32_t stream_log) {return syscall(OSLOG_COPROC,(long)buff,(long)buff_len,(long)type,(long)uuid,(long)timestamp,(long)offset,(long)stream_log);}
    inline int munmap(caddr_ut addr,size_ut len) {return syscall(MUNMAP,(long)addr,(long)len);}
    inline int mprotect(caddr_ut addr,size_ut len,int prot) {return syscall(MPROTECT,(long)addr,(long)len,(long)prot);}
    inline int madvise(caddr_ut addr,size_ut len,int behav) {return syscall(MADVISE,(long)addr,(long)len,(long)behav);}
    inline int mincore(caddr_ut addr,size_ut len,user_addr_t vec) {return syscall(MINCORE,(long)addr,(long)len,(long)vec);}
    inline int getgroups(u_int gidsetsize,gid_t *gidset) {return syscall(GETGROUPS,(long)gidsetsize,(long)gidset);}
    inline int setgroups(u_int gidsetsize,gid_t *gidset) {return syscall(SETGROUPS,(long)gidsetsize,(long)gidset);}
    inline int getpgrp(void) {return syscall(GETPGRP);}
    inline int setpgid(int pid,int pgid) {return syscall(SETPGID,(long)pid,(long)pgid);}
    inline int setitimer(u_int which, itimerval *itv, itimerval *oitv) {return syscall(SETITIMER,(long)which,(long)itv,(long)oitv);}
    inline int swapon(void) {return syscall(SWAPON);}
    inline int getitimer(u_int which, itimerval *itv) {return syscall(GETITIMER,(long)which,(long)itv);}
    inline int sys_getdtablesize(void) {return syscall(SYS_GETDTABLESIZE);}
    inline int sys_dup2(u_int from,u_int to) {return syscall(SYS_DUP2,(long)from,(long)to);}
    inline int sys_fcntl(int fd,int cmd,long arg) {return syscall(SYS_FCNTL,(long)fd,(long)cmd,(long)arg);}
    inline int select(int nd,u_int32_t *in,u_int32_t *ou,u_int32_t *ex, timeval *tv) {return syscall(SELECT,(long)nd,(long)in,(long)ou,(long)ex,(long)tv);}
    inline int fsync(int fd) {return syscall(FSYNC,(long)fd);}
    inline int setpriority(int which,id_t who,int prio) {return syscall(SETPRIORITY,(long)which,(long)who,(long)prio);}
    inline int socket(int domain,int type,int protocol) {return syscall(SOCKET,(long)domain,(long)type,(long)protocol);}
    inline int connect(int s,caddr_t name,socklen_t namelen) {return syscall(CONNECT,(long)s,(long)name,(long)namelen);}
    inline int getpriority(int which,id_t who) {return syscall(GETPRIORITY,(long)which,(long)who);}
    inline int bind(int s,caddr_t name,socklen_t namelen) {return syscall(BIND,(long)s,(long)name,(long)namelen);}
    inline int setsockopt(int s,int level,int name,caddr_t val,socklen_t valsize) {return syscall(SETSOCKOPT,(long)s,(long)level,(long)name,(long)val,(long)valsize);}
    inline int listen(int s,int backlog) {return syscall(LISTEN,(long)s,(long)backlog);}
    inline int sigsuspend(sigset_t mask) {return syscall(SIGSUSPEND,(long)mask);}
    inline int gettimeofday( timeval *tp, timezone *tzp,uint64_t *mach_absolute_time) {return syscall(GETTIMEOFDAY,(long)tp,(long)tzp,(long)mach_absolute_time);}
    inline int getrusage(int who, rusage *rusage) {return syscall(GETRUSAGE,(long)who,(long)rusage);}
    inline int getsockopt(int s,int level,int name,caddr_t val,socklen_t *avalsize) {return syscall(GETSOCKOPT,(long)s,(long)level,(long)name,(long)val,(long)avalsize);}
    inline user_ssize_t readv(int fd, iovec *iovp,u_int iovcnt) {return syscall(READV,(long)fd,(long)iovp,(long)iovcnt);}
    inline user_ssize_t writev(int fd, iovec *iovp,u_int iovcnt) {return syscall(WRITEV,(long)fd,(long)iovp,(long)iovcnt);}
    inline int settimeofday( timeval *tv, timezone *tzp) {return syscall(SETTIMEOFDAY,(long)tv,(long)tzp);}
    inline int fchown(int fd,int uid,int gid) {return syscall(FCHOWN,(long)fd,(long)uid,(long)gid);}
    inline int fchmod(int fd,int mode) {return syscall(FCHMOD,(long)fd,(long)mode);}
    inline int setreuid(uid_t ruid,uid_t euid) {return syscall(SETREUID,(long)ruid,(long)euid);}
    inline int setregid(gid_t rgid,gid_t egid) {return syscall(SETREGID,(long)rgid,(long)egid);}
    inline int rename(char *from,char *to) {return syscall(RENAME,(long)from,(long)to);}
    inline int sys_flock(int fd,int how) {return syscall(SYS_FLOCK,(long)fd,(long)how);}
    inline int mkfifo(user_addr_t path,int mode) {return syscall(MKFIFO,(long)path,(long)mode);}
    inline int sendto(int s,caddr_t buf,size_t len,int flags,caddr_t to,socklen_t tolen) {return syscall(SENDTO,(long)s,(long)buf,(long)len,(long)flags,(long)to,(long)tolen);}
    inline int shutdown(int s,int how) {return syscall(SHUTDOWN,(long)s,(long)how);}
    inline int socketpair(int domain,int type,int protocol,int *rsv) {return syscall(SOCKETPAIR,(long)domain,(long)type,(long)protocol,(long)rsv);}
    inline int mkdir(user_addr_t path,int mode) {return syscall(MKDIR,(long)path,(long)mode);}
    inline int rmdir(char *path) {return syscall(RMDIR,(long)path);}
    inline int utimes(char *path, timeval *tptr) {return syscall(UTIMES,(long)path,(long)tptr);}
    inline int futimes(int fd, timeval *tptr) {return syscall(FUTIMES,(long)fd,(long)tptr);}
    inline int adjtime( timeval *delta, timeval *olddelta) {return syscall(ADJTIME,(long)delta,(long)olddelta);}
    inline int gethostuuid(unsigned char *uuid_buf,const  timespec *timeoutp) {return syscall(GETHOSTUUID,(long)uuid_buf,(long)timeoutp);}
    inline int setsid(void) {return syscall(SETSID);}
    inline int getpgid(pid_t pid) {return syscall(GETPGID,(long)pid);}
    inline int setprivexec(int flag) {return syscall(SETPRIVEXEC,(long)flag);}
    inline user_ssize_t pread(int fd,user_addr_t buf,user_size_t nbyte,off_t offset) {return syscall(PREAD,(long)fd,(long)buf,(long)nbyte,(long)offset);}
    inline user_ssize_t pwrite(int fd,user_addr_t buf,user_size_t nbyte,off_t offset) {return syscall(PWRITE,(long)fd,(long)buf,(long)nbyte,(long)offset);}
    inline int nfssvc(int flag,caddr_t argp) {return syscall(NFSSVC,(long)flag,(long)argp);}
    inline int statfs_(char *path, statfs *buf) {return syscall(STATFS,(long)path,(long)buf);}
    inline int fstatfs(int fd, statfs *buf) {return syscall(FSTATFS,(long)fd,(long)buf);}
    inline int unmount(user_addr_t path,int flags) {return syscall(UNMOUNT,(long)path,(long)flags);}
    inline int getfh(char *fname,fhandle_t *fhp) {return syscall(GETFH,(long)fname,(long)fhp);}
    inline int funmount(int fd,int flags) {return syscall(FUNMOUNT,(long)fd,(long)flags);}
    inline int quotactl(const char *path,int cmd,int uid,caddr_t arg) {return syscall(QUOTACTL,(long)path,(long)cmd,(long)uid,(long)arg);}
    inline int mount(char *type,char *path,int flags,caddr_t data) {return syscall(MOUNT,(long)type,(long)path,(long)flags,(long)data);}
    inline int csops(pid_t pid,uint32_t ops,user_addr_t useraddr,user_size_t usersize) {return syscall(CSOPS,(long)pid,(long)ops,(long)useraddr,(long)usersize);}
    inline int csops_audittoken(pid_t pid,uint32_t ops,user_addr_t useraddr,user_size_t usersize,user_addr_t uaudittoken) {return syscall(CSOPS_AUDITTOKEN,(long)pid,(long)ops,(long)useraddr,(long)usersize,(long)uaudittoken);}
    inline int waitid(idtype_t idtype,id_t id,siginfo_t *infop,int options) {return syscall(WAITID,(long)idtype,(long)id,(long)infop,(long)options);}
    inline int kdebug_typefilter(void** addr,size_t* size) {return syscall(KDEBUG_TYPEFILTER,(long)addr,(long)size);}
    inline uint64_t kdebug_trace_string(uint32_t debugid,uint64_t str_id,const char *str) {return syscall(KDEBUG_TRACE_STRING,(long)debugid,(long)str_id,(long)str);}
    inline int kdebug_trace64(uint32_t code,uint64_t arg1,uint64_t arg2,uint64_t arg3,uint64_t arg4) {return syscall(KDEBUG_TRACE64,(long)code,(long)arg1,(long)arg2,(long)arg3,(long)arg4);}
    inline int kdebug_trace(uint32_t code,u_long arg1,u_long arg2,u_long arg3,u_long arg4) {return syscall(KDEBUG_TRACE,(long)code,(long)arg1,(long)arg2,(long)arg3,(long)arg4);}
    inline int setgid(gid_t gid) {return syscall(SETGID,(long)gid);}
    inline int setegid(gid_t egid) {return syscall(SETEGID,(long)egid);}
    inline int seteuid(uid_t euid) {return syscall(SETEUID,(long)euid);}
    inline int sigreturn( ucontext *uctx,int infostyle,user_addr_t token) {return syscall(SIGRETURN,(long)uctx,(long)infostyle,(long)token);}
    inline int sys_panic_with_data(uuid_t uuid,void *addr,uint32_t len,uint32_t flags,const char *msg) {return syscall(SYS_PANIC_WITH_DATA,(long)uuid,(long)addr,(long)len,(long)flags,(long)msg);}
    inline int thread_selfcounts(uint32_t kind,user_addr_t buf,user_size_t size) {return syscall(THREAD_SELFCOUNTS,(long)kind,(long)buf,(long)size);}
    inline int fdatasync(int fd) {return syscall(FDATASYNC,(long)fd);}
    inline int stat(user_addr_t path,user_addr_t ub) {return syscall(STAT,(long)path,(long)ub);}
    inline int sys_fstat(int fd,user_addr_t ub) {return syscall(SYS_FSTAT,(long)fd,(long)ub);}
    inline int lstat(user_addr_t path,user_addr_t ub) {return syscall(LSTAT,(long)path,(long)ub);}
    inline int pathconf(char *path,int name) {return syscall(PATHCONF,(long)path,(long)name);}
    inline int sys_fpathconf(int fd,int name) {return syscall(SYS_FPATHCONF,(long)fd,(long)name);}
    inline int getrlimit(u_int which, rlimit *rlp) {return syscall(GETRLIMIT,(long)which,(long)rlp);}
    inline int setrlimit(u_int which, rlimit *rlp) {return syscall(SETRLIMIT,(long)which,(long)rlp);}
    inline int getdirentries(int fd,char *buf,u_int count,long *basep) {return syscall(GETDIRENTRIES,(long)fd,(long)buf,(long)count,(long)basep);}
    inline user_addr_t mmap(caddr_ut addr,size_ut len,int prot,int flags,int fd,off_t pos) {return syscall(MMAP,(long)addr,(long)len,(long)prot,(long)flags,(long)fd,(long)pos);}
    inline off_t lseek(int fd,off_t offset,int whence) {return syscall(LSEEK,(long)fd,(long)offset,(long)whence);}
    inline int truncate(char *path,off_t length) {return syscall(TRUNCATE,(long)path,(long)length);}
    inline int ftruncate(int fd,off_t length) {return syscall(FTRUNCATE,(long)fd,(long)length);}
    inline int sysctl(int *name,u_int namelen,void *old,size_t *oldlenp,void *_new,size_t newlen) {return syscall(SYSCTL,(long)name,(long)namelen,(long)old,(long)oldlenp,(long)_new,(long)newlen);}
    inline int mlock(caddr_ut addr,size_ut len) {return syscall(MLOCK,(long)addr,(long)len);}
    inline int munlock(caddr_ut addr,size_ut len) {return syscall(MUNLOCK,(long)addr,(long)len);}
    inline int undelete(user_addr_t path) {return syscall(UNDELETE,(long)path);}
    inline int open_dprotected_np(user_addr_t path,int flags,int _class,int dpflags,int mode) {return syscall(OPEN_DPROTECTED_NP,(long)path,(long)flags,(long)_class,(long)dpflags,(long)mode);}
    inline user_ssize_t fsgetpath_ext(user_addr_t buf,size_t bufsize,user_addr_t fsid,uint64_t objid,uint32_t options) {return syscall(FSGETPATH_EXT,(long)buf,(long)bufsize,(long)fsid,(long)objid,(long)options);}
    inline int openat_dprotected_np(int fd,user_addr_t path,int flags,int _class,int dpflags,int mode,int authfd) {return syscall(OPENAT_DPROTECTED_NP,(long)fd,(long)path,(long)flags,(long)_class,(long)dpflags,(long)mode,(long)authfd);}
    inline int getattrlist(const char *path, attrlist *alist,void *attributeBuffer,size_t bufferSize,u_long options) {return syscall(GETATTRLIST,(long)path,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int setattrlist(const char *path, attrlist *alist,void *attributeBuffer,size_t bufferSize,u_long options) {return syscall(SETATTRLIST,(long)path,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int getdirentriesattr(int fd, attrlist *alist,void *buffer,size_t buffersize,u_long *count,u_long *basep,u_long *newstate,u_long options) {return syscall(GETDIRENTRIESATTR,(long)fd,(long)alist,(long)buffer,(long)buffersize,(long)count,(long)basep,(long)newstate,(long)options);}
    inline int exchangedata(const char *path1,const char *path2,u_long options) {return syscall(EXCHANGEDATA,(long)path1,(long)path2,(long)options);}
    inline int searchfs(const char *path, fssearchblock *searchblock,uint32_t *nummatches,uint32_t scriptcode,uint32_t options, searchstate *state) {return syscall(SEARCHFS,(long)path,(long)searchblock,(long)nummatches,(long)scriptcode,(long)options,(long)state);}
    inline int delete_(user_addr_t path) {return syscall(DELETE,(long)path);}
    inline int copyfile(char *from,char *to,int mode,int flags) {return syscall(COPYFILE,(long)from,(long)to,(long)mode,(long)flags);}
    inline int fgetattrlist(int fd, attrlist *alist,void *attributeBuffer,size_t bufferSize,u_long options) {return syscall(FGETATTRLIST,(long)fd,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int fsetattrlist(int fd, attrlist *alist,void *attributeBuffer,size_t bufferSize,u_long options) {return syscall(FSETATTRLIST,(long)fd,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int poll( pollfd *fds,u_int nfds,int timeout) {return syscall(POLL,(long)fds,(long)nfds,(long)timeout);}
    inline user_ssize_t getxattr(user_addr_t path,user_addr_t attrname,user_addr_t value,size_t size,uint32_t position,int options) {return syscall(GETXATTR,(long)path,(long)attrname,(long)value,(long)size,(long)position,(long)options);}
    inline user_ssize_t fgetxattr(int fd,user_addr_t attrname,user_addr_t value,size_t size,uint32_t position,int options) {return syscall(FGETXATTR,(long)fd,(long)attrname,(long)value,(long)size,(long)position,(long)options);}
    inline int setxattr(user_addr_t path,user_addr_t attrname,user_addr_t value,size_t size,uint32_t position,int options) {return syscall(SETXATTR,(long)path,(long)attrname,(long)value,(long)size,(long)position,(long)options);}
    inline int fsetxattr(int fd,user_addr_t attrname,user_addr_t value,size_t size,uint32_t position,int options) {return syscall(FSETXATTR,(long)fd,(long)attrname,(long)value,(long)size,(long)position,(long)options);}
    inline int removexattr(user_addr_t path,user_addr_t attrname,int options) {return syscall(REMOVEXATTR,(long)path,(long)attrname,(long)options);}
    inline int fremovexattr(int fd,user_addr_t attrname,int options) {return syscall(FREMOVEXATTR,(long)fd,(long)attrname,(long)options);}
    inline user_ssize_t listxattr(user_addr_t path,user_addr_t namebuf,size_t bufsize,int options) {return syscall(LISTXATTR,(long)path,(long)namebuf,(long)bufsize,(long)options);}
    inline user_ssize_t flistxattr(int fd,user_addr_t namebuf,size_t bufsize,int options) {return syscall(FLISTXATTR,(long)fd,(long)namebuf,(long)bufsize,(long)options);}
    inline int fsctl(const char *path,u_long cmd,caddr_t data,u_int options) {return syscall(FSCTL,(long)path,(long)cmd,(long)data,(long)options);}
    inline int initgroups(u_int gidsetsize,gid_t *gidset,int gmuid) {return syscall(INITGROUPS,(long)gidsetsize,(long)gidset,(long)gmuid);}
    inline int posix_spawn(pid_t *pid,const char *path,const  _posix_spawn_args_desc *adesc,char **argv,char **envp) {return syscall(POSIX_SPAWN,(long)pid,(long)path,(long)adesc,(long)argv,(long)envp);}
    inline int ffsctl(int fd,u_long cmd,caddr_t data,u_int options) {return syscall(FFSCTL,(long)fd,(long)cmd,(long)data,(long)options);}
    inline int fhopen(const  fhandle *u_fhp,int flags) {return syscall(FHOPEN,(long)u_fhp,(long)flags);}
    inline int minherit(caddr_ut addr,size_ut len,int inherit) {return syscall(MINHERIT,(long)addr,(long)len,(long)inherit);}
    inline int semsys(u_int which,int a2,int a3,int a4,int a5) {return syscall(SEMSYS,(long)which,(long)a2,(long)a3,(long)a4,(long)a5);}
    inline int msgsys(u_int which,int a2,int a3,int a4,int a5) {return syscall(MSGSYS,(long)which,(long)a2,(long)a3,(long)a4,(long)a5);}
    inline int shmsys(u_int which,int a2,int a3,int a4) {return syscall(SHMSYS,(long)which,(long)a2,(long)a3,(long)a4);}
    inline int semctl(int semid,int semnum,int cmd,semun_t arg) {return syscall(SEMCTL,(long)semid,(long)semnum,(long)cmd,(long)arg.buf);}
    inline int semget(key_t key,int nsems,int semflg) {return syscall(SEMGET,(long)key,(long)nsems,(long)semflg);}
    inline int semop(int semid, sembuf *sops,int nsops) {return syscall(SEMOP,(long)semid,(long)sops,(long)nsops);}
    inline int msgctl(int msqid,int cmd, msqid_ds *buf) {return syscall(MSGCTL,(long)msqid,(long)cmd,(long)buf);}
    inline int msgget(key_t key,int msgflg) {return syscall(MSGGET,(long)key,(long)msgflg);}
    inline int msgsnd(int msqid,void *msgp,size_t msgsz,int msgflg) {return syscall(MSGSND,(long)msqid,(long)msgp,(long)msgsz,(long)msgflg);}
    inline user_ssize_t msgrcv(int msqid,void *msgp,size_t msgsz,long msgtyp,int msgflg) {return syscall(MSGRCV,(long)msqid,(long)msgp,(long)msgsz,(long)msgtyp,(long)msgflg);}
    inline user_addr_t shmat(int shmid,void *shmaddr,int shmflg) {return syscall(SHMAT,(long)shmid,(long)shmaddr,(long)shmflg);}
    inline int shmctl(int shmid,int cmd, shmid_ds *buf) {return syscall(SHMCTL,(long)shmid,(long)cmd,(long)buf);}
    inline int shmdt(void *shmaddr) {return syscall(SHMDT,(long)shmaddr);}
    inline int shmget(key_t key,size_t size,int shmflg) {return syscall(SHMGET,(long)key,(long)size,(long)shmflg);}
    inline int shm_open(const char *name,int oflag,int mode) {return syscall(SHM_OPEN,(long)name,(long)oflag,(long)mode);}
    inline int shm_unlink(const char *name) {return syscall(SHM_UNLINK,(long)name);}
    inline user_addr_t sem_open(const char *name,int oflag,int mode,int value) {return syscall(SEM_OPEN,(long)name,(long)oflag,(long)mode,(long)value);}
    inline int sem_close(sem_t *sem) {return syscall(SEM_CLOSE,(long)sem);}
    inline int sem_unlink(const char *name) {return syscall(SEM_UNLINK,(long)name);}
    inline int sem_wait(sem_t *sem) {return syscall(SEM_WAIT,(long)sem);}
    inline int sem_trywait(sem_t *sem) {return syscall(SEM_TRYWAIT,(long)sem);}
    inline int sem_post(sem_t *sem) {return syscall(SEM_POST,(long)sem);}
    inline int sys_sysctlbyname(const char *name,size_t namelen,void *old,size_t *oldlenp,void *_new,size_t newlen) {return syscall(SYS_SYSCTLBYNAME,(long)name,(long)namelen,(long)old,(long)oldlenp,(long)_new,(long)newlen);}
    inline int open_extended(user_addr_t path,int flags,uid_t uid,gid_t gid,int mode,user_addr_t xsecurity) {return syscall(OPEN_EXTENDED,(long)path,(long)flags,(long)uid,(long)gid,(long)mode,(long)xsecurity);}
    inline int umask_extended(int newmask,user_addr_t xsecurity) {return syscall(UMASK_EXTENDED,(long)newmask,(long)xsecurity);}
    inline int stat_extended(user_addr_t path,user_addr_t ub,user_addr_t xsecurity,user_addr_t xsecurity_size) {return syscall(STAT_EXTENDED,(long)path,(long)ub,(long)xsecurity,(long)xsecurity_size);}
    inline int lstat_extended(user_addr_t path,user_addr_t ub,user_addr_t xsecurity,user_addr_t xsecurity_size) {return syscall(LSTAT_EXTENDED,(long)path,(long)ub,(long)xsecurity,(long)xsecurity_size);}
    inline int sys_fstat_extended(int fd,user_addr_t ub,user_addr_t xsecurity,user_addr_t xsecurity_size) {return syscall(SYS_FSTAT_EXTENDED,(long)fd,(long)ub,(long)xsecurity,(long)xsecurity_size);}
    inline int chmod_extended(user_addr_t path,uid_t uid,gid_t gid,int mode,user_addr_t xsecurity) {return syscall(CHMOD_EXTENDED,(long)path,(long)uid,(long)gid,(long)mode,(long)xsecurity);}
    inline int fchmod_extended(int fd,uid_t uid,gid_t gid,int mode,user_addr_t xsecurity) {return syscall(FCHMOD_EXTENDED,(long)fd,(long)uid,(long)gid,(long)mode,(long)xsecurity);}
    inline int access_extended(user_addr_t entries,size_t size,user_addr_t results,uid_t uid) {return syscall(ACCESS_EXTENDED,(long)entries,(long)size,(long)results,(long)uid);}
    inline int sys_settid(uid_t uid,gid_t gid) {return syscall(SYS_SETTID,(long)uid,(long)gid);}
    inline int gettid(uid_t *uidp,gid_t *gidp) {return syscall(GETTID,(long)uidp,(long)gidp);}
    inline int setsgroups(int setlen,user_addr_t guidset) {return syscall(SETSGROUPS,(long)setlen,(long)guidset);}
    inline int getsgroups(user_addr_t setlen,user_addr_t guidset) {return syscall(GETSGROUPS,(long)setlen,(long)guidset);}
    inline int setwgroups(int setlen,user_addr_t guidset) {return syscall(SETWGROUPS,(long)setlen,(long)guidset);}
    inline int getwgroups(user_addr_t setlen,user_addr_t guidset) {return syscall(GETWGROUPS,(long)setlen,(long)guidset);}
    inline int mkfifo_extended(user_addr_t path,uid_t uid,gid_t gid,int mode,user_addr_t xsecurity) {return syscall(MKFIFO_EXTENDED,(long)path,(long)uid,(long)gid,(long)mode,(long)xsecurity);}
    inline int mkdir_extended(user_addr_t path,uid_t uid,gid_t gid,int mode,user_addr_t xsecurity) {return syscall(MKDIR_EXTENDED,(long)path,(long)uid,(long)gid,(long)mode,(long)xsecurity);}
    inline int identitysvc(int opcode,user_addr_t message) {return syscall(IDENTITYSVC,(long)opcode,(long)message);}
    inline int shared_region_check_np(uint64_t *start_address) {return syscall(SHARED_REGION_CHECK_NP,(long)start_address);}
    inline int vm_pressure_monitor(int wait_for_pressure,int nsecs_monitored,uint32_t *pages_reclaimed) {return syscall(VM_PRESSURE_MONITOR,(long)wait_for_pressure,(long)nsecs_monitored,(long)pages_reclaimed);}
    inline uint32_t psynch_rw_longrdlock(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_LONGRDLOCK,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline uint32_t psynch_rw_yieldwrlock(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_YIELDWRLOCK,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline int psynch_rw_downgrade(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_DOWNGRADE,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline uint32_t psynch_rw_upgrade(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_UPGRADE,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline uint32_t psynch_mutexwait(user_addr_t mutex,uint32_t mgen,uint32_t  ugen,uint64_t tid,uint32_t flags) {return syscall(PSYNCH_MUTEXWAIT,(long)mutex,(long)mgen,(long)ugen,(long)tid,(long)flags);}
    inline uint32_t psynch_mutexdrop(user_addr_t mutex,uint32_t mgen,uint32_t  ugen,uint64_t tid,uint32_t flags) {return syscall(PSYNCH_MUTEXDROP,(long)mutex,(long)mgen,(long)ugen,(long)tid,(long)flags);}
    inline uint32_t psynch_cvbroad(user_addr_t cv,uint64_t cvlsgen,uint64_t cvudgen,uint32_t flags,user_addr_t mutex,uint64_t mugen,uint64_t tid) {return syscall(PSYNCH_CVBROAD,(long)cv,(long)cvlsgen,(long)cvudgen,(long)flags,(long)mutex,(long)mugen,(long)tid);}
    inline uint32_t psynch_cvsignal(user_addr_t cv,uint64_t cvlsgen,uint32_t cvugen,int thread_port,user_addr_t mutex,uint64_t mugen,uint64_t tid,uint32_t flags) {return syscall(PSYNCH_CVSIGNAL,(long)cv,(long)cvlsgen,(long)cvugen,(long)thread_port,(long)mutex,(long)mugen,(long)tid,(long)flags);}
    inline uint32_t psynch_cvwait(user_addr_t cv,uint64_t cvlsgen,uint32_t cvugen,user_addr_t mutex,uint64_t mugen,uint32_t flags,int64_t sec,uint32_t nsec) {return syscall(PSYNCH_CVWAIT,(long)cv,(long)cvlsgen,(long)cvugen,(long)mutex,(long)mugen,(long)flags,(long)sec,(long)nsec);}
    inline uint32_t psynch_rw_rdlock(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_RDLOCK,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline uint32_t psynch_rw_wrlock(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_WRLOCK,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline uint32_t psynch_rw_unlock(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_UNLOCK,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline uint32_t psynch_rw_unlock2(user_addr_t rwlock,uint32_t lgenval,uint32_t ugenval,uint32_t rw_wc,int flags)  {return syscall(PSYNCH_RW_UNLOCK2,(long)rwlock,(long)lgenval,(long)ugenval,(long)rw_wc,(long)flags);}
    inline int getsid(pid_t pid) {return syscall(GETSID,(long)pid);}
    inline int sys_settid_with_pid(pid_t pid,int assume) {return syscall(SYS_SETTID_WITH_PID,(long)pid,(long)assume);}
    inline int psynch_cvclrprepost(user_addr_t cv,uint32_t cvgen,uint32_t cvugen,uint32_t cvsgen,uint32_t prepocnt,uint32_t preposeq,uint32_t flags) {return syscall(PSYNCH_CVCLRPREPOST,(long)cv,(long)cvgen,(long)cvugen,(long)cvsgen,(long)prepocnt,(long)preposeq,(long)flags);}
    inline int aio_fsync(int op,user_addr_t aiocbp) {return syscall(AIO_FSYNC,(long)op,(long)aiocbp);}
    inline user_ssize_t aio_return(user_addr_t aiocbp) {return syscall(AIO_RETURN,(long)aiocbp);}
    inline int aio_suspend(user_addr_t aiocblist,int nent,user_addr_t timeoutp) {return syscall(AIO_SUSPEND,(long)aiocblist,(long)nent,(long)timeoutp);}
    inline int aio_cancel(int fd,user_addr_t aiocbp) {return syscall(AIO_CANCEL,(long)fd,(long)aiocbp);}
    inline int aio_error(user_addr_t aiocbp) {return syscall(AIO_ERROR,(long)aiocbp);}
    inline int aio_read(user_addr_t aiocbp) {return syscall(AIO_READ,(long)aiocbp);}
    inline int aio_write(user_addr_t aiocbp) {return syscall(AIO_WRITE,(long)aiocbp);}
    inline int lio_listio(int mode,user_addr_t aiocblist,int nent,user_addr_t sigp) {return syscall(LIO_LISTIO,(long)mode,(long)aiocblist,(long)nent,(long)sigp);}
    inline int iopolicysys(int cmd,void *arg) {return syscall(IOPOLICYSYS,(long)cmd,(long)arg);}
    inline int process_policy(int scope,int action,int policy,int policy_subtype,user_addr_t attrp,pid_t target_pid,uint64_t target_threadid) {return syscall(PROCESS_POLICY,(long)scope,(long)action,(long)policy,(long)policy_subtype,(long)attrp,(long)target_pid,(long)target_threadid);}
    inline int mlockall(int how) {return syscall(MLOCKALL,(long)how);}
    inline int munlockall(int how) {return syscall(MUNLOCKALL,(long)how);}
    inline int issetugid(void) {return syscall(ISSETUGID);}
    inline int __pthread_kill(int thread_port,int sig) {return syscall(__PTHREAD_KILL,(long)thread_port,(long)sig);}
    inline int __pthread_sigmask(int how,user_addr_t set,user_addr_t oset) {return syscall(__PTHREAD_SIGMASK,(long)how,(long)set,(long)oset);}
    inline int __sigwait(user_addr_t set,user_addr_t sig) {return syscall(__SIGWAIT,(long)set,(long)sig);}
    inline int __disable_threadsignal(int value) {return syscall(__DISABLE_THREADSIGNAL,(long)value);}
    inline int __pthread_markcancel(int thread_port) {return syscall(__PTHREAD_MARKCANCEL,(long)thread_port);}
    inline int __pthread_canceled(int  action) {return syscall(__PTHREAD_CANCELED,(long)action);}
    inline int __semwait_signal(int cond_sem,int mutex_sem,int timeout,int relative,int64_t tv_sec,int32_t tv_nsec) {return syscall(__SEMWAIT_SIGNAL,(long)cond_sem,(long)mutex_sem,(long)timeout,(long)relative,(long)tv_sec,(long)tv_nsec);}
    inline int proc_info(int32_t callnum,int32_t pid,uint32_t flavor,uint64_t arg,user_addr_t buffer,int32_t buffersize) {return syscall(PROC_INFO,(long)callnum,(long)pid,(long)flavor,(long)arg,(long)buffer,(long)buffersize);}
    inline int sendfile(int fd,int s,off_t offset,off_t *nbytes, sf_hdtr *hdtr,int flags) {return syscall(SENDFILE,(long)fd,(long)s,(long)offset,(long)nbytes,(long)hdtr,(long)flags);}
    inline int stat64(user_addr_t path,user_addr_t ub) {return syscall(STAT64,(long)path,(long)ub);}
    inline int sys_fstat64(int fd,user_addr_t ub) {return syscall(SYS_FSTAT64,(long)fd,(long)ub);}
    inline int lstat64(user_addr_t path,user_addr_t ub) {return syscall(LSTAT64,(long)path,(long)ub);}
    inline int stat64_extended(user_addr_t path,user_addr_t ub,user_addr_t xsecurity,user_addr_t xsecurity_size) {return syscall(STAT64_EXTENDED,(long)path,(long)ub,(long)xsecurity,(long)xsecurity_size);}
    inline int lstat64_extended(user_addr_t path,user_addr_t ub,user_addr_t xsecurity,user_addr_t xsecurity_size) {return syscall(LSTAT64_EXTENDED,(long)path,(long)ub,(long)xsecurity,(long)xsecurity_size);}
    inline int sys_fstat64_extended(int fd,user_addr_t ub,user_addr_t xsecurity,user_addr_t xsecurity_size) {return syscall(SYS_FSTAT64_EXTENDED,(long)fd,(long)ub,(long)xsecurity,(long)xsecurity_size);}
    inline user_ssize_t getdirentries64(int fd,void *buf,user_size_t bufsize,off_t *position) {return syscall(GETDIRENTRIES64,(long)fd,(long)buf,(long)bufsize,(long)position);}
    inline int statfs64_(char *path, statfs64 *buf) {return syscall(STATFS64,(long)path,(long)buf);}
    inline int fstatfs64(int fd, statfs64 *buf) {return syscall(FSTATFS64,(long)fd,(long)buf);}
    inline int getfsstat64(user_addr_t buf,int bufsize,int flags) {return syscall(GETFSSTAT64,(long)buf,(long)bufsize,(long)flags);}
    inline int __pthread_chdir(user_addr_t path) {return syscall(__PTHREAD_CHDIR,(long)path);}
    inline int __pthread_fchdir(int fd) {return syscall(__PTHREAD_FCHDIR,(long)fd);}
    inline int audit(void *record,int length) {return syscall(AUDIT,(long)record,(long)length);}
    inline int auditon(int cmd,void *data,int length) {return syscall(AUDITON,(long)cmd,(long)data,(long)length);}
    inline int getauid(au_id_t *auid) {return syscall(GETAUID,(long)auid);}
    inline int setauid(au_id_t *auid) {return syscall(SETAUID,(long)auid);}
    inline int getaudit_addr( auditinfo_addr *auditinfo_addr,int length) {return syscall(GETAUDIT_ADDR,(long)auditinfo_addr,(long)length);}
    inline int setaudit_addr( auditinfo_addr *auditinfo_addr,int length) {return syscall(SETAUDIT_ADDR,(long)auditinfo_addr,(long)length);}
    inline int auditctl(char *path) {return syscall(AUDITCTL,(long)path);}
    inline user_addr_t bsdthread_create(user_addr_t func,user_addr_t func_arg,user_addr_t stack,user_addr_t pthread,uint32_t flags) {return syscall(BSDTHREAD_CREATE,(long)func,(long)func_arg,(long)stack,(long)pthread,(long)flags);}
    inline int bsdthread_terminate(user_addr_t stackaddr,size_t freesize,uint32_t port,user_addr_t sema_or_ulock) {return syscall(BSDTHREAD_TERMINATE,(long)stackaddr,(long)freesize,(long)port,(long)sema_or_ulock);}
    inline int kqueue(void) {return syscall(KQUEUE);}
    inline int kevent(int fd,const  kevent *changelist,int nchanges, kevent *eventlist,int nevents,const  timespec *timeout) {return syscall(KEVENT,(long)fd,(long)changelist,(long)nchanges,(long)eventlist,(long)nevents,(long)timeout);}
    inline int lchown(user_addr_t path,uid_t owner,gid_t group) {return syscall(LCHOWN,(long)path,(long)owner,(long)group);}
    inline int bsdthread_register(user_addr_t threadstart,user_addr_t wqthread,uint32_t flags,user_addr_t stack_addr_hint,user_addr_t targetconc_ptr,uint32_t dispatchqueue_offset,uint32_t tsd_offset) {return syscall(BSDTHREAD_REGISTER,(long)threadstart,(long)wqthread,(long)flags,(long)stack_addr_hint,(long)targetconc_ptr,(long)dispatchqueue_offset,(long)tsd_offset);}
    inline int workq_open(void) {return syscall(WORKQ_OPEN);}
    inline int workq_kernreturn(int options,user_addr_t item,int affinity,int prio) {return syscall(WORKQ_KERNRETURN,(long)options,(long)item,(long)affinity,(long)prio);}
    inline int kevent64(int fd,const  kevent64_s *changelist,int nchanges, kevent64_s *eventlist,int nevents,unsigned int flags,const  timespec *timeout) {return syscall(KEVENT64,(long)fd,(long)changelist,(long)nchanges,(long)eventlist,(long)nevents,(long)flags,(long)timeout);}
    inline uint64_t thread_selfid(void) {return syscall(THREAD_SELFID);}
    inline int ledger(int cmd,caddr_t arg1,caddr_t arg2,caddr_t arg3) {return syscall(LEDGER,(long)cmd,(long)arg1,(long)arg2,(long)arg3);}
    inline int kevent_qos(int fd,const  kevent_qos_s *changelist,int nchanges, kevent_qos_s *eventlist,int nevents,void *data_out,size_t *data_available,unsigned int flags) {return syscall(KEVENT_QOS,(long)fd,(long)changelist,(long)nchanges,(long)eventlist,(long)nevents,(long)data_out,(long)data_available,(long)flags);}
    inline int kevent_id(uint64_t id,const  kevent_qos_s *changelist,int nchanges, kevent_qos_s *eventlist,int nevents,void *data_out,size_t *data_available,unsigned int flags) {return syscall(KEVENT_ID,(long)id,(long)changelist,(long)nchanges,(long)eventlist,(long)nevents,(long)data_out,(long)data_available,(long)flags);}
    inline int __mac_execve(char *fname,char **argp,char **envp, Mac *mac_p) {return syscall(__MAC_EXECVE,(long)fname,(long)argp,(long)envp,(long)mac_p);}
    inline int __mac_syscall(char *policy,int call,user_addr_t arg) {return syscall(__MAC_SYSCALL,(long)policy,(long)call,(long)arg);}
    inline int __mac_get_file(char *path_p, Mac *mac_p) {return syscall(__MAC_GET_FILE,(long)path_p,(long)mac_p);}
    inline int __mac_set_file(char *path_p, Mac *mac_p) {return syscall(__MAC_SET_FILE,(long)path_p,(long)mac_p);}
    inline int __mac_get_link(char *path_p, Mac *mac_p) {return syscall(__MAC_GET_LINK,(long)path_p,(long)mac_p);}
    inline int __mac_set_link(char *path_p, Mac *mac_p) {return syscall(__MAC_SET_LINK,(long)path_p,(long)mac_p);}
    inline int __mac_get_proc( Mac *mac_p) {return syscall(__MAC_GET_PROC,(long)mac_p);}
    inline int __mac_set_proc( Mac *mac_p) {return syscall(__MAC_SET_PROC,(long)mac_p);}
    inline int __mac_get_fd(int fd, Mac *mac_p) {return syscall(__MAC_GET_FD,(long)fd,(long)mac_p);}
    inline int __mac_set_fd(int fd, Mac *mac_p) {return syscall(__MAC_SET_FD,(long)fd,(long)mac_p);}
    inline int __mac_get_pid(pid_t pid, Mac *mac_p) {return syscall(__MAC_GET_PID,(long)pid,(long)mac_p);}
    inline int pselect(int nd,u_int32_t *in,u_int32_t *ou,u_int32_t *ex,const  timespec *ts,const sigset_t *mask) {return syscall(PSELECT,(long)nd,(long)in,(long)ou,(long)ex,(long)ts,(long)mask);}
    inline int pselect_nocancel(int nd,u_int32_t *in,u_int32_t *ou,u_int32_t *ex,const  timespec *ts,const sigset_t *mask) {return syscall(PSELECT_NOCANCEL,(long)nd,(long)in,(long)ou,(long)ex,(long)ts,(long)mask);}
    inline user_ssize_t read_nocancel(int fd,user_addr_t cbuf,user_size_t nbyte) {return syscall(READ_NOCANCEL,(long)fd,(long)cbuf,(long)nbyte);}
    inline user_ssize_t write_nocancel(int fd,user_addr_t cbuf,user_size_t nbyte) {return syscall(WRITE_NOCANCEL,(long)fd,(long)cbuf,(long)nbyte);}
    inline int open_nocancel(user_addr_t path,int flags,int mode) {return syscall(OPEN_NOCANCEL,(long)path,(long)flags,(long)mode);}
    inline int sys_close_nocancel(int fd) {return syscall(SYS_CLOSE_NOCANCEL,(long)fd);}
    inline int wait4_nocancel(int pid,user_addr_t status,int options,user_addr_t rusage) {return syscall(WAIT4_NOCANCEL,(long)pid,(long)status,(long)options,(long)rusage);}
    inline int recvmsg_nocancel(int s, msghdr *msg,int flags) {return syscall(RECVMSG_NOCANCEL,(long)s,(long)msg,(long)flags);}
    inline int sendmsg_nocancel(int s,caddr_t msg,int flags) {return syscall(SENDMSG_NOCANCEL,(long)s,(long)msg,(long)flags);}
    inline int recvfrom_nocancel(int s,void *buf,size_t len,int flags, sockaddr *from,int *fromlenaddr) {return syscall(RECVFROM_NOCANCEL,(long)s,(long)buf,(long)len,(long)flags,(long)from,(long)fromlenaddr);}
    inline int accept_nocancel(int s,caddr_t name,socklen_t *anamelen) {return syscall(ACCEPT_NOCANCEL,(long)s,(long)name,(long)anamelen);}
    inline int msync_nocancel(caddr_ut addr,size_ut len,int flags) {return syscall(MSYNC_NOCANCEL,(long)addr,(long)len,(long)flags);}
    inline int sys_fcntl_nocancel(int fd,int cmd,long arg) {return syscall(SYS_FCNTL_NOCANCEL,(long)fd,(long)cmd,(long)arg);}
    inline int select_nocancel(int nd,u_int32_t *in,u_int32_t *ou,u_int32_t *ex, timeval *tv) {return syscall(SELECT_NOCANCEL,(long)nd,(long)in,(long)ou,(long)ex,(long)tv);}
    inline int fsync_nocancel(int fd) {return syscall(FSYNC_NOCANCEL,(long)fd);}
    inline int connect_nocancel(int s,caddr_t name,socklen_t namelen) {return syscall(CONNECT_NOCANCEL,(long)s,(long)name,(long)namelen);}
    inline int sigsuspend_nocancel(sigset_t mask) {return syscall(SIGSUSPEND_NOCANCEL,(long)mask);}
    inline user_ssize_t readv_nocancel(int fd, iovec *iovp,u_int iovcnt) {return syscall(READV_NOCANCEL,(long)fd,(long)iovp,(long)iovcnt);}
    inline user_ssize_t writev_nocancel(int fd, iovec *iovp,u_int iovcnt) {return syscall(WRITEV_NOCANCEL,(long)fd,(long)iovp,(long)iovcnt);}
    inline int sendto_nocancel(int s,caddr_t buf,size_t len,int flags,caddr_t to,socklen_t tolen) {return syscall(SENDTO_NOCANCEL,(long)s,(long)buf,(long)len,(long)flags,(long)to,(long)tolen);}
    inline user_ssize_t pread_nocancel(int fd,user_addr_t buf,user_size_t nbyte,off_t offset) {return syscall(PREAD_NOCANCEL,(long)fd,(long)buf,(long)nbyte,(long)offset);}
    inline user_ssize_t pwrite_nocancel(int fd,user_addr_t buf,user_size_t nbyte,off_t offset) {return syscall(PWRITE_NOCANCEL,(long)fd,(long)buf,(long)nbyte,(long)offset);}
    inline int waitid_nocancel(idtype_t idtype,id_t id,siginfo_t *infop,int options) {return syscall(WAITID_NOCANCEL,(long)idtype,(long)id,(long)infop,(long)options);}
    inline int poll_nocancel( pollfd *fds,u_int nfds,int timeout) {return syscall(POLL_NOCANCEL,(long)fds,(long)nfds,(long)timeout);}
    inline int msgsnd_nocancel(int msqid,void *msgp,size_t msgsz,int msgflg) {return syscall(MSGSND_NOCANCEL,(long)msqid,(long)msgp,(long)msgsz,(long)msgflg);}
    inline user_ssize_t msgrcv_nocancel(int msqid,void *msgp,size_t msgsz,long msgtyp,int msgflg) {return syscall(MSGRCV_NOCANCEL,(long)msqid,(long)msgp,(long)msgsz,(long)msgtyp,(long)msgflg);}
    inline int sem_wait_nocancel(sem_t *sem) {return syscall(SEM_WAIT_NOCANCEL,(long)sem);}
    inline int aio_suspend_nocancel(user_addr_t aiocblist,int nent,user_addr_t timeoutp) {return syscall(AIO_SUSPEND_NOCANCEL,(long)aiocblist,(long)nent,(long)timeoutp);}
    inline int __sigwait_nocancel(user_addr_t set,user_addr_t sig) {return syscall(__SIGWAIT_NOCANCEL,(long)set,(long)sig);}
    inline int __semwait_signal_nocancel(int cond_sem,int mutex_sem,int timeout,int relative,int64_t tv_sec,int32_t tv_nsec) {return syscall(__SEMWAIT_SIGNAL_NOCANCEL,(long)cond_sem,(long)mutex_sem,(long)timeout,(long)relative,(long)tv_sec,(long)tv_nsec);}
    inline int __mac_mount(char *type,char *path,int flags,caddr_t data, Mac *mac_p) {return syscall(__MAC_MOUNT,(long)type,(long)path,(long)flags,(long)data,(long)mac_p);}
    inline int __mac_get_mount(char *path, Mac *mac_p) {return syscall(__MAC_GET_MOUNT,(long)path,(long)mac_p);}
    inline int __mac_getfsstat(user_addr_t buf,int bufsize,user_addr_t mac,int macsize,int flags) {return syscall(__MAC_GETFSSTAT,(long)buf,(long)bufsize,(long)mac,(long)macsize,(long)flags);}
    inline user_ssize_t fsgetpath(user_addr_t buf,size_t bufsize,user_addr_t fsid,uint64_t objid) {return syscall(FSGETPATH,(long)buf,(long)bufsize,(long)fsid,(long)objid);}
    inline mach_port_name_t audit_session_self(void) {return syscall(AUDIT_SESSION_SELF);}
    inline int audit_session_join(mach_port_name_t port) {return syscall(AUDIT_SESSION_JOIN,(long)port);}
    inline int sys_fileport_makeport(int fd,user_addr_t portnamep) {return syscall(SYS_FILEPORT_MAKEPORT,(long)fd,(long)portnamep);}
    inline int sys_fileport_makefd(mach_port_name_t port) {return syscall(SYS_FILEPORT_MAKEFD,(long)port);}
    inline int audit_session_port(au_asid_t asid,user_addr_t portnamep) {return syscall(AUDIT_SESSION_PORT,(long)asid,(long)portnamep);}
    inline int pid_suspend(int pid) {return syscall(PID_SUSPEND,(long)pid);}
    inline int pid_resume(int pid) {return syscall(PID_RESUME,(long)pid);}
    inline int pid_hibernate(int pid) {return syscall(PID_HIBERNATE,(long)pid);}
    inline int pid_shutdown_sockets(int pid,int level) {return syscall(PID_SHUTDOWN_SOCKETS,(long)pid,(long)level);}
    inline int kas_info(int selector,void *value,size_t *size) {return syscall(KAS_INFO,(long)selector,(long)value,(long)size);}
    inline int memorystatus_control(uint32_t command,int32_t pid,uint32_t flags,user_addr_t buffer,size_t buffersize) {return syscall(MEMORYSTATUS_CONTROL,(long)command,(long)pid,(long)flags,(long)buffer,(long)buffersize);}
    inline int guarded_open_np(user_addr_t path,const guardid_t *guard,u_int guardflags,int flags,int mode) {return syscall(GUARDED_OPEN_NP,(long)path,(long)guard,(long)guardflags,(long)flags,(long)mode);}
    inline int guarded_close_np(int fd,const guardid_t *guard) {return syscall(GUARDED_CLOSE_NP,(long)fd,(long)guard);}
    inline int guarded_kqueue_np(const guardid_t *guard,u_int guardflags) {return syscall(GUARDED_KQUEUE_NP,(long)guard,(long)guardflags);}
    inline int change_fdguard_np(int fd,const guardid_t *guard,u_int guardflags,const guardid_t *nguard,u_int nguardflags,int *fdflagsp) {return syscall(CHANGE_FDGUARD_NP,(long)fd,(long)guard,(long)guardflags,(long)nguard,(long)nguardflags,(long)fdflagsp);}
    inline int usrctl(uint32_t flags) {return syscall(USRCTL,(long)flags);}
    inline int proc_rlimit_control(pid_t pid,int flavor,void *arg) {return syscall(PROC_RLIMIT_CONTROL,(long)pid,(long)flavor,(long)arg);}
    inline int connectx(int socket,const sa_endpoints_t *endpoints,sae_associd_t associd,unsigned int flags,const  iovec *iov,unsigned int iovcnt,size_t *len,sae_connid_t *connid) {return syscall(CONNECTX,(long)socket,(long)endpoints,(long)associd,(long)flags,(long)iov,(long)iovcnt,(long)len,(long)connid);}
    inline int disconnectx(int s,sae_associd_t aid,sae_connid_t cid) {return syscall(DISCONNECTX,(long)s,(long)aid,(long)cid);}
    inline int peeloff(int s,sae_associd_t aid) {return syscall(PEELOFF,(long)s,(long)aid);}
    inline int socket_delegate(int domain,int type,int protocol,pid_t epid) {return syscall(SOCKET_DELEGATE,(long)domain,(long)type,(long)protocol,(long)epid);}
    inline int telemetry(uint64_t cmd,uint64_t deadline,uint64_t interval,uint64_t leeway,uint64_t arg4,uint64_t arg5) {return syscall(TELEMETRY,(long)cmd,(long)deadline,(long)interval,(long)leeway,(long)arg4,(long)arg5);}
    inline int proc_uuid_policy(uint32_t operation,uuid_t uuid,size_t uuidlen,uint32_t flags) {return syscall(PROC_UUID_POLICY,(long)operation,(long)uuid,(long)uuidlen,(long)flags);}
    inline int memorystatus_get_level(user_addr_t level) {return syscall(MEMORYSTATUS_GET_LEVEL,(long)level);}
    inline int system_override(uint64_t timeout,uint64_t flags) {return syscall(SYSTEM_OVERRIDE,(long)timeout,(long)flags);}
    inline int vfs_purge(void) {return syscall(VFS_PURGE);}
    inline int sfi_ctl(uint32_t operation,uint32_t sfi_class,uint64_t time,uint64_t *out_time) {return syscall(SFI_CTL,(long)operation,(long)sfi_class,(long)time,(long)out_time);}
    inline int sfi_pidctl(uint32_t operation,pid_t pid,uint32_t sfi_flags,uint32_t *out_sfi_flags) {return syscall(SFI_PIDCTL,(long)operation,(long)pid,(long)sfi_flags,(long)out_sfi_flags);}
    inline int coalition(uint32_t operation,uint64_t *cid,uint32_t flags) {return syscall(COALITION,(long)operation,(long)cid,(long)flags);}
    inline int coalition_info(uint32_t flavor,uint64_t *cid,void *buffer,size_t *bufsize) {return syscall(COALITION_INFO,(long)flavor,(long)cid,(long)buffer,(long)bufsize);}
    inline int necp_match_policy(uint8_t *parameters,size_t parameters_size, necp_aggregate_result *returned_result) {return syscall(NECP_MATCH_POLICY,(long)parameters,(long)parameters_size,(long)returned_result);}
    inline int getattrlistbulk(int dirfd, attrlist *alist,void *attributeBuffer,size_t bufferSize,uint64_t options) {return syscall(GETATTRLISTBULK,(long)dirfd,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int clonefileat(int src_dirfd,user_addr_t src,int dst_dirfd,user_addr_t dst,uint32_t flags) {return syscall(CLONEFILEAT,(long)src_dirfd,(long)src,(long)dst_dirfd,(long)dst,(long)flags);}
    inline int openat(int fd,user_addr_t path,int flags,int mode) {return syscall(OPENAT,(long)fd,(long)path,(long)flags,(long)mode);}
    inline int openat_nocancel(int fd,user_addr_t path,int flags,int mode) {return syscall(OPENAT_NOCANCEL,(long)fd,(long)path,(long)flags,(long)mode);}
    inline int renameat(int fromfd,char *from,int tofd,char *to) {return syscall(RENAMEAT,(long)fromfd,(long)from,(long)tofd,(long)to);}
    inline int faccessat(int fd,user_addr_t path,int amode,int flag) {return syscall(FACCESSAT,(long)fd,(long)path,(long)amode,(long)flag);}
    inline int fchmodat(int fd,user_addr_t path,int mode,int flag) {return syscall(FCHMODAT,(long)fd,(long)path,(long)mode,(long)flag);}
    inline int fchownat(int fd,user_addr_t path,uid_t uid,gid_t gid,int flag) {return syscall(FCHOWNAT,(long)fd,(long)path,(long)uid,(long)gid,(long)flag);}
    inline int fstatat(int fd,user_addr_t path,user_addr_t ub,int flag) {return syscall(FSTATAT,(long)fd,(long)path,(long)ub,(long)flag);}
    inline int fstatat64(int fd,user_addr_t path,user_addr_t ub,int flag) {return syscall(FSTATAT64,(long)fd,(long)path,(long)ub,(long)flag);}
    inline int linkat(int fd1,user_addr_t path,int fd2,user_addr_t link,int flag) {return syscall(LINKAT,(long)fd1,(long)path,(long)fd2,(long)link,(long)flag);}
    inline int unlinkat(int fd,user_addr_t path,int flag) {return syscall(UNLINKAT,(long)fd,(long)path,(long)flag);}
    inline int readlinkat(int fd,user_addr_t path,user_addr_t buf,size_t bufsize) {return syscall(READLINKAT,(long)fd,(long)path,(long)buf,(long)bufsize);}
    inline int symlinkat(user_addr_t *path1,int fd,user_addr_t path2) {return syscall(SYMLINKAT,(long)path1,(long)fd,(long)path2);}
    inline int mkdirat(int fd,user_addr_t path,int mode) {return syscall(MKDIRAT,(long)fd,(long)path,(long)mode);}
    inline int getattrlistat(int fd,const char *path, attrlist *alist,void *attributeBuffer,size_t bufferSize,u_long options) {return syscall(GETATTRLISTAT,(long)fd,(long)path,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int proc_trace_log(pid_t pid,uint64_t uniqueid) {return syscall(PROC_TRACE_LOG,(long)pid,(long)uniqueid);}
    inline int bsdthread_ctl(user_addr_t cmd,user_addr_t arg1,user_addr_t arg2,user_addr_t arg3) {return syscall(BSDTHREAD_CTL,(long)cmd,(long)arg1,(long)arg2,(long)arg3);}
    inline int openbyid_np(user_addr_t fsid,user_addr_t objid,int oflags) {return syscall(OPENBYID_NP,(long)fsid,(long)objid,(long)oflags);}
    inline user_ssize_t recvmsg_x(int s, msghdr_x *msgp,u_int cnt,int flags) {return syscall(RECVMSG_X,(long)s,(long)msgp,(long)cnt,(long)flags);}
    inline user_ssize_t sendmsg_x(int s, msghdr_x *msgp,u_int cnt,int flags) {return syscall(SENDMSG_X,(long)s,(long)msgp,(long)cnt,(long)flags);}
    inline uint64_t thread_selfusage(void) {return syscall(THREAD_SELFUSAGE);}
    inline int csrctl(uint32_t op,user_addr_t useraddr,user_addr_t usersize) {return syscall(CSRCTL,(long)op,(long)useraddr,(long)usersize);}
    inline int guarded_open_dprotected_np(user_addr_t path,const guardid_t *guard,u_int guardflags,int flags,int dpclass,int dpflags,int mode) {return syscall(GUARDED_OPEN_DPROTECTED_NP,(long)path,(long)guard,(long)guardflags,(long)flags,(long)dpclass,(long)dpflags,(long)mode);}
    inline user_ssize_t guarded_write_np(int fd,const guardid_t *guard,user_addr_t cbuf,user_size_t nbyte) {return syscall(GUARDED_WRITE_NP,(long)fd,(long)guard,(long)cbuf,(long)nbyte);}
    inline user_ssize_t guarded_pwrite_np(int fd,const guardid_t *guard,user_addr_t buf,user_size_t nbyte,off_t offset) {return syscall(GUARDED_PWRITE_NP,(long)fd,(long)guard,(long)buf,(long)nbyte,(long)offset);}
    inline user_ssize_t guarded_writev_np(int fd,const guardid_t *guard, iovec *iovp,int iovcnt) {return syscall(GUARDED_WRITEV_NP,(long)fd,(long)guard,(long)iovp,(long)iovcnt);}
    inline int renameatx_np(int fromfd,char *from,int tofd,char *to,u_int flags) {return syscall(RENAMEATX_NP,(long)fromfd,(long)from,(long)tofd,(long)to,(long)flags);}
    inline int mremap_encrypted(caddr_ut addr,size_ut len,uint32_t cryptid,uint32_t cputype,uint32_t cpusubtype) {return syscall(MREMAP_ENCRYPTED,(long)addr,(long)len,(long)cryptid,(long)cputype,(long)cpusubtype);}
    inline int netagent_trigger(uuid_t agent_uuid,size_t agent_uuidlen) {return syscall(NETAGENT_TRIGGER,(long)agent_uuid,(long)agent_uuidlen);}
    inline int stack_snapshot_with_config(int stackshot_config_version,user_addr_t stackshot_config,size_t stackshot_config_size) {return syscall(STACK_SNAPSHOT_WITH_CONFIG,(long)stackshot_config_version,(long)stackshot_config,(long)stackshot_config_size);}
    inline int microstackshot(user_addr_t tracebuf,uint32_t tracebuf_size,uint32_t flags) {return syscall(MICROSTACKSHOT,(long)tracebuf,(long)tracebuf_size,(long)flags);}
    inline user_ssize_t grab_pgo_data(user_addr_t uuid,int flags,user_addr_t buffer,user_ssize_t size) {return syscall(GRAB_PGO_DATA,(long)uuid,(long)flags,(long)buffer,(long)size);}
    inline int persona(uint32_t operation,uint32_t flags, kpersona_info *info,uid_t *id,size_t *idlen,char *path) {return syscall(PERSONA,(long)operation,(long)flags,(long)info,(long)id,(long)idlen,(long)path);}
    inline uint64_t mach_eventlink_signal(mach_port_name_t eventlink_port,uint64_t signal_count) {return syscall(MACH_EVENTLINK_SIGNAL,(long)eventlink_port,(long)signal_count);}
    inline uint64_t mach_eventlink_wait_until(mach_port_name_t eventlink_port,uint64_t wait_count,uint64_t deadline,uint32_t clock_id,uint32_t option) {return syscall(MACH_EVENTLINK_WAIT_UNTIL,(long)eventlink_port,(long)wait_count,(long)deadline,(long)clock_id,(long)option);}
    inline uint64_t mach_eventlink_signal_wait_until(mach_port_name_t eventlink_port,uint64_t wait_count,uint64_t signal_count,uint64_t deadline,uint32_t clock_id,uint32_t option) {return syscall(MACH_EVENTLINK_SIGNAL_WAIT_UNTIL,(long)eventlink_port,(long)wait_count,(long)signal_count,(long)deadline,(long)clock_id,(long)option);}
    inline int work_interval_ctl(uint32_t operation,uint64_t work_interval_id,void *arg,size_t len) {return syscall(WORK_INTERVAL_CTL,(long)operation,(long)work_interval_id,(long)arg,(long)len);}
    inline int getentropy(void *buffer,size_t size) {return syscall(GETENTROPY,(long)buffer,(long)size);}
    inline int necp_open(int flags) {return syscall(NECP_OPEN,(long)flags);}
    inline int necp_client_action(int necp_fd,uint32_t action,uuid_t client_id,size_t client_id_len,uint8_t *buffer,size_t buffer_size) {return syscall(NECP_CLIENT_ACTION,(long)necp_fd,(long)action,(long)client_id,(long)client_id_len,(long)buffer,(long)buffer_size);}
    inline int __nexus_open( nxctl_init *init,uint32_t init_len) {return syscall(__NEXUS_OPEN,(long)init,(long)init_len);}
    inline int __nexus_register(int ctl, nxprov_reg *reg,uint32_t reg_len,uuid_t *prov_uuid,uint32_t prov_uuid_len) {return syscall(__NEXUS_REGISTER,(long)ctl,(long)reg,(long)reg_len,(long)prov_uuid,(long)prov_uuid_len);}
    inline int __nexus_deregister(int ctl,uuid_t prov_uuid,uint32_t prov_uuid_len) {return syscall(__NEXUS_DEREGISTER,(long)ctl,(long)prov_uuid,(long)prov_uuid_len);}
    inline int __nexus_create(int ctl,uuid_t prov_uuid,uint32_t prov_uuid_len,uuid_t *nx_uuid,uint32_t nx_uuid_len) {return syscall(__NEXUS_CREATE,(long)ctl,(long)prov_uuid,(long)prov_uuid_len,(long)nx_uuid,(long)nx_uuid_len);}
    inline int __nexus_destroy(int ctl,uuid_t nx_uuid,uint32_t nx_uuid_len) {return syscall(__NEXUS_DESTROY,(long)ctl,(long)nx_uuid,(long)nx_uuid_len);}
    inline int __nexus_get_opt(int ctl,uint32_t opt,void *aoptval,uint32_t *aoptlen) {return syscall(__NEXUS_GET_OPT,(long)ctl,(long)opt,(long)aoptval,(long)aoptlen);}
    inline int __nexus_set_opt(int ctl,uint32_t opt,const void *aoptval,uint32_t optlen) {return syscall(__NEXUS_SET_OPT,(long)ctl,(long)opt,(long)aoptval,(long)optlen);}
    inline int __channel_open( ch_init *init,uint32_t init_len) {return syscall(__CHANNEL_OPEN,(long)init,(long)init_len);}
    inline int __channel_get_info(int c, ch_info *cinfo,uint32_t cinfolen) {return syscall(__CHANNEL_GET_INFO,(long)c,(long)cinfo,(long)cinfolen);}
    inline int __channel_sync(int c,int mode,int flags) {return syscall(__CHANNEL_SYNC,(long)c,(long)mode,(long)flags);}
    inline int __channel_get_opt(int c,uint32_t opt,void *aoptval,uint32_t *aoptlen) {return syscall(__CHANNEL_GET_OPT,(long)c,(long)opt,(long)aoptval,(long)aoptlen);}
    inline int __channel_set_opt(int c,uint32_t opt,const void *aoptval,uint32_t optlen) {return syscall(__CHANNEL_SET_OPT,(long)c,(long)opt,(long)aoptval,(long)optlen);}
    inline int sys_ulock_wait(uint32_t operation,void *addr,uint64_t value,uint32_t timeout) {return syscall(SYS_ULOCK_WAIT,(long)operation,(long)addr,(long)value,(long)timeout);}
    inline int sys_ulock_wake(uint32_t operation,void *addr,uint64_t wake_value) {return syscall(SYS_ULOCK_WAKE,(long)operation,(long)addr,(long)wake_value);}
    inline int fclonefileat(int src_fd,int dst_dirfd,user_addr_t dst,uint32_t flags) {return syscall(FCLONEFILEAT,(long)src_fd,(long)dst_dirfd,(long)dst,(long)flags);}
    inline int fs_snapshot(uint32_t op,int dirfd,user_addr_t name1,user_addr_t name2,user_addr_t data,uint32_t flags) {return syscall(FS_SNAPSHOT,(long)op,(long)dirfd,(long)name1,(long)name2,(long)data,(long)flags);}
    inline int terminate_with_payload(int pid,uint32_t reason_namespace,uint64_t reason_code,void *payload,uint32_t payload_size,const char *reason_string,uint64_t reason_flags) {return syscall(TERMINATE_WITH_PAYLOAD,(long)pid,(long)reason_namespace,(long)reason_code,(long)payload,(long)payload_size,(long)reason_string,(long)reason_flags);}
    inline void abort_with_payload(uint32_t reason_namespace,uint64_t reason_code,void *payload,uint32_t payload_size,const char *reason_string,uint64_t reason_flags) {syscall(ABORT_WITH_PAYLOAD,(long)reason_namespace,(long)reason_code,(long)payload,(long)payload_size,(long)reason_string,(long)reason_flags);}
    inline int necp_session_open(int flags) {return syscall(NECP_SESSION_OPEN,(long)flags);}
    inline int necp_session_action(int necp_fd,uint32_t action,uint8_t *in_buffer,size_t in_buffer_length,uint8_t *out_buffer,size_t out_buffer_length) {return syscall(NECP_SESSION_ACTION,(long)necp_fd,(long)action,(long)in_buffer,(long)in_buffer_length,(long)out_buffer,(long)out_buffer_length);}
    inline int setattrlistat(int fd,const char *path, attrlist *alist,void *attributeBuffer,size_t bufferSize,uint32_t options) {return syscall(SETATTRLISTAT,(long)fd,(long)path,(long)alist,(long)attributeBuffer,(long)bufferSize,(long)options);}
    inline int net_qos_guideline( net_qos_param *param,uint32_t param_len) {return syscall(NET_QOS_GUIDELINE,(long)param,(long)param_len);}
    inline int fmount(const char *type,int fd,int flags,void *data) {return syscall(FMOUNT,(long)type,(long)fd,(long)flags,(long)data);}
    inline int ntp_adjtime( timex *tp) {return syscall(NTP_ADJTIME,(long)tp);}
    inline int ntp_gettime( ntptimeval *ntvp) {return syscall(NTP_GETTIME,(long)ntvp);}
    inline int os_fault_with_payload(uint32_t reason_namespace,uint64_t reason_code,void *payload,uint32_t payload_size,const char *reason_string,uint64_t reason_flags) {return syscall(OS_FAULT_WITH_PAYLOAD,(long)reason_namespace,(long)reason_code,(long)payload,(long)payload_size,(long)reason_string,(long)reason_flags);}
    inline int kqueue_workloop_ctl(user_addr_t cmd,uint64_t options,user_addr_t addr,size_t sz) {return syscall(KQUEUE_WORKLOOP_CTL,(long)cmd,(long)options,(long)addr,(long)sz);}
    inline uint64_t __mach_bridge_remote_time(uint64_t local_timestamp) {return syscall(__MACH_BRIDGE_REMOTE_TIME,(long)local_timestamp);}
    inline int coalition_ledger(uint32_t operation,uint64_t *cid,void *buffer,size_t *bufsize) {return syscall(COALITION_LEDGER,(long)operation,(long)cid,(long)buffer,(long)bufsize);}
    inline int log_data(unsigned int tag,unsigned int flags,void *buffer,unsigned int size) {return syscall(LOG_DATA,(long)tag,(long)flags,(long)buffer,(long)size);}
    inline uint64_t memorystatus_available_memory(void) {return syscall(MEMORYSTATUS_AVAILABLE_MEMORY);}
    inline int objc_bp_assist_cfg_np(uint64_t adr,uint64_t ctl) {return syscall(OBJC_BP_ASSIST_CFG_NP,(long)adr,(long)ctl);}
    inline int shared_region_map_and_slide_2_np(uint32_t files_count,const  shared_file_np *files,uint32_t mappings_count,const shared_file_mapping_slide_np_ut *mappings_u) {return syscall(SHARED_REGION_MAP_AND_SLIDE_2_NP,(long)files_count,(long)files,(long)mappings_count,(long)mappings_u);}
    inline int pivot_root(const char *new_rootfs_path_before,const char *old_rootfs_path_after) {return syscall(PIVOT_ROOT,(long)new_rootfs_path_before,(long)old_rootfs_path_after);}
    inline int task_inspect_for_pid(mach_port_name_t target_tport,int pid,mach_port_name_t *t) {return syscall(TASK_INSPECT_FOR_PID,(long)target_tport,(long)pid,(long)t);}
    inline int task_read_for_pid(mach_port_name_t target_tport,int pid,mach_port_name_t *t) {return syscall(TASK_READ_FOR_PID,(long)target_tport,(long)pid,(long)t);}
    inline user_ssize_t sys_preadv(int fd, iovec *iovp,int iovcnt,off_t offset) {return syscall(SYS_PREADV,(long)fd,(long)iovp,(long)iovcnt,(long)offset);}
    inline user_ssize_t sys_pwritev(int fd, iovec *iovp,int iovcnt,off_t offset) {return syscall(SYS_PWRITEV,(long)fd,(long)iovp,(long)iovcnt,(long)offset);}
    inline user_ssize_t sys_preadv_nocancel(int fd, iovec *iovp,int iovcnt,off_t offset) {return syscall(SYS_PREADV_NOCANCEL,(long)fd,(long)iovp,(long)iovcnt,(long)offset);}
    inline user_ssize_t sys_pwritev_nocancel(int fd, iovec *iovp,int iovcnt,off_t offset) {return syscall(SYS_PWRITEV_NOCANCEL,(long)fd,(long)iovp,(long)iovcnt,(long)offset);}
    inline int sys_ulock_wait2(uint32_t operation,void *addr,uint64_t value,uint64_t timeout,uint64_t value2) {return syscall(SYS_ULOCK_WAIT2,(long)operation,(long)addr,(long)value,(long)timeout,(long)value2);}
    inline int proc_info_extended_id(int32_t callnum,int32_t pid,uint32_t flavor,uint32_t flags,uint64_t ext_id,uint64_t arg,user_addr_t buffer,int32_t buffersize) {return syscall(PROC_INFO_EXTENDED_ID,(long)callnum,(long)pid,(long)flavor,(long)flags,(long)ext_id,(long)arg,(long)buffer,(long)buffersize);}
    inline int tracker_action(int action,char *buffer,size_t buffer_size) {return syscall(TRACKER_ACTION,(long)action,(long)buffer,(long)buffer_size);}
    inline int debug_syscall_reject(uint64_t packed_selectors) {return syscall(DEBUG_SYSCALL_REJECT,(long)packed_selectors);}
    inline int sys_debug_syscall_reject_config(uint64_t packed_selectors1,uint64_t packed_selectors2,uint64_t flags) {return syscall(SYS_DEBUG_SYSCALL_REJECT_CONFIG,(long)packed_selectors1,(long)packed_selectors2,(long)flags);}
    inline int graftdmg(int dmg_fd,const char *mountdir,uint32_t graft_type,graftdmg_args_un *gda) {return syscall(GRAFTDMG,(long)dmg_fd,(long)mountdir,(long)graft_type,(long)gda);}
    inline int map_with_linking_np(void *regions,uint32_t region_count,void *link_info,uint32_t link_info_size) {return syscall(MAP_WITH_LINKING_NP,(long)regions,(long)region_count,(long)link_info,(long)link_info_size);}
    inline int freadlink(int fd,user_addr_t buf,user_size_t bufsize) {return syscall(FREADLINK,(long)fd,(long)buf,(long)bufsize);}
    inline int sys_record_system_event(uint32_t type,uint32_t subsystem,const char *event,const char *payload) {return syscall(SYS_RECORD_SYSTEM_EVENT,(long)type,(long)subsystem,(long)event,(long)payload);}
    inline int mkfifoat(int fd,user_addr_t path,int mode) {return syscall(MKFIFOAT,(long)fd,(long)path,(long)mode);}
    inline int mknodat(int fd,user_addr_t path,int mode,int dev) {return syscall(MKNODAT,(long)fd,(long)path,(long)mode,(long)dev);}
    inline int ungraftdmg(const char *mountdir,uint64_t flags) {return syscall(UNGRAFTDMG,(long)mountdir,(long)flags);}
    inline int sys_coalition_policy_set(uint64_t cid,uint32_t flavor,uint32_t value) {return syscall(SYS_COALITION_POLICY_SET,(long)cid,(long)flavor,(long)value);}
    inline int sys_coalition_policy_get(uint64_t cid,uint32_t flavor) {return syscall(SYS_COALITION_POLICY_GET,(long)cid,(long)flavor);}
}