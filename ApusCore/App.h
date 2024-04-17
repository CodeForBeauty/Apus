#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Camera.h"

namespace ApusCore {
	class App {
	private:
		double lastTime = 0;
	protected:
		Window window;
		Renderer renderer;
		Camera camera;
	public:
		double time = 0, delta = 0;

		App() : renderer(Renderer()), window(Window()), camera(Camera(lm::vec2(), 0)) {
			renderer.Init();
		}

		void Init();

		virtual void Start();
		virtual void Tick();
		virtual void End();

		void AddSprite(Sprite* newSprite);
	};
}