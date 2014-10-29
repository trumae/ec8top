#include <stdio.h>
#include <string.h>
#include "mongoose.h"

int memoria(char *b, size_t n){
	system("df");//comando df para mostrar memória livre
}

static int ev_handler(struct mg_connection *conn, enum mg_event ev) {
  switch (ev) {
    case MG_AUTH: return MG_TRUE;
    case MG_REQUEST:
      mg_send_header(conn, "Content-Type", "text/html");
      mg_printf_data(conn, "<doctype html>"
	"<html>"
        "<header><title>EC8</title></header>"
        "<body>"
        "<center><h1>Galo Doido</h1></center>"
        "</body>"
        "</html>");
      return MG_TRUE;
    default: return MG_FALSE;
  }
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
	
	char buffer[100];
	memoria(buffer,100);
}
