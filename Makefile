CC = g++
CFLAGS = -Wall -Wextra -lSDL2
EXEC = wox


all: main.cpp world extras
	$(CC) $(CFLAGS) -o $(EXEC) *.o main.cpp

world: engine woxworld/world.hpp woxworld/world.cpp woxworld/tile.hpp woxworld/tile.cpp
	$(CC) $(CFLAGS) -c woxworld/world.cpp woxworld/tile.cpp

extras: engine woxengine/animation.hpp woxengine/animatedtext.cpp woxengine/spritesheet.hpp woxengine/spritesheet.cpp
	$(CC) $(CFLAGS) -c woxengine/spritesheet.cpp
	$(CC) $(CFLAGS) -c woxengine/animatedtext.cpp

engine: state font woxengine/window.hpp woxengine/window.cpp woxengine/input.hpp woxengine/input.cpp
	$(CC) $(CFLAGS) -c woxengine/window.cpp
	$(CC) $(CFLAGS) -c woxengine/input.cpp

font: image woxengine/font.cpp woxengine/font.hpp
	$(CC) $(CFLAGS) -c woxengine/font.cpp

image: woxengine/image.hpp woxengine/image.cpp
	$(CC) $(CFLAGS) -c woxengine/image.cpp

state: woxengine/state.hpp woxengine/state.cpp
	$(CC) $(CFLAGS) -c woxengine/state.cpp

clean:
	rm *.o $(EXEC)