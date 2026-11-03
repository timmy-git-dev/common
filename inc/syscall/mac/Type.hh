#pragma once

union graft_args;
using graftdmg_args_un = graft_args;
struct shared_file_np;
struct ntptimeval;
struct net_qos_param;
struct ch_info;
struct ch_init;
struct kpersona_info;
struct msghdr_x;
using __uint8_t = unsigned char;
using uint8_t = __uint8_t;
using mach_port_name_t = int;
struct Mac;
struct kevent_qos_s;
struct necp_aggregate_result;
struct kevent64_s;
struct kevent;
struct auditinfo_addr;
using __id_t = unsigned int;
using id_t = __id_t;
struct timeval;
using __caddr_t = char *;
using caddr_t = __caddr_t;
using __u_long = unsigned long;
using u_long = __u_long;
struct rusage;
struct msqid_ds;
using __u_int = unsigned int;
using u_int = __u_int;
struct itimerval;
struct sigaction;
struct fhandle;
struct _posix_spawn_args_desc;
using __pid_t = int;
using pid_t = __pid_t;
using au_asid_t = pid_t;
using __uint32_t = unsigned int;
using u_int32_t = __uint32_t;
struct attrlist;
using size_t = int;
struct sembuf;
struct __sigaction;
struct shmid_ds;
using __uint64_t = unsigned long;
using uint64_t = __uint64_t;
struct msghdr;
struct searchstate;
using uint32_t = __uint32_t;
using __gid_t = unsigned int;
using gid_t = __gid_t;
struct iovec;
using caddr_ut = caddr_t;
struct sigaltstack;
using __uid_t = unsigned int;
using uid_t = __uid_t;
using size_ut = __typeof__(sizeof(int));
using __socklen_t = unsigned int;
using socklen_t = __socklen_t;
struct ucontext;
struct siginfo_t;
enum idtype_t { };
struct sockaddr;
struct statfs64;
struct nxprov_reg;
struct nxctl_init;
using __off_t = long;
using off_t = __off_t;
using au_id_t = uid_t;
struct statfs;
struct timex;
using fhandle_t = fhandle;
using uuid_t = unsigned char[16];
using __key_t = int;
using key_t = __key_t;
struct rlimit;
struct pollfd;
using sem_t = int;
using __darwin_sigset_t = __uint32_t;
using sigset_t = __darwin_sigset_t;
using __int64_t = long;
using int64_t = __int64_t;
using __int32_t = int;
using __uint16_t = unsigned short;
using int32_t = __int32_t;
struct shared_file_mapping_slide_np_t;
using shared_file_mapping_slide_np_ut = shared_file_mapping_slide_np_t;
typedef __uint32_t sae_associd_t;
struct sa_endpoints;
using sa_endpoints_t = sa_endpoints;
using u_int64_t = __uint64_t;
using user_size_t = u_int64_t;
using user_ssize_t = int64_t;
using user_addr_t = u_int64_t;
struct fssearchblock;
struct sigvec;
struct timezone;
struct sf_hdtr;
using sae_connid_t = __uint32_t;
using guardid_t = __uint64_t;
union semun {
    int             val;            /* value for SETVAL */
    struct semid_ds *buf;           /* buffer for IPC_STAT & IPC_SET */
    unsigned short  *array;         /* array for GETALL & SETALL */
};
typedef union semun semun_t;
typedef struct semid_ds *semun_t_buf;

typedef __int64_t     blkcnt_t;      /* total blocks */
typedef __int32_t     blksize_t;     /* preferred block size */
typedef __int32_t     dev_t;         /* dev_t */
typedef unsigned int  fsblkcnt_t;    /* Used by statvfs and fstatvfs */
typedef unsigned int  fsfilcnt_t;    /* Used by statvfs and fstatvfs */
typedef __uint32_t    gid_t;         /* [???] process and group IDs */
typedef __uint32_t    id_t;          /* [XSI] pid_t, uid_t, or gid_t*/
typedef __uint64_t    ino64_t;       /* [???] Used for 64 bit inodes */
typedef ino64_t        ino_t;         /* [???] Used for inodes */
typedef __uint16_t    mode_t;        /* [???] Some file attributes */
typedef __int64_t     off_t;         /* [???] Used for file sizes */
typedef __int32_t     pid_t;         /* [???] process and group IDs */
typedef __uint32_t    sigset_t;      /* [???] signal set */
typedef __int32_t     suseconds_t;   /* [???] microseconds */
typedef __uint32_t    uid_t;         /* [???] user IDs */
typedef __uint32_t    useconds_t;    /* [???] microseconds */
typedef unsigned char uuid_t[16];
typedef char          uuid_string_t[37];

typedef long time_t;
typedef __uint16_t nlink_t;

struct timespec
{
	time_t tv_sec;
	long            tv_nsec;
};

struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is defined */
    dev_t     st_dev;	   /* ID of device containing file */
    mode_t    st_mode;	   /* Mode of file (see below) */
    nlink_t   st_nlink;	   /* Number of hard links */
    ino_t     st_ino;	   /* File serial number */
    uid_t     st_uid;	   /* User ID of the file */
    gid_t     st_gid;	   /* Group ID of the file */
    dev_t     st_rdev;	   /* Device ID */
    timespec  st_atimespec;	   /* time of last access */
    timespec  st_mtimespec;	   /* time of last data modification */
    timespec  st_ctimespec;	   /* time of last status change */
    timespec  st_birthtimespec; /* time of file creation(birth) */
    off_t     st_size;	   /* file size, in bytes */
    blkcnt_t  st_blocks;	   /* blocks allocated for file */
    blksize_t st_blksize;	   /* optimal blocksize for I/O */
    uint32_t  st_flags;	   /* user defined flags for file */
    uint32_t  st_gen;	   /* file generation number */
    int32_t   st_lspare;	   /* RESERVED: DO NOT USE! */
    int64_t   st_qspare[2];	   /* RESERVED: DO NOT USE! */
};