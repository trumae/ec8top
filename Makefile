# compilador
MM=g++#se a compilação com o gcc acarretar em erro, e a compilação com o g++ ocorrer corretamente, significa que existe algum comando em c++ na biblioteca 
CC=gcc
# variaveis com diretorios
LIB=./#./lib/
INCLUDE=./#./include/
SRC=#./src/
OBJ=#./obj/
DIR=#./
# opcoes de compilacao
LIBFLAGS = -lversaoso -lbateria
FLAGS = -Wall -lpthread
all: versaoso bateria
	$(CC) $(SRC)$(DIR)oc8top.c $(SRC)$(DIR)mongoose.c $(FLAGS) -I$(INCLUDE) -L$(LIB) $(LIBFLAGS) -o main
versaoso:
	$(CC) -c $(SRC)$(DIR)versaoso.c $(FLAGS) -I$(INCLUDE) -o $(OBJ)$(DIR)versaoso.o
	ar -cru $(LIB)$(DIR)libversaoso.a $(OBJ)$(DIR)versaoso.o
bateria:
	$(CC) -c $(SRC)$(DIR)bateria.c $(FLAGS) -I$(INCLUDE) -o $(OBJ)$(DIR)bateria.o
	ar -cru $(LIB)$(DIR)libbateria.a $(OBJ)$(DIR)bateria.o	
clean:
	rm -rf *~ main *o *a