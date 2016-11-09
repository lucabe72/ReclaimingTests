#include "task.h"
#include "taskset.h"
#include "schedulability.h"

unsigned int is_partitionable(struct taskset *ts, unsigned int m)
{
  double u[m];
  unsigned int i;

  for (i = 0; i < m; i++) {
    u[i] = 0;
  }

  for (i = 0; i < ts->n; i++) {
    double u;
    unsigned int j;
    unsigned int ci, pi, di;

    ci = ts->t[i].c;
    pi = ts->t[i].p;
    di = ts->t[i].d;
    u = (double)ts->t[i].c / (double)ts->t[i].p;
    for (j = i; j > 0; j--) {
      double u1;

      u1 = (double)ts->t[j - 1].c / (double)ts->t[j - 1].p;
      if (u1 < u) break;
      ts->t[j].c = ts->t[j - 1].c;
      ts->t[j].p = ts->t[j - 1].p;
      ts->t[j].d = ts->t[j - 1].d;
    }
    ts->t[j].c = ci;
    ts->t[j].p = pi;
    ts->t[j].d = di;
  }

  for (i = 0; i < ts->n; i++) {
    unsigned int p;
    unsigned int min_p;
    double min;
    double ui;

    ui = (double)ts->t[i].c / (double)ts->t[i].p;
    min = 2;
    for (p = 0; p < m; p++) {
      if ((1 - u[p] - ui > 0) && (1.0 - u[p] - ui < min)) {
        min = 1.0 - u[p] - ui;
        min_p = p;
      }
    }
    if (min > 1.0) return 0;
    u[min_p] += ui;
    ts->t[i].cpu = min_p;
  }

  return 1;
}
