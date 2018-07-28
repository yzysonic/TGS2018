#pragma once
#include "core\Core.h"
#include "MainCamera.h"
#include "Pamyu.h"

class SceneHaraTest:public Scene
{
public:
	void Init(void) override;
	void Uninit(void) override;

	void Update(void) override;

	MainCamera * camera;

	Pamyu *pamyu;

	Object *model;
};