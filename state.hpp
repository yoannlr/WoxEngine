namespace WoxEngine {
	class Window;
	class State;
}

// pure virtual class

class WoxEngine::State {
	public:
		virtual void update(WoxEngine::Window*, float) = 0;
		virtual void draw(WoxEngine::Window*) = 0;
		virtual void keyPressed(char) = 0;
		virtual void keyReleased(char) = 0;
};