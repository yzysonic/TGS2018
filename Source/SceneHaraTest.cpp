#include "SceneHaraTest.h"

void SceneHaraTest::Init(void)
{
	ModelData::Load("hara_test");


	model = new Object;
	model->AddComponent<StaticModel>("hara_test");


	// ƒJƒƒ‰‰Šú‰»
	camera = new MainCamera;
	camera->SetTarget(&model->transform);
	camera->setBackColor(0xC1CED3);

	// ƒŒƒ“ƒ_ƒŠƒ“ƒOÝ’è
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
