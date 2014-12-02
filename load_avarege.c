#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>//biblioteca para obter informação direto do sistema (proc)
#include "load_avarege.h"

int load_avarege(char *b, size_t s) {

  /*cria a struct que irá obtem informções do sistema*/
  struct sysinfo Sinfo;

  char buffer[500];
  buffer[0] = '\x0';

  if(sysinfo(&Sinfo) != -1)

  /* Impressão do Load Averages de 1, 5 and 15 minutos
   * necessário a divisão por 65536 = (2¹⁶), para igualar a escalar do que é entregue pelo proc*/
  snprintf(buffer,500, "<b>Load Avarege:</b> (%.2f), (%.2f), (%.2f)<br>\n",
          ((Sinfo.loads[0])/65536.0), ((Sinfo.loads[1])/65536.0), ((Sinfo.loads[2])/65536.0));
	
  //coloca as informacoes no buffer do projeto
  strncat(b, buffer, s);

  return 0;
}
