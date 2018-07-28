#include "SceneHaraTest.h"
#include "Pamyu.h"
#include "Player.h"
#include "FadeScreen.h"
#include "SceneResult.h"
#include "PamyuManager.h"

void SceneHaraTest::Init(void)
{


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

	player = new Player(Vector3::zero);

	pm = new PamyuManager(player);

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

	//ModelData::Load("hara_test");


	//model = new Object;
	//model->AddComponent<StaticModel>("hara_test");

	//pamyu = new Pamyu(Vector3::one, Pamyu::PamyuType::Mi);

	//// カメラ初期化
	//camera = new MainCamera;
	//camera->SetTarget(&model->transform);
	//camera->setBackColor(0xC1CED3);

	//// レンダリング設定
	//Renderer::GetInstance()->setCamera(camera);

}

void SceneHaraTest::Uninit(void)
{

	Renderer::GetInstance()->setCamera(nullptr);


	//Renderer::GetInstance()->setCamera(nullptr);
	//ModelData::Release("hara_test");
}

void SceneHaraTest::Update(void)
{
	if (time->TimerEnd()) {

		GameManager::SetGameScore(score->GetScore());
		GameManager::GetInstance()->SetScene(new SceneResult);
	}

}
