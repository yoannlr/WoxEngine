#include "window.hpp"

WoxEngine::Window::Window(int w, int h, char* t) : width(w), height(h) {
	title = t;

	win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if(!win) {
		fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	rend  = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!rend) {
		fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

WoxEngine::Window::~Window() {
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
}

void WoxEngine::Window::redraw() {
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	SDL_RenderClear(rend);
	(*drawFuncPtr)();
	SDL_RenderPresent(rend);
}

void WoxEngine::Window::setDrawFunc(void (*dfPtr)()) {
	drawFuncPtr = dfPtr;
}

void WoxEngine::Window::processEvents() {
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				quitRequested = true;
				break;
			case SDL_KEYDOWN:
				kbe = &event.key;
				keyStates[kbe->keysym.sym] = true;
				// envoyer keyPressed(kbe->keysym.sym) à currentState
				break;
			case SDL_KEYUP:
				kbe = &event.key;
				keyStates[kbe->keysym.sym] = false;
				// envoyer keyReleased(kbe->keysym.sym) à currentState
				break;
		}
	}
}

bool WoxEngine::Window::shouldQuit() {
	return quitRequested;
}


// keyboard related functions

bool WoxEngine::Window::isKeyDown(char key) {
	return keyStates[int(key)];
}


// drawing functions

void WoxEngine::Window::setColor(Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetRenderDrawColor(rend, r, g, b, 255);
}

void WoxEngine::Window::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_SetRenderDrawColor(rend, r, g, b, a);
}

void WoxEngine::Window::fillRectangle(int x, int y, int w, int h) {
	SDL_Rect rect = {x, y, w, h};
	SDL_RenderFillRect(rend, &rect);
}