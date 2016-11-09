#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "taskset.h"

int main(int argc, char *argv[])
{
  struct taskset *ts;
  unsigned int m = 4;
  double ufree;

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
  

  ufree = ((double)m - (double)(m - 1) * ts_umax(ts)) - ts_utot(ts);
  if (ufree < 0) {
    ufree = 0;
  }
  printf("%u\n", (unsigned)(ufree * 100000));

  return 0;
}
