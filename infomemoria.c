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
	snprintf(buffer,500, "<p>Total RAM: %5.1f MB<br>Total RAM in use: %5.1f MB<br>Total RAM Free : %5.1f MB</p>",
       		si.totalram / megabyte , (si.totalram - si.freeram) / megabyte , si.freeram / megabyte);

	//acrescenta ao buffer do projeto os dados contidos no buffer da função
	strncat(b, buffer, s);
  
	return 1;
}



