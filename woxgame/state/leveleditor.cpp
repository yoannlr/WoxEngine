#include "../woxworld/world.hpp"

namespace WoxGame {
	class LevelEditor;
}

class WoxGame::LevelEditor : public WoxEngine::State {
	public:
		WoxWorld::World* level;
		LevelEditor(WoxEngine::Window* _win) : WoxEngine::State(_win) {

		}
		~LevelEditor() {}
		void update(float delta) {}
		void draw() {}
		void keyPressed(char c) {}
		void keyReleased(char c) {}
		void mouseClicked(Uint8 b) {}
		void mouseReleased(Uint8 b) {}
}