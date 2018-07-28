#pragma once

#include "Core/Core.h"
#include "Player.h"
#include "MainCamera.h"
#include "DebugMenu.h"
#include"ScoreObject.h"
#include "TimerObject.h"

class SceneYangTest : public Scene
{
public:
	void Init(void) override;
	void Update(void) override;
	void Uninit(void) override;

private:
	Player * player;
	MainCamera * camera;
	DebugMenu * debug;
	FrameTimer timer;
	Object * test_model;

	Object* field;
	ScoreObject* score;
	TimerObject* time;

};