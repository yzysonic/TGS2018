#include "TimerObject.h"
#include "Core/Text.h"

#include <string>

TimerObject::TimerObject() {
	this->AddComponent<Text>()->LoadFont("‚¨‚Â‚Æ‚ßƒtƒHƒ“ƒg");
	this->GetComponent<Text>()->SetSize(100.f, 80.f);
	this->GetComponent<Text>()->area = { 500,0,SystemParameters::ResolutionX,SystemParameters::ResolutionY };
	this->GetComponent<Text>()->SetFormat(DT_SINGLELINE | DT_LEFT );

	score = 0;
	frame = 0;
	timer = 70;
}

void TimerObject::Update() {

	
	frame++;
	if (frame >= 60) {
		frame = 0;
		timer--;

	}

	this->GetComponent<Text>()->SetText("Timer::" + std::to_string(timer));
}

void TimerObject::Uninit() {
}

bool TimerObject::TimerEnd() {

	if (timer == 0) {
		return true;
	}

	return false;
}