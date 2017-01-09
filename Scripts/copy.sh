LINES=$(wc -l $1 | cut -f 1 -d ' ')

cplines() {
  tail -n $1 $2 | head -n 4
}

L=$LINES
while [ "$L" -gt 4 ]
 do
  cplines $L $1
  L=$((L - 4))
  sleep 1
 done
