#pragma once
#include "core\Core.h"
#include "MainCamera.h"

class SceneTitle :public Scene {
public:
	void Init(void) override;
	void Uninit(void) override;

	void Update(void) override;

	FrameTimer fTimer;	// フレームタイマー


	Object* titlelogo;
	bool SceneEnd = false;

};