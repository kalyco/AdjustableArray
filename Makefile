CC=g++
CFLAGS=-std=c++0x -g
SRCS=main.cpp Array.cpp AdjustableArray.cpp
EXEC=Array

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC)

clean: 
	rm Array *~ 
