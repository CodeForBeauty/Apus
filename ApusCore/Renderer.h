#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace ApusCore {
	class Renderer {
	public:
		Renderer() {
			if (!glfwInit())
				throw std::exception("Error: initializing glfw");
		}

		void Init() {
			gladLoadGL();
		}

		void Render() {
			glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	};
}