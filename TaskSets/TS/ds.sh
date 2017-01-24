ALPHAS="0.2 0.3 0.4 0.5 0.6 0.7 0.8"
GAMMAS="0.9 1.0 1.1 1.2 1.3 1.4 1.5"

for G in $GAMMAS
 do
  echo "Gamma=$G"
  for A in $ALPHAS
   do
    R0=$(sh dosum.sh Gamma-$G/R-0/res-$A.txt)
    R1=$(sh dosum.sh Gamma-$G/R-1/res-$A.txt)
    echo "$A $R0 $R1" > /dev/kmsg
   done
 done
