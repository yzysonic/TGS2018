#include "ScoreObject.h"
#include "Core/Text.h"

#include <string>

ScoreObject::ScoreObject() {

	this->AddComponent<Text>()->LoadFont("‚¨‚Â‚Æ‚ßƒtƒHƒ“ƒg");
	this->GetComponent<Text>()->SetSize(100.f, 80.f);
	this->GetComponent<Text>()->area = { 30,0,SystemParameters::ResolutionX,SystemParameters::ResolutionY };
	this->GetComponent<Text>()->SetFormat(DT_SINGLELINE | DT_LEFT );

	score = 0;




}

void ScoreObject::Update() {
	score++;

	this->GetComponent<Text>()->SetText("Score::"+std::to_string(score));
}

void ScoreObject::Uninit() {

}

int ScoreObject::GetScore() {
	return score;
}
