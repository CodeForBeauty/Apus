#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <list>

#include "Sprite.h"


namespace ApusCore {
	class Renderer {
	public:
		lm::vec4 background = { 0, 0, 0, 1 };
		std::vector<Mesh*> sprites;

		Renderer() {
			if (!glfwInit())
				throw std::exception("Error: initializing glfw");
		}

		void Init() {
			gladLoadGL();
		}

		void Destroy();

		void Render(lm::mat4 proj, lm::mat4 cam);

		void SetBackground(float x, float y, float z, float w);
	};
}