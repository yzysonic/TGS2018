#include "Shadow.h"

Shadow::Shadow(Object* target)
{
	AddComponent<Billboard>("shadow", Layer::BG_01);
	this->transform.scale.x = 85.0f;
	this->transform.scale.y = 130.0f;
	//this->transform.setRotation(0.5f*PI, 0.0f, 0.0f);
	this->target = &target->transform;
}

void Shadow::Update(void)
{
	this->transform.position = this->target->position;
}

void Shadow::SetOpacity(float value)
{
	this->GetComponent<RectPolygon>()->SetOpacity(value);
}
