#include "SceneYangTest.h"
#include "Core/Physics.h"
#include "Light.h"
#include "FadeScreen.h"
#include "InspectorContentCamera.h"
#include "Inspector.h"
#include "DebugManager.h"
#include "Pamyu.h"
#

#pragma region SceneYangTest

void SceneYangTest::Init(void)
{
	// リソースのロード
	Texture::Load("field_kari");
	Texture::Load("time");
	Texture::Load("score");
	Texture::Load("house");
	Texture::Load("clickrange");

	// オブジェクト初期化
	player	= new Player(Vector3(0.0f, 0.0f, 30.f));

	// カメラ初期化
	camera = new MainCamera;
	camera->SetTarget(&player->transform);

	// レンダリング設定
	Renderer::GetInstance()->setCamera(camera);

	field = new Object;

	field->AddComponent<RectPolygon>("field_kari", Layer::BG_00);
	field->GetComponent<RectPolygon>()->SetSize(Vector2(1000, 500));
	field->transform.setRotation(PI / 2, 0, 0);
	field->transform.position = Vector3(0.f, -50.f, 0.f);

	score = new ScoreObject;
	time = new TimerObject;

	for (int i = 0; i < 3; i++)
	{
		new Pamyu(Vector3(100*i, 0.0f, 0.0f), Pamyu::PamyuType::Mi);
	}

	//debug	= DebugManager::GetInstance()->GetComponent<DebugMenu>();
	//DebugManager::OpenInspector(player);
}

void SceneYangTest::Update(void)
{
	if (time->TimerEnd()) {

		//GameManager::SetGameScore(score->GetScore());
		//GameManager::GetInstance()->SetScene(new SceneResult);
	}

}

void SceneYangTest::Uninit(void)
{
	Texture::Release("field_kari");
	Texture::Release("time");
	Texture::Release("score");
	Texture::Release("house");
	Texture::Release("clickrange");

	Renderer::GetInstance()->setCamera(nullptr);

}

#pragma endregion
