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
	protected:
		std::vector<Vertex> vertBase;
		
		lm::vec4 tintColor;
		lm::vec2 tiling;

		lm::vec2 position;
		lm::vec2 scale;
		float rotation;
		float z;

	public:
		Sprite(lm::vec4 tint = { 1, 1, 1, 1 }, lm::vec2 scale = { 1, 1 }, lm::vec2 position = { 0, 0 }, float rotation = 0, lm::vec2 tiling = { 1, 1 });


		void SetPosition(lm::vec2 newPos);
		void SetRotation(float newRot);
		void SetScale(lm::vec2 scale);

		lm::vec2 GetPosition();
		float GetRotation();
		lm::vec2 GetScale();

		lm::vec2 Move(lm::vec2 offset);
		float Rotate(float offset);
		lm::vec2 Scale(lm::vec2 offset);


		void SetZ(float zValue);
		float GetZ();
	};
}