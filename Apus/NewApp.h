#pragma once
#include <App.h>
#include <Sprite.h>

#include <cmath>


class NewApp : public ApusCore::App {
public:
	ApusCore::Sprite sp;
	ApusCore::Sprite sp1;
	ApusCore::ScreenOverlay sp2 = ApusCore::ScreenOverlay(&window);

	void Start() override {
		auto test = [](lm::vec2 pos, lm::vec2 uv) {
			ApusCore::Color output = { uv.x, uv.y, 0, 1 };
			return output;
		};

		sp1.material.tex.Save("testing/texture1.png", ApusCore::ImageType::png);

		sp.LoadTexture("testing/grass.jpg");
		sp2.GenerateTexture(test, true);

		AddObject(&sp);
		AddObject(&sp1);
		AddObject(&sp2);

		window.ResizeViewport(850, 600);
	}

	void Tick() override {
		App::Tick();
	}

	void LateTick() override {
		App::LateTick();
	}

	void End() override {
		App::End();
	}
};