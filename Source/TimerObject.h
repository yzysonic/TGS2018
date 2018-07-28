#pragma once
#include "Core/Core.h"

class TimerObject :public Object {
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