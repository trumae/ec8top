#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>//http://www.scs.stanford.edu/histar/src/pkg/uclibc/include/sys/utsname.h
#include "versaoso.h"
int versaoso(char *b, size_t s) {//Função mostra na tela os dados da versão do sistema
  struct utsname my_uname;
  if(uname(&my_uname) == -1){
    	printf("uname call failed!");  
	return -1;
  }else{   
    char buffer[500];
    buffer[0] = '\x0';
    snprintf(buffer,500, "S.O.: %s<br>Nome personalizado: %s<br>Release: %s<br>Versão: %s<br>Arquitetura: %s<br>",
       my_uname.sysname, my_uname.nodename, my_uname.release,my_uname.version,my_uname.machine);
    strncat(b, "<h4>Versão do Sistema Operacional</h4>", s);
    strncat(b, buffer, s);
  }
	return 1;
}