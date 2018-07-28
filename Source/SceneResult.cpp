#include "SceneResult.h"
#include "SceneTitle.h"
#include "Core\Text.h"
#include "SceneMainGame.h"
void SceneResult::Init(void) {



	score = new Object;
	
	score->AddComponent<Text>()->LoadFont("‚¨‚Â‚Æ‚ßƒtƒHƒ“ƒg");
	score->GetComponent<Text>()->SetSize(100.f, 80.f);
	score->GetComponent<Text>()->area = { 30,0,SystemParameters::ResolutionX,SystemParameters::ResolutionY };
	score->GetComponent<Text>()->SetFormat(DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	score->GetComponent<Text>()->SetColor(Color::black);

}

void SceneResult::Uninit(void) {
}

void SceneResult::Update(void) {


	score->GetComponent<Text>()->SetText(std::to_string(SceneMainGame::gamescore));


	if (GetKeyboardTrigger(DIK_RETURN))
	{
		GameManager::GetInstance()->SetScene(new SceneTitle);
	}
}
