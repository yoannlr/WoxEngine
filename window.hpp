#include <SDL2/SDL.h>
#include <map>

namespace WoxEngine {
	class Window;
}

class WoxEngine::Window {
	int width, height;
	char* title;
	SDL_Window* win;
	SDL_Renderer* rend;
	void (*drawFuncPtr)();
	bool quitRequested = false;
	SDL_Event event;
	SDL_KeyboardEvent* kbe;
	std::map<int, bool> keyStates;

	public:
		Window(int, int, char*);
		~Window();
		void redraw();
		void setDrawFunc(void (*)());
		void processEvents();
		bool shouldQuit();

		// keyboard related functions
		bool isKeyDown(char);

		// drawing functions
		void setColor(Uint8, Uint8, Uint8);
		void setColor(Uint8, Uint8, Uint8, Uint8);
		void fillRectangle(int, int, int, int);
};