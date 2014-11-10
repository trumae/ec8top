CC=gcc

FLAGS = -Wall -lpthread

all: 
	$(CC) oc8top.c mongoose.c versaoso.c infomemoria.c numprocessos.c -o oc8top $(FLAGS) 


clean:
	rm -rf *~ main *o *a
