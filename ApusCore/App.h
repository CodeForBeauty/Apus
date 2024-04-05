#pragma once
#include "Window.h"
#include "Renderer.h"

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

		void Start();
		void Tick();
	};
}