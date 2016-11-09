#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "taskset.h"
#include "schedulability.h"

unsigned int is_schedulable_with(const struct taskset *ts, unsigned int m, unsigned int c, unsigned int t)
{
  unsigned int res;
  struct taskset new_ts;

  new_ts.n = ts->n + 1;
  new_ts.t = malloc(sizeof(struct task) * new_ts.n);
  if (new_ts.t == NULL) {
    return 0;
  }
  memcpy(new_ts.t, ts->t, sizeof(struct task) * ts->n);
  new_ts.t[ts->n].c = c;
  new_ts.t[ts->n].p = t;
  new_ts.t[ts->n].d = t;
  res = is_schedulable_baker(&new_ts, m);
  free(new_ts.t);

  return res;
}

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
  
  schedulable = is_schedulable_baker(ts, m);

  printf("Taskset ");
  ts_print(ts);
  if (schedulable) {
    unsigned int t;
    printf("is schedulable on %u CPUs according to Baker\n", m);

    for (t = 5000; t < 1000000 ; t += 1000) {
      unsigned int c;

      c = 1000;
      while(is_schedulable_with(ts, m, c, t)) {
        c += 1000;
      }
      printf("Idle task: (%u, %u)\n", c - 1000, t);
    }
  } else {
    printf("is NOT schedulable on %u CPUs according to Baker\n", m);
    res = -1;
  }

  return res;
}

