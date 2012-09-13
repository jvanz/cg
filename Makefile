ARGS=-lglut -lGLU -lGL -Wall -lm
CC=gcc

all: Exe1 Exe2 Exe3

Exe1:
	$(CC) Exe01.c -o 1gl $(ARGS)

Exe2:
	$(CC) Exe02.c -o 2gl $(ARGS)

Exe3:
	$(CC) Exe03.c -o 3gl $(ARGS)

Exe4:
	$(CC) n2/Exe04.c -o 4gl $(ARGS)

Exe6:
	$(CC) Exe06.c -o 6gl $(ARGS)
