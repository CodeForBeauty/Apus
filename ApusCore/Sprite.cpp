#include "Sprite.h"

void ApusCore::Sprite::Destroy() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

Vertex* ApusCore::Sprite::GetData() {
	return vertices;
}

void ApusCore::Sprite::SetZ(float zValue) {
	position.z = zValue;
	for (int i = 0; i < 6; i++) {
		vertices[i].pos.z = zValue;
	}
}

void ApusCore::Sprite::Bind() {
	material.Bind();
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void ApusCore::Sprite::Unbind() {
	glUseProgram(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
