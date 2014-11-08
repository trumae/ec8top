#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>//necessário para a função cpusage
#include "mongoose.h"
#include "cpu_usage.h"

#define tamanho_buffer 10000

static int segmento_inicial(char *b, size_t s) {//snprintf substitui o valor no buffer, se usá-lo irá substituir os dados do buffer
    snprintf(b,s, "<h1>Monitorador de recursos</h1><hr>");
    return 1;
}

static int segmento_sobre(char *b, size_t s) {//strncat concatena informações ao buffer, por isso é bom usá-lo somente
    strncat(b, "<hr><center><h4><i>Feito pela turma 2011 da Unipac Lafaiete - &copy; Todos os direitos reservados</i></h4></center>", s);
    return 1;
}

static int ev_handler(struct mg_connection *conn, 
                      enum mg_event ev) {
  char buffer[tamanho_buffer];
  buffer[0] = '\x0';
  switch (ev) {
    case MG_AUTH: return MG_TRUE;
    case MG_REQUEST:
      mg_send_header(conn, "Content-Type", "text/html");
      strncpy(buffer, 
        "<doctype html>\n"
	"<html>\n"
        "<header>"
        "<title>EC8</title>"
        "</header>\n"
        "<body>\n", sizeof(buffer));
      segmento_inicial(buffer, sizeof(buffer));
      
      	//acrescenta as informações de versão do SO
	///versaoso(buffer, sizeof(buffer));
	cpuusage(buffer, sizeof(buffer));
      
      segmento_sobre(buffer, sizeof(buffer));
      strncat(buffer, 
        "</body>\n"
        "</html>", sizeof(buffer));

      mg_printf_data(conn, buffer);
      return MG_TRUE;
    default: return MG_FALSE;
  }
}

int cpuusage(char *b, size_t s){//chama a função cpu_usage.c e escreve o resultado em html
	
	struct cpu_counters cpu_cnt_start, cpu_cnt_end;
	char buffer[100];

	read_cpu_counters(&cpu_cnt_start);//primeiro ele começa a fazer a contagem dos contadores da CPU com a struct start

	sleep(1);//dorme por um tempo

	read_cpu_counters(&cpu_cnt_end);//depois ele termina a contagem dos contadores com a struct end

	//escreve no html
	snprintf(buffer,500, "Utiliza&ccedil&atildeo Total do Processador: %3.2f<br>", cpu_usage(&cpu_cnt_start, &cpu_cnt_end));
	strncat(b, buffer, s);

	return 0;
}

int main(void) {
  	struct mg_server *server;

	// Create and configure the server
	server = mg_create_server(NULL, ev_handler);
	mg_set_option(server, "listening_port", "8080");

	// Serve request. Hit Ctrl-C to terminate the program
	printf("Starting on port %s\n", mg_get_option(server, "listening_port"));
	for (;;) {
		mg_poll_server(server, 1000);
	}

	// Cleanup, and free server instance
	mg_destroy_server(&server);

	return 0;
}
