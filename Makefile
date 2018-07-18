#declare the varibales
CC=g++ -std=c++11


CFLAGS=-c -Wall

all: main

main: main.o 
	$(CC) main.o -o main
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean:
	rm -rf *o main
