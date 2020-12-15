#include "../woxengine/window.hpp"
#include "tile.hpp"

#include <vector>

namespace WoxWorld {
	class World;
}

class WoxWorld::World {
	public:
		int width, height;
		std::vector<std::vector<WoxWorld::Tile>> tiles;
		World(int, int);
		~World();
		void update(float);
		void render(WoxEngine::Window*);
		bool addTile(int, int, WoxWorld::Tile);
};