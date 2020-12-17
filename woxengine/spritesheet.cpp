#include "spritesheet.hpp"

WoxEngine::Spritesheet::Spritesheet(WoxEngine::Image* img, int _sw, int _sh) :
	spriteW(_sw), spriteH(_sh) {
		spritesheet = img;
		if(spritesheet->width < spriteW || spritesheet->height < spriteH)
			fprintf(stderr, "WoxEngine::Spritesheet - Warn - Spritesheet image is smaller than one sprite\n");
		nSprites = spritesheet->width / spriteW;
		fprintf(stdout, "WoxEngine::Spritesheet - Info - Spritesheet contains %d sprites\n", nSprites);
}

WoxEngine::Rectangle WoxEngine::Spritesheet::getSprite(int n) {
	SDL_Rect r = {0, 0, spriteW, spriteH};
	if(n > nSprites) return r;
	else {
		r.x = n * spriteW;
		return r;
	}
}