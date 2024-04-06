#pragma once
#include <typeindex>
#include <vector>

#include <lm/lm.h>


#include "Vertex.h"
#include "Material.h"


namespace ApusCore {
	class Object {
	protected:
		std::vector<Vertex> vertices;
		unsigned int vbo, vao;
	public:
		Material material = {};

		Object(size_t vertCount);

		void Destroy();
		void Draw();
		Vertex* GetData();
	};

	class Sprite : public Object {
	public:
		lm::vec4 tintColor;
		lm::vec3 scale;
		lm::vec3 position;
		float rotation;

		lm::vec2 tiling;


		Sprite(lm::vec4 tint = { 1, 1, 1, 1 }, lm::vec3 scale = { 1, 1, 1 }, lm::vec3 position = { 0, 0, 0 }, float rotation = 0, lm::vec2 tiling = { 1, 1 });


		void SetZ(float zValue);
	};
}