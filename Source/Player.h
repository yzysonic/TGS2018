#pragma once
#include "Core/Core.h"
#include <queue>

#define PlayerSpeed (3.0f)

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
	Vector3 dir;
	std::queue<Vector3> pos_history;
};