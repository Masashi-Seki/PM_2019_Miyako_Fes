#pragma once

#include "ofApp.h"
#include <string>

class Message {
public:

	Message(string _message, ofPoint r_pos, ofPoint l_pos);
	~Message(); //デストラクタ

	void draw();

	bool state;
	ofImage message_R;
	ofImage message_L;

	ofPoint r_pos;
	ofPoint l_pos;
};