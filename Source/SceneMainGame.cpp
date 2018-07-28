#include "SceneMainGame.h"

void SceneMainGame::Init(void) {

	// カメラ初期化
	camera = new MainCamera;
	camera->at = Vector3(0.f, 0.f, 0.f);
	camera->setBackColor(0xC1CED3);

	// レンダリング設定
	Renderer::GetInstance()->setCamera(camera);
}

void SceneMainGame::Uninit(void) {
}

void SceneMainGame::Update(void) {
}
