#include <stdio.h>

#include "task.h"
#include "taskset.h"

int main(int argc, char *argv[])
{
  struct taskset *ts;

  if (argc < 2) {
    fprintf(stderr, "No filename provided!\n");

    return -1;
  }

  ts = ts_load(argv[1]);
  if (ts == NULL) {
    fprintf(stderr, "Cannot load taskset %s!\n", argv[1]);

    return -1;
  }
  printf("Loaded %d tasks:\n\t", ts->n);
  ts_print(ts);

  return 0;
}
