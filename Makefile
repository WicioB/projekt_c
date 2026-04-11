all:
	gcc -Wall --pedantic algorithm.c graph.c main.c -o graph -lm

tests:
	gcc -Wall --pedantic tests/test.c -o tests/test_runner -lm

test: all tests
	cd tests && ./test_runner

clean-test:
	rm -rf tests/out/*