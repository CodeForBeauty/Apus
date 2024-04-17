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
		renderer.Render(window.GetProjection(), camera.GetMatrix());
		window.Update();
	}

	End();

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

void ApusCore::App::End() {
	std::cout << "App closed" << std::endl;
}

void ApusCore::App::AddSprite(Sprite* newSprite) {
	renderer.sprites.push_back(newSprite);
}