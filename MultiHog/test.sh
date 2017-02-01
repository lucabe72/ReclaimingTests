IDS=$(seq 1 11)

do_test() {
  for D in $IDS
   do
    sudo ./dlhog 2 &
   done
  top -b -d 1 -n 10 | grep "dlhog"
  sudo killall dlhog
  sleep 1
}

BS=$(seq 200000 50000 950000)

for B in $BS
 do
  echo "Testing $B 1000000..."
  sudo sh -c "echo $B > /proc/sys/kernel/sched_rt_runtime_us"
  do_test
 done
