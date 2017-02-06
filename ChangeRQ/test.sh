PID=$1
sudo mount -t tmpfs cgroup_root       /sys/fs/cgroup
sudo mkdir                            /sys/fs/cgroup/cpuset
sudo mount -t cgroup -o cpuset cpuset /sys/fs/cgroup/cpuset

sudo mkdir              /sys/fs/cgroup/cpuset/Set1
sudo su -c "echo 0    > /sys/fs/cgroup/cpuset/Set1/cpuset.cpus"
sudo su -c "echo 0    > /sys/fs/cgroup/cpuset/Set1/cpuset.mems"
sudo su -c "echo 1    > /sys/fs/cgroup/cpuset/Set1/cpuset.cpu_exclusive"
sudo mkdir              /sys/fs/cgroup/cpuset/Set2
sudo su -c "echo 1    > /sys/fs/cgroup/cpuset/Set2/cpuset.cpus"
sudo su -c "echo 0    > /sys/fs/cgroup/cpuset/Set2/cpuset.mems"
sudo su -c "echo 1    > /sys/fs/cgroup/cpuset/Set2/cpuset.cpu_exclusive"


sudo ./dlblocked &
P=$!
echo PID: $P

echo "Moving to Set 1"
sudo su -c "echo $PID > /sys/fs/cgroup/cpuset/Set1/tasks"
sleep 2

echo "Moving to Set 2"
sudo su -c "echo $PID > /sys/fs/cgroup/cpuset/Set2/tasks"
sleep 2

echo "Moving to Set 1"
sudo su -c "echo $PID > /sys/fs/cgroup/cpuset/Set1/tasks"
sleep 2

echo "Moving to Set 2"
sudo su -c "echo $PID > /sys/fs/cgroup/cpuset/Set2/tasks"
sleep 2

echo "Killing..."
sudo kill dlblocked
