#include "SceneMainGame.h"

void SceneMainGame::Init(void) {

	// ƒJƒƒ‰‰Šú‰»
	camera = new MainCamera;
	camera->at = Vector3(0.f, 0.f, 0.f);
	camera->setBackColor(0xC1CED3);

	// ƒŒƒ“ƒ_ƒŠƒ“ƒOÝ’è
	Renderer::GetInstance()->setCamera(camera);
}

void SceneMainGame::Uninit(void) {
}

void SceneMainGame::Update(void) {
}
