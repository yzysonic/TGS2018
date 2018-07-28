#pragma once
#include "core\Core.h"
#include "MainCamera.h"

class SceneMainGame :public Scene {
public:
	void Init(void) override;
	void Uninit(void) override;

	void Update(void) override;

	MainCamera * camera;


};