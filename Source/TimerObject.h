#pragma once
#include "Core/Core.h"

class TimerObject :public Camera {
public:

	TimerObject();

	void Update();
	void Uninit();
	bool TimerEnd();
private:


	int score;
	int timer;
	int frame;
};