#include "Pamyu.h"

Pamyu::Pamyu(Vector3 pos, PamyuType pamyu_type)
{
	Texture::Load("pamyu_pink_wait00")->SetDivision(6, 10);

	switch (pamyu_type)
	{
	case PamyuType::Pa:
		//moji = AddComponent<Billboard>
		break;
	case PamyuType::Mi:
		break;
	case PamyuType::Yu:
		break;
	case PamyuType::Po:
		break;
	case PamyuType::Mo:
		break;
	case PamyuType::Yo:
		break;

	}
	Texture::Load("pa");

	//moji = AddComponent<Billboard>
	 

	for (int i = 0; i < 10; i++)
	{
		posHistory.push(pos);
	}

	state = 0;		// �Ǐ]����

	type = ObjectType::Item;	// �^�C�v

	pamyuType = pamyu_type;
}

Pamyu::~Pamyu()
{
}

void Pamyu::Uninit(void)
{

}

void Pamyu::Update(void)
{
	// �����̈ʒu���Z�b�g
	//moji->

}

void Pamyu::Follow(Vector3 frontPos)
{
	transform.position = frontPos;

	posHistory.push(frontPos);

	follower->Follow(posHistory.back());

	posHistory.pop();
}
