#include "window.hpp"

WoxEngine::Window::Window(int w, int h, int fps, char* t) : width(w), height(h) {
	title = t;
	maxMillis = int(1000 / fps);

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
	target->draw();
	SDL_RenderPresent(rend);
}

void WoxEngine::Window::setTarget(WoxEngine::State* s) {
	target = s;
}

WoxEngine::State* WoxEngine::Window::getTarget() {
	return target;
}

void WoxEngine::Window::processEvents() {
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				quitRequested = true;
				break;
			default:
				input.handleEvent(target, &event);
				break;
		}
	}
}

bool WoxEngine::Window::shouldQuit() {
	return quitRequested;
}


// updating function

void WoxEngine::Window::update(int millis) {
	target->update(float(millis / 1000.0));
}


// game loop

void WoxEngine::Window::runGameLoop() {
	// peut être optimisée, c'est sûr.
	int startTime = 0, remainingTime = 0, lastTick = SDL_GetTicks();
	while(!shouldQuit()) {
		startTime = SDL_GetTicks();
		processEvents();
		update(SDL_GetTicks() - lastTick);
		lastTick = SDL_GetTicks();
		redraw();
		remainingTime = maxMillis - startTime + SDL_GetTicks();
		if(remainingTime > 0) SDL_Delay(remainingTime);
	}
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