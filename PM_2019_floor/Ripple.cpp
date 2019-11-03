#include "Ripple.h"
#include "ofApp.h"

Ripple::Ripple(ofPoint _pos, int _radius, int _lineWidth, ofColor _color) {

	pos = _pos;
	color = _color;

	lineWidth = _lineWidth;
	radius = _radius;
	expandRate = 1; //固定

	dead = false;
	timer = 500; //固定
}

Ripple::~Ripple() {
	//メモリ解放
}

void Ripple::update() {
	//円をアップデート
	radius += expandRate;

	timer -= 1;
	color.a -= 0.5;

	if (timer < 0) {
		dead = true;
	}
}

void Ripple::draw() {
	//円を絵画
	ofSetColor(color.r, color.g, color.b, color.a);
	ofNoFill();
	ofSetLineWidth(lineWidth);
	ofCircle(pos.x, pos.y, radius);
}