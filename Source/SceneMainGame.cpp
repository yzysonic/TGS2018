#include "SceneMainGame.h"
#include "SceneResult.h"
#include "FadeScreen.h"
#include "CharacterDisplayer.h"

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
	field->transform.position = Vector3(0.f, -50.f, 0.f);
	
	score = new ScoreObject;
	time = new TimerObject;

	charaDisp = new CharacterDisplayer;

	house = new Object;
	house->AddComponent<Billboard>("house");
	house->transform.position = Vector3(400.f, 100.f, 0.f);
	house->transform.scale = Vector3(100, 100, 100);

	// カメラ初期化
	camera = new MainCamera;
	camera->at = Vector3(0.f, 0.f, 0.f);
	camera->setBackColor(0xC1CED3);

	// レンダリング設定
	Renderer::GetInstance()->setCamera(camera);
	FadeScreen::FadeIn(Color::white, 0.2f);

	
	//出荷箱
	syukka = new Syukka;
	syukka->AddComponent<RectPolygon>("clickrange");
	syukka->GetComponent<RectPolygon>()->SetSize(Vector2(100, 100));
	syukka->transform.setRotation(PI / 2, 0, 0);
	syukka->transform.position = Vector3(350.f, 0.01f, 0.f);

	syukka->AddComponent<SphereCollider>();
	syukka->GetComponent<SphereCollider>()->radius = 50.f;
	syukka->SetScorePointer(score);
	syukka->charaptr = charaDisp;
	player = new Player(Vector3::zero);
	
	pm = new PamyuManager(player);
}


void SceneMainGame::Update(void) {




	if (time->TimerEnd()) {

		gamescore = score->GetScore();
		//GameManager::GetInstance()->SetScene(new SceneResult);
	}

}
void SceneMainGame::Uninit(void) {
	Renderer::GetInstance()->setCamera(nullptr);
}

