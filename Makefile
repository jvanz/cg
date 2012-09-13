ARGS=-lglut -lGLU -lGL -Wall -lm
CC=gcc

all: Exe1 Exe2 Exe3 Exe4 Exe6

Exe1:
	$(CC) n2/Exe01.c -o 1gl $(ARGS)

Exe2:
	$(CC) n2/Exe02.c -o 2gl $(ARGS)

Exe3:
	$(CC) n2/Exe03.c -o 3gl $(ARGS)

Exe4:
	$(CC) n2/Exe04.c -o 4gl $(ARGS)

Exe6:
	$(CC) n2/Exe06.c -o 6gl $(ARGS)
