all: main
run: main
	./wox
main: main.cpp window.o
	g++ -Wall -lSDL2 -o wox *.o main.cpp
window.o: window.hpp window.cpp
	g++ -Wall -c window.cpp
clean:
	rm *.o wox