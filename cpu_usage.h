#ifndef CPU_USAGE_H
#define CPU_USAGE_H

struct cpu_counters {
  long long total_jiffies;
  long long work_jiffies;
};

/* lê os valores atuais da cpu através do /proc/stat */
int read_cpu_counters(struct cpu_counters *cpu_cnt);

/* retorna o uso da cpu em % */
float cpu_usage(const struct cpu_counters *cpu_cnt_start, const struct cpu_counters *cpu_cnt_end);

#endif
