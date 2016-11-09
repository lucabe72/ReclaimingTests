struct taskset {
  unsigned int n;
  struct task *t;
};

struct taskset *ts_load(const char *fname);
void ts_print(const struct taskset *ts);
void ts_bindings(const struct taskset *ts);

double ts_umax(const struct taskset *ts);
double ts_utot(const struct taskset *ts);

