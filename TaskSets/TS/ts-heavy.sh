N_TASKS=6
MIN_PERIOD=100000
MAX_PERIOD=500000
U=0.4
TSG=./taskgen.py

do_ts() {
  IDS=$(seq 1 $2)
  U=$1
  for ID in $IDS
   do
    $TSG -n 2 -p $MIN_PERIOD -q $MAX_PERIOD --round-C -g 1000 -s 1 -u 1.5 -f "%(C)d %(T)d %(T)d\n" > $3/ts$ID.txt
    $TSG -n $N_TASKS -p $MIN_PERIOD -q $MAX_PERIOD --round-C -g 1000 -s 1 -u $U -f "%(C)d %(T)d %(T)d\n" >> $3/ts$ID.txt
   done
}

mkdir -p $1
do_ts $U 100 $1
