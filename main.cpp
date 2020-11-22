#include <iostream>
#include "window.hpp"

class StateExample : public WoxEngine::State {
	void update(WoxEngine::Window* win, float dt) {
		// std::cout << "update with dt=" << dt << std::endl;
		if(win->isKeyDown('a')) std::cout << "a" << std::endl;
	}
	void draw(WoxEngine::Window* win) {
		win->setColor(255, 0, 0);
		win->fillRectangle(100, 50, 100, 150);
	}
	void keyPressed(char c) {
		// std::cout << "keyPressed=" << c << std::endl;
	}
	void keyReleased(char c) {}
};

int main(int argc, char* argv[]) {
	if(SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	WoxEngine::Window win(640, 360, 60, (char*)"test");
	StateExample* s = new StateExample();
	win.setTarget(s);
	win.runGameLoop();

	SDL_Quit();

	return EXIT_SUCCESS;
}