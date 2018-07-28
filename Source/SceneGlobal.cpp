#include "SceneGlobal.h"
#include "FadeScreen.h"
#include "Core\Game.h"
#include "Core/Physics.h"

#ifdef _DEBUG
#include "DebugManager.h"
#endif

void SceneGlobal::Init(void)
{
	// リソースのロード
	VertexShader::Load("InstancingVS.hlsl");
	Texture::Load("shadow");

	// 終了プロセスの設定
	Game::EndProcess = [this]
	{
		Sound::Get("game_stop")->Play();
		stop_timer.Reset(2.0f);
	};
	stop_timer.Reset(-1.0f);

	// グローバルカメラを作成
	camera = new Camera;

	// レンダースペースを作成し、カメラを追加
	RenderSpace::Add("global");
	RenderSpace::Get("global")->AddCamera(camera);

	// レンダーターゲットの作成
	render_target = RenderTarget::Make("rt_main");
	RenderSpace::Get("default")->GetCamera(0)->render_target = render_target;
	(new Object)->AddComponent<RectPolygon2D>(render_target, Layer::DEFAULT, "global");

	SetCameraActive(false);

	// フェイドエフェクトの初期化
	FadeScreen::Create();

	//重力設定
	Physics::GetInstance()->setGravity(Vector3(0.0f, -98.0f, 0.0f));

	// サウンドボリューム設定
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
