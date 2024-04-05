#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"


namespace ApusCore {
	class Material {
	private:
		Shader vs, fs;
		unsigned int program;

		void _Compile();
	public:
		Material(): vs(Shader("shaders/vertex.vert", GL_VERTEX_SHADER)), fs("shaders/fragment.frag", GL_FRAGMENT_SHADER) {
			_Compile();
		}

		void Destroy();

		void Bind();
	};
}