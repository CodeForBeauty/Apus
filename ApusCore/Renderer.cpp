#include "Renderer.h"

#include<iostream>

void ApusCore::Renderer::Destroy() {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i]->Destroy();
	}
}

void ApusCore::Renderer::Render(lm::mat4 proj, lm::mat4 cam) {
	glClearColor(background.x, background.y, background.z, background.w);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < sprites.size(); i++) {
		sprites[i]->Draw(proj, cam);
		//sprites[i].Unbind();
	}
}

void ApusCore::Renderer::SetBackground(float x, float y, float z, float w) {
	background = { x, y, z, w };
}
