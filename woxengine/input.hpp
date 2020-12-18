#ifndef input_h
#define input_h

#include <SDL2/SDL.h>
#include <map>

#include "state.hpp"

namespace WoxEngine {
	class State;
	class Input;
	const Uint8 MOUSELEFT = SDL_BUTTON_LEFT;
	const Uint8 MOUSERIGHT = SDL_BUTTON_RIGHT;
	const Uint8 MOUSEMIDDLE = SDL_BUTTON_MIDDLE;
}

class WoxEngine::Input {
	std::map<int, bool> keyStates;
	std::map<int, bool> mouseButtonStates;
	SDL_KeyboardEvent* kbe;
	SDL_MouseButtonEvent* mbe;
	SDL_MouseMotionEvent* mme;
	int mouseX, mouseY;
	public:
		Input();
		void handleEvent(WoxEngine::State*, SDL_Event*);
		bool isKeyDown(char);
		bool isMouseClicked(Uint8);
		int getMouseX();
		int getMouseY();
};

#endif