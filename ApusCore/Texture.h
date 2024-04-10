#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stb/stb_image.h>


namespace ApusCore {
	class Texture {
	private:
		std::string path;
		unsigned int id;
		unsigned char* data;
	public:
		int width, height, channels;

		Texture(const char* path);

		~Texture() {
			Clear();
		}

		void LoadTexture(const char* texturePath);

		void Clear() {
			stbi_image_free(data);
		}

		void Bind() {
			glBindTexture(GL_TEXTURE_2D, id);
		}

		void Unbind() {
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	};
}