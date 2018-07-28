#pragma once
#include "Core/Core.h"
#include "Pamyu.h"
#include "Shadow.h"
#include <queue>

#define PlayerSpeed (3.0f)

class Player : public Object
{
public:
	Player(Vector3 pos);
	Pamyu * pamyu;

	void Update(void) override;
	void OnCollisionEnter(Object * other);
	void Clearfollower();
private:
	Billboard * billboard;
	SphereCollider * collider;
	FrameTimer animTimer;
	Vector3 dir;
	std::queue<Vector3> pos_history;
	Shadow * shadow;
	Texture * texture[4];
	bool atari;
};