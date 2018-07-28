#include "SceneMainGame.h"

#include"ScoreObject.h"
#include "TimerObject.h"
void SceneMainGame::Init(void) {

	Texture::Load("field_kari");
	Texture::Load("time");
	Texture::Load("score");
	
	field = new Object;

	field->AddComponent<RectPolygon>("field_kari");
	field->GetComponent<RectPolygon>()->SetSize(Vector2(1000, 500));
	field->transform.setRotation(PI / 2, 0, 0);
	field->transform.position = Vector3(0.f, 0.f, 0.f);
	
	score = new ScoreObject;

	time = new TimerObject;


	// ƒJƒƒ‰‰Šú‰»
	camera = new MainCamera;
	camera->at = Vector3(0.f, 0.f, 0.f);
	camera->setBackColor(0xC1CED3);

	// ƒŒƒ“ƒ_ƒŠƒ“ƒOÝ’è
	Renderer::GetInstance()->setCamera(camera);




}


void SceneMainGame::Update(void) {


}
void SceneMainGame::Uninit(void) {

}

