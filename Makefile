# compilador
MM=g++#se a compilação com o gcc acarretar em erro, e a compilação com o g++ ocorrer corretamente, significa que existe algum comando em c++ na biblioteca 
CC=gcc
# variaveis com diretorios
LIB=/#./lib/
INCLUDE=/#./include/
SRC=#./src/
OBJ=#./obj/
DIR=#/
# opcoes de compilacao
LIBFLAGS = -lversaoso
FLAGS = -Wall -lpthread
all: versaoso
	$(CC) $(SRC)$(DIR)oc8top.c $(SRC)$(DIR)mongoose.c $(FLAGS) -I$(INCLUDE) -L$(LIB) $(LIBFLAGS) -o main
versaoso:
	$(CC) -c $(SRC)$(DIR)versaoso.c $(FLAGS) -I$(INCLUDE) -o $(OBJ)$(DIR)versaoso.o
	ar -cru $(LIB)$(DIR)libversaoso.a $(OBJ)$(DIR)versaoso.o
clean:
	rm -rf *~ main *o *a