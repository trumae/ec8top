#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>//necessário para a cpu_resultado (função sleep)
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
	strncat(buf, "Error: Can't read the /proc/stat<br>", sizeof(buffer));
    	return -1;
  }

  /*os contadores da CPU estão na primeira linha */
  if (!fgets(buf, 256, f)) {
	strncat(buf, "Error: Invalid cpu counters in /proc/stat<br>", sizeof(buffer));
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

int cpu_resultado(char *b, size_t s){// escreve o resultado em html
	
	struct cpu_counters cpu_cnt_start, cpu_cnt_end;
	char buffer[100];

	read_cpu_counters(&cpu_cnt_start);//primeiro ele começa a fazer a contagem dos contadores da CPU com a struct start

	sleep(1);//dorme por um tempo

	read_cpu_counters(&cpu_cnt_end);//depois ele termina a contagem dos contadores com a struct end

	//escreve no html
	/* o segundo %(do html) gera dois warnig oqe nao interfere na na operação do código*/
	snprintf(buffer,500,"<p><b>CPU Usage:</b> %3.2f%%<br>\r\n", cpu_usage(&cpu_cnt_start, &cpu_cnt_end));
	
	//coloca as informacoes no buffer do projeto
	strncat(b, buffer, s);

	return 0;
}


