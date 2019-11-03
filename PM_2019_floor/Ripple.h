#pragma once

#include "ofApp.h"

class Ripple {
public:

	Ripple(ofPoint _pos, int radius, int _lineWidth, ofColor _color); //�R���X�g���N�^�F�����F�ʒu�C���a�C���̑����C�F
	~Ripple(); //�f�X�g���N�^

	void update();
	void draw();

	ofColor color;		//r,g,b,a
	ofPoint pos;		//x,y���W
	float radius;		//���a
	int lineWidth;		//������
	float expandRate;	//�L���藦
	int timer;			//�^�C�}�[
	bool dead;			//���S����

};