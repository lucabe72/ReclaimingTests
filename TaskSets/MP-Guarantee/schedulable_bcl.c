#include "task.h"
#include "taskset.h"
#include "schedulability.h"

static unsigned int fl(unsigned int a, unsigned int b)
{
  return a / b;
}

static unsigned int min(unsigned int a, unsigned int b)
{
  return a < b ? a : b;
}

static unsigned int n(const struct taskset *ts, unsigned int j, unsigned int i)
{
  return fl(ts->t[i].d, ts->t[j].p);
}

static unsigned int interference(const struct taskset *ts, unsigned int j, unsigned int i)
{
  return min(n(ts, j, i) * ts->t[j].c + min(ts->t[j].c, ts->t[i].d - n(ts, j, i) * ts->t[j].p), ts->t[i].d - ts->t[i].c);
}

/*
      for all i,     \sum_{j \neq i}   I_j   / m  <= (D_i - C_i + 1)

	and 
  
       I_j = min(   n_j C_j + min(C_j, D_i - n_j T_j),     D_i - C_i )

      and  

       n_j = \floor{\frac{D_i}{T_j}}
 */
unsigned int is_schedulable_bcl(const struct taskset *ts, unsigned int m)
{
  unsigned int i;
  unsigned int schedulable = 1;

  for (i = 0; i < ts->n; i++) {
    unsigned int j;
    unsigned int sum;

    sum = 0;
    for (j = 0; j < ts->n; j++) {
      if (j != i) {
        sum += interference(ts, j, i);
      }
    }
    sum = sum / m;
    if (sum > ts->t[i].d - ts->t[i].c + 1) {
//printf("(%u %u - interf %u\n", ts->t[i].c, ts->t[i].d, sum);
      schedulable = 0;
    }
  }

  return schedulable;
}
