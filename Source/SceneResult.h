#pragma once
#include "core\Core.h"
#include "MainCamera.h"

class SceneResult :public Scene {
public:
	void Init(void) override;
	void Uninit(void) override;
	void Update(void) override;

private:
	bool	next_scene;
	Object* result;
};