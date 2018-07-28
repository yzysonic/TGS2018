#pragma once
#include "core\Core.h"
#include <queue>

class Pamyu :public Object
{
public:

	enum PamyuType
	{
		Pa = 0,		// 「ぱ」
		Mi,			// 「み」
		Yu,			// 「ゆ」
		Po,
		Mo,
		Yo,
		// 「その他」
	};

	Billboard *moji;
	Billboard *body;
	SphereCollider * collider;

	int state;				// 現在の状態（0: 待機, 1:追従follow）
	PamyuType pamyuType;	// 「ぱ」「み」「ゅ」「その他」
	FrameTimer ft;

	Object *mojiObj;

	Pamyu *follower;		// 次のぱみゅへのポインタ
	Pamyu(Vector3 pos, PamyuType pamyu_type);	// 指定位置、指定のタイプでポップ
	~Pamyu();

	std::queue<Vector3> posHistory;

	void Uninit(void) override;
	void Update(void) override;

	void Follow(Vector3 frontPos);
};