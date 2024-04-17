#include "Camera.h"

void ApusCore::Camera::UpdateMatrix() {
	lm::mat4 rot = lm::rotation2d(rotation);
	rot.w.z = 1;
	rot.w.w = 1;

	/*matrix.w.x = 1;
	matrix.w.y = 1;
	matrix.w.z = 1;*/
	
	matrix = rot * lm::position3d(-position);
}

void ApusCore::Camera::SetPosition(lm::vec2 newPosition) {
	position = newPosition;
	UpdateMatrix();
}

void ApusCore::Camera::SetRotation(float newRotation) {
	rotation = newRotation;
	UpdateMatrix();
}

void ApusCore::Camera::Move(lm::vec2 offset) {
	position += offset;
	UpdateMatrix();
}

void ApusCore::Camera::Rotate(float offset) {
	rotation += offset;
	UpdateMatrix();
}
