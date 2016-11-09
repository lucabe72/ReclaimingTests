#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "taskset.h"

void ts_json(const struct taskset *ts, double alpha, double gamma, unsigned int r)
{
  unsigned int i;

  printf("{\n");
  printf("\t\"resources\" : 0,\n");
  printf("\t\"tasks\" : {\n");
  for (i = 0; i < ts->n; i++) {
    if (ts->t[i].c > 1000) {

      printf("\t\t\"task%u\" : {\n", i);
      printf("\t\t\t\"bcet\" : %u,\n", (unsigned)(ts->t[i].c * gamma * alpha));
      printf("\t\t\t\"wcet\" : %u,\n", (unsigned)(ts->t[i].c * gamma));
      if (r) {
        printf("\t\t\t\"reclaiming\" : true,\n");
      }
      printf("\t\t\t\"runtime\" : %u,\n", ts->t[i].c);
      printf("\t\t\t\"period\" : %u,\n", ts->t[i].p);
      printf("\t\t\t\"deadline\" : %u\n", ts->t[i].d);
      printf("\t\t},\n");
    }
  }
  printf("\t},\n");
  printf("\t\"global\" : {\n");
  printf("\t\t\"default_policy\" : \"SCHED_DEADLINE\",\n");
  printf("\t\t\"duration\" : 10,\n");
  printf("\t\t\"logdir\" : \"/tmp/\",\n");
  printf("\t\t\"log_basename\" : \"rt-app\",\n");
  printf("\t\t\"lock_pages\" : true\n");
  printf("\t}\n");

  printf("},\n");
}
