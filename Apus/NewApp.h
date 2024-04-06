#pragma once
#include <App.h>
#include <Sprite.h>

#include <math.h>



class NewApp : public ApusCore::App {
public:
	ApusCore::Sprite* sp;
	ApusCore::Sprite* sp1;

	void Start() override {
		sp = CreateSprite();
		sp1 = CreateSprite();

		sp = (ApusCore::Sprite*) & renderer.sprites[0];
		sp1 = (ApusCore::Sprite*) & renderer.sprites[1];

		sp1->SetRotation(-25);
		sp1->SetPosition({ 0.1, 0 });
		//std::cout << std::hex << glGetError() << std::endl;
	}

	void Tick() override {
		//std::cout << delta << std::endl;
		lm::vec2 pos = sp->GetPosition();
		sp->SetPosition({ std::sin((float)time), pos.y });
		sp1->Rotate(20 * delta);
		App::Tick();
	}
};