#pragma once

#include "ofApp.h"
#include <string>

#define HASU_SIZE 200

class Hasu {
public:

	Hasu(string leafName_maru, string leafName_nami, string flowerName, ofPoint _pos, int _state); //コンストラクタ：引数：位置，半径，線の太さ，色
	~Hasu(); //デストラクタ

	void update();
	void draw();

	ofPoint pos;	//x,y座標
	ofPoint noise;
	float size;		//大きさ
	bool stepOn;	//踏まれた判定
	float deg;		//回転角

	float x_deg;
	float y_deg;

	ofImage leaf_maru;
	ofImage leaf_nami;
	ofImage flower;

	int state;

	float impact;

	float x_moveRate;
	float y_moveRate;
};