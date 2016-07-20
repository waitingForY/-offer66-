.PHONY:clean all
CC=g++
CFLAGS=-Wall -g
BIN=main

all:$(BIN)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
