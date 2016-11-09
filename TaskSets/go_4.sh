CPUPATH=/sys/devices/system/cpu/

CPUS="4 5 6 7"

for C in $CPUS
 do
  echo 0 > $CPUPATH/cpu$C/online
 done
