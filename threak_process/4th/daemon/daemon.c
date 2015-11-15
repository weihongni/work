#include <string.h>
#include "daemon.h"

extern void debug_wait (int debug);

void test_to_locked ()
{
	int fd;
	struct flock lock;
	char *buf = "abdcefghijklmnopqrstuvwxyz";
	//begin to test file lock   
	fd = open ("/tmp/mylock.lock", O_RDWR | O_CREAT, 0777);
	if (fd < 0) {
		perror ("Open file error");
		exit (1);
	}

	write (fd, buf, strlen (buf));
	fsync (fd);/* 确保数据写入到文件 */

	//file be locked?
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	lock.l_type = F_WRLCK;
	lock.l_pid = -1;
	if (fcntl (fd, F_GETLK, &lock) < 0) {
		perror ("fcntl failed!");
		exit (1);
	}
	//  if(lock.l_type == F_WRLCK)
	if (lock.l_type != F_UNLCK) {
		printf ("have a daemon. so quit!\n");
		exit (1);
	}
	//locked file
	lock.l_type = F_WRLCK;
	if (fcntl (fd, F_SETLKW, &lock) < 0) {
		printf ("Lock file failed: type = %d\n", lock.l_type);
		exit (1);
	}
	printf ("file have locked!\n");
}

int daemon_init (void)
{
	pid_t pid;
	int fd0, fd1, fd2, max_fd, i;
	struct rlimit rl;
	struct sigaction sa;


	umask (0);

	/* 第一次fork(),父进程退出: 子进程变成孤儿进程，并交给init进程进行托管，这样就和控制终端进行脱离  */
	if ((pid = fork ()) < 0) {
		perror ("fork faild!");
		exit (1);
	} else if (pid != 0) {
		exit (0);
	}

	/* 2. 调用setsid()， 进程成为新的session的领头进程 */
	if (setsid () < 0)
		exit (1);

	signal (SIGHUP, SIG_IGN); /*ignore： 忽略SIGHUP信号 */

	/* 第二次fork()，(子进程会继承父进程对信号的处理办法)，父进程退出*/
	if ((pid = fork ()) < 0) {
		perror ("fork faild!");
		exit (1);
	} else if (pid != 0) {
		exit (0);
	}

	chdir ("/");
	//umask(0);
	setpgrp ();
#if 0
	// Get maximum number of file descriptors.
	if (getrlimit (RLIMIT_NOFILE, &rl) < 0) {
		perror ("can't get file limit");
	}
	// Close all open file descriptors.
	if (rl.rlim_max == RLIM_INFINITY)
		rl.rlim_max = 1024;
	for (i = 0; i < rl.rlim_max; i++)
		close (i);
#else
	/* 关闭所有的文件描述符*/
	max_fd = sysconf (_SC_OPEN_MAX);
	for (i = max_fd; i >= 0; i--)
		close (i);
#endif
	/* 把所有的标准终端定位到/dev/null设备上 */
	//attach file descriptors 0, 1, and 2 to /dev/null.
	fd0 = open ("/dev/null", O_RDWR);
	fd1 = dup (0);
	fd2 = dup (0);

	test_to_locked (); /* 记录锁 因为子进程不会继承父进程的文件锁（记录锁是文件锁的一种），所以此锁放在第二次fork()之后 */
	//Initialize the log file.
	openlog ("1507_daemon_test", LOG_CONS | LOG_PID, LOG_DAEMON);
	if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
		syslog (LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
		exit (1);
	}

	return 0;
}
