#include "SceneResult.h"
#include "SceneTitle.h"
#include "Core\Text.h"
#include "SceneMainGame.h"
#include "FadeScreen.h"

void SceneResult::Init(void)
{
	Texture::Load("result_background");

	result = new Object;
	result->AddComponent<RectPolygon2D>("result_background", Layer::BG_00);

	result->AddComponent<Text>()->LoadFont("‚¨‚Â‚Æ‚ßƒtƒHƒ“ƒg");
	result->GetComponent<Text>()->SetSize(100, 0);
	result->GetComponent<Text>()->area = { 750,300,1025,500 };
	result->GetComponent<Text>()->SetFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	result->GetComponent<Text>()->SetColor(Color::black);

	next_scene = false;
	FadeScreen::FadeIn(Color::white, 1.0f);
}

void SceneResult::Uninit(void)
{
	Texture::Release("result_background");
}

void SceneResult::Update(void)
{
	result->GetComponent<Text>()->SetText(std::to_string(SceneMainGame::gamescore));

	if (!next_scene && GetKeyboardTrigger(DIK_RETURN))
	{
		FadeScreen::FadeOut(Color::black, 1.0f, [this] {
			GameManager::GetInstance()->SetScene(new SceneTitle);
		});
		next_scene = true;
	}
}
