#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>

#include "Sprite.h"


namespace ApusCore {
	class Renderer {
	public:
		std::vector<Object*> sprites;

		Renderer() {
			if (!glfwInit())
				throw std::exception("Error: initializing glfw");
		}

		void Init() {
			gladLoadGL();
		}

		void Destroy();

		void Render(lm::mat4 proj, lm::mat4 cam);
	};
}