NUM=$(cut -d ' ' -f 2 $1  | paste -sd+ | bc)
DEN=$(cut -d ' ' -f 4 $1  | paste -sd+ | bc)
RES=$(echo "scale=5; $NUM / $DEN" | bc)

echo $NUM / $DEN = $RES
