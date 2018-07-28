#pragma once
#include "core\Core.h"
#include "MainCamera.h"

#include "Pamyu.h"
#include "Player.h"

class PamyuManager : public Object
{
public:


	FrameTimer ft;
	int numPamyu;		// ぱみゅの出現数

	Player * player;
	Pamyu * pamyu;

	PamyuManager(Player *pl);
	~PamyuManager();

	void Uninit(void) override;
	void Update(void) override;

	Pamyu::PamyuType LotPamyu(void);	// ぱみゅを ランダムする
};