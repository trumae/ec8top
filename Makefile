# compilador
CC=gcc
# variaveis com diretorios
LIB=./
INCLUDE=./
# opcoes de compilacao 
LIBFLAGS = -llayout -lversaoso -lbateria -linfomemoria -lnumprocessos -lcpu_usage -lload_avarege -g
FLAGS = -Wall -lpthread
all: layout versaoso bateria memoria processos cpu_usage load_avarege
	$(CC) oc8top.c mongoose.c $(FLAGS) -I$(INCLUDE) -L$(LIB) $(LIBFLAGS) -o oc8top
layout:
	$(CC) -c layout.c $(FLAGS) -I$(INCLUDE) -o layout.o
	ar -cru $(LIB)liblayout.a layout.o
versaoso:
	$(CC) -c versaoso.c $(FLAGS) -I$(INCLUDE) -o versaoso.o
	ar -cru $(LIB)libversaoso.a versaoso.o
bateria:
	$(CC) -c bateria.c $(FLAGS) -I$(INCLUDE) -o bateria.o
	ar -cru $(LIB)libbateria.a bateria.o	
memoria:
	$(CC) -c infomemoria.c $(FLAGS) -I$(INCLUDE) -o infomemoria.o
	ar -cru $(LIB)libinfomemoria.a infomemoria.o	
processos:
	$(CC) -c numprocessos.c $(FLAGS) -I$(INCLUDE) -o numprocessos.o
	ar -cru $(LIB)libnumprocessos.a numprocessos.o
cpu_usage:
	$(CC) -c cpu_usage.c $(FLAGS) -I$(INCLUDE) -o cpu_usage.o
	ar -cru $(LIB)libcpu_usage.a cpu_usage.o
load_avarege:
	$(CC) -c load_avarege.c $(FLAGS) -I$(INCLUDE) -o load_avarege.o
	ar -cru $(LIB)libload_avarege.a load_avarege.o	
clean:
	rm -rf *~ oc8top *o *a
