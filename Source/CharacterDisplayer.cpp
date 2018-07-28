#include "CharacterDisplayer.h"

CharacterDisplayer::CharacterDisplayer()
{
	numDisplayCharacters = 0;
	ft.Reset(5);
}

CharacterDisplayer::~CharacterDisplayer()
{
}

void CharacterDisplayer::Uninit(void)
{
}

void CharacterDisplayer::Update(void)
{
	ft.Step();
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
	if (numDisplayCharacters == 0) return;
	int i = 0;
	int size = min(75, 1000/numDisplayCharacters);
	while (!pamyuType.empty())
	{
		Pamyu::PamyuType pt = pamyuType.front();

		// Žš‚ð•\Ž¦
		Object *moji_object = new Object;
		moji_object->transform.scale = Vector3::one * size;
		//moji_object->transform.position = Vector3(0.0f, 0.0f, 0.0f);
		moji_object->transform.position = Vector3(-600.0f + i * size + size*0.2f, 0.0f, 330.0f);

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
