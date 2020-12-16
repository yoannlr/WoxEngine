#include <iostream>
#include "woxworld/world.hpp"

class StateExample : public WoxEngine::State {
	WoxEngine::Image* test;
	WoxEngine::Image* fontImg;
	WoxEngine::Font* font;
	public:
		StateExample(WoxEngine::Window* _win) : WoxEngine::State(_win) {
			test = win->loadImage("tree.bmp");
			// Uint32 col = test->getPixel(0, 0);
			// printf("%x\n", col);
			// test->setPixel(0, 0, 0xFFFF0000);
			fontImg = win->loadImage("font.bmp");
			font = new WoxEngine::Font(fontImg, (char*) "abcdef", 0xFF000000);
		}
		~StateExample() {
			std::cout << "StateExample destructor" << std::endl;
			delete test;
			delete font;
			delete fontImg;
		}
		void update(float dt) {
			// std::cout << "update with dt=" << dt << std::endl;
			if(win->input.isKeyDown('a')) std::cout << "a" << std::endl;
		}
		void draw() {
			win->setColor(255, 0, 0);
			// win->fillRectangle(100, 50, 100, 150);
			win->drawImage(test, 200, 100);
			win->drawImage(test, 400, 200, 45.0, 24, 24, 24, 24);
			win->fillRectangle(win->drawText(font, (char*) "abcdefge\nblep", 10, 10, 0), 10, 5, 5);
		}
		void keyPressed(char c) {
			std::cout << "keyPressed=" << c << std::endl;
			if(c == 'p') win->resize(2.0);
			else if(c == 'm') win->resize(1.0);
			else if(c == 's') win->screenshot();
			else if(c == 'q') win->quit();
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