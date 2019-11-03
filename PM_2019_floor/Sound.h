#pragma once

#include "ofApp.h"
#include <string>

class Sound {
public:

	Sound(string _soundFile); //コンストラクタ：引数：位置，半径，線の太さ，色
	~Sound(); //デストラクタ

	void update();

	bool stepOn;
	string soundFile;
	ofSoundPlayer soundPlayer;
};