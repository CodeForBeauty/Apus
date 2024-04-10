#include "Renderer.h"

#include<iostream>

void ApusCore::Renderer::Destroy() {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i]->Destroy();
	}
}

void ApusCore::Renderer::Render(lm::mat4 proj) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < sprites.size(); i++) {
		sprites[i]->Draw(proj);
		//sprites[i].Unbind();
	}
}
