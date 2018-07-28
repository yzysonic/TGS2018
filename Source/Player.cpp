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
}

void Player::OnCollisionEnter(Object * other)
{
	if (other->type == ObjectType::Item)
	{

	}
}
