./dlblocked &
P=$!
echo PID: $P

sleep 5
echo "Moving to Set 1"
echo $P > /sys/fs/cgroup/cpuset/Set1/tasks
sleep 5

echo "Moving to Set 2"
echo $P > /sys/fs/cgroup/cpuset/Set2/tasks
sleep 5

echo "Moving to Set 1"
echo $P > /sys/fs/cgroup/cpuset/Set1/tasks
sleep 5

echo "Moving to Set 2"
echo $P > /sys/fs/cgroup/cpuset/Set2/tasks
sleep 5

echo "Killing..."
kill $P
