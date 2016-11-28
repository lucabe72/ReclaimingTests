ALPHA=$2
GAMMA=$3
RECLAIM=$4

do_run() {
  echo Executiong $1...
  mkdir -p $2/$(basename $1)
  Q=$(../MP-Guarantee/umax_free $1)
  echo fake $Q 400000
  sudo ../Fake/fake $Q 400000 0 &
  sudo ../Fake/fake $Q 400000 1 &
  sudo ../Fake/fake $Q 400000 2 &
  sudo ../Fake/fake $Q 400000 3 &
  sudo ../rt-app/src/rt-app $1.json
  sudo killall fake
  cp /tmp/rt-app* $2/$(basename $1)
}

do_process() {
  echo Processing $1...
#  ../MP-Guarantee/json_generate $1 > $1.json
#  ../MP-Guarantee/json_generate $1 > $1.json
  ../MP-Guarantee/json_generate $1 $ALPHA $GAMMA $RECLAIM > $1.json
  do_run $1 $2
}

FILES=$(sh check.sh $1 | grep -v KO)
rm res.txt

mkdir -p $1/JSON
mkdir $1/Results
for F in $FILES
 do
  do_process $F Results
  sh parse.sh Results/$(basename $F) >> res.txt
 done
mv $1/*.json $1/JSON

