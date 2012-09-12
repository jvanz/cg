ARGS=-lglut -lGLU -lGL -Wall -lm
CC = clang
all:
	$(CC) Exe01.c -o gl $(ARGS)
