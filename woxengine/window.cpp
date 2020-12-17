#include "window.hpp"

WoxEngine::Window::Window(int w, int h, int fps, char* t) : width(w), height(h) {
	title = t;
	maxMillis = int(1000 / fps);

	win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if(!win) {
		fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	rend  = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!rend) {
		fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

WoxEngine::Window::~Window() {
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
}

void WoxEngine::Window::redraw() {
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	SDL_RenderClear(rend);
	target->draw();
	SDL_RenderPresent(rend);
}

void WoxEngine::Window::setTarget(WoxEngine::State* s) {
	target = s;
}

WoxEngine::State* WoxEngine::Window::getTarget() {
	return target;
}

void WoxEngine::Window::processEvents() {
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				quitRequested = true;
				break;
			default:
				input.handleEvent(target, &event);
				break;
		}
	}
}

void WoxEngine::Window::quit() {
	quitRequested = true;
}

bool WoxEngine::Window::shouldQuit() {
	return quitRequested;
}

void WoxEngine::Window::resize(float factor) {
	SDL_SetWindowSize(win, int(width * factor), int(height * factor));
	SDL_RenderSetScale(rend, factor, factor);
}

void WoxEngine::Window::screenshot() {
	int w, h;
	SDL_GetWindowSize(win, &w, &h);
	SDL_Surface *sshot = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(rend, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
	SDL_SaveBMP(sshot, "screenshot.bmp");
	SDL_FreeSurface(sshot);
}


// updating function

void WoxEngine::Window::update(int millis) {
	target->update(float(millis / 1000.0));
}


// game loop

void WoxEngine::Window::runGameLoop() {
	// peut être optimisée, c'est sûr.
	int startTime = 0, remainingTime = 0, lastTick = SDL_GetTicks();
	while(!shouldQuit()) {
		startTime = SDL_GetTicks();
		processEvents();
		update(SDL_GetTicks() - lastTick);
		lastTick = SDL_GetTicks();
		redraw();
		remainingTime = maxMillis - startTime + SDL_GetTicks();
		if(remainingTime > 0) SDL_Delay(remainingTime);
	}
}


// drawing functions

void WoxEngine::Window::setColor(Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetRenderDrawColor(rend, r, g, b, 255);
}

void WoxEngine::Window::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_SetRenderDrawColor(rend, r, g, b, a);
}

void WoxEngine::Window::fillRectangle(int x, int y, int w, int h) {
	SDL_Rect rect = {x, y, w, h};
	SDL_RenderFillRect(rend, &rect);
}

void WoxEngine::Window::renderScale(float factor) {
	SDL_RenderSetScale(rend, factor, factor);
}

WoxEngine::Image* WoxEngine::Window::loadImage(const char* path) {
	SDL_Surface* surf = SDL_LoadBMP(path);
	if(surf == NULL) {
		fprintf(stderr, "SDL_LoadBMP failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surf);
	if(tex == NULL) {
		fprintf(stderr, "SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	return new WoxEngine::Image(tex, surf);
}

void WoxEngine::Window::drawImage(WoxEngine::Image* img, int x, int y) {
	SDL_Rect r = {x, y, img->width, img->height};
	SDL_RenderCopy(rend, img->tex, NULL, &r);
}

void WoxEngine::Window::drawImage(WoxEngine::Image* img, int x, int y, int cropX, int cropY, int cropW, int cropH) {
	SDL_Rect src = {cropX, cropY, cropW, cropH};
	SDL_Rect dst = {x, y, cropW, cropH};
	SDL_RenderCopy(rend, img->tex, &src, &dst);
}

void WoxEngine::Window::drawImage(WoxEngine::Image* img, int x, int y, double rot) {
	SDL_Rect r = {x, y, img->width, img->height};
	SDL_RenderCopyEx(rend, img->tex, NULL, &r, rot, NULL, SDL_FLIP_NONE);
}

void WoxEngine::Window::drawImage(WoxEngine::Image* img, int x, int y, double rot, int cropX, int cropY, int cropW, int cropH) {
	SDL_Rect src = {cropX, cropY, cropW, cropH};
	SDL_Rect dst = {x, y, cropW, cropH};
	SDL_RenderCopyEx(rend, img->tex, &src, &dst, rot, NULL, SDL_FLIP_NONE);
}

void WoxEngine::Window::drawImage(WoxEngine::Image* img, int x, int y, double rot, WoxEngine::Rectangle* crop) {
	SDL_Rect dst = {x, y, crop->w, crop->h};
	SDL_RenderCopyEx(rend, img->tex, crop, &dst, rot, NULL, SDL_FLIP_NONE);
}

void WoxEngine::Window::drawImage(WoxEngine::Image* img, int x, int y, double rot, WoxEngine::Rectangle crop) {
	SDL_Rect dst = {x, y, crop.w, crop.h};
	SDL_RenderCopyEx(rend, img->tex, &crop, &dst, rot, NULL, SDL_FLIP_NONE);
}

// text

int WoxEngine::Window::drawText(WoxEngine::Font* font, char* text, int x, int y, int lineHeight = 0) {
	int maxX = x;
	int currentX = x;
	int currentY = y;
	int textIndex = 0;
	SDL_Rect rect;

	Uint8 r, g, b;
	SDL_GetRenderDrawColor(rend, &r, &g, &b, nullptr);
	SDL_SetTextureColorMod(font->charmap->tex, r, g, b);

	while(*(text + textIndex)) {
		if(*(text + textIndex) == '\n') {
			if(currentX > maxX) maxX = currentX;
			currentX = x;
			currentY += font->charmap->height + lineHeight;
		} else if((rect = font->getRenderRect(*(text + textIndex))).x != -1) {
			drawImage(font->charmap, currentX, currentY, 0, &rect);
			currentX += rect.w;
		}
		textIndex++;
	}
	return maxX;
}