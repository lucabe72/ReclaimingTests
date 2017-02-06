#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */
#include <time.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/types.h>
#include <linux/sched.h>

/* 
 * The following structure and function are needed because they
 * were not include on headers yet. Do not know why, though.
 * man page says they should be on sched.h
 */

struct sched_attr {
	__u32 size;
	__u32 sched_policy;
	__u64 sched_flags;
	__s32 sched_nice;
	__u32 sched_priority;
	__u64 sched_runtime;
	__u64 sched_deadline;
	__u64 sched_period;
};

int sched_setattr(pid_t pid, const struct sched_attr *attr,
		  unsigned int flags)
{
	return syscall(__NR_sched_setattr, pid, attr, flags);
}

#define SCHED_FLAG_RECLAIM		0x02

int main (int argc, char **argv)
{
	int ret;
	int f = 0;
	unsigned int flags = 0;
	struct sched_attr attr;

	if (argc > 1) {
		f = atoi(argv[1]);
	}
	memset(&attr, 0, sizeof(attr));
	attr.size = sizeof(attr);
	attr.sched_flags = /*SCHED_FLAG_RECLAIM*/ f;
	attr.sched_nice = 0;
	attr.sched_priority = 0;

	/* This creates a 10ms/30ms reservation */
	attr.sched_policy = SCHED_DEADLINE;
	attr.sched_runtime = 10 * 1000 * 1000;
	attr.sched_period = attr.sched_deadline = 30 * 1000 * 1000;

	ret = sched_setattr(0, &attr, flags);
	if (ret < 0) {
		perror("sched_setattr");
		exit(-1);
	}

	while(1) sleep(60);

	exit(0);
}

