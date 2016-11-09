ALPHAS="0.2 0.3 0.4 0.5 0.6 0.7 0.8"
GAMMAS="0.9 1.0 1.1 1.2 1.3 1.4 1.5"

for G in $GAMMAS
 do
  rm new-gamma-$G.txt
  for A in $ALPHAS
   do
    SS0=$(sh dosum.sh New-Sequential/Gamma-$G/R-0/res-$A.txt | cut -d ' ' -f 5)
    SS1=$(sh dosum.sh New-Sequential/Gamma-$G/R-1/res-$A.txt | cut -d ' ' -f 5)
    SP0=$(sh dosum.sh Parallel/Gamma-$G/R-0/res-$A.txt | cut -d ' ' -f 5)
    SP1=$(sh dosum.sh Parallel/Gamma-$G/R-1/res-$A.txt | cut -d ' ' -f 5)
    echo "$A $SS0 $SS1 $SP0 $SP1" >> new-gamma-$G.txt
   done
 done
