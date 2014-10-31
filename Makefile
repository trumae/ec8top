CC=gcc

FLAGS = -Wall -lpthread

all: 
	$(CC) oc8top.c mongoose.c versaoso.c -o oc8top $(FLAGS) 


clean:
	rm -rf *~ main *o *a
