mount debugfs /sys/kernel/debug -t debugfs
echo sched_migrate_task          >  /sys/kernel/debug/tracing/set_event
echo sched_stat_params_dl        >> /sys/kernel/debug/tracing/set_event
echo sched_stat_running_bw_add   >> /sys/kernel/debug/tracing/set_event
echo sched_stat_running_bw_clear >> /sys/kernel/debug/tracing/set_event

cat /sys/kernel/debug/tracing/trace_pipe > /tmp/trace &
