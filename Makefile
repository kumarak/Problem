
CC = g++
CFLAGS = -Wall -g
OBJS = Audio.o Host.o

libAudio.a: $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

main: libAudio.a
	$(CC) $(CFLAGS) main.o -L ./  -o $@

hello.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o libAudio.a main

all: main 
	.PHONY: all clean
