#include "image.hpp"

WoxEngine::Image::Image(SDL_Texture* _t, SDL_Surface* _s) {
	tex = _t;
	surf = _s;
	width = surf->w;
	height = surf->h;
}

WoxEngine::Image::~Image() {
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
}

Uint32 WoxEngine::Image::getPixel(int x, int y) {
	// TODO - Pixels may not always be 32 bits values
	Uint32* pixels = (Uint32*) surf->pixels;
	return pixels[y * width + x];
}

void WoxEngine::Image::setPixel(int x, int y, Uint32 color) {
	// TODO - Pixels may not always be 32 bits values
	Uint32* pixels = (Uint32*) surf->pixels;
	pixels[y * width + x] = color;
	SDL_Rect px_rect = {x, y, 1, 1};
	SDL_UpdateTexture(tex, &px_rect, pixels + y * width + x, sizeof(Uint32));
}