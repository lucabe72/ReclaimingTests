#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "taskset.h"
#include "schedulability.h"

int main(int argc, char *argv[])
{
  struct taskset *ts;
  unsigned int schedulable, m = 4;
  int res = 0;

  if (argc < 2) {
    fprintf(stderr, "No filename provided!\n");

    return -1;
  }

  ts = ts_load(argv[1]);
  if (ts == NULL) {
    fprintf(stderr, "Cannot load taskset %s!\n", argv[1]);

    return -1;
  }

  if (argc > 2) {
    m = atoi(argv[2]);
  }
  
  schedulable = is_schedulable_bcl(ts, m) || is_schedulable_umax(ts, m);

  printf("Taskset ");
  ts_print(ts);
  if (schedulable) {
    printf("is schedulable on %u CPUs according to BCL+Umax\n", m);
  } else {
    printf("is NOT schedulable on %u CPUs according to BCL+Umax\n", m);
    res = -1;
  }

  return res;
}

