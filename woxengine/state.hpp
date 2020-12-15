#include <SDL2/SDL.h>

namespace WoxEngine {
	class Window;
	class State;
}

class WoxEngine::State {
	public:
		WoxEngine::Window* win;
		State(WoxEngine::Window*);
		virtual ~State() = 0;
		virtual void update(float) = 0;
		virtual void draw() = 0;
		virtual void keyPressed(char) = 0;
		virtual void keyReleased(char) = 0;
		virtual void mouseClicked(Uint8) = 0;
		virtual void mouseReleased(Uint8) = 0;
};