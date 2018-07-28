#pragma once
#include "Core/Core.h"
#include <queue>

#define PlayerSpeed (40.0f)

class Player : public Object
{
public:
	Player(void);
	void Update(void) override;
	void OnCollisionEnter(Object * other);

private:
	Billboard * billboard;
	BoxCollider2D * collider;
	FrameTimer animTimer;
	std::queue<Vector3> pos_history;
};