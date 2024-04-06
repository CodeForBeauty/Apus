#include "Sprite.h"

ApusCore::Sprite::Sprite(lm::vec4 tint, lm::vec3 scale, lm::vec3 position, float rotation, lm::vec2 tiling) :
	tintColor(tint), scale(scale), position(position), rotation(rotation), tiling(tiling) {
	for (int i = 0; i < 6; i++) {
		vertices[i].pos *= scale;
		vertices[i].uv *= tiling;
		vertices[i].pos += position;
		vertices[i].col = tint;
	}

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, col));


	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

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

void ApusCore::Sprite::Draw() {
	material.Bind();
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

	glDrawArrays(GL_TRIANGLES, 0, 6);
}
