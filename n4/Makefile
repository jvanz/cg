CC = g++
ARGS = -Wall -lglut -lGLU -lGL -lm
FILES = tentativa.cpp glm.cpp

all:
	$(CC) $(FILES) $(ARGS) -o n4 

clean:
	rm n4 t terra

debug:
	$(CC) $(FILES) $(ARGS) -o n4 -g

t:
#	rm t
	$(CC) tentativa.cpp glm.cpp $(ARGS) -o t
