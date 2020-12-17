#ifndef incl_image
#include "image.hpp"
#define incl_image
#endif

namespace WoxEngine {
	class Spritesheet;
}

class WoxEngine::Spritesheet {
	public:
		WoxEngine::Image* spritesheet;
		int spriteW, spriteH, nSprites;
		Spritesheet(WoxEngine::Image*, int, int);
		WoxEngine::Rectangle getSprite(int);
};