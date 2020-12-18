#ifndef image_h
#define image_h

#include <SDL2/SDL.h>

namespace WoxEngine {
	class Image;
	typedef SDL_Rect Rectangle;
}

class WoxEngine::Image {
	public:
		SDL_Texture* tex;
		SDL_Surface* surf;
		int width, height;
		Image(SDL_Texture*, SDL_Surface*);
		~Image();
		Uint32 getPixel(int, int);
		void setPixel(int, int, Uint32);
};

#endif