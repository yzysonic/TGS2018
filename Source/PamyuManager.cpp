#include "PamyuManager.h"

PamyuManager::PamyuManager(Player *pl)
{
	numPamyu = 0;
	pamyu = NULL;

	player = pl;

	// ぱみゅ　を一定数出しておく

	for (int i = 0; i < 10; i++)
	{
		float x = Randomf(-500, 500);
		float z = Randomf(-250, 250);

		while (pow(player->transform.position.x - x, 2) + pow(player->transform.position.z - z, 2) < 250)
		{
			x = Randomf(-500, 500);
			z = Randomf(-250, 250);
		}

		new Pamyu(Vector3(x, 0, z), LotPamyu());

		numPamyu++;
	}

	// 時間をセット
	ft.Reset(3);
}

PamyuManager::~PamyuManager()
{
}

void PamyuManager::Uninit(void)
{
}

void PamyuManager::Update(void)
{

	ft.Step();

	if (ft.TimeUp())
	{
		if (numPamyu < 100)
		{
			float x = Randomf(-500, 500);
			float z = Randomf(-250, 250);

			while (pow(player->transform.position.x - x, 2) + pow(player->transform.position.z - z, 2) < 250)
			{
				x = Randomf(-500, 500);
				z = Randomf(-250, 250);
			}

			new Pamyu(Vector3(x, 0, z), LotPamyu());
			numPamyu++;
			//new Pamyu(Vector3(Randomf(-500, 500), 0, Randomf(-250, 250)), Pamyu::PamyuType::Mi);
		}

		ft.Reset();
	}



}

Pamyu::PamyuType PamyuManager::LotPamyu(void)
{

	int number = Random(0, 98);

	if (number < 25)
	{
		return Pamyu::PamyuType::Pa;
	}
	else if (number < 50)
	{
		return Pamyu::PamyuType::Mi;
	}
	else if (number < 75)
	{
		return Pamyu::PamyuType::Yu;
	}
	else if (number < 83)
	{
		return Pamyu::PamyuType::Po;
	}
	else if (number < 91)
	{
		return Pamyu::PamyuType::Mo;
	}
	else
	{
		return Pamyu::PamyuType::Yo;
	}
}

