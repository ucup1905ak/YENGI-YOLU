CC = gcc
CFLAGS=-I.
DEPS = header.h


all: main run
main: main.o source.o
	$(CC) -o main main.o source.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run:
	./main.exe