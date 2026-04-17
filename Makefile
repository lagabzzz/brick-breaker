#Makefile

OUT = project
CC = g++
CFLAGS = -Wall -std=c++17
PKGS     := gtkmm-4.0
LINKING  := $(shell pkg-config --cflags $(PKGS))
LDLIBS   := $(shell pkg-config --libs $(PKGS))
OFILES = project.o game.o paddle.o brick.o ball.o message.o tools.o graphic.o gui.o
HFILES = game.h paddle.h brick.h ball.h tools.h constants.h message.h graphic.h gui.h

all: $(OUT)

message.o: message.cc message.h
	$(CC) $(CFLAGS) -c $< -o $@

tools.o: tools.cc tools.h message.h
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@

ball.o: ball.cc ball.h tools.h constants.h message.h
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@

brick.o: brick.cc brick.h tools.h constants.h message.h
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@ 

paddle.o: paddle.cc paddle.h tools.h constants.h message.h
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@ 	

game.o: game.cc paddle.h brick.h ball.h tools.h constants.h message.h
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@ 	

graphic.o: graphic.cc graphic.h
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@

gui.o: gui.cc gui.h graphic.o
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@

project.o: project.cc $(HFILES)
	$(CC) $(CFLAGS) $(LINKING) -c $< -o $@ 

$(OUT): $(OFILES)
	$(CC) $(OFILES) $(LINKING) -o $@ $(LDLIBS)

clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f *.o *.x *.cc~ *.h~ $(OUT)