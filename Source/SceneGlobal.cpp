#include "SceneGlobal.h"
#include "FadeScreen.h"
#include "Core\Game.h"
#include "Core/Physics.h"

#ifdef _DEBUG
#include "DebugManager.h"
#endif

void SceneGlobal::Init(void)
{
	// ���\�[�X�̃��[�h
	VertexShader::Load("InstancingVS.hlsl");
	Texture::Load("shadow");

	// �I���v���Z�X�̐ݒ�
	Game::EndProcess = [this]
	{
		Sound::Get("game_stop")->Play();
		stop_timer.Reset(2.0f);
	};
	stop_timer.Reset(-1.0f);

	// �O���[�o���J�������쐬
	camera = new Camera;

	// �����_�[�X�y�[�X���쐬���A�J������ǉ�
	RenderSpace::Add("global");
	RenderSpace::Get("global")->AddCamera(camera);

	// �����_�[�^�[�Q�b�g�̍쐬
	render_target = RenderTarget::Make("rt_main");
	RenderSpace::Get("default")->GetCamera(0)->render_target = render_target;
	(new Object)->AddComponent<RectPolygon2D>(render_target, Layer::DEFAULT, "global");

	SetCameraActive(false);

	// �t�F�C�h�G�t�F�N�g�̏�����
	FadeScreen::Create();

	//�d�͐ݒ�
	Physics::GetInstance()->setGravity(Vector3(0.0f, -98.0f, 0.0f));

	// �T�E���h�{�����[���ݒ�
	Sound::SetGlobalVolume(0.6f);

	GameManager::GetInstance()->Var<int>("NumPosHistory") = 30;


#ifdef _DEBUG
	DebugManager::Create();
#endif
}


void SceneGlobal::Update(void)
{
	if (stop_timer.interval > 0.0f)
	{
		stop_timer++;
		if (stop_timer.TimeUp())
			Game::Stop();
	}
}

void SceneGlobal::Uninit(void)
{
	Texture::Release("shadow");
	FadeScreen::Singleton<FadeScreen>::Destroy();

#ifdef _DEBUG
	DebugManager::Singleton<DebugManager>::Destroy();
#endif

}

void SceneGlobal::SetCameraActive(bool value)
{
	camera->SetActive(value);

	if (value)
	{
		RenderSpace::Get("default")->GetCamera(0)->render_target = render_target;
	}
	else
	{
		RenderSpace::Get("default")->GetCamera(0)->render_target = RenderTarget::BackBuffer();
	}
}
