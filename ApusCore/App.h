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

		void Start();
		virtual void Tick();

		Sprite* CreateSprite(lm::vec4 tint = { 1, 1, 1, 1 }, lm::vec3 scale = { 1, 1, 1 }, lm::vec3 position = { 0, 0, 0 }, float rotation = 0, lm::vec2 tiling = { 1, 1 });
	};
}