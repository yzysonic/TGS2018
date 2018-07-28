#include "SceneTitle.h"
#include "SceneMainGame.h"
#include "FadeScreen.h"
#include "Core\Text.h"

void SceneTitle::Init(void)
{
	Texture::Load("title_background");

	title = new Object;
	title->AddComponent<RectPolygon2D>("title_background", Layer::BG_00);

	title->AddComponent<Text>()->LoadFont("おつとめフォント");
	title->GetComponent<Text>()->SetSize(64, 0);
	title->GetComponent<Text>()->SetColor(Color::black);
	title->GetComponent<Text>()->area = { 0,300,800,500 };
	title->GetComponent<Text>()->SetFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	next_scene = false;
	FadeScreen::FadeIn(Color::black, 1.0f);
}

void SceneTitle::Uninit(void)
{
	Texture::Release("title_background");
}

void SceneTitle::Update(void)
{
	if (!next_scene && GetKeyboardTrigger(DIK_RETURN))
	{
		FadeScreen::FadeOut(Color::white, 1.0f, [this] {
			GameManager::GetInstance()->SetScene(new SceneMainGame);
		});
		next_scene = true;
	}
	//if (!next_scene && FadeScreen::Finished())
	//{
	//	title->GetComponent<Text>()->SetText("エンターキーではじめる");
	//}
}
