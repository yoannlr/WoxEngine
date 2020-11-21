#include <iostream>
#include "window.hpp"

WoxEngine::Window* win;

void winRender() {
	win->setColor(255, 0, 0);
	win->fillRectangle(100, 50, 100, 150);
}

int main(int argc, char* argv[]) {
	if(SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	win = new WoxEngine::Window(640, 360, (char*)"test");
	win->setDrawFunc(&winRender);
	win->redraw();

	SDL_Delay(3000);
	SDL_Quit();

	return EXIT_SUCCESS;
}