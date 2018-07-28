#pragma once
#include "core\Core.h"
#include "MainCamera.h"
#include "Pamyu.h"

#include"ScoreObject.h"
#include "TimerObject.h"
#include "PamyuManager.h"
#include "Player.h"

class SceneHaraTest:public Scene
{
public:
	void Init(void) override;
	void Uninit(void) override;

	void Update(void) override;

	MainCamera * camera;

	Player *player;

	Object* field;
	ScoreObject* score;
	TimerObject* time;

	PamyuManager* pm;
	Object* house;

//public:
//	void Init(void) override;
//	void Uninit(void) override;
//
//	void Update(void) override;
//
//	MainCamera * camera;
//
//	Pamyu *pamyu;
//
//	Object *model;
};