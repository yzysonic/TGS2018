#pragma once
#include "core\Core.h"
#include "MainCamera.h"

#include "Pamyu.h"

class CharacterDisplayer :public Object
{
public:

	FrameTimer ft;

	int numDisplayCharacters;

	std::queue<Pamyu::PamyuType> pamyuType;
	std::queue<Object*> moji_list;

	CharacterDisplayer();
	~CharacterDisplayer();

	void Uninit(void) override;
	void Update(void) override;

	void InitDisplayCharacter(void);
	void SetDisplayCharacter(Pamyu::PamyuType pt);
	void FinishSetCharacter(void);
};