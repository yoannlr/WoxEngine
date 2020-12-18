#ifndef window_h
#define window_h

#include <SDL2/SDL.h>

#include "state.hpp"
#include "image.hpp"
#include "input.hpp"
#include "font.hpp"

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
		void quit();
		bool shouldQuit();
		void resize(float);
		void screenshot();

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
		void renderScale(float);

		// images
		WoxEngine::Image* loadImage(const char*);
		void drawImage(WoxEngine::Image*, int, int);
		void drawImage(WoxEngine::Image*, int, int, int, int, int, int);
		void drawImage(WoxEngine::Image*, int, int, double);
		void drawImage(WoxEngine::Image*, int, int, double, int, int, int, int);
		void drawImage(WoxEngine::Image*, int, int, double, WoxEngine::Rectangle*);
		void drawImage(WoxEngine::Image*, int, int, double, WoxEngine::Rectangle);

		// text
		int drawText(WoxEngine::Font*, char*, int, int, int);
};

#endif