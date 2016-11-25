doit() {
  LINES=$(wc -l $1 | cut -f 1 -d ' ')
#echo Lines: $LINES
  LINES=$((LINES-3))
  LAX=$(tail -n $LINES $1 | cut -f 10)
  CNT=0
  for L in $LAX
   do
#  ((L < 0)) && echo $L
   [ $L -lt 0 ] && CNT=$((CNT + 1))
   done
  echo -n "Miss: $CNT / $LINES = "
  echo $((CNT * 10000 / LINES))
}

FILES=$(ls $1/*.log)

for F in $FILES
 do
  echo -n $F
  doit $F
 done
