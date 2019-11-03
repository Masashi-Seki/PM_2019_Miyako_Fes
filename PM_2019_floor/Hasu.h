#pragma once

#include "ofApp.h"
#include <string>

#define HASU_SIZE 200

class Hasu {
public:

	Hasu(string leafName_maru, string leafName_nami, string flowerName, ofPoint _pos, int _state); //�R���X�g���N�^�F�����F�ʒu�C���a�C���̑����C�F
	~Hasu(); //�f�X�g���N�^

	void update();
	void draw();

	ofPoint pos;	//x,y���W
	ofPoint noise;
	float size;		//�傫��
	bool stepOn;	//���܂ꂽ����
	float deg;		//��]�p

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