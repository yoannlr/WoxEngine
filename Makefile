all: main
run: main
	./wox
main: main.cpp world animtext
	g++ -Wall -lSDL2 -o wox *.o main.cpp
animtext: woxengine/animation.hpp woxengine/animatedtext.cpp
	g++ -c woxengine/animatedtext.cpp
world: engine woxworld/world.hpp woxworld/world.cpp woxworld/tile.hpp woxworld/tile.cpp
	g++ -Wall -c woxworld/world.cpp woxworld/tile.cpp
engine: state.o font.o woxengine/window.hpp woxengine/window.cpp woxengine/input.hpp woxengine/input.cpp
	g++ -Wall -c woxengine/window.cpp woxengine/input.cpp
font.o: image.o woxengine/font.cpp woxengine/font.hpp
	g++ -Wall -c woxengine/font.cpp
image.o: woxengine/image.hpp woxengine/image.cpp
	g++ -Wall -c woxengine/image.cpp
state.o: woxengine/state.hpp woxengine/state.cpp
	g++ -Wall -c woxengine/state.cpp
clean:
	rm *.o wox