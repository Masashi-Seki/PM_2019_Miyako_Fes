#pragma once

#include "ofApp.h"

class Mask {
public:

	Mask();
	~Mask(); //デストラクタ

	void update();
	void draw();

	bool black;
	ofColor color;
	int width;
	int height;
};