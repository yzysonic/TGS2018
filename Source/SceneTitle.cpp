#include "SceneTitle.h"
#include "SceneMainGame.h"

void SceneTitle::Init(void) {

	// �w�i�F�i�w�i�摜�ƒu�������\��H�j
	Renderer::GetInstance()->getCamera()->backColor = Color(0xffffaa);

	//Texture::Load("background");
	Texture::Load("titlelogo");

	Object *titlelogo = new Object;
	//Object *titlebg = new Object;

	titlelogo->transform.position.x = - SystemParameters::ResolutionX * 0.1f;
	titlelogo->transform.position.y = SystemParameters::ResolutionY * 0.2f;
	titlelogo->AddComponent<RectPolygon2D>("titlelogo", Layer::BG_00);


	//titlebg->transform.position.x = SystemParameters::ResolutionX * 0.5f;
	//titlebg->AddComponent<RectPolygon2D>("background", Layer::BG_00);

	fTimer.Reset(5);		// ���Z�b�g�i�b���Łj�E�X�V�K�v

}

void SceneTitle::Uninit(void) {

	//Texture::Release("background");
	Texture::Release("titlelogo");

}

void SceneTitle::Update(void) {

	if (GetKeyboardTrigger(DIK_RETURN))
	{
		GameManager::GetInstance()->SetScene(new SceneMainGame);
	}

	fTimer++;	// �b���X�V
	fTimer.TimeUp();	// �^�C���A�b�v���m�F
}
