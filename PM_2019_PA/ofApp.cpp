/*
 * Tokyo Metropolitan University
 * Code of the projection show at Miyako fest.
 *
 * Code of the slave (PA).
 * Written by Masashi Seki
 *
 * 2019.10.12 Sat.
 *
 * -----
 * Set IP address of controller in ofApp.h
 * Change the device name of URL of function reply() in ofApp.cpp
 * -----
 */

#include "ofApp.h"

 //--------------------------------------------------------------
void ofApp::setup() {

	ofHideCursor(); //win and mac
	//CGDisplayHideCursor(NULL); //mac only

	ofBackground(0, 0, 0);
	ofSetFrameRate(60);

	sound.load("sound1.mp3");
	qr.load("sound2.mp3");
	logo.load("pm2019_logo.png");

	sound.setLoop(false);
	qr.setLoop(false);

	sender.setup(IP_CONTROLLER, PORT_TO_CONTROLLER);
	receiver.setup(PORT_TO_SLAVE);

	count_start = false;
	pauseFlag = false;
	framecount = 0;
	soundType = 0;

	width = ofGetWidth();
	height = ofGetHeight();

	//-- sound start --
	//count_start = true;
	//soundType = 2;
}

//--------------------------------------------------------------
void ofApp::update() {

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		if (m.getAddress() == "/pmap/media/play") {
			count_start = true;
			soundType = 1;
		}
		else if (m.getAddress() == "/pmap/media/QR_play") {
			count_start = true;
			soundType = 2;
		}
		else if (m.getAddress() == "/pmap/media/pause") {
			count_start = true;
			pauseFlag = true;
		}
		else if (m.getAddress() == "/pmap/media/rewind") {
			rewind();
		}
		else if (m.getAddress() == "/pmap/screen/off") {
			screenOff();
		}
		else if (m.getAddress() == "/pmap/screen/on") {
			screenOn();
		}
		else if (m.getAddress() == "/pmap/connection/ask") {
			reply();
		}
	}

	if (count_start) {

		framecount++;

		if (framecount > PLAY_ADJUST) {

			if (pauseFlag == true) {
				pause();
				//cout << "#0 " << endl;
			}
			else if (soundType == 1) {
				play();
				//cout << "#1 " << endl;
			}
			else if (soundType == 2) {
				QR_play();
				//cout << "#2 " << endl;
			}

			count_start = false;
			pauseFlag = false;
			framecount = 0;
		}

	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	if (!black) {
		logo.draw(0, 0);
	}
	else {
		ofRectangle(0, 0, width, height);
	}
	//debug
	//cout << count_start << " " << framecount << " " << movie_on << " " << videoType << " " << black << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'q') {
		black = !black;
		cout << "black:" << black << endl;
	}

	/*
	if (key == 'p') {
		count_start = true;
		soundType = 1;
	}
	else if (key == 's') {
		count_start = true;
		pauseFlag = true;
	}
	else if (key == 'r') {
		rewind();
	}
	*/

}

//--------------------------------------------------------------
void ofApp::play() {
	sound.setPaused(false);
	qr.setPaused(true);
	if (sound.getPosition() == 0.0f) {
		sound.play();
	}
	cout << "play" << endl;
}

//--------------------------------------------------------------
void ofApp::QR_play() {
	qr.setPaused(false);
	sound.setPaused(true);
	if (qr.getPosition() == 0.0f) {
		qr.play();
	}
	cout << "qr play" << endl;
}

//--------------------------------------------------------------
void ofApp::pause() {
	sound.setPaused(true);
	qr.setPaused(true);
	framecount = 0;
	cout << "pause" << endl;
}

//--------------------------------------------------------------
void ofApp::rewind() {
	sound.setPaused(true);
	sound.setPosition(0.0);
	qr.setPaused(true);
	qr.setPosition(0.0);
	soundType = 1;
	cout << "rewind" << endl;
}

//--------------------------------------------------------------
void ofApp::screenOff() {
	black = true;
	cout << "screen off" << endl;
}

//--------------------------------------------------------------
void ofApp::screenOn() {
	black = false;
	cout << "screen on" << endl;
}

//--------------------------------------------------------------
void ofApp::reply() {
	// osc message
	ofxOscMessage message;
	message.setAddress("/pmap/connection/responce/PA"); //change URL according to device name.

	//stalling
	for (int i = 0; i < 10000; i++);
	sender.sendMessage(message);

	cout << "replay" << endl;
}