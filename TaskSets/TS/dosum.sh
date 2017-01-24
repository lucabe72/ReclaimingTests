NUMS=$(cut -d ' ' -f 2 $1)
DENS=$(cut -d ' ' -f 4 $1)
NUM=0
DEN=0

for N in $NUMS
 do
  NUM=$((NUM+N))
 done
for N in $DENS
 do
  DEN=$((DEN+N))
 done

echo $NUM / $DEN
