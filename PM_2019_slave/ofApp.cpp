/*
* Tokyo Metropolitan University
* Code of the projection show at Miyako fest.
*
* Code of the slave (projector).
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

	cout << "p1:" << movie.isPlaying() << ", ";

	ofHideCursor(); //win and mac
					//CGDisplayHideCursor(NULL); //mac only

	ofBackground(0, 0, 0);
	ofSetFrameRate(60);

	cout << "p2:" << movie.isPlaying() << ", ";

	movie.load("movie1.mp4");
	qr.load("movie2.mp4");

	movie.setLoopState(OF_LOOP_NONE);
	qr.setLoopState(OF_LOOP_NONE);

	cout << "p3:" << movie.isPlaying() << ", ";

	sender.setup(IP_CONTROLLER, PORT_TO_CONTROLLER);
	receiver.setup(PORT_TO_SLAVE);

	cout << "p4:" << movie.isPlaying() << ", ";

	black = false;
	movie_on = false;
	count_start = false;
	pauseFlag = false;
	framecount = 0;
	videoType = 0;

	width = ofGetWidth();
	height = ofGetHeight();

	//--- Malfunction Countermeasure add 10/28 ---
	pause();
	rewind();
	//---

	cout << "p5:" << movie.isPlaying() << ", ";
	cout << count_start << " " << framecount << " " << movie_on << " " << videoType << " " << black << " " << pauseFlag << endl;
}

//--------------------------------------------------------------
void ofApp::update() {

	cout << "pU:" << movie.isPlaying() << ", ";

	movie.update();
	qr.update();

	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		cout << "GET:" << &m << ", ";
		cout << "p6:" << movie.isPlaying() << ", ";

		if (m.getAddress() == "/pmap/media/play") {
			count_start = true;
			videoType = 1;
			cout << "p7:" << movie.isPlaying() << ", ";
		}
		else if (m.getAddress() == "/pmap/media/QR_play") {
			count_start = true;
			videoType = 2;
			cout << "p8:" << movie.isPlaying() << ", ";
		}
		else if (m.getAddress() == "/pmap/media/pause") {
			count_start = true;
			pauseFlag = true;
			cout << "p9:" << movie.isPlaying() << ", ";
		}
		else if (m.getAddress() == "/pmap/media/rewind") {
			rewind();
			cout << "p10:" << movie.isPlaying() << ", ";
		}
		else if (m.getAddress() == "/pmap/screen/off") {
			screenOff();
			cout << "p11:" << movie.isPlaying() << ", ";
		}
		else if (m.getAddress() == "/pmap/screen/on") {
			screenOn();
			cout << "p12:" << movie.isPlaying() << ", ";
		}
		else if (m.getAddress() == "/pmap/connection/ask") {
			reply();
			cout << "p13:" << movie.isPlaying() << ", ";
		}
		cout << "p14:" << movie.isPlaying() << ", ";
	}

	cout << "p15:" << movie.isPlaying() << ", ";

	if (count_start) {

		framecount++;
		cout << "p16:" << movie.isPlaying() << ", ";

		if (framecount > PLAY_ADJUST) {
			movie_on = true;
			cout << "p17:" << movie.isPlaying() << ", ";

			if (pauseFlag == true) {
				pause();
				//cout << "#0 " << endl;
				cout << "p18:" << movie.isPlaying() << ", ";
			}
			else if (videoType == 1) {
				play();
				//cout << "#1 " << endl;
				cout << "p19:" << movie.isPlaying() << ", ";
			}
			else if (videoType == 2) {
				QR_play();
				//cout << "#2 " << endl;
				cout << "p20:" << movie.isPlaying() << ", ";
			}

			count_start = false;
			pauseFlag = false;
			framecount = 0;
			cout << "p21:" << movie.isPlaying() << ", ";
		}
		cout << "p22:" << movie.isPlaying() << ", ";
	}
	cout << "p23:" << movie.isPlaying() << ", ";
}

//--------------------------------------------------------------
void ofApp::draw() {

	cout << "p24:" << movie.isPlaying() << ", ";

	if (black == false && movie_on == true) {

		cout << "p25:" << movie.isPlaying() << ", ";

		if (videoType == 1) {
			movie.draw(0, 0, width, height);
			//cout << "+1 ";
			cout << "p26:" << movie.isPlaying() << ", ";
		}
		else if (videoType == 2) {
			qr.draw(0, 0, width, height);
			//cout << "+2 ";
			cout << "p27:" << movie.isPlaying() << ", ";
		}
		cout << "p28:" << movie.isPlaying() << ", ";
	}

	cout << "p29:" << movie.isPlaying() << ", ";

	//debug
	//cout << count_start << " " << framecount << " " << movie_on << " " << videoType << " " << black << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'q') {
		black = !black;
		cout << "black:" << black << endl;
	}

	if (key == 'p') {
		count_start = true;
		videoType = 1;
	}
	else if (key == 's') {
		count_start = true;
		pauseFlag = true;
	}
	else if (key == 'r') {
		rewind();
	}
}

//--------------------------------------------------------------
void ofApp::play() {
	cout << "p30:" << movie.isPlaying() << ", ";
	movie.setPaused(false);
	qr.setPaused(true);
	if (movie.getPosition() == 0.0f) {
		movie.play();
		cout << "p31:" << movie.isPlaying() << ", ";
	}
	cout << "play" << endl;
}

//--------------------------------------------------------------
void ofApp::QR_play() {
	cout << "p32:" << movie.isPlaying() << ", ";
	qr.setPaused(false);
	movie.setPaused(true);
	if (qr.getPosition() == 0.0f) {
		qr.play();
		cout << "p33:" << movie.isPlaying() << ", ";
	}
	cout << "qr play" << endl;
}

//--------------------------------------------------------------
void ofApp::pause() {
	movie.setPaused(true);
	qr.setPaused(true);
	framecount = 0;
	cout << "pause" << endl;
}

//--------------------------------------------------------------
void ofApp::rewind() {
	movie.setPaused(true);
	movie.setPosition(0.0);
	qr.setPaused(true);
	qr.setPosition(0.0);
	videoType = 1;
	movie_on = false;
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
	message.setAddress("/pmap/connection/responce/A"); //change URL according to device name.

													   //stalling
	for (int i = 0; i < 10000; i++);
	sender.sendMessage(message);

	cout << "replay" << endl;
}