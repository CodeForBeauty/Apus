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

	window.Destroy();
	glfwTerminate();
}

void ApusCore::App::Tick() {
	window.RenameWindow(std::to_string(1 / delta).c_str());
}
