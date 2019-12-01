CC=gcc
OBJECTS_MAIN=myBank.o main.o
FLAGS= -Wall -g -fPIC

all: main	
main: $(OBJECTS_MAIN)
		$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) -lm
myBank.o: myBank.c myBank.h
		$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h 
		$(CC) $(FLAGS) -c main.c
	
.PHONY: clean all
	
clean:
		rm -f *.o main
