#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h> //biblioteca que permite obter info dos sistema
#include "numprocessos.h"

int numprocessos(char *b, size_t s) {//Função que que mostra quantos processos estao executando na maquina

	/* Conversoes para uso de medidas */
	const long minuto = 60;
	const long hora = minuto * 60;
	const long dia = hora * 24;

	/* Obtendo informacoes do sistema  */
	struct sysinfo si;
	sysinfo (&si);
    
	char buffer[500];
	buffer[0] = '\x0';
	
	/*impressao das informacoes*/
	snprintf(buffer,500, "<p>Tempo de funcionamento do sistema: %ld dias, %ld:%02ld:%02ld h <br> Quantidade de processo em 			execu&ccedil&atildeo:  %d Procesos</p>",
       		si.uptime / dia , (si.uptime % dia) / hora,(si.uptime % hora) / minuto , si.uptime % minuto , si.procs);
	strncat(b, "<h2>Atividade da M&aacutequina e Processos: </h2>", s);
	strncat(b, buffer, s);
  
	return 1;
}



