#include "Ripple.h"
#include "ofApp.h"

Ripple::Ripple(ofPoint _pos, int _radius, int _lineWidth, ofColor _color) {

	pos = _pos;
	color = _color;

	lineWidth = _lineWidth;
	radius = _radius;
	expandRate = 1; //�Œ�

	dead = false;
	timer = 500; //�Œ�
}

Ripple::~Ripple() {
	//���������
}

void Ripple::update() {
	//�~���A�b�v�f�[�g
	radius += expandRate;

	timer -= 1;
	color.a -= 0.5;

	if (timer < 0) {
		dead = true;
	}
}

void Ripple::draw() {
	//�~���G��
	ofSetColor(color.r, color.g, color.b, color.a);
	ofNoFill();
	ofSetLineWidth(lineWidth);
	ofCircle(pos.x, pos.y, radius);
}