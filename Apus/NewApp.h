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

		
		/*auto test = [](lm::vec2 pos, lm::vec2 uv) {
			unsigned char output[3] {uv.x * 255, uv.y * 255, 0};
			return output;
		};*/
		// r\left(x, y\right) = .2 + .8\operatorname{ abs }\left(f\left(\frac{ \arctan\left(y,x\right) }{2\pi} - .15\sqrt{ x^ {2} + y^ {2} } + t\right)\right)
		auto test = [](lm::vec2 pos, lm::vec2 uv) {
			ApusCore::Color output = { uv.x, uv.y, 0, 1 };//{ (std::abs(uv.x * 2 - 1.0f)) * (std::abs(uv.y * 2 - 1.0f)) };
			return output;
		};

		//sp1.GenerateTexture(test, 1024, 812, false);

		sp1.material.tex.Save("testing/texture1.png", ApusCore::ImageType::png);

		sp.LoadTexture("testing/grass.jpg");

		//sp1.SetRotation(-25);
		//sp1.SetPosition({ 0.1, 0 });

		//sp2.material.tex.LoadTexture("testing/Red-Ball-Transparent.png");
		//sp2.material.tex.LoadTexture("testing/grass.jpg");
		sp2.GenerateTexture(test, true);
		//sp2.material.tex.LoadTexture("testing/SizeTesting.jpg");

		AddObject(&sp);
		AddObject(&sp1);
		AddObject(&sp2);

		ApusCore::Color a = {1, 1, 1, 0};
		ApusCore::Color b = {2, 1, 0.5f, 0.5f};
		std::cout << a * b << std::endl;

		//std::cout << std::hex << glGetError() << std::endl;
		window.ResizeViewport(850, 600);
	}

	void Tick() override {
		//auto test = [this](lm::vec2 pos, lm::vec2 uv) {
		//	//unsigned char val = (unsigned char)(Plot(uv.x, uv.y) * 255);
		//	uv *= 1000;
		//	uv -= 500;
		//	unsigned char val = (unsigned char)(0.2f + 0.8f * std::abs(2 * std::fmod(std::atan2(uv.x, uv.y) / (2 * lm::PI) - (0.15f * std::sqrtf(uv.x * uv.x + uv.y * uv.y)) + this->time, 1) - 1) * 255);
		//	uv += 5;
		//	unsigned char val1 = (unsigned char)(0.2f + 0.8f * std::abs(2 * std::fmod(std::atan2(uv.x, uv.y) / (2 * lm::PI) - (0.15f * std::sqrtf(uv.x * uv.x + uv.y * uv.y)) + this->time, 1) - 1) * 255);
		//	uv -= 10;
		//	unsigned char val2 = (unsigned char)(0.2f + 0.8f * std::abs(2 * std::fmod(std::atan2(uv.x, uv.y) / (2 * lm::PI) - (0.15f * std::sqrtf(uv.x * uv.x + uv.y * uv.y)) + this->time, 1) - 1) * 255);
		//	unsigned char output[3]{ val1 * 0.3f, val2 * 0.3f, val };
		//	return output;
		//	};

		//sp1.GenerateTexture(test, 512, 512);
		//sp1.material.tex.Save("testing/texture1.png", ApusCore::ImageType::png);

		//std::cout << delta << std::endl;
		/*lm::vec2 pos = sp.GetPosition();
		sp.SetPosition({ std::sin((float)time), pos.y });
		sp1.Rotate(20 * delta);*/
		//camera.Rotate(20 * delta);
		//camera.Move(lm::vec2(0.1 * delta, 0));
		App::Tick();
	}

	void LateTick() override {
		//renderer.SaveRender("testing/output.png", ApusCore::ImageType::png);
	}

	void End() override {
		App::End();
	}
};