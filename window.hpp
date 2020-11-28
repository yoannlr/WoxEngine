#include <SDL2/SDL.h>

#ifndef incl_state
#include "state.hpp"
#define incl_state 1
#endif
#include "input.hpp"
#include "image.hpp"

namespace WoxEngine {
	class Window;
}

class WoxEngine::Window {
	int width, height;
	char* title;
	SDL_Window* win;
	SDL_Renderer* rend;
	bool quitRequested = false;
	SDL_Event event;
	int maxMillis;

	WoxEngine::State* target;

	public:
		WoxEngine::Input input;

		Window(int, int, int, char*);
		~Window();
		void redraw();
		void processEvents();
		bool shouldQuit();

		void setTarget(WoxEngine::State*);
		WoxEngine::State* getTarget();

		// updating function
		void update(int);

		// game loop
		void runGameLoop();

		// drawing functions
		void setColor(Uint8, Uint8, Uint8);
		void setColor(Uint8, Uint8, Uint8, Uint8);
		void fillRectangle(int, int, int, int);
		WoxEngine::Image* loadImage(const char*);
		void drawImage(WoxEngine::Image*, int, int);
		// TODO - drawImage with more params 
};