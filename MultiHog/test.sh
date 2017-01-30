IDS=$(seq 1 11)

for D in $IDS
 do
  sudo ./d 2 &
 done
pidstat 1 10; sudo killall d
