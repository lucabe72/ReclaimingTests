mount -t tmpfs cgroup_root       /sys/fs/cgroup
mkdir                            /sys/fs/cgroup/cpuset
mount -t cgroup -o cpuset cpuset /sys/fs/cgroup/cpuset

mkdir       /sys/fs/cgroup/cpuset/Set1
echo 0    > /sys/fs/cgroup/cpuset/Set1/cpuset.cpus
echo 0    > /sys/fs/cgroup/cpuset/Set1/cpuset.mems
echo 1    > /sys/fs/cgroup/cpuset/Set1/cpuset.cpu_exclusive
mkdir       /sys/fs/cgroup/cpuset/Set2
echo 1    > /sys/fs/cgroup/cpuset/Set2/cpuset.cpus
echo 0    > /sys/fs/cgroup/cpuset/Set2/cpuset.mems
echo 1    > /sys/fs/cgroup/cpuset/Set2/cpuset.cpu_exclusive
