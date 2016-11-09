ADMISSION_TEST=../MP-Guarantee/partitioned_test
ADMISSION_TEST=../MP-Guarantee/bcl_test
ADMISSION_TEST=../MP-Guarantee/bclumax_test
#ADMISSION_TEST=../MP-Guarantee/umax_test
#ADMISSION_TEST=../MP-Guarantee/baker_test
FILES=$(ls $1/*.txt)

do_check() {
  echo -n "$1 "
  $ADMISSION_TEST $1 > /dev/null || echo -n KO
  echo
}

for F in $FILES
 do
 do_check $F
 done
