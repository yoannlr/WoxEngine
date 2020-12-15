namespace WoxWorld {
	class Tile;
}

class WoxWorld::Tile {
	public:
		bool solid;
		Tile();
		Tile(bool);
		~Tile();
};

const WoxWorld::Tile null_tile(false);