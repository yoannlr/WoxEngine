#include "font.hpp"
#include <cstring>

// #include "../util.cpp"

char* WoxEngine::FONT_UPPER = (char*) "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* WoxEngine::FONT_LOWER = (char*) "abcdefghijklmnopqrstuvwxyz";
char* WoxEngine::FONT_NUMBERS = (char*) "0123456789";
char* WoxEngine::FONT_SYMBOLS = (char*) "'.?!:/,;<>&~#{}()[]-|_@+=%*";
char* WoxEngine::FONT_FULL = (char*) "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'.?!:/,;<>&~#{}()[]-|_@+=%*";

WoxEngine::Font::Font(WoxEngine::Image* _charmap, char* _chars, Uint32 separator) {
	charmap = _charmap;
	chars = _chars;
	imgpos.resize(strlen(chars) + 1);
	int charindex = 0;
	int x = 0;

	for(x = 0; x < charmap->width; x++) {
		if(charmap->getPixel(x, 0) == separator) {
			if(*(chars + charindex)) {
				imgpos[charindex] = x;
				charpos[*(chars + charindex)] = charindex;
				charindex++;
				charmap->setPixel(x, 0, 0x00000000);
			} else {
				fprintf(stderr, "WoxEngine::Font::Font - Font contains more characters than specified\n");
				break;
			}
		}
	}

	imgpos[charindex] = charmap->width;

	// printMap(charpos);
	// printVector(imgpos);
}

WoxEngine::Font::~Font() {
	// Font : "Not my job to delete the image, you've loaded it elsewhere ! Nya ~"
}

WoxEngine::Rectangle WoxEngine::Font::getRenderRect(char c) {
	SDL_Rect r;
	if(charpos.find(c) == charpos.end()) {
		r = {-1, 0, 0, 0};
		// fprintf(stderr, "WoxEngine::Font::getRenderRect - Character %c not supported by font\n", c);
	}
	else r = {imgpos[charpos[c]], 0, imgpos[charpos[c] + 1] - imgpos[charpos[c]], charmap->height};
	return r;
}