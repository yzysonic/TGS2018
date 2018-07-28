#include "syukka.h"
#include "Player.h"
#include <list>
Syukka::Syukka() {
}

void Syukka::Update() {



}

void Syukka::Uninit() {


}

void Syukka::OnCollisionEnter(Object* other) {

	int score = 0;
	int combo = 0;
	int count = 0;

	if (other->type == ObjectType::Player) {
		Player* player = dynamic_cast<Player*>(other);

		Pamyu* pamyu = player->pamyu;

		while (pamyu != NULL) {

			score += 10 * (combo+1);
			if ((Pamyu::PamyuType)(count) == pamyu->pamyuType) {
				count++;
				if (count == 2){
					count = 0;
					combo++;
				}
			}
			else{
				count = 0;
			}
			pamyu = pamyu->follower;

		}

		
		if (scoreobj != nullptr) {
			scoreobj->AddScore(score);
		}

		player->Clearfollower();
	}




}

void Syukka::SetScorePointer(ScoreObject* ptr) {
	scoreobj = ptr;
}