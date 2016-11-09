#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "taskset.h"

struct taskset *ts_load(const char *fname)
{
  FILE *f;
  struct taskset *ts;

  f = fopen(fname, "r");
  if (f == NULL) {
    return NULL;
  }

  ts = malloc(sizeof(struct taskset));
  if (ts == NULL) {
    fclose(f);

    return NULL;
  }
  ts->n = 0;
  ts->t = NULL;

  while(!feof(f)) {
    int res;
    unsigned int c, p, d;

    res = fscanf(f, "%u %u %u\n", &c, &p, &d);
    if (res == 3) {
      ts->t = realloc(ts->t, (ts->n + 1) * sizeof(struct task));
      if (ts->t) {
        ts->t[ts->n].c = c;
        ts->t[ts->n].p = p;
        ts->t[ts->n].d = d;

        ts->t[ts->n].cpu = -1;

        ts->n = ts->n + 1;
      } else {
        ts->n = 0;
      }
    }
  }

  fclose(f);

  return ts;
}

void ts_print(const struct taskset *ts)
{
  unsigned int i;

  printf("{");
  for (i = 0; i < ts->n; i++) {
    printf("(%u, %u, %u)", ts->t[i].c, ts->t[i].p, ts->t[i].d);
    if (i != ts->n - 1) printf(", ");
  }
  printf("}\n");
}

void ts_bindings(const struct taskset *ts)
{
  unsigned int i;

  for (i = 0; i < ts->n; i++) {
    printf("\t(%u, %u, %u) -> %d\n", ts->t[i].c, ts->t[i].p, ts->t[i].d, ts->t[i].cpu);
  }
}

double ts_umax(const struct taskset *ts)
{
  double umax;
  unsigned int i;

  umax = 0;
  for (i = 0; i < ts->n; i++) {
    double u;

    u = (double)ts->t[i].c / (double)ts->t[i].p;
    if (u > umax) {
      umax = u;
    }
  }

  return umax;
}

double ts_utot(const struct taskset *ts)
{
  double utot;
  unsigned int i;

  utot = 0;
  for (i = 0; i < ts->n; i++) {
    double u;

    u = (double)ts->t[i].c / (double)ts->t[i].p;
    utot += u;
  }

  return utot;
}
