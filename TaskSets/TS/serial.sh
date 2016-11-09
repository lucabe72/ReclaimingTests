ALPHAS="0.2 0.3 0.4 0.5 0.6 0.7 0.8"
GAMMAS="0.9 1.0 1.1 1.2 1.3 1.4 1.5"
RS="1 0"

for G in $GAMMAS
 do
  mkdir Gamma-$G
  for R in $RS
   do
    for A in $ALPHAS
     do
      rm -rf TH/JSON TH/Results TH/*.json
      sh process.sh TH $A $G $R
#      sh process-1.sh TH $A $G $R
      mv res.txt res-$A.txt
     done
     mkdir -p Gamma-$G/R-$R
     mv res-*.txt Gamma-$G/R-$R
   done
 done
