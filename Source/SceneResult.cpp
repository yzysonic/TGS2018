#include "SceneResult.h"
#include "SceneTitle.h"
void SceneResult::Init(void) {




}

void SceneResult::Uninit(void) {
}

void SceneResult::Update(void) {


	if (GetKeyboardTrigger(DIK_RETURN))
	{
		GameManager::GetInstance()->SetScene(new SceneTitle);
	}
}
