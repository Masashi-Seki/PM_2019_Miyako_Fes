#pragma once

#include "ofApp.h"
#include <string>

#define HASU_SIZE 200

class Hasu {
public:

	Hasu(string _fileName, ofPoint _pos); //コンストラクタ：引数：位置，半径，線の太さ，色
	~Hasu(); //デストラクタ
	void setState(bool _state);

	void update();
	void draw();

	string fileName;
	ofPoint pos;	//x,y座標
	float size;		//大きさ
	bool stepOn;	//踏まれた判定
	float speed;	//回転速度
	float deg;		//回転角
	bool state;		//状態 0;葉，1:花
	int counter;

};