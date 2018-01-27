all: main test
test: test.cpp
	g++ test.cpp -std=c++17 -pedantic -pedantic-errors -o test
main: main.cpp
	g++ main.cpp -std=c++17 -pedantic -pedantic-errors -o main
clean:
	rm -f test
	rm -f main
