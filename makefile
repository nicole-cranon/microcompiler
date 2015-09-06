# nicole cranon <nicole.cranon@ucdenver.edu>
# csci 4640, fall 2015
# assignment 3 - microcompiler - a simple adhoc compiler
# makefile

CC=g++
CFLAGS=-c -Wall 
INC=-I ./include -I ./src/microparser/include -I ./src/microparser/src/microscanner/include

compile: main.o compiler.o parser.o scanner.o 
	$(CC) main.o compiler.o parser.o scanner.o -o compile

main.o: ./src/main.cpp
	$(CC) $(INC) -c ./src/main.cpp -o main.o

compiler.o: ./src/compiler.cpp
	$(CC) $(INC) -c ./src/compiler.cpp -o compiler.o

parser.o: ./src/microparser/src/parser.cpp
	$(CC) $(INC) -c ./src/microparser/src/parser.cpp -o parser.o

scanner.o: ./src/microparser/src/microscanner/src/scanner.cpp
	$(CC) $(INC) -c ./src/microparser/src/microscanner/src/scanner.cpp -o scanner.o

clean:
	rm *.o; rm compile
