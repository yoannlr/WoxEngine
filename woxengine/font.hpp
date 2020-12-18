#ifndef font_h
#define font_h

#include "image.hpp"

#include <map>
#include <vector>

namespace WoxEngine {
	class Font;
	extern char* FONT_UPPER;
	extern char* FONT_LOWER;
	extern char* FONT_NUMBERS;
	extern char* FONT_SYMBOLS;
	extern char* FONT_FULL;
}

class WoxEngine::Font {
	public:
		WoxEngine::Image* charmap;
		char* chars;
		std::map<char, int> charpos;
		std::vector<int> imgpos;
		Font(WoxEngine::Image*, char*, Uint32);
		~Font();
		WoxEngine::Rectangle getRenderRect(char);
};

#endif