#pragma once
#include <lm/lm.h>

#include "Vertex.h"
#include "Material.h"


namespace ApusCore {
	class Sprite {
	protected:
		Vertex vertices[6] {
			{{-0.5f, 0.5f, 0}, lm::vec2(0, 1)},
			{{0.5f, 0.5f, 0}, lm::vec2(1, 1) },
			{{0.5f, -0.5f, 0}, lm::vec2(1, 0) },

			{{0.5f, -0.5f, 0}, lm::vec2(1, 0) },
			{{-0.5f, -0.5f, 0}, lm::vec2(0, 0)},
			{{-0.5f, 0.5f, 0}, lm::vec2(0, 1)},
		};

	public:
		unsigned int vbo, vao;
		lm::vec4 tintColor;
		lm::vec3 scale;
		lm::vec3 position;
		float rotation;

		lm::vec2 tiling;

		Material material = {};


		Sprite(lm::vec4 tint = { 1, 1, 1, 1 }, lm::vec3 scale = { 1, 1, 1 }, lm::vec3 position = { 0, 0, 0 }, float rotation = 0, lm::vec2 tiling = { 1, 1 });

		void Destroy();

		Vertex* GetData();
		void SetZ(float zValue);

		void Draw();
	};
}