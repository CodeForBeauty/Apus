#pragma once
#include <lm/lm.h>

#include "Vertex.h"
#include "Material.h"


namespace ApusCore {
	class Sprite {
	private:
		Vertex vertices[6] {
			{{-0.5f, 0.5f, 0}, lm::vec2(0, 1)},
			{{0.5f, 0.5f, 0}, lm::vec2(1, 1) },
			{{0.5f, -0.5f, 0}, lm::vec2(1, 0) },

			{{0.5f, -0.5f, 0}, lm::vec2(1, 0) },
			{{-0.5f, -0.5f, 0}, lm::vec2(0, 0)},
			{{-0.5f, 0.5f, 0}, lm::vec2(0, 1)},
		};

		float testing[18] = {
			-0.5, 0.5, 0,
			0.5, 0.5, 0,
			0.5, -0.5, 0,

			0.5, -0.5, 0,
			-0.5, -0.5, 0,
			-0.5, 0.5, 0
		};

	public:
		unsigned int vbo, vao;
		lm::vec4 tintColor;
		lm::vec3 scale;
		lm::vec3 position;
		float rotation;

		lm::vec2 tiling;

		Material material = {};


		Sprite(lm::vec4 tint = { 1, 1, 1, 1 }, lm::vec3 scale = { 1, 1, 1 }, lm::vec3 position = { 0, 0, 0 }, float rotation = 0, lm::vec2 tiling = { 1, 1 }) :
			tintColor(tint), scale(scale), position(position), rotation(rotation), tiling(tiling) {
			for (int i = 0; i < 6; i++) {
				//vertices[i].pos *= scale;
				vertices[i].uv *= tiling;
				//vertices[i].pos += position;
				vertices[i].col = tint;
			}

			glGenVertexArrays(1, &vao);
			glGenBuffers(1, &vbo);

			glBindVertexArray(vao);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(testing), testing, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

			int result = 0;
			//glGetVertexArrayiv(vao, GL_ELEMENT_ARRAY_BUFFER_BINDING, &result);

			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			std::cout << std::hex << glGetError() << std::endl;
		}

		void Destroy();

		Vertex* GetData();
		void SetZ(float zValue);

		void Bind();
		void Unbind();
	};
}