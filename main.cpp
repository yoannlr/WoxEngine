#include <iostream>
#include "window.hpp"

class StateExample : public WoxEngine::State {
	WoxEngine::Image* test;
	public:
		StateExample(WoxEngine::Window* _win) : WoxEngine::State(_win) {
			test = win->loadImage("tree.bmp");
		}
		void update(float dt) {
			// std::cout << "update with dt=" << dt << std::endl;
			if(win->input.isKeyDown('a')) std::cout << "a" << std::endl;
		}
		void draw() {
			win->setColor(255, 0, 0);
			win->fillRectangle(100, 50, 100, 150);
			win->drawImage(test, 200, 100);
		}
		void keyPressed(char c) {
			std::cout << "keyPressed=" << c << std::endl;
		}
		void keyReleased(char c) {}
		void mouseClicked(Uint8 b) {
			if(b == WoxEngine::MOUSELEFT) std::cout << "leftClick" << std::endl;
			std::cout << win->input.getMouseX() << ", " << win->input.getMouseY() << std::endl;
		}
		void mouseReleased(Uint8 b) {}
};

int main(int argc, char* argv[]) {
	if(SDL_Init(SDL_INIT_VIDEO)) {
		fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	WoxEngine::Window win(640, 360, 60, (char*)"test");
	StateExample* s = new StateExample(&win);
	win.setTarget(s);
	win.runGameLoop();

	SDL_Quit();

	return EXIT_SUCCESS;
}