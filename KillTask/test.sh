echo "Starting CPU Hog..."
./hog &
PID=$!
echo "Started! Has PID $PID"

sleep 1
echo "Making it -deadline..."
sudo ./chdl $PID 10000 50000
echo "Done!"

pidstat -p $PID 1 10
echo "Killing it..."
kill $PID

