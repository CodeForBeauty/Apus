#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <lm/lm.h>


struct vec3 {
	GLfloat x, y, z;
};

struct Vertex {
	lm::vec3 pos;
	lm::vec2 uv;
	lm::vec4 col;
	unsigned int tex;
};