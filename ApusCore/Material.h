#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Texture.h"


namespace ApusCore {
	class Material {
	private:
		Texture tex;
		Shader vs, fs;
		unsigned int program;

		void _Compile();
	public:
		Material(): vs("shaders/vertex.vert", GL_VERTEX_SHADER), fs("shaders/fragment.frag", GL_FRAGMENT_SHADER), tex("shaders/Default.jpg") {
			_Compile();
		}

		void Destroy();

		void Bind();
	};
}