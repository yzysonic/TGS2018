#pragma once
#include "Core/Core.h"
#include "ScoreObject.h"
class Syukka :public Object {
public:

	Syukka();

	void Update();
	void Uninit();

	void OnCollisionEnter(Object* other);

	void SetScorePointer(ScoreObject* ptr);
private:


	ScoreObject* scoreobj;
	int score;
};