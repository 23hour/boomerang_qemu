[  0] = { 0,	0,		SEN(restart_syscall),		"restart_syscall"	},
[  1] = { 1,	TP|SE,		SEN(exit),			"exit"			},
[  2] = { 0,	TP,		SEN(fork),			"fork"			},
[  3] = { 3,	TD,		SEN(read),			"read"			},
[  4] = { 3,	TD,		SEN(write),			"write"			},
[  5] = { 3,	TD|TF,		SEN(open),			"open"			},
[  6] = { 1,	TD,		SEN(close),			"close"			},
[  7] = { 4,	TP,		SEN(wait4),			"wait4"			},
[  8] = { 2,	TD|TF,		SEN(creat),			"creat"			},
[  9] = { 2,	TF,		SEN(link),			"link"			},
[ 10] = { 1,	TF,		SEN(unlink),			"unlink"		},
[ 11] = { 2,	TF|TP|SE|SI,	SEN(execv),			"execv"			},
[ 12] = { 1,	TF,		SEN(chdir),			"chdir"			},
[ 13] = { 3,	TF,		SEN(chown16),			"chown"			},
[ 14] = { 3,	TF,		SEN(mknod),			"mknod"			},
[ 15] = { 2,	TF,		SEN(chmod),			"chmod"			},
[ 16] = { 3,	TF,		SEN(chown16),			"lchown"		},
[ 17] = { 1,	TM|SI,		SEN(brk),			"brk"			},
[ 18] = { 4,	0,		SEN(printargs),			"perfctr"		},
[ 19] = { 3,	TD,		SEN(lseek),			"lseek"			},
[ 20] = { 0,	NF,		SEN(getpid),			"getpid"		},
[ 21] = { 2,	0,		SEN(capget),			"capget"		},
[ 22] = { 2,	0,		SEN(capset),			"capset"		},
[ 23] = { 1,	0,		SEN(setuid16),			"setuid"		},
[ 24] = { 0,	NF,		SEN(getuid16),			"getuid"		},
[ 25] = { 4,	TD,		SEN(vmsplice),			"vmsplice"		},
[ 26] = { 4,	0,		SEN(ptrace),			"ptrace"		},
[ 27] = { 1,	0,		SEN(alarm),			"alarm"			},
[ 28] = { 2,	TS,		SEN(sigaltstack),		"sigaltstack"		},
[ 29] = { 0,	TS,		SEN(pause),			"pause"			},
[ 30] = { 2,	TF,		SEN(utime),			"utime"			},
[ 31] = { 3,	TF,		SEN(chown),			"lchown32"		},
[ 32] = { 3,	TD,		SEN(fchown),			"fchown32"		},
[ 33] = { 2,	TF,		SEN(access),			"access"		},
[ 34] = { 1,	0,		SEN(nice),			"nice"			},
[ 35] = { 3,	TF,		SEN(chown),			"chown32"		},
[ 36] = { 0,	0,		SEN(sync),			"sync"			},
[ 37] = { 2,	TS,		SEN(kill),			"kill"			},
[ 38] = { 2,	TF,		SEN(stat),			"stat"			},
[ 39] = { 4,	TD|TN,		SEN(sendfile),			"sendfile"		},
[ 40] = { 2,	TF,		SEN(lstat),			"lstat"			},
[ 41] = { 1,	TD,		SEN(dup),			"dup"			},
[ 42] = { 0,	TD,		SEN(pipe),			"pipe"			},
[ 43] = { 1,	0,		SEN(times),			"times"			},
[ 44] = { 0,	NF,		SEN(getuid),			"getuid32"		},
[ 45] = { 2,	TF,		SEN(umount2),			"umount2"		},
[ 46] = { 1,	0,		SEN(setgid16),			"setgid"		},
[ 47] = { 0,	NF,		SEN(getgid16),			"getgid"		},
[ 48] = { 2,	TS,		SEN(signal),			"signal"		},
[ 49] = { 0,	NF,		SEN(geteuid16),			"geteuid"		},
[ 50] = { 0,	NF,		SEN(getegid16),			"getegid"		},
[ 51] = { 1,	TF,		SEN(acct),			"acct"			},
[ 52] = { },
[ 53] = { 0,	NF,		SEN(getgid),			"getgid32"		},
[ 54] = { 3,	TD,		SEN(ioctl),			"ioctl"			},
[ 55] = { 4,	0,		SEN(reboot),			"reboot"		},
[ 56] = { 6,	TD|TM|SI,	SEN(mmap_4koff),		"mmap2"			},
[ 57] = { 2,	TF,		SEN(symlink),			"symlink"		},
[ 58] = { 3,	TF,		SEN(readlink),			"readlink"		},
[ 59] = { 3,	TF|TP|SE|SI,	SEN(execve),			"execve"		},
[ 60] = { 1,	NF,		SEN(umask),			"umask"			},
[ 61] = { 1,	TF,		SEN(chroot),			"chroot"		},
[ 62] = { 2,	TD,		SEN(fstat),			"fstat"			},
[ 63] = { 2,	TD,		SEN(fstat64),			"fstat64"		},
[ 64] = { 0,	0,		SEN(getpagesize),		"getpagesize"		},
[ 65] = { 3,	TM,		SEN(msync),			"msync"			},
[ 66] = { 0,	TP,		SEN(vfork),			"vfork"			},
[ 67] = { 5,	TD,		SEN(pread),			"pread64"		},
[ 68] = { 5,	TD,		SEN(pwrite),			"pwrite64"		},
[ 69] = { 0,	NF,		SEN(geteuid),			"geteuid32"		},
[ 70] = { 0,	NF,		SEN(getegid),			"getegid32"		},
[ 71] = { 6,	TD|TM|SI,	SEN(mmap),			"mmap"			},
[ 72] = { 2,	0,		SEN(setreuid),			"setreuid32"		},
[ 73] = { 2,	TM|SI,		SEN(munmap),			"munmap"		},
[ 74] = { 3,	TM|SI,		SEN(mprotect),			"mprotect"		},
[ 75] = { 3,	TM,		SEN(madvise),			"madvise"		},
[ 76] = { 0,	0,		SEN(vhangup),			"vhangup"		},
[ 77] = { 3,	TF,		SEN(truncate64),		"truncate64"		},
[ 78] = { 3,	TM,		SEN(mincore),			"mincore"		},
[ 79] = { 2,	0,		SEN(getgroups16),		"getgroups"		},
[ 80] = { 2,	0,		SEN(setgroups16),		"setgroups"		},
[ 81] = { 0,	0,		SEN(getpgrp),			"getpgrp"		},
[ 82] = { 2,	0,		SEN(setgroups),			"setgroups32"		},
[ 83] = { 3,	0,		SEN(setitimer),			"setitimer"		},
[ 84] = { 3,	TD,		SEN(ftruncate64),		"ftruncate64"		},
[ 85] = { 2,	TF,		SEN(swapon),			"swapon"		},
[ 86] = { 2,	0,		SEN(getitimer),			"getitimer"		},
[ 87] = { 1,	0,		SEN(setuid),			"setuid32"		},
[ 88] = { 2,	0,		SEN(sethostname),		"sethostname"		},
[ 89] = { 1,	0,		SEN(setgid),			"setgid32"		},
[ 90] = { 2,	TD,		SEN(dup2),			"dup2"			},
[ 91] = { 1,	NF,		SEN(setfsuid),			"setfsuid32"		},
[ 92] = { 3,	TD,		SEN(fcntl),			"fcntl"			},
[ 93] = { 5,	TD,		SEN(select),			"select"		},
[ 94] = { 1,	NF,		SEN(setfsgid),			"setfsgid32"		},
[ 95] = { 1,	TD,		SEN(fsync),			"fsync"			},
[ 96] = { 3,	0,		SEN(setpriority),		"setpriority"		},
[ 97] = { 3,	TN,		SEN(socket),			"socket"		},
[ 98] = { 3,	TN,		SEN(connect),			"connect"		},
[ 99] = { 3,	TN,		SEN(accept),			"accept"		},
[100] = { 2,	0,		SEN(getpriority),		"getpriority"		},
[101] = { 0,	TS,		SEN(rt_sigreturn),		"rt_sigreturn"		},
[102] = { 5,	TS,		SEN(rt_sigaction),		"rt_sigaction"		},
[103] = { 4,	TS,		SEN(rt_sigprocmask),		"rt_sigprocmask"	},
[104] = { 2,	TS,		SEN(rt_sigpending),		"rt_sigpending"		},
[105] = { 4,	TS,		SEN(rt_sigtimedwait),		"rt_sigtimedwait"	},
[106] = { 3,	TS,		SEN(rt_sigqueueinfo),		"rt_sigqueueinfo"	},
[107] = { 2,	TS,		SEN(rt_sigsuspend),		"rt_sigsuspend"		},
[108] = { 3,	0,		SEN(setresuid),			"setresuid32"		},
[109] = { 3,	0,		SEN(getresuid),			"getresuid32"		},
[110] = { 3,	0,		SEN(setresgid),			"setresgid32"		},
[111] = { 3,	0,		SEN(getresgid),			"getresgid32"		},
[112] = { 2,	0,		SEN(setregid),			"setregid32"		},
[113] = { 3,	TN,		SEN(recvmsg),			"recvmsg"		},
[114] = { 3,	TN,		SEN(sendmsg),			"sendmsg"		},
[115] = { 2,	0,		SEN(getgroups),			"getgroups32"		},
[116] = { 2,	0,		SEN(gettimeofday),		"gettimeofday"		},
[117] = { 2,	0,		SEN(getrusage),			"getrusage"		},
[118] = { 5,	TN,		SEN(getsockopt),		"getsockopt"		},
[119] = { 2,	TF,		SEN(getcwd),			"getcwd"		},
[120] = { 3,	TD,		SEN(readv),			"readv"			},
[121] = { 3,	TD,		SEN(writev),			"writev"		},
[122] = { 2,	0,		SEN(settimeofday),		"settimeofday"		},
[123] = { 3,	TD,		SEN(fchown16),			"fchown"		},
[124] = { 2,	TD,		SEN(fchmod),			"fchmod"		},
[125] = { 6,	TN,		SEN(recvfrom),			"recvfrom"		},
[126] = { 2,	0,		SEN(setreuid16),		"setreuid"		},
[127] = { 2,	0,		SEN(setregid16),		"setregid"		},
[128] = { 2,	TF,		SEN(rename),			"rename"		},
[129] = { 2,	TF,		SEN(truncate),			"truncate"		},
[130] = { 2,	TD,		SEN(ftruncate),			"ftruncate"		},
[131] = { 2,	TD,		SEN(flock),			"flock"			},
[132] = { 2,	TF,		SEN(lstat64),			"lstat64"		},
[133] = { 6,	TN,		SEN(sendto),			"sendto"		},
[134] = { 2,	TN,		SEN(shutdown),			"shutdown"		},
[135] = { 4,	TN,		SEN(socketpair),		"socketpair"		},
[136] = { 2,	TF,		SEN(mkdir),			"mkdir"			},
[137] = { 1,	TF,		SEN(rmdir),			"rmdir"			},
[138] = { 2,	TF,		SEN(utimes),			"utimes"		},
[139] = { 2,	TF,		SEN(stat64),			"stat64"		},
[140] = { 4,	TD|TN,		SEN(sendfile64),		"sendfile64"		},
[141] = { 3,	TN,		SEN(getpeername),		"getpeername"		},
[142] = { 6,	0,		SEN(futex),			"futex"			},
[143] = { 0,	NF,		SEN(gettid),			"gettid"		},
[144] = { 2,	0,		SEN(getrlimit),			"getrlimit"		},
[145] = { 2,	0,		SEN(setrlimit),			"setrlimit"		},
[146] = { 2,	TF,		SEN(pivotroot),			"pivot_root"		},
[147] = { 5,	0,		SEN(prctl),			"prctl"			},
[148] = { 5,	0,		SEN(printargs),			"pciconfig_read"	},
[149] = { 5,	0,		SEN(printargs),			"pciconfig_write"	},
[150] = { 3,	TN,		SEN(getsockname),		"getsockname"		},
[151] = { 0,	TD,		SEN(inotify_init),		"inotify_init"		},
[152] = { 3,	TD,		SEN(inotify_add_watch),		"inotify_add_watch"	},
[153] = { 3,	TD,		SEN(poll),			"poll"			},
[154] = { 3,	TD,		SEN(getdents64),		"getdents64"		},
[155] = { 3,	TD,		SEN(fcntl64),			"fcntl64"		},
[156] = { 2,	TD,		SEN(inotify_rm_watch),		"inotify_rm_watch"	},
[157] = { 2,	TF,		SEN(statfs),			"statfs"		},
[158] = { 2,	TD,		SEN(fstatfs),			"fstatfs"		},
[159] = { 1,	TF,		SEN(umount),			"umount"		},
[160] = { 3,	0,		SEN(sched_setaffinity),		"sched_set_affinity"	},
[161] = { 3,	0,		SEN(sched_getaffinity),		"sched_get_affinity"	},
[162] = { 2,	0,		SEN(printargs),			"getdomainname"		},
[163] = { 2,	0,		SEN(setdomainname),		"setdomainname"		},
[164] = { },
[165] = { 4,	TF,		SEN(quotactl),			"quotactl"		},
[166] = { 1,	0,		SEN(set_tid_address),		"set_tid_address"	},
[167] = { 5,	TF,		SEN(mount),			"mount"			},
[168] = { 2,	0,		SEN(ustat),			"ustat"			},
[169] = { 5,	TF,		SEN(setxattr),			"setxattr"		},
[170] = { 5,	TF,		SEN(setxattr),			"lsetxattr"		},
[171] = { 5,	TD,		SEN(fsetxattr),			"fsetxattr"		},
[172] = { 4,	TF,		SEN(getxattr),			"getxattr"		},
[173] = { 4,	TF,		SEN(getxattr),			"lgetxattr"		},
[174] = { 3,	TD,		SEN(getdents),			"getdents"		},
[175] = { 0,	0,		SEN(setsid),			"setsid"		},
[176] = { 1,	TD,		SEN(fchdir),			"fchdir"		},
[177] = { 4,	TD,		SEN(fgetxattr),			"fgetxattr"		},
[178] = { 3,	TF,		SEN(listxattr),			"listxattr"		},
[179] = { 3,	TF,		SEN(listxattr),			"llistxattr"		},
[180] = { 3,	TD,		SEN(flistxattr),		"flistxattr"		},
[181] = { 2,	TF,		SEN(removexattr),		"removexattr"		},
[182] = { 2,	TF,		SEN(removexattr),		"lremovexattr"		},
[183] = { 1,	TS,		SEN(sigpending),		"sigpending"		},
[184] = { 5,	0,		SEN(query_module),		"query_module"		},
[185] = { 2,	0,		SEN(setpgid),			"setpgid"		},
[186] = { 2,	TD,		SEN(fremovexattr),		"fremovexattr"		},
[187] = { 2,	TS,		SEN(kill),			"tkill"			},
[188] = { 1,	TP|SE,		SEN(exit),			"exit_group"		},
[189] = { 1,	0,		SEN(uname),			"uname"			},
[190] = { 3,	0,		SEN(init_module),		"init_module"		},
[191] = { 1,	NF,		SEN(personality),		"personality"		},
[192] = { 5,	TM|SI,		SEN(remap_file_pages),		"remap_file_pages"	},
[193] = { 1,	TD,		SEN(epoll_create),		"epoll_create"		},
[194] = { 4,	TD,		SEN(epoll_ctl),			"epoll_ctl"		},
[195] = { 4,	TD,		SEN(epoll_wait),		"epoll_wait"		},
[196] = { 3,	0,		SEN(ioprio_set),		"ioprio_set"		},
[197] = { 0,	NF,		SEN(getppid),			"getppid"		},
[198] = { 3,	TS,		SEN(sigaction),			"sigaction"		},
[199] = { 0,	TS,		SEN(siggetmask),		"sgetmask"		},
[200] = { 1,	TS,		SEN(sigsetmask),		"ssetmask"		},
[201] = { 3,	TS,		SEN(sigsuspend),		"sigsuspend"		},
[202] = { 2,	TF,		SEN(lstat),			"oldlstat"		},
[203] = { 1,	TF,		SEN(uselib),			"uselib"		},
[204] = { 3,	TD,		SEN(readdir),			"readdir"		},
[205] = { 4,	TD,		SEN(readahead),			"readahead"		},
[206] = { 2,	TD,		SEN(socketcall),		"socketcall"		},
[207] = { 3,	0,		SEN(syslog),			"syslog"		},
[208] = { 4,	0,		SEN(lookup_dcookie),		"lookup_dcookie"	},
[209] = { 5,	TD,		SEN(fadvise64),			"fadvise64"		},
[210] = { 6,	TD,		SEN(fadvise64_64),		"fadvise64_64"		},
[211] = { 3,	TS,		SEN(tgkill),			"tgkill"		},
[212] = { 3,	TP,		SEN(waitpid),			"waitpid"		},
[213] = { 1,	TF,		SEN(swapoff),			"swapoff"		},
[214] = { 1,	0,		SEN(sysinfo),			"sysinfo"		},
[215] = { 6,	TI,		SEN(ipc),			"ipc"			},
[216] = { 0,	TS,		SEN(sigreturn),			"sigreturn"		},
[217] = { 5,	TP,		SEN(clone),			"clone"			},
[218] = { 2,	0,		SEN(ioprio_get),		"ioprio_get"		},
[219] = { 1,	0,		SEN(adjtimex),			"adjtimex"		},
[220] = { 3,	TS,		SEN(sigprocmask),		"sigprocmask"		},
[221] = { 2,	0,		SEN(create_module),		"create_module"		},
[222] = { 2,	0,		SEN(delete_module),		"delete_module"		},
[223] = { 1,	0,		SEN(get_kernel_syms),		"get_kernel_syms"	},
[224] = { 1,	0,		SEN(getpgid),			"getpgid"		},
[225] = { 2,	0,		SEN(bdflush),			"bdflush"		},
[226] = { 3,	0,		SEN(sysfs),			"sysfs"			},
[227] = { 5,	0,		SEN(afs_syscall),		"afs_syscall"		},
[228] = { 1,	NF,		SEN(setfsuid16),		"setfsuid"		},
[229] = { 1,	NF,		SEN(setfsgid16),		"setfsgid"		},
[230] = { 5,	TD,		SEN(select),			"_newselect"		},
[231] = { 1,	0,		SEN(time),			"time"			},
[232] = { 6,	TD,		SEN(splice),			"splice"		},
[233] = { 1,	0,		SEN(stime),			"stime"			},
[234] = { 3,	TF,		SEN(statfs64),			"statfs64"		},
[235] = { 3,	TD,		SEN(fstatfs64),			"fstatfs64"		},
[236] = { 5,	TD,		SEN(llseek),			"_llseek"		},
[237] = { 2,	TM,		SEN(mlock),			"mlock"			},
[238] = { 2,	TM,		SEN(munlock),			"munlock"		},
[239] = { 1,	TM,		SEN(mlockall),			"mlockall"		},
[240] = { 0,	TM,		SEN(munlockall),		"munlockall"		},
[241] = { 2,	0,		SEN(sched_setparam),		"sched_setparam"	},
[242] = { 2,	0,		SEN(sched_getparam),		"sched_getparam"	},
[243] = { 3,	0,		SEN(sched_setscheduler),	"sched_setscheduler"	},
[244] = { 1,	0,		SEN(sched_getscheduler),	"sched_getscheduler"	},
[245] = { 0,	0,		SEN(sched_yield),		"sched_yield"		},
[246] = { 1,	0,		SEN(sched_get_priority_max),	"sched_get_priority_max"},
[247] = { 1,	0,		SEN(sched_get_priority_min),	"sched_get_priority_min"},
[248] = { 2,	0,		SEN(sched_rr_get_interval),	"sched_rr_get_interval"	},
[249] = { 2,	0,		SEN(nanosleep),			"nanosleep"		},
[250] = { 5,	TM|SI,		SEN(mremap),			"mremap"		},
[251] = { 1,	0,		SEN(sysctl),			"_sysctl"		},
[252] = { 1,	0,		SEN(getsid),			"getsid"		},
[253] = { 1,	TD,		SEN(fdatasync),			"fdatasync"		},
[254] = { 3,	0,		SEN(nfsservctl),		"nfsservctl"		},
[255] = { 6,	TD,		SEN(sync_file_range),		"sync_file_range"	},
[256] = { 2,	0,		SEN(clock_settime),		"clock_settime"		},
[257] = { 2,	0,		SEN(clock_gettime),		"clock_gettime"		},
[258] = { 2,	0,		SEN(clock_getres),		"clock_getres"		},
[259] = { 4,	0,		SEN(clock_nanosleep),		"clock_nanosleep"	},
[260] = { 3,	0,		SEN(sched_getaffinity),		"sched_getaffinity"	},
[261] = { 3,	0,		SEN(sched_setaffinity),		"sched_setaffinity"	},
[262] = { 4,	0,		SEN(timer_settime),		"timer_settime"		},
[263] = { 2,	0,		SEN(timer_gettime),		"timer_gettime"		},
[264] = { 1,	0,		SEN(timer_getoverrun),		"timer_getoverrun"	},
[265] = { 1,	0,		SEN(timer_delete),		"timer_delete"		},
[266] = { 3,	0,		SEN(timer_create),		"timer_create"		},
[267] = { },
[268] = { 2,	0,		SEN(io_setup),			"io_setup"		},
[269] = { 1,	0,		SEN(io_destroy),		"io_destroy"		},
[270] = { 3,	0,		SEN(io_submit),			"io_submit"		},
[271] = { 3,	0,		SEN(io_cancel),			"io_cancel"		},
[272] = { 5,	0,		SEN(io_getevents),		"io_getevents"		},
[273] = { 4,	0,		SEN(mq_open),			"mq_open"		},
[274] = { 1,	0,		SEN(mq_unlink),			"mq_unlink"		},
[275] = { 5,	0,		SEN(mq_timedsend),		"mq_timedsend"		},
[276] = { 5,	0,		SEN(mq_timedreceive),		"mq_timedreceive"	},
[277] = { 2,	0,		SEN(mq_notify),			"mq_notify"		},
[278] = { 3,	0,		SEN(mq_getsetattr),		"mq_getsetattr"		},
[279] = { 5,	TP,		SEN(waitid),			"waitid"		},
[280] = { 4,	TD,		SEN(tee),			"tee"			},
[281] = { 5,	0,		SEN(add_key),			"add_key"		},
[282] = { 4,	0,		SEN(request_key),		"request_key"		},
[283] = { 5,	0,		SEN(keyctl),			"keyctl"		},
[284] = { 4,	TD|TF,		SEN(openat),			"openat"		},
[285] = { 3,	TD|TF,		SEN(mkdirat),			"mkdirat"		},
[286] = { 4,	TD|TF,		SEN(mknodat),			"mknodat"		},
[287] = { 5,	TD|TF,		SEN(fchownat),			"fchownat"		},
[288] = { 3,	TD|TF,		SEN(futimesat),			"futimesat"		},
[289] = { 4,	TD|TF,		SEN(newfstatat),		"fstatat64"		},
[290] = { 3,	TD|TF,		SEN(unlinkat),			"unlinkat"		},
[291] = { 4,	TD|TF,		SEN(renameat),			"renameat"		},
[292] = { 5,	TD|TF,		SEN(linkat),			"linkat"		},
[293] = { 3,	TD|TF,		SEN(symlinkat),			"symlinkat"		},
[294] = { 4,	TD|TF,		SEN(readlinkat),		"readlinkat"		},
[295] = { 3,	TD|TF,		SEN(fchmodat),			"fchmodat"		},
[296] = { 3,	TD|TF,		SEN(faccessat),			"faccessat"		},
[297] = { 6,	TD,		SEN(pselect6),			"pselect6"		},
[298] = { 5,	TD,		SEN(ppoll),			"ppoll"			},
[299] = { 1,	TP,		SEN(unshare),			"unshare"		},
[300] = { 2,	0,		SEN(set_robust_list),		"set_robust_list"	},
[301] = { 3,	0,		SEN(get_robust_list),		"get_robust_list"	},
[302] = { 4,	TM,		SEN(migrate_pages),		"migrate_pages"		},
[303] = { 6,	TM,		SEN(mbind),			"mbind"			},
[304] = { 5,	TM,		SEN(get_mempolicy),		"get_mempolicy"		},
[305] = { 3,	TM,		SEN(set_mempolicy),		"set_mempolicy"		},
[306] = { 4,	0,		SEN(kexec_load),		"kexec_load"		},
[307] = { 6,	TM,		SEN(move_pages),		"move_pages"		},
[308] = { 3,	0,		SEN(getcpu),			"getcpu"		},
[309] = { 6,	TD,		SEN(epoll_pwait),		"epoll_pwait"		},
[310] = { 4,	TD|TF,		SEN(utimensat),			"utimensat"		},
[311] = { 3,	TD|TS,		SEN(signalfd),			"signalfd"		},
[312] = { 2,	TD,		SEN(timerfd_create),		"timerfd_create"	},
[313] = { 1,	TD,		SEN(eventfd),			"eventfd"		},
[314] = { 6,	TD,		SEN(fallocate),			"fallocate"		},
[315] = { 4,	TD,		SEN(timerfd_settime),		"timerfd_settime"	},
[316] = { 2,	TD,		SEN(timerfd_gettime),		"timerfd_gettime"	},
[317] = { 4,	TD|TS,		SEN(signalfd4),			"signalfd4"		},
[318] = { 2,	TD,		SEN(eventfd2),			"eventfd2"		},
[319] = { 1,	TD,		SEN(epoll_create1),		"epoll_create1"		},
[320] = { 3,	TD,		SEN(dup3),			"dup3"			},
[321] = { 2,	TD,		SEN(pipe2),			"pipe2"			},
[322] = { 1,	TD,		SEN(inotify_init1),		"inotify_init1"		},
[323] = { 4,	TN,		SEN(accept4),			"accept4"		},
[324] = { 5,	TD,		SEN(preadv),			"preadv"		},
[325] = { 5,	TD,		SEN(pwritev),			"pwritev"		},
[326] = { 4,	TP|TS,		SEN(rt_tgsigqueueinfo),		"rt_tgsigqueueinfo"	},
[327] = { 5,	TD,		SEN(perf_event_open),		"perf_event_open"	},
[328] = { 5,	TN,		SEN(recvmmsg),			"recvmmsg"		},
[329] = { 2,	TD,		SEN(fanotify_init),		"fanotify_init"		},
[330] = { 6,	TD|TF,		SEN(fanotify_mark),		"fanotify_mark"		},
[331] = { 4,	0,		SEN(prlimit64),			"prlimit64"		},
[332] = { 5,	TD|TF,		SEN(name_to_handle_at),		"name_to_handle_at"	},
[333] = { 3,	TD,		SEN(open_by_handle_at),		"open_by_handle_at"	},
[334] = { 2,	0,		SEN(clock_adjtime),		"clock_adjtime"		},
[335] = { 1,	TD,		SEN(syncfs),			"syncfs"		},
[336] = { 4,	TN,		SEN(sendmmsg),			"sendmmsg"		},
[337] = { 2,	TD,		SEN(setns),			"setns"			},
[338] = { 6,	0,		SEN(process_vm_readv),		"process_vm_readv"	},
[339] = { 6,	0,		SEN(process_vm_writev),		"process_vm_writev"	},
[340] = { 0,	NF,		SEN(printargs),			"kern_features"		},
[341] = { 5,	0,		SEN(kcmp),			"kcmp"			},
[342] = { 3,	TD,		SEN(finit_module),		"finit_module"		},
[343] = { 3,	0,		SEN(sched_setattr),		"sched_setattr"		},
[344] = { 4,	0,		SEN(sched_getattr),		"sched_getattr"		},
[345] = { 5,	TD|TF,		SEN(renameat2),			"renameat2"		},
[346] = { 3,	0,		SEN(seccomp),			"seccomp",		},
[347] = { 3,	0,		SEN(getrandom),			"getrandom",		},
[348] = { 2,	TD,		SEN(memfd_create),		"memfd_create",		},
[349] = { 3,	TD,		SEN(bpf),			"bpf",			},
[350] = { 5,	TD|TF|TP|SE|SI,	SEN(execveat),			"execveat",		},
[351] = { 2,	0,		SEN(membarrier),		"membarrier",		},
[352] = { 1,	TD,		SEN(userfaultfd),		"userfaultfd",		},
[353] = { 3,	TN,		SEN(bind),			"bind"			},
[354] = { 2,	TN,		SEN(listen),			"listen"		},
[355] = { 5,	TN,		SEN(setsockopt),		"setsockopt"		},
[356] = { 3,	TM,		SEN(mlock2),			"mlock2"		},
[357] = { 6,	TD,		SEN(copy_file_range),		"copy_file_range"	},
[358] = { 6,	TD,		SEN(preadv2),			"preadv2"		},
[359] = { 6,	TD,		SEN(pwritev2),			"pwritev2"		},

#define SYS_socket_subcall	400
#include "subcall.h"
