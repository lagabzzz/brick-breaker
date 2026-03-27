#Makefile


CC = g++
CFLAGS = -Wall -std=c++11

all: project

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

project.o: project.cc game.h paddle.h brick.h ball.h tools.h constants.h message.h
	$(CC) $(CFLAGS) -c $< -o $@ 

project: game.o paddle.o brick.o ball.o message.o tools.o	project.o
	$(CC) project.o game.o paddle.o brick.o ball.o message.o tools.o -o project
clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x *.cc~ *.h~ project