#pragma once

#include "ofApp.h"
#include <string>

class Sound {
public:

	Sound(string _soundFile); //�R���X�g���N�^�F�����F�ʒu�C���a�C���̑����C�F
	~Sound(); //�f�X�g���N�^

	void update();

	bool stepOn;
	string soundFile;
	ofSoundPlayer soundPlayer;
};