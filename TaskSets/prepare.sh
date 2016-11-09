setterm -blank 0
echo Y  > /sys/module/printk/parameters/ignore_loglevel
echo -1 > /proc/sys/kernel/sched_rt_runtime_us
echo 30 > /sys/devices/system/cpu/intel_pstate/min_perf_pct
echo 30 > /sys/devices/system/cpu/intel_pstate/max_perf_pct
echo  1 > /sys/devices/system/cpu/intel_pstate/no_turbo
