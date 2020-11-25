all: main
run: main
	./wox
main: main.cpp window.o
	g++ -Wall -lSDL2 -o wox *.o main.cpp
window.o: state.o window.hpp window.cpp input.hpp input.cpp
	g++ -Wall -c window.cpp input.cpp
state.o: state.hpp state.cpp
	g++ -Wall -c state.cpp
clean:
	rm *.o wox