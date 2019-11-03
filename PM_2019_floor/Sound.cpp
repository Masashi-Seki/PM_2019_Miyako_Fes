#include "Sound.h"
#include "ofApp.h"

using namespace std;

Sound::Sound(string _soundFile) {
	stepOn = false;
	soundFile = _soundFile;
	soundPlayer.load(soundFile);
	soundPlayer.setMultiPlay(true);
	//cout <<"+" <<soundPlayer.isLoaded() << endl; //load check
}

Sound::~Sound() {
	//���������
}

void Sound::update() {
	if (stepOn == true) {
		soundPlayer.play();
		stepOn = false;
	}
}
