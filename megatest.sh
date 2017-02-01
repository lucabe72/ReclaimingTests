RUNS=$(seq 1 500)

cd MultiHog
for R in $RUNS
 do
  echo MultiHog Cycle $R
  sh test.sh
 done
cd..

cd ChangeParameters
sh test.sh
cd ..

#Inheritance

cd KillTask

for R in $RUNS
 do
  echo KillTask Cycle $R
  sh test.sh
 done
cd ..

cd SwitchTest
sh test.sh
cd ..

cd TaskSets
sh test-driver.sh
