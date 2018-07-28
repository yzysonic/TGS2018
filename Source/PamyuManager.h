#pragma once
#include "core\Core.h"
#include "MainCamera.h"

#include "Pamyu.h"
#include "Player.h"

class PamyuManager : public Object
{
public:

	FrameTimer ft;
	int numPamyu;		// ‚Ï‚İ‚ã‚ÌoŒ»”

	Player * player;
	Pamyu * pamyu;

	PamyuManager(Player *pl);
	~PamyuManager();

	void Uninit(void) override;
	void Update(void) override;

	void PopPamyu(void);	// ‚Ï‚İ‚ã‚ğ Pop‚·‚é
	

};