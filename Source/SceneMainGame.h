#pragma once
#include "core\Core.h"
#include "MainCamera.h"


#include"ScoreObject.h"
#include "TimerObject.h"
#include "syukka.h"
class SceneMainGame :public Scene {
public:
	void Init(void) override;
	void Uninit(void) override;

	void Update(void) override;

	MainCamera * camera;

	Object* field;
	ScoreObject* score;
	TimerObject* time;

	Object* house;
	Syukka* syukka;



	static int gamescore;
};