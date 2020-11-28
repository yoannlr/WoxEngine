#include <SDL2/SDL.h>

namespace WoxEngine {
	class Image;
}

class WoxEngine::Image {
	public:
		SDL_Texture* tex;
		int width, height;
		Image(SDL_Texture*);
		~Image();
};