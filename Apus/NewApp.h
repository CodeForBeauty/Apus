#pragma once
#include <App.h>
#include <Sprite.h>



class NewApp : public ApusCore::App {
public:
	ApusCore::Sprite* sp;

	void Start() override {
		sp = CreateSprite();
	}

	void Tick() override {
		//std::cout << delta << std::endl;
		//sp->Rotate(0.1 * delta);
		App::Tick();
	}
};