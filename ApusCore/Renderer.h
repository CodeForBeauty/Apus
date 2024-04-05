#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "Sprite.h"


namespace ApusCore {
	class Renderer {
	public:
		std::vector<Sprite> sprites;

		Renderer() {
			if (!glfwInit())
				throw std::exception("Error: initializing glfw");
		}

		void Init() {
			gladLoadGL();
		}

		void Destroy();

		void Render();
	};
}