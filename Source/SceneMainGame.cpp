#include "SceneMainGame.h"

void SceneMainGame::Init(void) {

	Texture::Load("field001");
	Texture::Load("time");
	Texture::Load("score");
	
	field = new Object;

	field->AddComponent<RectPolygon>("field001");
	field->GetComponent<RectPolygon>()->SetSize(Vector2(500.f, 500.f));
	field->transform.setRotation(PI / 2, 0, 0);
	field->transform.position = Vector3(0.f, 0.f, 0.f);
	

	score = new Object;
	score->AddComponent<RectPolygon2D>("score");
	score->transform.position = Vector3(-400,300,0);
	score->GetComponent<RectPolygon2D>()->SetSize(400.f, 200.f);

	time = new Object;
	time->AddComponent<RectPolygon2D>("time");
	time->transform.position = Vector3(0, 300, 0);
	time->GetComponent<RectPolygon2D>()->SetSize(400.f, 200.f);

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
