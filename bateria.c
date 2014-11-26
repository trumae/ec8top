#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bateria.h"


#define TAMBUFF 500
 

int bateria(char *b, size_t s){
    //buffer que conterá o texto
    char buffer[TAMBUFF];
    buffer[0] = '\x0';
    
    //leitor de arquivos
    FILE *arquivo;
    
    char *linha;
    char buff[TAMBUFF];
    buff[0] = '\x0';
    
    //valor da porcentagem da bateria
    float valor;
    
    //setando o nivel total de bateria
    arquivo = fopen("/sys/class/power_supply/BAT0/charge_full", "r");
    if (arquivo == 0)
      arquivo = fopen("/sys/class/power_supply/BAT0/energy_full", "r");
    if (arquivo == 0)
    {
      strncat(b, "<br><p>Dispositivo Desktop</p>", s); 
      return -1;
    }
      //O nível da bateria não pôde ser lido
      
    //atribuindo o total da bateria a um float
    while (!feof(arquivo)){
	linha = fgets(buff, TAMBUFF, arquivo);
	if (linha != 0){
	    valor = atoi(linha);
	}
    }
    fclose(arquivo);

    //setando o nivel atual de bateria
    arquivo = fopen("/sys/class/power_supply/BAT0/charge_now", "r");
    if (arquivo == 0)
      arquivo = fopen("/sys/class/power_supply/BAT0/energy_now", "r");
    if (arquivo == 0)
    {
      strncat(b, "O arquivo _now nao pode ser lido", s); 
      return -1;
    }
      //O nível da bateria não pôde ser lido    
      
    //atribuindo a carga total ao float
    while (!feof(arquivo)){
	linha = fgets(buff, TAMBUFF, arquivo);
	if (linha != 0){
	    //calculando a porcentagem
	    valor = atoi(linha)/valor*100;
	}
    }
    fclose(arquivo);
    
    
    snprintf(buffer,TAMBUFF, "<h2>Bateria: %.0f%%</h2>", valor);
    strncat(b,
	"<div id='bateria' class=\"coluna\">\r\n"
	"<figure class=\"foto\"><img src=\"images/04.png\"></figure>\r\n"
    ,s);
    snprintf(buffer,TAMBUFF, "<h2>Bateria: %.0f%%</h2>", valor);
    strncat(b,
	buffer
    , s);
    snprintf(buffer,TAMBUFF, "<h2>Bateria: %.0f%%</h2>", valor);
    strncat(b,
	"</div>\r\n" 
    , s);     

    //retorna sucesso
    return 1;
}
