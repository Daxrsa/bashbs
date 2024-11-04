flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean test

test: test.o
    cc $(flags) $^ -o $@ $(ldflags)

test.o: test.c test.h
    cc $(flags) -c $<

clean:
    rm -f *.o test
