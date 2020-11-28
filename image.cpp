#include "image.hpp"

WoxEngine::Image::Image(SDL_Texture* _t) {
	tex = _t;
	SDL_QueryTexture(tex, NULL, NULL, &width, &height);
}

WoxEngine::Image::~Image() {
	SDL_DestroyTexture(tex);
}