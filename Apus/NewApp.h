#pragma once
#include <App.h>
#include <Sprite.h>

#include <math.h>



class NewApp : public ApusCore::App {
public:
	ApusCore::Sprite sp;
	ApusCore::Sprite sp1;

	void Start() override {
		sp = ApusCore::Sprite();
		sp1 = ApusCore::Sprite();

		sp.LoadTexture("testing/grass.jpg");

		//sp1.SetRotation(-25);
		//sp1.SetPosition({ 0.1, 0 });

		AddSprite(&sp);
		AddSprite(&sp1);

		window.ResizeViewport(800, 650);
		//std::cout << std::hex << glGetError() << std::endl;
	}

	void Tick() override {
		//std::cout << delta << std::endl;
		lm::vec2 pos = sp.GetPosition();
		sp.SetPosition({ std::sin((float)time), pos.y });
		sp1.Rotate(20 * delta);
		//camera.Rotate(20 * delta);
		//camera.Move(lm::vec2(0.1 * delta, 0));
		App::Tick();
	}

	void LateTick() override {
		renderer.SaveRender("testing/output.png", ApusCore::ImageType::png);
	}

	void End() override {
		App::End();
	}
};