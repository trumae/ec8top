#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cpu_usage.h"

int read_cpu_counters(struct cpu_counters *cpu_cnt)
{
  FILE *f = NULL;
  char buf[256];
  char *rest = NULL, *token, *str;
  int ntok = 0;
  int err = 0;
char buffer[100];

/*abre o proc/stat */
  f = fopen("/proc/stat", "r");
  if (!f) {
	strncat(b, "Erro: N&atildeo foi poss&iacutevel ler /proc/stat<br>", sizeof(buffer));
    	fprintf(stderr, "Erro: Não foi possível ler /proc/stat\n");
    	return -1;
  }

  /*os contadores da CPU estão na primeira linha */
  if (!fgets(buf, 256, f)) {
	strncat(b, "Erro: Contadores da CPU inv&aacutelidos /proc/stat<br>", sizeof(buffer));
    fprintf(stderr, "error: invalid cpu counters in /proc/stat \n");
    err = -1;
    goto out;
  }

  str = buf;
  memset(cpu_cnt, 0, sizeof(*cpu_cnt));
  while ((token = strtok_r(str, " ", &rest)) != NULL) {
    ++ntok;
    str = rest;
    /* pula a primeira linha*/
    if (ntok == 1)
      continue;
    if (ntok < 5)
      cpu_cnt->work_jiffies += atoll(token);
  }

out:
  fclose(f);
  return err;
}

float cpu_usage(const struct cpu_counters *cpu_cnt_start,
    const struct cpu_counters *cpu_cnt_end)
{

return ((float)(cpu_cnt_end->work_jiffies - cpu_cnt_start->work_jiffies));
}

