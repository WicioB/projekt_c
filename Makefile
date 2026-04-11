all:
	gcc -Wall --pedantic algorithm.c graph.c main.c -o graph -lm
test: all