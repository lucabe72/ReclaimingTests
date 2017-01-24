#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <linux/types.h>

static const int N = 100;

#define SCHED_OTHER	0
#define SCHED_DEADLINE	6

/* XXX use the proper syscall numbers */
#ifdef __x86_64__
#define __NR_sched_setattr		314
#define __NR_sched_getattr		315
#endif

#ifdef __i386__
#define __NR_sched_setattr		351
#define __NR_sched_getattr		352
#endif

#ifdef __arm__
#define __NR_sched_setattr		380
#define __NR_sched_getattr		381
#endif

struct sched_attr {
	__u32 size;

	__u32 sched_policy;
	__u64 sched_flags;

	/* SCHED_NORMAL, SCHED_BATCH */
	__s32 sched_nice;

	/* SCHED_FIFO, SCHED_RR */
	__u32 sched_priority;

	/* SCHED_DEADLINE (nsec) */
	__u64 sched_runtime;
	__u64 sched_deadline;
	__u64 sched_period;
};

static int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
{
	return syscall(__NR_sched_setattr, pid, attr, flags);
}


int main()
{
  int cnt, res;

  cnt = 0;
  while(cnt++ < N) {
    struct sched_attr dl;

    dl.size = sizeof(struct sched_attr);
    dl.sched_policy = SCHED_DEADLINE;
    dl.sched_flags = 0;
    dl.sched_nice = 0;
    dl.sched_priority = 0;
    dl.sched_runtime =  100 * 1000 * 1000;
    dl.sched_deadline = 200 * 1000 * 1000;
    dl.sched_period =   200 * 1000 * 1000;

    res = sched_setattr(0, &dl, 0);
    if (res < 0) {
      perror("Cannot switch to SCHED_DEADLINE!!!");

      return -1;
    }

    usleep((cnt % 10) * 1000);

    dl.size = sizeof(struct sched_attr);
    dl.sched_policy   = SCHED_OTHER;
    dl.sched_flags    = 0;
    dl.sched_nice     = 0;
    dl.sched_priority = 0;
    dl.sched_runtime  = 0;
    dl.sched_deadline = 0;
    dl.sched_period   = 0;

    res = sched_setattr(0, &dl, 0);
    if (res < 0) {
      perror("Cannot switch back to SCHED_OTHER!!!");

      return -1;
    }

  }

  return 0;
}
