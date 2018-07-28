#pragma once
#include "core\Core.h"
#include <queue>

class Pamyu :public Object
{
public:

	enum PamyuType
	{
		Pa = 0,		// �u�ρv
		Mi,			// �u�݁v
		Yu,			// �u��v
		Po,
		Mo,
		Yo,
		// �u���̑��v
	};

	Billboard *moji;
	Billboard *body;
	SphereCollider * collider;

	int state;				// ���݂̏�ԁi0: �ҋ@, 1:�Ǐ]follow�j
	PamyuType pamyuType;	// �u�ρv�u�݁v�u��v�u���̑��v
	FrameTimer ft;

	Object *mojiObj;

	Pamyu *follower;		// ���̂ς݂�ւ̃|�C���^
	Pamyu(Vector3 pos, PamyuType pamyu_type);	// �w��ʒu�A�w��̃^�C�v�Ń|�b�v
	~Pamyu();

	std::queue<Vector3> posHistory;

	void Uninit(void) override;
	void Update(void) override;

	void Follow(Vector3 frontPos);
};