#include <SDL2/SDL.h>

namespace WoxEngine {
	class Window;
}

class WoxEngine::Window {
	int width, height;
	char* title;
	SDL_Window* win;
	SDL_Renderer* rend;
	void (*drawFuncPtr)();

	public:
		Window(int, int, char*);
		~Window();
		void redraw();
		void setDrawFunc(void (*)());

		// drawing functions
		void setColor(Uint8, Uint8, Uint8);
		void setColor(Uint8, Uint8, Uint8, Uint8);
		void fillRectangle(int, int, int, int);
};