#pragma once

#include "Core/Core.h"
#include "Player.h"
#include "MainCamera.h"
#include "DebugMenu.h"

class TestObject : public Object
{
public:
	TestObject(void);
	void Update(void) override;
	void OnCollisionEnter(Object* other) override;
	void OnCollisionStay(Object* object) override;
	void OnCollisionExit(Object* other) override;

private:
	BoxCollider2D * collider;
	bool collide;
	StaticModel * model;
}; 


class SceneYangTest : public Scene
{
public:
	void Init(void) override;
	void Update(void) override;
	void Uninit(void) override;

private:
	TestObject * test[10];
	Player * player;
	MainCamera * camera;
	DebugMenu * debug;
	FrameTimer timer;
	Object * test_model;
};