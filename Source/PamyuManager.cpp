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

		new Pamyu(Vector3(x, 0, z), (Pamyu::PamyuType)(Random(0, 5)));

		numPamyu++;
	}

	// 時間をセット
	ft.Reset(1);
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

			new Pamyu(Vector3(x, 0, z), (Pamyu::PamyuType)(Random(0, 5)));
			numPamyu++;
			//new Pamyu(Vector3(Randomf(-500, 500), 0, Randomf(-250, 250)), Pamyu::PamyuType::Mi);
		}

		ft.Reset();
	}



}

