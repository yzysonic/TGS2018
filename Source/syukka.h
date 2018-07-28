#pragma once
#include "Core/Core.h"
#include "ScoreObject.h"
#include"CharacterDisplayer.h"
class Syukka :public Object {
public:

	CharacterDisplayer *charaptr;

	Syukka();

	void Update();
	void Uninit();

	void OnCollisionEnter(Object* other);

	void SetScorePointer(ScoreObject* ptr);
private:


	ScoreObject* scoreobj;

	int score;
};