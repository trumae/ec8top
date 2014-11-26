#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mongoose.h"
#include "../../versaoso.h"
#include "../../bateria.h"
#include "../../numprocessos.h"
#include "../../infomemoria.h"
#include "../../layout.h"

#define tamanho_buffer 150000

static int ev_handler(struct mg_connection *conn, 
                      enum mg_event ev) {
  char buffer[tamanho_buffer];
  buffer[0] = '\x0';

  switch (ev) {
    case MG_AUTH:
	return MG_MORE;
    case MG_REQUEST:
    //REQUISIÇÕES DE PÁGINA
    //Toda requisição, seja digitando URL,
    //ou uma chamada css ou javascript
    //ativa esta opção
	//printf("[%d] %s\n", strlen(conn->uri), conn->uri);
	//se nao tiver nada na url ele executa esse texto, caso contrario executa a url
	if(strlen(conn->uri)<=1){
		mg_send_header(conn, "Content-Type", "text/html");
		strncpy(buffer, "", sizeof(buffer));
 
		segmento_inicial(buffer, sizeof(buffer));

		//div com informações da bateria
		strncat(buffer,      
		"<div class=\"float-left\" style=\"width:400px\">\r\n"
		"<div class=\"fundo\"></div><div class=\"texto\">\r\n",
		sizeof(buffer));
		      //acrescenta as informações da bateria
		      bateria(buffer, sizeof(buffer));  
		strncat(buffer,   
		"</div>\r\n"
		"</div>\r\n",
		sizeof(buffer));

		//div com informações do S.O.
		strncat(buffer,      
		"<div class=\"float-right\" style=\"width:400px\">\r\n"
		"<div class=\"fundo\"></div><div class=\"texto\">\r\n",
		sizeof(buffer));
		      //acrescenta as informações do S.O.
		      versaoso(buffer, sizeof(buffer));
		strncat(buffer,   
		"</div>\r\n"
		"</div>\r\n",
		sizeof(buffer));

		//div com informações sobre memoria RAM
		strncat(buffer,      
		"<div class=\"float-left\" style=\"width:400px\">\r\n"
		"<div class=\"fundo\"></div><div class=\"texto\">\r\n",
		sizeof(buffer));
		      //acrescenta as informações sobre memoria RAM
		      numprocessos(buffer, sizeof(buffer));
		strncat(buffer,   
		"</div>\r\n"
		"</div>\r\n",
		sizeof(buffer));

		//div com informações sobre quantidade de processos e tempo de atividade
		strncat(buffer,      
		"<div class=\"float-right\" style=\"width:400px\">\r\n"
		"<div class=\"fundo\"></div><div class=\"texto\">\r\n",
		sizeof(buffer));
		      //informações sobre quantidade de processos e tempo de atividade
		      infomemoria(buffer, sizeof(buffer));
		strncat(buffer,   
		"</div>\r\n"
		"</div>\r\n",
		sizeof(buffer));

		segmento_final(buffer, sizeof(buffer));

    		mg_printf_data(conn, buffer);

    		return MG_TRUE;
    	}
    default: return MG_FALSE;
  }
}

int startHTTP(void) {
  struct mg_server *server;

  // Create and configure the server
  server = mg_create_server(NULL, ev_handler);
  mg_set_option(server, "document_root", ".");
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

