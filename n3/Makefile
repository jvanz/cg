CC = g++
ARGS = -Wall -lglut -lGLU -lGL -lm -lvart
FILES = main.cpp objetografico.cpp poligno.cpp mundo.cpp bbox.cpp

all:
	$(CC) $(FILES) $(ARGS) -o n3 

clean:
	rm n3

doxy:
	doxygen Doxyfile

debug:
	$(CC) $(FILES) $(ARGS) -o n3 -g
