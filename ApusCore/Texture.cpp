#include "Texture.h"
#include <iostream>

#include <stb/stb_image_write.h>


ApusCore::Texture::Texture(const char* path) : path(path) {
	data = stbi_load(path, &width, &height, &channels, 0);

	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << (float)data[(i + width * j) * channels] << " " << (float)data[(i + width * j) * channels + 1] << " " << (float)data[(i + width * j) * channels + 2] << " " << std::endl;
		}
	}*/

	glGenTextures(1, &id);
	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	Unbind();
}

ApusCore::Texture::Texture(unsigned char* (*func)(lm::vec2 pos, lm::vec2 uv), int width, int height) : width(width), height(height) {
	glGenTextures(1, &id);
	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	Generate(func);
}

void ApusCore::Texture::LoadTexture(const char* texturePath) {
	//std::cout << texturePath << std::endl;
	if (strcmp(path.c_str(), texturePath) == 0)
		return;
	//std::cout << texturePath << "1" << std::endl;
	Clear();
	path = texturePath;
	data = stbi_load(texturePath, &width, &height, &channels, 0);


	Bind();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	Unbind();
}

void ApusCore::Texture::Generate(std::function<unsigned char* (lm::vec2 pos, lm::vec2 uv)> func) {
	Clear();

	data = new unsigned char[width * height * 3];
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			unsigned char* pixel = func({ (float)i, (float)j }, { (float)i / width, (float)j / height });
			for (int ch = 0; ch < 3; ch++) {
				data[(i + width * j) * 3 + ch] = pixel[ch];
			}
		}
	}

	Bind();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	Unbind();
}

void ApusCore::Texture::Save(const char* outputPath, ApusCore::ImageType imgType) {
	switch (imgType) {
	case ApusCore::png:
		stbi_write_png(outputPath, width, height, 3, data, width * 3);
		break;
	case ApusCore::jpeg:
		stbi_write_jpg(outputPath, width, height, 3, data, width * 3);
		break;
	case ApusCore::bmp:
		stbi_write_bmp(outputPath, width, height, 3, data);
		break;
	case ApusCore::tga:
		stbi_write_tga(outputPath, width, height, 3, data);
		break;
	}
}
