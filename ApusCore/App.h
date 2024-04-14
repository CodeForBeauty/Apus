#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Sprite.h"


namespace ApusCore {
	class App {
	private:
		double lastTime = 0;
	protected:
		Window window;
		Renderer renderer;
	public:
		double time = 0, delta = 0;

		App() : renderer(Renderer()), window(Window()){
			renderer.Init();
		}

		void Init();

		virtual void Start();
		virtual void Tick();
		virtual void End();

		void AddSprite(Sprite* newSprite);
	};
}