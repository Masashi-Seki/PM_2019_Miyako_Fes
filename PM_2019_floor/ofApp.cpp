#include "ofApp.h"

vector<Ripple *> ripples; //インスタンス作成
vector<Hasu *> hasus;
vector<ofImage *> image;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);

	//シリアル通信設定
	//serial.setup("COM3", 9600); //win
	//serial.setup("/dev/tty.usbmodem1411",9600); //mac
	//serial.writeByte(0xFF); //コントローラリセット

	/*
	hasuike.load("hasuike_suimen_5s.mp4");
	hasuike.setLoopState(OF_LOOP_NORMAL);
	hasuike.play();
	*/

	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos1_x, pos1_y)));
	hasus.push_back(new Hasu("leef_nami.png", ofPoint(pos2_x, pos2_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos3_x, pos3_y)));
	hasus.push_back(new Hasu("leef_nami.png", ofPoint(pos4_x, pos4_y)));
	hasus.push_back(new Hasu("leef_nami.png", ofPoint(pos5_x, pos5_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos6_x, pos6_y)));
	hasus.push_back(new Hasu("leef_nami.png", ofPoint(pos7_x, pos7_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos8_x, pos8_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos9_x, pos9_y)));
	hasus.push_back(new Hasu("leef_mani.png", ofPoint(pos10_x, pos10_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos11_x, pos11_y)));
	hasus.push_back(new Hasu("leef_mani.png", ofPoint(pos12_x, pos12_y)));
	hasus.push_back(new Hasu("leef_nami.png", ofPoint(pos13_x, pos13_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos14_x, pos14_y)));
	hasus.push_back(new Hasu("leef_nami.png", ofPoint(pos15_x, pos15_y)));
	hasus.push_back(new Hasu("leef_maru.png", ofPoint(pos16_x, pos16_y)));
	
	for (int i = 0; i < hasus.size(); i++) {
		image.push_back(new ofImage());
		if (i == 0 || i == 2 || i == 5 || i == 7 || i == 8 || i == 10 || i == 13 || i == 15 ) {
			image[i]->load("leef_maru.png");
		}
		else {
			image[i]->load("leef_nami.png");
		}
	}

	for (int i = 0; i < 4; i++) {
		image[ofRandom(0, 15)]->load("hasu_big_edit.png");
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
	//cout << rect[0]->resetFlag << endl;
	//cout << ripples.size() << endl;

	//コントローラからのデータ取得
	//getData = serial.readByte();

	for (int i = 0; i < ripples.size(); i++) {
		ripples[i]->update();

		//使い終わったメモリは解放
		if (ripples[i]->dead == true) {
			ripples.erase(ripples.begin() + i);
		}
	}

	/*
	if (getData == 0x01) {
		serial.writeByte(0x01);
		cout << "button 1 pushed" << endl;
		//---
		// ボタン1が押されたときにやる処理を記述
		//---
	}
	else if (getData == 0x02) {
		serial.writeByte(0x02);
		cout << "button 2 pushed" << endl;
	}
	else if (getData == 0x03) {
		serial.writeByte(0x03);
		cout << "button 3 pushed" << endl;
	}
	else if (getData == 0x04) {
		serial.writeByte(0x04);
		cout << "button 4 pushed" << endl;
	}
	else if (getData == 0x05) {
		serial.writeByte(0x05);
		cout << "button 5 pushed" << endl;
	}
	else if (getData == 0x06) {
		serial.writeByte(0x06);
		cout << "button 6 pushed" << endl;
	}
	else if (getData == 0x07) {
		serial.writeByte(0x07);
		cout << "button 7 pushed" << endl;
	}
	else if (getData == 0x08) {
		serial.writeByte(0x08);
		cout << "button 8 pushed" << endl;
	}
	else if (getData == 0x09) {
		serial.writeByte(0x09);
		cout << "button 9 pushed" << endl;
	}
	else if (getData == 0x0A) {
		serial.writeByte(0x0A);
		cout << "button 10 pushed" << endl;
	}
	else if (getData == 0x0B) {
		serial.writeByte(0x0B);
		cout << "button 11 pushed" << endl;
	}
	else if (getData == 0x0C) {
		serial.writeByte(0x0C);
		cout << "button 12 pushed" << endl;
	}
	else if (getData == 0x0D) {
		serial.writeByte(0x0D);
		cout << "button 13 pushed" << endl;
	}
	else if (getData == 0x0E) {
		serial.writeByte(0x0E);
		cout << "button 14 pushed" << endl;
	}
	else if (getData == 0x0F) {
		serial.writeByte(0x0F);
		cout << "button 15 pushed" << endl;
	}
	else if (getData == 0x10) {
		serial.writeByte(0x10);
		cout << "button 16 pushed" << endl;
	}
	*/

	for (int i = 0; i < hasus.size(); i++) {
		hasus[i]->update();
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

	//蓮の絵画
	for (int i = 0; i < hasus.size(); i++) {
		ofPushMatrix();
		ofTranslate(hasus[i]->pos.x, hasus[i]->pos.y);
		ofRotateDeg(hasus[i]->deg);
		ofTranslate(-hasus[i]->pos.x, -hasus[i]->pos.y);
		image[i]->draw(hasus[i]->pos.x - (HASU_SIZE / 2), hasus[i]->pos.y - (HASU_SIZE / 2));
		ofPopMatrix();
	}

	//波紋の絵画
	ofPushStyle();
	for (int i = 0; i < ripples.size(); i++) {
		ripples[i]->draw();
	}
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'm') {
		for (int i = 0; i < ofRandom(3, 5); i++) {
			ripples.push_back(new Ripple(ofPoint(pos1_x, pos1_y), ofRandom(70,100) , 3, ofColor(0, ofRandom(100, 255), ofRandom(100, 255)))); //引数：位置，半径，線の太さ，色
			hasus[0]->stepOn = true;
		}
	}
}
//--------------------------------------------------------------
void ofApp::reset() {
	resetCounter = 0;
	for (int i = 0; i < hasus.size(); i++) {
		hasus[i]->state = false;
	}
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
