#ifndef incl_image
#include "image.hpp"
#define incl_image
#endif

#include <map>
#include <vector>

namespace WoxEngine {
	class Font;
}

class WoxEngine::Font {
	public:
		WoxEngine::Image* charmap;
		char* chars;
		std::map<char, int> charpos;
		std::vector<int> imgpos;
		Font(WoxEngine::Image*, char*, Uint32);
		~Font();
		SDL_Rect getRenderRect(char);
};