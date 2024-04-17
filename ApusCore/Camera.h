#pragma once
#include <lm/lm.h>


namespace ApusCore {
	class Camera {
	private:
		lm::mat4 matrix;
		lm::vec2 position;
		float rotation;

		void UpdateMatrix();
	public:
		Camera(lm::vec2 position, float rotation) : position(position), rotation(rotation) {}

		lm::vec2 GetPostion() const { return position; }
		float GetRotation() const { return rotation; }

		void SetPosition(lm::vec2 newPosition);
		void SetRotation(float newRotation);
		void Move(lm::vec2 offset);
		void Rotate(float offset);

		lm::mat4 GetMatrix() const { return matrix; }
	};
}