#pragma once
#include "Core\Core.h"
#include "Core\Text.h"

class SceneTitle :public Scene {
public:
	void Init(void) override;
	void Uninit(void) override;
	void Update(void) override;

private:
	bool			next_scene;
	Object*			title;
};