#include "SceneMainGame.h"
#include "SceneResult.h"
#include "FadeScreen.h"

int SceneMainGame::gamescore;
void SceneMainGame::Init(void) {

	Texture::Load("field_kari");
	Texture::Load("time");
	Texture::Load("score");
	Texture::Load("house");
	Texture::Load("clickrange");

	field = new Object;

	field->AddComponent<RectPolygon>("field_kari");
	field->GetComponent<RectPolygon>()->SetSize(Vector2(1000, 500));
	field->transform.setRotation(PI / 2, 0, 0);
	field->transform.position = Vector3(0.f, 0.f, 0.f);
	
	score = new ScoreObject;
	time = new TimerObject;


	house = new Object;
	house->AddComponent<Billboard>("house");
	house->transform.position = Vector3(400.f, 100.f, 0.f);
	house->transform.scale = Vector3(100, 100, 100);

	// ƒJƒƒ‰‰Šú‰»
	camera = new MainCamera;
	camera->at = Vector3(0.f, 0.f, 0.f);
	camera->setBackColor(0xC1CED3);

	// ƒŒƒ“ƒ_ƒŠƒ“ƒOÝ’è
	Renderer::GetInstance()->setCamera(camera);
	FadeScreen::FadeIn(Color::white, 0.2f);

	syukka = new Object;

}


void SceneMainGame::Update(void) {




	if (time->TimerEnd()) {

		gamescore = score->GetScore();
		GameManager::GetInstance()->SetScene(new SceneResult);
	}

}
void SceneMainGame::Uninit(void) {
	Renderer::GetInstance()->setCamera(nullptr);
}

