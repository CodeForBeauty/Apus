#include <string>

#include "App.h"



void ApusCore::App::Start() {
	time = glfwGetTime();

	while (!window.ShouldClose()) {
		lastTime = time;
		time = glfwGetTime();
		delta = time - lastTime;
		Tick();
		renderer.Render();
		window.Update();
	}

	renderer.Destroy();
	window.Destroy();
	glfwTerminate();
}

void ApusCore::App::Tick() {
	window.RenameWindow(std::to_string(1 / delta).c_str());
}

ApusCore::Sprite* ApusCore::App::CreateSprite(lm::vec4 tint, lm::vec3 scale, lm::vec3 position, float rotation, lm::vec2 tiling) {
	renderer.sprites.push_back({ tint, scale, position, rotation, tiling });
	return &renderer.sprites[renderer.sprites.size() - 1];
}
