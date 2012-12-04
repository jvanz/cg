CC = clang
ARGS = -lglut -lGLU -lGL -Wall -lm
FILES = *.c

all:
	$(CC) $(FILES) $(ARGS)

transformation:
	$(CC) glm.c transformation.c $(ARGS) -o transformation

projection:
	$(CC) glm.c projection.c $(ARGS) -o projection

shape:
	$(CC) glm.c shapes.c $(ARGS) -o shape

texture:
	$(CC) glm.c texture.c $(ARGS) -o texture
