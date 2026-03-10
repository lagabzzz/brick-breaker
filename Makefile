#Makefile

all: lecture

CC = g++
CFLAGS = -Wall -std=c++11
OFILES = lecture.o

lecture.o: lecture.cc
	$(CC) $(CFLAGS) -c $< -o $@

lecture: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

 