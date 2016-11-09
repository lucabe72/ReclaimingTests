CFLAGS=-Wall -Werror -std=c99

all: baker_test bcl_test umax_test partitioned_test json_generate umax_free

ts_test:          ts_test.o taskset.o
json_generate:    json_generate.o taskset.o json.o
baker_test:       baker_test.o taskset.o schedulable_baker.o
bcl_test:         bcl_test.o taskset.o schedulable_bcl.o
bclumax_test:     bclumax_test.o taskset.o schedulable_bcl.o schedulable_umax.o
umax_test:        umax_test.o taskset.o schedulable_umax.o
partitioned_test: partitioned_test.o taskset.o schedulable_partitioned.o
baker_fill:       baker_fill.o taskset.o schedulable_baker.o
umax_free:        umax_free.o taskset.o

clean:
	rm -f *.o
	rm -f ts_test baker_test bcl_test umax_test partitioned_test baker_fill json_generate umax_free
