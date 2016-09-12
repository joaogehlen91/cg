all:
	g++ -Wall $(var).cpp -o $(var) -lglut -lGL -lGLU -lm

clean:
	rm $(var)