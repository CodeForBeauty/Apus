#include "Sprite.h"


ApusCore::Object::Object(size_t vertCount) {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertCount, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, col));


	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ApusCore::Object::Destroy() {
	material.Destroy();
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void ApusCore::Object::Draw() {
	material.Bind();
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * vertices.size(), vertices.data());

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

Vertex* ApusCore::Object::GetData() {
	return &vertices[0];
}

ApusCore::Sprite::Sprite(lm::vec4 tint, lm::vec3 scale, lm::vec3 position, float rotation, lm::vec2 tiling) : 
	Object(6), tintColor(tint), scale(scale), position(position), rotation(rotation), tiling(tiling) {
	vertices.push_back({ {-0.5f,  0.5f, 0.0f}, {0, 1}, {1, 1, 1, 1} });
	vertices.push_back({ { 0.5f,  0.5f, 0.0f}, {1, 1}, {1, 1, 1, 1} });
	vertices.push_back({ { 0.5f, -0.5f, 0.0f}, {1, 0}, {0, 0, 0, 1} });

	vertices.push_back({ { 0.5f, -0.5f, 0.0f}, {1, 0}, {0, 0, 0, 1} });
	vertices.push_back({ {-0.5f, -0.5f, 0.0f}, {0, 0}, {0, 0, 0, 1} });
	vertices.push_back({ {-0.5f,  0.5f, 0.0f}, {0, 1}, {1, 1, 1, 1} });
	
	for (int i = 0; i < 6; i++) {

		vertices.at(i).pos *= scale;
		vertices[i].uv *= tiling;
		vertices[i].pos += position;
		vertices[i].col *= tint;
	}
	
}

void ApusCore::Sprite::SetZ(float zValue) {
	position.z = zValue;
	for (int i = 0; i < 6; i++) {
		vertices[i].pos.z = zValue;
	}
}


