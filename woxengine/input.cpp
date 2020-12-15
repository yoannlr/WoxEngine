#include <iostream>

#include "input.hpp"

WoxEngine::Input::Input() {}

void WoxEngine::Input::handleEvent(WoxEngine::State* t, SDL_Event* e) {
	switch(e->type) {
		case SDL_KEYDOWN:
			kbe = &(e->key);
			keyStates[kbe->keysym.sym] = true;
			t->keyPressed(char(kbe->keysym.sym));
			break;
		case SDL_KEYUP:
			kbe = &(e->key);
			keyStates[kbe->keysym.sym] = false;
			t->keyReleased(char(kbe->keysym.sym));
			break;
		case SDL_MOUSEBUTTONDOWN:
			mbe = &(e->button);
			mouseButtonStates[mbe->button] = true;
			t->mouseClicked(mbe->button);
			break;
		case SDL_MOUSEBUTTONUP:
			mbe = &(e->button);
			mouseButtonStates[mbe->button] = false;
			t->mouseClicked(mbe->button);
			break;
		case SDL_MOUSEMOTION:
			mme = &(e->motion);
			mouseX = mme->x;
			mouseY = mme->y;
			break;
	}
}

bool WoxEngine::Input::isKeyDown(char key) {
	return keyStates[int(key)];
}

bool WoxEngine::Input::isMouseClicked(Uint8 btn) {
	return mouseButtonStates[btn];
}

int WoxEngine::Input::getMouseX() {
	return mouseX;
}

int WoxEngine::Input::getMouseY() {
	return mouseY;
}