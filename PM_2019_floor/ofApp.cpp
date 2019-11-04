#include "ofApp.h"

vector<Ripple *> ripples; //インスタンス作成
vector<Hasu *> hasus;
vector<ofImage *> image;
vector<Sound *> sound;
vector<Message *> message;
vector<Mask *> mask;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);

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
	/*
	ofFill();
	ofSetColor(200, 200, 0);
	ofRect(100, 900, 600, 150);
	ofRect(1250, 900, 600, 150);
	*/
}

//--------------------------------------------------------------
void ofApp::update(){

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
void ofApp::draw(){

	//枠の絵画
	ofPushStyle();
	ofSetColor(255, 255, 255);
	ofSetLineWidth(3);
	ofLine(vertex1_x, vertex1_y, vertex2_x, vertex2_y);
	ofLine(vertex2_x, vertex2_y, vertex3_x, vertex3_y);
	ofLine(vertex3_x, vertex3_y, vertex4_x, vertex4_y);
	ofLine(vertex4_x, vertex4_y, vertex1_x, vertex1_y);
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

	//メッセージの絵画
	ofPushStyle();
	for (int i = 0; i < message.size(); i++) {
		message[i]->draw();
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
void ofApp::keyPressed(int key){
	if (key == 'a') {
		createRipple(0, ofPoint(pos1_x, pos1_y), hasus[0]->state, ofRandom(3, 5)); //No.，位置，state，輪の数
	}

	else if (key == 'q') {
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
}
//--------------------------------------------------------------
void ofApp::createRipple(int _no, ofPoint _pos, int _state, int _rippleNum) {
	for (int i = 0; i < _rippleNum; i++) {
		if(hasus[_no]->state == 2) //花
			ripples.push_back(new Ripple(ofPoint(_pos.x, _pos.y), ofRandom(50, 100), 6, ofColor(ofRandom(70, 255), ofRandom(70, 255), 0)));
		else //葉
			ripples.push_back(new Ripple(ofPoint(_pos.x, _pos.y), ofRandom(50, 100), 6, ofColor(0, ofRandom(70, 255), ofRandom(70, 255))));
	}
	hasus[_no]->stepOn = true;
	sound[_no]->stepOn = true;
	
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
