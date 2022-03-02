SOURCE = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SOURCE))

all: 
	gcc -c $(SOURCE)
	gcc -o lab1 $(OBJ)
	rm *.o