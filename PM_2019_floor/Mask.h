#pragma once

#include "ofApp.h"

class Mask {
public:

	Mask();
	~Mask(); //�f�X�g���N�^

	void update();
	void draw();

	bool black;
	ofColor color;
	int width;
	int height;
};