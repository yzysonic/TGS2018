#include "SceneYangTest.h"
#include "Core/Physics.h"
#include "Light.h"
#include "FadeScreen.h"
#include "InspectorContentCamera.h"
#include "Inspector.h"
#include "DebugManager.h"
#include "Pamyu.h"

#pragma region SceneYangTest

void SceneYangTest::Init(void)
{
	// ���\�[�X�̃��[�h
	ModelData::Load("field");

	// �I�u�W�F�N�g������
	player	= new Player(Vector3(0.0f, 0.0f, 30.f));

	// �J����������
	camera = new MainCamera;
	camera->SetTarget(&player->transform);
	camera->setBackColor(0xC1CED3);

	// �����_�����O�ݒ�
	Renderer::GetInstance()->setCamera(camera);

	// �d�͐ݒ�
	Physics::GetInstance()->setGravity(Vector3(0.0f, -98.0f, 0.0f));

	//// �n�ʃu���b�N�̐���
	//{
	//	int i = 0;
	//	for (auto& t : test)
	//	{
	//		t = new TestObject;
	//		t->transform.position.x = (float)(i*10);
	//		t->transform.position.y = (float)(((i/2)%2)*10);
	//		i++;
	//	}
	//}

	for (int i = 0; i < 3; i++)
	{
		new Pamyu(Vector3(50*i, 0.0f, 0.0f), Pamyu::PamyuType::Mi);
	}

	debug	= DebugManager::GetInstance()->GetComponent<DebugMenu>();
	DebugManager::OpenInspector(player);
}

void SceneYangTest::Update(void)
{
	timer++;

	// �e�X�g���j���[
	ImGui::SetNextWindowSize(ImVec2(150.0f, 0), ImGuiCond_Once);
	ImGui::Begin("TestMenu", NULL,  ImGuiWindowFlags_NoResize);

	ImGui::End();

	// �f�o�b�O���j���[
	ImGui::SetNextWindowSize(ImVec2(debug->MenuWidth, 0), ImGuiCond_Once);
	ImGui::Begin("DebugMenu ", NULL, ImGuiWindowFlags_NoResize);
	debug->GuiContent();
	ImGui::End();
}

void SceneYangTest::Uninit(void)
{
	Renderer::GetInstance()->setCamera(nullptr);
	ModelData::Release("field");

}

#pragma endregion


#pragma region SeasonTestObject

TestObject::TestObject(void)
{
	type = ObjectType::Field;
	model = AddComponent<StaticModel>("field");
	collider = AddComponent<BoxCollider2D>();
	collider->size = Vector2::one*10.0f;
}

void TestObject::Update(void)
{
}

void TestObject::OnCollisionEnter(Object * other)
{
}

void TestObject::OnCollisionStay(Object * object)
{
	collide = true;
}

void TestObject::OnCollisionExit(Object * other)
{
}

#pragma endregion