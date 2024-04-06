#pragma once

#include <App.h>


class NewApp : public ApusCore::App {
public:
	float newVal = 5.0f;

	void Tick() override {
		std::cout << newVal << std::endl;
	}
};