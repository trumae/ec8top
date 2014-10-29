#include <stdio.h>
#include <stdlib.h>
#include "mongoose.h"

int processos(char *b, size_t n){
	system("top");

}
int main(int argc, char **argv) {
	fprintf(stdout, "EC8TOP 23-10-14\n");
	char buffer[100];
	processos(buffer,100);

   return EXIT_SUCCESS;
}


