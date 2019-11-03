#pragma once

#include "ofApp.h"
#include <string>

#define HASU_SIZE 200

class Hasu {
public:

	Hasu(string _fileName, ofPoint _pos); //�R���X�g���N�^�F�����F�ʒu�C���a�C���̑����C�F
	~Hasu(); //�f�X�g���N�^
	void setState(bool _state);

	void update();
	void draw();

	string fileName;
	ofPoint pos;	//x,y���W
	float size;		//�傫��
	bool stepOn;	//���܂ꂽ����
	float speed;	//��]���x
	float deg;		//��]�p
	bool state;		//��� 0;�t�C1:��
	int counter;

};