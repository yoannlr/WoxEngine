#include "animation.hpp"
#include <cstring>
#include <iostream>

namespace WoxEngine {
	class AnimatedText;
}

// This is only a test. It may not be included for future releases.

class WoxEngine::AnimatedText : public WoxEngine::Animation {
	public:
		float speed, ellapsed;
		char* source;
		char* current;
		int sourceIndex = 0, currentIndex = 0;
		AnimatedText(char* _source, float _speed) {
			source = _source;
			speed = _speed;
			current = new char[strlen(source) + 1];
			*current = 0;
		}
		void setStep(int step) {
			reset();
			int i = 0;
			while(i < step && !next()) i++;
		}
		bool next() {
			char c;
			if((c = *(source + sourceIndex))) {
				if(c != '\\') {
					*(current + currentIndex) = c;
					*(current + currentIndex + 1) = 0;
					currentIndex++;
				}
				sourceIndex++;
			} else return true;
			return false;
		}
		bool prev() {
			setStep(sourceIndex - 1);
			return (sourceIndex == 0);
		}
		void reset() {
			currentIndex = 0;
			sourceIndex = 0;
			*current = 0;
		}
		void terminate() {
			while(!next()) {}
		}
		bool update(float delta) {
			ellapsed += delta;
			if(ellapsed >= speed) {
				ellapsed -= speed;
				return next();
			}
			return false;
		}
};