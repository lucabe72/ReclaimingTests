N_TASKS=8
MIN_PERIOD=10000
MAX_PERIOD=100000
U=2.0
TSG=./taskgen.py

do_ts() {
  IDS=$(seq 1 $2)
  U=$1
  for ID in $IDS
   do
    $TSG -n $N_TASKS -p $MIN_PERIOD -q $MAX_PERIOD --round-C -s 1 -u $U -f "%(C)d %(T)d %(T)d\n" > $3/ts$ID.txt
   done
}

mkdir -p $1
do_ts $U 100 $1
