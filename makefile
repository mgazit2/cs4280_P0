#MAKEFILE
#MATAN GAZIT

CC = gcc
CFLAGS = -Wall -g -std=gnu99

EXE = P0
OBJ = main.o tree.o traversals.o
OUT = $(EXE)

.SUFFIXES: .c .o
.PHONY: all clean

all: $(OUT)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	 /bin/rm -rf *.o output.*
