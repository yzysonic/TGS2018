#include "CharacterDisplayer.h"

CharacterDisplayer::CharacterDisplayer()
{
	numDisplayCharacters = 0;
	ft.Reset(2);
}

CharacterDisplayer::~CharacterDisplayer()
{
}

void CharacterDisplayer::Uninit(void)
{
}

void CharacterDisplayer::Update(void)
{
	if (ft.TimeUp())
	{
		// Žš‚ðÁ‚·
		while (!moji_list.empty())
		{
			moji_list.front()->Destroy();
			moji_list.pop();
		}

	}
}



void CharacterDisplayer::InitDisplayCharacter(void)
{
	while (!moji_list.empty())
	{
		moji_list.front()->Destroy();
		moji_list.pop();
	}
}

void CharacterDisplayer::SetDisplayCharacter(Pamyu::PamyuType pt)
{
	numDisplayCharacters++;
	pamyuType.push(pt);
}

void CharacterDisplayer::FinishSetCharacter(void)
{
	int i = 0;
	int size = min(50, 1000/numDisplayCharacters);
	while (!pamyuType.empty())
	{
		Pamyu::PamyuType pt = pamyuType.front();

		// Žš‚ð•\Ž¦
		Object *moji_object = new Object;
		moji_object->transform.position = Vector3(-500.0f + i * 50.0f, -200.0f, 0.0f);
		
		switch (pt)
		{
		case Pamyu::PamyuType::Pa:
			moji_object->AddComponent<Billboard>("pa");
			break;
		case Pamyu::PamyuType::Mi:
			moji_object->AddComponent<Billboard>("mi");
			break;
		case Pamyu::PamyuType::Yu:
			moji_object->AddComponent<Billboard>("yu");
			break;
		case Pamyu::PamyuType::Po:
			moji_object->AddComponent<Billboard>("po");
			break;
		case Pamyu::PamyuType::Mo:
			moji_object->AddComponent<Billboard>("mo");
			break;
		case Pamyu::PamyuType::Yo:
			moji_object->AddComponent<Billboard>("yo");
			break;

		}
		moji_list.push(moji_object);

		pamyuType.pop();
		i++;
	}

	numDisplayCharacters = 0;
	ft.Reset();
}
