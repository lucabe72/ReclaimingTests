IDS=$(seq 1 11)

for D in $IDS
 do
  sudo ./d &
 done
sleep 2; sudo killall d
