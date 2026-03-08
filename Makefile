#Makefile

all: main

CC = g++
CFLAGS = -Wall -std=c++11
OFILES = main.o

main.o: main.cc
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

 