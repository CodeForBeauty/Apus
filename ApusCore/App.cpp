#include <string>

#include "App.h"



void ApusCore::App::Init() {
	Start();

	time = glfwGetTime();

	while (!window.ShouldClose()) {
		lastTime = time;
		time = glfwGetTime();
		delta = time - lastTime;
		Tick();
		renderer.Render(window.GetProjection());
		window.Update();
	}

	renderer.Destroy();
	window.Destroy();
	glfwTerminate();
}

void ApusCore::App::Start() {
	std::cout << "App started" << std::endl;
}

void ApusCore::App::Tick() {
	window.RenameWindow(std::to_string(1 / delta).c_str());
}

ApusCore::Sprite* ApusCore::App::CreateSprite(lm::vec4 tint, lm::vec2 scale, lm::vec2 position, float rotation, lm::vec2 tiling) {
	renderer.sprites.push_back(Sprite(tint, scale, position, rotation, tiling));
	Object* obj = &renderer.sprites.back();
	return (Sprite*)obj;
}
