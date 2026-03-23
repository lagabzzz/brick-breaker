#Makefile


CC = g++
CFLAGS = -Wall -std=c++11

all: main

message.o: message.cc message.h
	$(CC) $(CFLAGS) -c $< -o $@

tools.o: tools.cc tools.h message.h
	$(CC) $(CFLAGS) -c $< -o $@

ball.o: ball.cc ball.h tools.h constants.h message.h
	$(CC) $(CFLAGS) -c $< -o $@

brick.o: brick.cc brick.h tools.h constants.h message.h
	$(CC) $(CFLAGS) -c $< -o $@ 

paddle.o: paddle.cc paddle.h tools.h constants.h message.h
	$(CC) $(CFLAGS) -c $< -o $@ 	

game.o: game.cc paddle.h brick.h ball.h tools.h constants.h message.h
	$(CC) $(CFLAGS) -c $< -o $@ 	

main.o: main.cc game.h paddle.h brick.h ball.h tools.h constants.h message.h
	$(CC) $(CFLAGS) -c $< -o $@ 

main : game.o paddle.o brick.o ball.o message.o tools.o	main.o
	$(CC) main.o game.o paddle.o brick.o ball.o message.o tools.o -o main