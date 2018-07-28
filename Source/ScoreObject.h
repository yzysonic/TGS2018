#pragma once
#include "Core/Core.h"

class ScoreObject :public Camera {
public:

	ScoreObject();

	void Update();
	void Uninit();
private:


	int score;
};