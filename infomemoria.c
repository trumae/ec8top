#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h> //biblioteca que permite obter info dos sistema
#include "infomemoria.h"

int infomemoria(char *b, size_t s) {//Função que que mostra status da memoria Ram do sistema

	/* Conversoes para uso de medidas */
	const double megabyte = 1024 * 1024;

	/* Obtendo informacoes do sistema  */
	struct sysinfo si;
	sysinfo (&si);
    
	char buffer[500];
	buffer[0] = '\x0';
	
	/*impressao das informacoes*/
	snprintf(buffer,500, "<p>Total de Mem&oacuteria RAM: %5.1f MB<br>Total de Mem&oacuteria RAM livre: %5.1f MB<br>Total de Mem&oacuteria 			RAM em uso: %5.1f MB</p>",
       		si.totalram / megabyte,si.freeram / megabyte , (si.totalram - si.freeram) / megabyte);
	strncat(b, "<h2>Informa&ccedil&otildees sobre a Mem&oacuteria RAM: </h2>", s);
	strncat(b, buffer, s);

  
	return 1;
}



