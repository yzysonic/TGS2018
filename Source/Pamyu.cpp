#include "Pamyu.h"

Pamyu::Pamyu(Vector3 pos, PamyuType pamyu_type)
{
	name = "pamy";
	Texture::Load("pamyu_pink_wait00")->SetDivision(6, 10);
	body = AddComponent<Billboard>("pamyu_pink_wait00");
	body->SetPattern(0);
	collider = AddComponent<SphereCollider>();
	collider->radius = 10.0f;

	switch (pamyu_type)
	{
	case PamyuType::Pa:
		mojiObj = new Object;
		Texture::Load("pa");
		moji = mojiObj->AddComponent<Billboard>("pa");
		moji->SetPattern(0);
		break;
	case PamyuType::Mi:
		mojiObj = new Object;
		Texture::Load("mi");
		moji = mojiObj->AddComponent<Billboard>("mi");
		moji->SetPattern(0);
		break;
	case PamyuType::Yu:
		mojiObj = new Object;
		Texture::Load("yu");
		moji = mojiObj->AddComponent<Billboard>("yu");
		moji->SetPattern(0);
		break;
	case PamyuType::Po:
		mojiObj = new Object;
		Texture::Load("po");
		moji = mojiObj->AddComponent<Billboard>("po");
		moji->SetPattern(0);
		break;
	case PamyuType::Mo:
		mojiObj = new Object;
		Texture::Load("mo");
		moji = mojiObj->AddComponent<Billboard>("mo");
		moji->SetPattern(0);
		break;
	case PamyuType::Yo:
		mojiObj = new Object;
		Texture::Load("yo");
		moji = mojiObj->AddComponent<Billboard>("yo");
		moji->SetPattern(0);
		break;

	}

	//moji = AddComponent<Billboard>
	 

	for (int i = 0; i < GameManager::GetInstance()->Var<int>("NumPosHistory"); i++)
	{
		posHistory.push(pos);
	}

	state = 0;		// 追従せず

	type = ObjectType::Item;	// タイプ

	pamyuType = pamyu_type;

	transform.position = pos;
	transform.scale = Vector3::one * 100.0f;
	mojiObj->transform.scale = transform.scale * 0.7f;

	ft.Reset(1 / 30.0f);
	
	follower = NULL;
}

Pamyu::~Pamyu()
{
}

void Pamyu::Uninit(void)
{

}

void Pamyu::Update(void)
{
	// 文字の位置をセット
	//moji->

	ft++;
	if (ft.TimeUp())
	{
		body->StepPattern();
	}
	static float off = 100;
	mojiObj->transform.position = transform.position + Vector3(0, 0, 0);

}

void Pamyu::Follow(Vector3 frontPos)
{
	transform.position = frontPos;

	posHistory.push(frontPos);

	if (follower != NULL)
	{
		follower->Follow(posHistory.front());
	}

	posHistory.pop();
}
