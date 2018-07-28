#include "Player.h"

Player::Player(Vector3 pos)
{
	name = "Player";
	type = ObjectType::Player;

	Texture::Load("pamyu_pink_move_back")->SetDivision(6, 5);
	Texture::Load("pamyu_pink_move_front")->SetDivision(6, 5);
	Texture::Load("pamyu_pink_move_left")->SetDivision(6, 5);
	Texture::Load("pamyu_pink_move_right")->SetDivision(6, 5);

	texture[0] = Texture::Get("pamyu_pink_move_back");
	texture[1] = Texture::Get("pamyu_pink_move_front");
	texture[2] = Texture::Get("pamyu_pink_move_left");
	texture[3] = Texture::Get("pamyu_pink_move_right");

	transform.scale = Vector3::one * 100.0f;
	transform.position = pos;
	billboard = AddComponent<Billboard>("pamyu_pink_move_back");
	billboard->SetPattern(0);
	collider = AddComponent<SphereCollider>();
	collider->radius = 20.0f;

	shadow = new Shadow(this);

	animTimer.Reset(1 / 30.f);
	dir = Vector3(0.0f, 0.0f, 1.0f);

	for (int i = 0; i < GameManager::GetInstance()->Var<int>("NumPosHistory"); i++)
	{
		pos_history.push(pos);
	}

	pamyu = nullptr;
}

void Player::Update(void)
{
	animTimer++;
	if (animTimer.TimeUp())
	{
		billboard->StepPattern();
	}

	if (GetKeyboardPress(DIK_UP))
	{
		dir = Vector3(0.0f, 0.0f, 1.0f);
		billboard->pTexture = texture[0];
	}
	else if (GetKeyboardPress(DIK_DOWN))
	{
		dir = Vector3(0.0f, 0.0, -1.0f);
		billboard->pTexture = texture[1];
	}
	else if (GetKeyboardPress(DIK_LEFT))
	{
		dir = Vector3(-1.0f, 0.0f, 0.0f);
		billboard->pTexture = texture[2];
	}
	if (GetKeyboardPress(DIK_RIGHT))
	{
		dir = Vector3(1.0f, 0.0f, 0.0f);
		billboard->pTexture = texture[3];
	}

	transform.position += dir*PlayerSpeed;

	if (transform.position.x < -500.0f)
		transform.position.x += 1000.0f;
	else if(transform.position.x > 500.0f)
		transform.position.x -= 1000.0f;
	else if (transform.position.z < -250.0f)
		transform.position.z += 500.0f;
	else if (transform.position.z > 250.0f)
		transform.position.z -= 500.0f;


	pos_history.push(transform.position);

	if (pamyu)
	{
		pamyu->Follow(pos_history.front());
	}

	pos_history.pop();
	
}

void Player::OnCollisionEnter(Object * other)
{

	if (other->type == ObjectType::Item)
	{
		auto newpamyu = (Pamyu*)other;
		if (newpamyu->state == 0)
		{
			newpamyu->state = 1;

			if (!pamyu)
				pamyu = newpamyu;
			else
			{
				auto last = pamyu;
				while (last->follower)
					last = last->follower;
				last->follower = newpamyu;
			}
		}
		else
		{

		}
		
	}

}

void Player::Clearfollower() {

	if (pamyu == nullptr) {
		return;
	}
	Pamyu* temp = pamyu;
	Pamyu* old;
	while (true){
		old = temp;
		temp = old->follower;
		old->mojiObj->Destroy();
		old->Destroy();


		if (temp == NULL) {
			break;
		}
	}
	pamyu = nullptr;

}
