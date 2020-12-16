namespace WoxEngine {
	class Animation;
}

class WoxEngine::Animation {
	public:
		virtual void setStep(int) = 0;
		virtual bool next() = 0;
		virtual bool prev() = 0;
		virtual void reset() = 0;
		virtual void terminate() = 0;
		virtual bool update(float) = 0;
};