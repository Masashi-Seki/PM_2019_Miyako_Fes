#pragma once

#include "ofApp.h"

class Ripple {
public:

	Ripple(ofPoint _pos, int radius, int _lineWidth, ofColor _color); //コンストラクタ：引数：位置，半径，線の太さ，色
	~Ripple(); //デストラクタ

	void update();
	void draw();

	ofColor color;		//r,g,b,a
	ofPoint pos;		//x,y座標
	float radius;		//半径
	int lineWidth;		//線太さ
	float expandRate;	//広がり率
	int timer;			//タイマー
	bool dead;			//死亡判定

};