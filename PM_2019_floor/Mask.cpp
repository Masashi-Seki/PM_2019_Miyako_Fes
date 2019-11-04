#include "Mask.h"
#include "ofApp.h"

using namespace std;

Mask::Mask() {
	color.r = color.g = color.b = 0;
	color.a = 255; //dark

	width = ofGetWidth();
	height = ofGetHeight();

	black = false;
}

Mask::~Mask() {
}

void Mask::update() {
	if (black == true) {
		if (color.a < 255) color.a++;
	}
	else {
		if (color.a > 0) color.a--;
	}
}

void Mask::draw() {
	ofSetColor(color.r, color.g, color.b, color.a);
	ofFill();
	ofRect(0, 0, width, height);
}
