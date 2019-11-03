#include "Hasu.h"
#include "ofApp.h"

#define _USE_MATH_DEFINES
#include "math.h"

using namespace std;

Hasu::Hasu(string leafName_maru, string leafName_nami, string flowerName, ofPoint _pos, int _state) {
	pos = _pos;
	deg = ofRandom(0, 360);
	x_deg = ofRandom(0, 360);
	y_deg = ofRandom(0, 360);

	stepOn = false;
	size = HASU_SIZE;

	leaf_maru.load(leafName_maru);
	leaf_nami.load(leafName_nami);
	flower.load(flowerName);

	state = _state;

	x_moveRate = ofRandom(5, 10) / 10.0;
	y_moveRate = ofRandom(5, 10) / 10.0;

	cout << x_moveRate << "	" << y_moveRate << endl;

	impact = 0;
}

Hasu::~Hasu() {
	//メモリ解放
}

void Hasu::update() {

	noise.x = 10 * cos(x_deg* M_PI / 180.0); //<<<
	noise.y = 10 * sin(y_deg* M_PI / 180.0); //<<<

	x_deg += x_moveRate; //<<<
	y_deg += y_moveRate; //<<<

	if (x_deg > 360) x_deg = 0;
	if (y_deg > 360) y_deg = 0;

	if (stepOn == true) {
		impact = 30;
		stepOn = false;
	}
	
}

void Hasu::draw() {

	ofPushMatrix();
	ofTranslate(pos.x, pos.y);
	ofRotateDeg(deg);
	ofTranslate(-pos.x, -pos.y);
	
	if (state == 0) {
		leaf_maru.draw((pos.x + noise.x) - size / 2, (pos.y + noise.y) - size / 2, size - impact, size - impact);
	}
	else if (state == 1) {
		leaf_nami.draw((pos.x + noise.x) - size / 2, (pos.y + noise.y) - size / 2, size - impact, size - impact);
	}
	else if (state == 2) {
		flower.draw((pos.x + noise.x) - size / 2, (pos.y + noise.y) - size / 2);
	}
	ofPopMatrix();

	if (impact > 0) {
		impact -= 0.5;
	}

}