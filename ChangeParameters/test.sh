do_test() {
  ./hog &
  P=$!
  echo PID: $P
  sudo ./chdl/chdl $P 50000 100000
  sleep 10 
  sudo ./chdl/chdl $P 40000 100000
  sleep 10 
  kill $P
}

RUNS=$(seq 1 500)

for R in $RUNS
 do
  echo Cycle $R
  do_test
 done
