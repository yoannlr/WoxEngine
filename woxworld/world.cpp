#include "world.hpp"

WoxWorld::World::World(int w, int h) : width(w), height(h) {
	tiles.resize(width);
	for(int x = 0; x < width; x++) tiles[x].resize(height);
}

WoxWorld::World::~World() {
}

void WoxWorld::World::update(float dt) {}

void WoxWorld::World::render(WoxEngine::Window* w) {

}

bool WoxWorld::World::addTile(int x, int y, WoxWorld::Tile t) {
	if(x < 0 || x > width || y < 0 || y > height) return false;
	tiles[x][y] = t;
	// TODO - update tiles adjacentes
	return true;
}