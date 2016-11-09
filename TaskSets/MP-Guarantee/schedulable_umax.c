#include "task.h"
#include "taskset.h"
#include "schedulability.h"

#include <stdio.h>
unsigned int is_schedulable_umax(const struct taskset *ts, unsigned int m)
{
  double utot, umax;
  unsigned int i;

  utot = 0; umax = 0;
  for (i = 0; i < ts->n; i++) {
    double u;

    u = (double)ts->t[i].c / (double)ts->t[i].p;
    if (u > umax) {
      umax = u;
    }
    utot += u;
  }
printf("Umax: %f\n", umax);
printf("Utot: %f\n", utot);
printf("check %f...\n", (double)m - (double)(m - 1) * umax);
  return (utot < (double)m - (double)(m - 1) * umax);
}
