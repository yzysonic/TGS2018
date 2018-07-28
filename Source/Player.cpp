#include "Player.h"

Player::Player(void)
{
	name = "Player";
	type = ObjectType::Player;

	Texture::Load("player")->SetDivision(6, 5);

	transform.scale = Vector3::one * 100.0f;
	billboard = AddComponent<Billboard>("player");
	billboard->SetPattern(0);
	animTimer.Reset(1 / 30.f);
	dir = Vector3(0.0f, 0.0f, 1.0f);

	for (int i = 0; i < GameManager::GetInstance()->Var<int>("NumPosHistory"); i++)
	{
		pos_history.push(Vector3::zero);
	}
}

void Player::Update(void)
{
	animTimer++;
	if (animTimer.TimeUp())
	{
		billboard->StepPattern();
	}

	if (GetKeyboardPress(DIK_UP))
		dir = Vector3(0.0f, 0.0f, 1.0f);
	else if (GetKeyboardPress(DIK_DOWN))
		dir = Vector3(0.0f, 0.0, -1.0f);
	else if (GetKeyboardPress(DIK_LEFT))
		dir = Vector3(-1.0f, 0.0f, 0.0f);
	if (GetKeyboardPress(DIK_RIGHT))
		dir = Vector3(1.0f, 0.0f, 0.0f);

	transform.position += dir*PlayerSpeed;
}

void Player::OnCollisionEnter(Object * other)
{
	if (other->type == ObjectType::Item)
	{

	}
}
