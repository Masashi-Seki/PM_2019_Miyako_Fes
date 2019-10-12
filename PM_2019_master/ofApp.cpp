/*
 * Tokyo Metropolitan University
 * Code of the projection show at Miyako fest.
 *
 * Code of the controller.
 * Written by Masashi Seki
 *
 * 2019.8.3 Sat.
 *
 * -----
 * Set IP address of slaves in ofApp.h
 * Put in the font data "VerdanaRef.ttf" in "data" folder
 * -----
 */

#include "ofApp.h"

 //--------------------------------------------------------------
void ofApp::setup() {

	ofBackground(0, 0, 0); //background
	ofSetFrameRate(30); //30frames per sec

	// Fonts
	ofTrueTypeFont::setGlobalDpi(72);
	verdana.load("VerdanaRef.ttf", 50);
	verdana.setLineHeight(24);
	verdana.setLetterSpacing(1.0);

	// osc setting
	projector_A1.setup(IP_PROJECTOR_A1, PORT_TO_SLAVE);
	projector_B1.setup(IP_PROJECTOR_B1, PORT_TO_SLAVE);
	projector_B2.setup(IP_PROJECTOR_B2, PORT_TO_SLAVE);
	projector_C1.setup(IP_PROJECTOR_C1, PORT_TO_SLAVE);
	pa.setup(IP_PA, PORT_TO_SLAVE);

	receiver.setup(PORT_TO_CONTROLLER);

	//width = ofGetScreenWidth();
	//height = ofGetScreenHeight();

	cnState_A1 = 2; //0:..., 1:success, 2:failed
	cnState_B1 = 2;
	cnState_B2 = 2;
	cnState_C1 = 2;
	cnState_PA = 2;

	connectionState = false;
	frameCount = 0;
	black = false;
}

//--------------------------------------------------------------
void ofApp::update() {

	getTime();

	if (connectionState == true) {
		frameCount++;

		while (receiver.hasWaitingMessages()) {
			ofxOscMessage m;
			receiver.getNextMessage(&m);

			if (m.getAddress() == "/pmap/connection/responce/A") { cnState_A1 = 1; }
			else if (m.getAddress() == "/pmap/connection/responce/B1") { cnState_B1 = 1; }
			else if (m.getAddress() == "/pmap/connection/responce/B2") { cnState_B2 = 1; }
			else if (m.getAddress() == "/pmap/connection/responce/C") { cnState_C1 = 1; }
			else if (m.getAddress() == "/pmap/connection/responce/PA") { cnState_PA = 1; }
			else;
		}

		if (frameCount > TIMEOUT) {
			if (cnState_A1 == 0) cnState_A1 = 2;
			if (cnState_B1 == 0) cnState_B1 = 2;
			if (cnState_B2 == 0) cnState_B2 = 2;
			if (cnState_C1 == 0) cnState_C1 = 2;
			if (cnState_PA == 0) cnState_PA = 2;

			connectionState = false;
		}

		if (cnState_A1 == 1 && cnState_B1 == 1 && cnState_B2 == 1 && cnState_C1 == 1 && cnState_PA == 1) connectionState = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	verdana.load("VerdanaRef.ttf", 30);
	ofSetColor(30, 200, 200);
	verdana.drawString(time, 530, 50);

	verdana.load("VerdanaRef.ttf", 40);
	ofSetColor(30, 200, 200);
	verdana.drawString("Connection", 50, 450);

	verdana.drawString("Media & Screen", 50, 150 - 40);

	verdana.load("VerdanaRef.ttf", 30);
	ofSetColor(30, 200, 200);
	verdana.drawString("- Projector A1", 150, 550);
	verdana.drawString("- Projector B1", 150, 600);
	verdana.drawString("- Projector B2", 150, 650);
	verdana.drawString("- Projector C1", 150, 700);
	verdana.drawString("- PA", 150, 750);

	verdana.drawString("+ Media Play", 90, 200 - 40); verdana.drawString("'   '", 480, 200 - 40);
	verdana.drawString("+ Media Pause", 90, 250 - 40); verdana.drawString("' p '", 480, 250 - 40);
	verdana.drawString("+ Media Rewind", 90, 300 - 40); verdana.drawString("' r '", 480, 300 - 40);
	verdana.drawString("+ Screen Blind", 90, 350 - 40); verdana.drawString("' q '", 480, 350 - 40);
	verdana.drawString("+ QR code play", 90, 400 - 40); verdana.drawString("' g '", 480, 400 - 40);


	verdana.drawString("+ Connection Check", 90, 500); verdana.drawString("' c '", 480, 500);

	if (cnState_A1 == 1) { ofSetColor(0, 200, 100); verdana.drawString("success", 455, 550); }
	else if (cnState_A1 == 2) { ofSetColor(200, 100, 0); verdana.drawString("failed", 470, 550); }
	else if (cnState_A1 == 0) { ofSetColor(30, 200, 200); verdana.drawString("connecting...", 440, 550); }

	if (cnState_B1 == 1) { ofSetColor(0, 200, 100); verdana.drawString("success", 455, 600); }
	else if (cnState_B1 == 2) { ofSetColor(200, 100, 0); verdana.drawString("failed", 470, 600); }
	else if (cnState_B1 == 0) { ofSetColor(30, 200, 200); verdana.drawString("connecting...", 440, 600); }

	if (cnState_B2 == 1) { ofSetColor(0, 200, 100); verdana.drawString("success", 455, 650); }
	else if (cnState_B2 == 2) { ofSetColor(200, 100, 0); verdana.drawString("failed", 470, 650); }
	else if (cnState_B2 == 0) { ofSetColor(30, 200, 200); verdana.drawString("connecting...", 440, 650); }

	if (cnState_C1 == 1) { ofSetColor(0, 200, 100); verdana.drawString("success", 455, 700); }
	else if (cnState_C1 == 2) { ofSetColor(200, 100, 0); verdana.drawString("failed", 470, 700); }
	else if (cnState_C1 == 0) { ofSetColor(30, 200, 200); verdana.drawString("connecting...", 440, 700); }

	if (cnState_PA == 1) { ofSetColor(0, 200, 100); verdana.drawString("success", 455, 750); }
	else if (cnState_PA == 2) { ofSetColor(200, 100, 0); verdana.drawString("failed", 470, 750); }
	else if (cnState_PA == 0) { ofSetColor(30, 200, 200); verdana.drawString("connecting...", 440, 750); }
}

//--------------------------------------------------------------
void ofApp::getTime() {

	if (ofGetSeconds() < 10)
		s = "0" + ofToString(ofGetSeconds(), 0);
	else
		s = ofToString(ofGetSeconds(), 0);
	if (ofGetMinutes() < 10)
		m = "0" + ofToString(ofGetMinutes(), 0);
	else
		m = ofToString(ofGetMinutes(), 0);

	if (ofGetHours() < 10)
		h = "0" + ofToString(ofGetHours(), 0);
	else
		h = ofToString(ofGetHours(), 0);

	time = h + ":" + m + ":" + s;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	switch (key) {
	case 'c':
		connectionCheck();
		cout << "connection check" << endl;
		break;

	case ' ':
		allPlay();
		cout << "main play" << endl;
		break;

	case 'p':
		allPause();
		cout << "pause" << endl;
		break;

	case 'r':
		allRewind();
		cout << "rewind" << endl;
		break;

	case 'q':
		black = (!black);
		if (black == false) allScreenOn();
		else if (black == true) allScreenOff();
		else;
		cout << "black: " << black << endl;
		break;

	case 'g':
		allQR_Play();
		cout << "qr play" << endl;
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------

void ofApp::connectionCheck() {

	cnState_A1 = 0;
	cnState_B1 = 0;
	cnState_B2 = 0;
	cnState_C1 = 0;
	cnState_PA = 0;

	// osc message
	ofxOscMessage message;
	message.setAddress("/pmap/connection/ask");

	//sendmessages
	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);

	connectionState = true;
	frameCount = 0;
}

//--------------------------------------------------------------
void ofApp::allPlay() {

	ofxOscMessage message;
	message.setAddress("/pmap/media/play");

	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);
}

//--------------------------------------------------------------
void ofApp::allPause() {

	ofxOscMessage message;
	message.setAddress("/pmap/media/pause");

	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);
}

//--------------------------------------------------------------
void ofApp::allRewind() {

	ofxOscMessage message;
	message.setAddress("/pmap/media/rewind");

	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);
}

//--------------------------------------------------------------
void ofApp::allScreenOff() {

	ofxOscMessage message;
	message.setAddress("/pmap/screen/off");

	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);
}

//--------------------------------------------------------------
void ofApp::allScreenOn() {

	ofxOscMessage message;
	message.setAddress("/pmap/screen/on");

	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);
}

//--------------------------------------------------------------
void ofApp::allQR_Play() {

	ofxOscMessage message;
	message.setAddress("/pmap/media/QR_play");

	projector_A1.sendMessage(message);
	projector_B1.sendMessage(message);
	projector_B2.sendMessage(message);
	projector_C1.sendMessage(message);
	pa.sendMessage(message);
}
