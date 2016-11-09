#define _GNU_SOURCE
#include <sys/types.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#include "dl_syscalls.h"

int main(int argc, char *argv[])
{
  int qs, ts;
  int cpu = -1;
  struct sched_attr sa = {0};
  int res;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s Qs Ts [cpu]\n", argv[0]);

    return -1;
  }
  qs = atoi(argv[1]);
  ts = atoi(argv[2]);
  if (argc > 3) {
    cpu = atoi(argv[3]);
  }

  if (cpu >= 0) {
    cpu_set_t affinity;

    CPU_ZERO(&affinity);
    CPU_SET(cpu, &affinity);
    res = sched_setaffinity(0, sizeof(affinity), &affinity);
    if (res < 0) {
      perror("sched_setaffinity");
    }
  }

  sa.size           = sizeof(sa);
  sa.sched_policy   = SCHED_DEADLINE;
  sa.sched_runtime  = qs * 1000;
  sa.sched_deadline = ts * 1000;
  sa.sched_period   = ts * 1000;

  res = sched_setattr(0, &sa, 0);
  if (res < 0) {
    perror("sched_setattr");

    return -1;
  }

  while(1) {
    pause();
  }

  return -1;
}
