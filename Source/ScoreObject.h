#pragma once
#include "Core/Core.h"

class ScoreObject :public Object {
public:

	ScoreObject();

	void Update();
	void Uninit();

	int GetScore();
	void AddScore(int score) { this->score += score; }
private:



	int score;
};