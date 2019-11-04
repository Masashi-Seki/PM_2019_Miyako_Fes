#include "ofApp.h"

vector<Ripple *> ripples; //インスタンス作成
vector<Hasu *> hasus;
vector<ofImage *> image;
vector<Sound *> sound;
vector<Message *> message;
vector<Mask *> mask;

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(75, 75, 75);

	//pondMask.load("pondMask.png");
	water.load("hasuike.mp4");
	water.setLoopState(OF_LOOP_NORMAL);
	water.play();

	//hasusのコンストラクタ
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos1_x, pos1_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos2_x, pos2_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos3_x, pos3_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos4_x, pos4_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos5_x, pos5_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos6_x, pos6_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos7_x, pos7_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos8_x, pos8_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos9_x, pos9_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos10_x, pos10_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos11_x, pos11_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos12_x, pos12_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos13_x, pos13_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos14_x, pos14_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos15_x, pos15_y), ofRandom(0, 2)));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos16_x, pos16_y), ofRandom(0, 2)));

	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos17_x, pos17_y), 2));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos18_x, pos18_y), 2));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos19_x, pos19_y), 2));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos20_x, pos20_y), 2));
	hasus.push_back(new Hasu("leaf_maru.png", "leaf_nami.png", "hasu_big_edit.png", ofPoint(pos21_x, pos21_y), 2));

	sound.push_back(new Sound("poundScale_C.mp3"));
	sound.push_back(new Sound("poundScale_Cs.mp3"));
	sound.push_back(new Sound("poundScale_D.mp3"));
	sound.push_back(new Sound("poundScale_Ds.mp3"));
	sound.push_back(new Sound("poundScale_E.mp3"));
	sound.push_back(new Sound("poundScale_F.mp3"));
	sound.push_back(new Sound("poundScale_Fs.mp3"));
	sound.push_back(new Sound("poundScale_G.mp3"));
	sound.push_back(new Sound("poundScale_Gs.mp3"));
	sound.push_back(new Sound("poundScale_A.mp3"));
	sound.push_back(new Sound("poundScale_As.mp3"));
	sound.push_back(new Sound("poundScale_H.mp3"));
	sound.push_back(new Sound("poundScale_Chigh.mp3"));
	sound.push_back(new Sound("poundChord_ADF.mp3"));
	sound.push_back(new Sound("poundChord_HDG.mp3"));
	sound.push_back(new Sound("poundChord_GDE.mp3"));

	message.push_back(new Message("message1.png", ofPoint(1250, 850), ofPoint(100, 850)));
	message.push_back(new Message("message2.png", ofPoint(1250, 850), ofPoint(100, 850)));
	message.push_back(new Message("message3.png", ofPoint(1250, 850), ofPoint(100, 850)));

	mask.push_back(new Mask());

	messageType = 0;
	keyPressed('m');

	ofHideCursor();
	//CGDisplayHideCursor(NULL);

	ofSetFrameRate(60);
	ofSetCircleResolution(150);
	ofEnableSmoothing();

	//serial.setup("COM3", 9600); //Win
	serial.setup("/dev/tty.usbmodem1411",9600); //Mac

	serial.writeByte(0xFF); //controller reset

}

//--------------------------------------------------------------
void ofApp::update() {

	water.update();

	getData = 0;
	getData = serial.readByte();

	if (getData == 0x04) createRipple(0, ofPoint(pos1_x, pos1_y), hasus[0]->state, ofRandom(3, 5)); //No.，位置，state，輪の数
	else if (getData == 0x08) createRipple(1, ofPoint(pos2_x, pos2_y), hasus[1]->state, ofRandom(3, 5));
	else if (getData == 0x0C) createRipple(2, ofPoint(pos3_x, pos3_y), hasus[2]->state, ofRandom(3, 5));
	else if (getData == 0x10) createRipple(3, ofPoint(pos4_x, pos4_y), hasus[3]->state, ofRandom(3, 5));
	else if (getData == 0x03) createRipple(4, ofPoint(pos5_x, pos5_y), hasus[4]->state, ofRandom(3, 5));
	else if (getData == 0x07) createRipple(5, ofPoint(pos6_x, pos6_y), hasus[5]->state, ofRandom(3, 5));
	else if (getData == 0x0B) createRipple(6, ofPoint(pos7_x, pos7_y), hasus[6]->state, ofRandom(3, 5));
	else if (getData == 0x0F) createRipple(7, ofPoint(pos8_x, pos8_y), hasus[7]->state, ofRandom(3, 5));
	else if (getData == 0x02) createRipple(8, ofPoint(pos9_x, pos9_y), hasus[8]->state, ofRandom(3, 5));
	else if (getData == 0x06) createRipple(9, ofPoint(pos10_x, pos10_y), hasus[9]->state, ofRandom(3, 5));
	else if (getData == 0x0A) createRipple(10, ofPoint(pos11_x, pos11_y), hasus[10]->state, ofRandom(3, 5));
	else if (getData == 0x0E) createRipple(11, ofPoint(pos12_x, pos12_y), hasus[11]->state, ofRandom(3, 5));
	else if (getData == 0x01) createRipple(12, ofPoint(pos13_x, pos13_y), hasus[12]->state, ofRandom(3, 5));
	else if (getData == 0x05) createRipple(13, ofPoint(pos14_x, pos14_y), hasus[13]->state, ofRandom(3, 5));
	else if (getData == 0x09) createRipple(14, ofPoint(pos15_x, pos15_y), hasus[14]->state, ofRandom(3, 5));
	else if (getData == 0x0D) createRipple(15, ofPoint(pos16_x, pos16_y), hasus[15]->state, ofRandom(3, 5));

	for (int i = 0; i < ripples.size(); i++) {
		ripples[i]->update();

		//使い終わったメモリは解放
		if (ripples[i]->dead == true) {
			ripples.erase(ripples.begin() + i);
		}
	}

	for (int i = 0; i < hasus.size(); i++) {
		hasus[i]->update();
	}

	for (int i = 0; i < sound.size(); i++) {
		sound[i]->update();
	}

	for (int i = 0; i < mask.size(); i++) {
		mask[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	/*
	//枠の絵画
	ofPushStyle();
	ofSetColor(255, 255, 255);
	ofSetLineWidth(3);
	ofLine(vertex1_x, vertex1_y, vertex2_x, vertex2_y);
	ofLine(vertex2_x, vertex2_y, vertex3_x, vertex3_y);
	ofLine(vertex3_x, vertex3_y, vertex4_x, vertex4_y);
	ofLine(vertex4_x, vertex4_y, vertex1_x, vertex1_y);
	ofPopStyle();
	*/

	//動画の絵画
	water.draw(0, 0);

	/*
	//池マスクの絵画
	pondMask.draw(0, 0);
	*/
	//メッセージの絵画
	ofPushStyle();
	for (int i = 0; i < message.size(); i++) {
		message[i]->draw();
	}
	ofPopStyle();

	//波紋の絵画
	ofPushStyle();
	for (int i = 0; i < ripples.size(); i++) {
		ripples[i]->draw();
	}
	ofPopStyle();

	//蓮の絵画
	ofPushStyle();
	for (int i = 0; i < hasus.size(); i++) {
		hasus[i]->draw();
	}
	ofPopStyle();

	//マスクの絵画
	ofPushStyle();
	for (int i = 0; i < mask.size(); i++) {
		mask[i]->draw();
	}
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == 'q') {
		mask[0]->black = !mask[0]->black;
	}

	else if (key == 'm') {

		switch (messageType) {
		case 0:
			message[0]->state = true;
			message[1]->state = false;
			message[2]->state = false;
			break;
		case 1:
			message[0]->state = false;
			message[1]->state = true;
			message[2]->state = false;
			break;
		case 2:
			message[0]->state = false;
			message[1]->state = false;
			message[2]->state = true;
			break;
		default:
			break;
		}

		messageType++;
		if (messageType > 2) messageType = 0;
	}

	else if (key == '5') createRipple(0, ofPoint(pos1_x, pos1_y), hasus[0]->state, ofRandom(3, 5)); //No.，位置，state，輪の数
	else if (key == '4') createRipple(1, ofPoint(pos2_x, pos2_y), hasus[1]->state, ofRandom(3, 5));
	else if (key == '3') createRipple(2, ofPoint(pos3_x, pos3_y), hasus[2]->state, ofRandom(3, 5));
	else if (key == '2') createRipple(3, ofPoint(pos4_x, pos4_y), hasus[3]->state, ofRandom(3, 5));
	else if (key == 't') createRipple(4, ofPoint(pos5_x, pos5_y), hasus[4]->state, ofRandom(3, 5));
	else if (key == 'r') createRipple(5, ofPoint(pos6_x, pos6_y), hasus[5]->state, ofRandom(3, 5));
	else if (key == 'e') createRipple(6, ofPoint(pos7_x, pos7_y), hasus[6]->state, ofRandom(3, 5));
	else if (key == 'w') createRipple(7, ofPoint(pos8_x, pos8_y), hasus[7]->state, ofRandom(3, 5));
	else if (key == 'g') createRipple(8, ofPoint(pos9_x, pos9_y), hasus[8]->state, ofRandom(3, 5));
	else if (key == 'f') createRipple(9, ofPoint(pos10_x, pos10_y), hasus[9]->state, ofRandom(3, 5));
	else if (key == 'd') createRipple(10, ofPoint(pos11_x, pos11_y), hasus[10]->state, ofRandom(3, 5));
	else if (key == 's') createRipple(11, ofPoint(pos12_x, pos12_y), hasus[11]->state, ofRandom(3, 5));
	else if (key == 'b') createRipple(12, ofPoint(pos13_x, pos13_y), hasus[12]->state, ofRandom(3, 5));
	else if (key == 'v') createRipple(13, ofPoint(pos14_x, pos14_y), hasus[13]->state, ofRandom(3, 5));
	else if (key == 'c') createRipple(14, ofPoint(pos15_x, pos15_y), hasus[14]->state, ofRandom(3, 5));
	else if (key == 'x') createRipple(15, ofPoint(pos16_x, pos16_y), hasus[15]->state, ofRandom(3, 5));


}
//--------------------------------------------------------------
void ofApp::createRipple(int _no, ofPoint _pos, int _state, int _rippleNum) {
	for (int i = 0; i < _rippleNum; i++) {
		if (hasus[_no]->state == 2) //花
			ripples.push_back(new Ripple(ofPoint(_pos.x, _pos.y), ofRandom(50, 100), 6, ofColor(ofRandom(70, 255), ofRandom(70, 255), 0)));
		else //葉
			ripples.push_back(new Ripple(ofPoint(_pos.x, _pos.y), ofRandom(50, 100), 6, ofColor(0, ofRandom(70, 255), ofRandom(70, 255))));
	}
	hasus[_no]->stepOn = true;
	sound[_no]->stepOn = true;

}
//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
