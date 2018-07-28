#include "SceneHaraTest.h"
#include "Pamyu.h"

void SceneHaraTest::Init(void)
{
	ModelData::Load("hara_test");


	model = new Object;
	model->AddComponent<StaticModel>("hara_test");

	pamyu = new Pamyu(Vector3::one, Pamyu::PamyuType::Mi);

	// カメラ初期化
	camera = new MainCamera;
	camera->SetTarget(&model->transform);
	camera->setBackColor(0xC1CED3);

	// レンダリング設定
	Renderer::GetInstance()->setCamera(camera);

}

void SceneHaraTest::Uninit(void)
{
	Renderer::GetInstance()->setCamera(nullptr);
	ModelData::Release("hara_test");
}

void SceneHaraTest::Update(void)
{

}
