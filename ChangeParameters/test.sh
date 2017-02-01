do_test() {
  ./hog &
  P=$!
  echo PID: $P
  sudo ./chdl/chdl $P 50000 100000
  #pidstat -p $P 1 5
  top -b -d 1 -n 5 | grep hog
  sudo ./chdl/chdl $P 40000 100000
  #pidstat -p $P 1 5
  top -b -d 1 -n 5 | grep hog
  kill $P
}

RUNS=$(seq 1 500)

for R in $RUNS
 do
  echo Cycle $R
  do_test
 done
