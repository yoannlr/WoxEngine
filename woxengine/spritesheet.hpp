#ifndef image_h
#include "image.hpp"
#define image_h
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