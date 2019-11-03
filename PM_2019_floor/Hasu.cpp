#include "Hasu.h"
#include "ofApp.h"

Hasu::Hasu(string _fileName, ofPoint _pos) {
	fileName = _fileName;
	pos = _pos;
	deg = ofRandom(0, 360);

	stepOn = false;
	speed = 0;;
	state = false;
	counter = 0;
}

Hasu::~Hasu() {
	//ƒƒ‚ƒŠ‰ğ•ú
}

void Hasu::setState(bool _state){
	this->state = _state;
}

void Hasu::update() {
	if (stepOn == true) {
		speed = 10.0;
		stepOn = false;
	}

	if (speed > 0) {
		speed -= 0.1;
		deg += speed;
	}
}

void Hasu::draw() {
	//‰~‚ğŠG‰æ

}