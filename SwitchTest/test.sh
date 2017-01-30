do_test() {
  sudo ./switch_test
  sleep 1 
}

RUNS=$(seq 1 500)

for R in $RUNS
 do
  echo Cycle $R
  do_test
 done

