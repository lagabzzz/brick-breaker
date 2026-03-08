#Makefile

all: test

test.o: test.cc
	g++ -c test.cc -o test.o

test: test.o
	g++ test.o -o test

 