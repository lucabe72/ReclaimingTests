#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "taskset.h"
#include "json.h"

int main(int argc, char *argv[])
{
  struct taskset *ts;
  double alpha = 1.0;
  double overp = 0.05;
  unsigned int reclaim = 0;
  unsigned int s = time(NULL) + clock();

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
    alpha = atof(argv[2]);
  }

  if (argc > 3) {
    overp = atof(argv[3]);
  }

  if (argc > 4) {
    reclaim = atoi(argv[4]);
  }

  if (argc > 5) {
    s = atoi(argv[5]);
  }
  
  srand(s);
  ts_json(ts, alpha, overp, reclaim);

  return 0;
}
