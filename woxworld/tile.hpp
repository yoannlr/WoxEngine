namespace WoxWorld {
	class Tile;
}

class WoxWorld::Tile {
	public:
		Uint16 tile;
		Uint8 variant;
		Tile(int, int);
		~Tile();
};

const WoxWorld::Tile null_tile(false);