ARGS=-lglut -lGLU -lGL -Wall -lm
CC = clang

all: Exe1 Exe2

Exe1:
	$(CC) Exe01.c -o 1gl $(ARGS)

Exe2:
	$(CC) Exe02.c -o 2gl $(ARGS)
