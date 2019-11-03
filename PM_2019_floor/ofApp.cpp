#include "ofApp.h"

vector<Ripple *> ripples; //ÉCÉìÉXÉ^ÉìÉXçÏê¨
vector<Hasu *> hasus;
vector<ofImage *> image;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);

	//hasusÇÃÉRÉìÉXÉgÉâÉNÉ^
	hasus.push_back(new Hasu(ofPoint(pos1_x, pos1_y)));
	hasus.push_back(new Hasu(ofPoint(pos2_x, pos2_y)));
	hasus.push_back(new Hasu(ofPoint(pos3_x, pos3_y)));
	hasus.push_back(new Hasu(ofPoint(pos4_x, pos4_y)));
	hasus.push_back(new Hasu(ofPoint(pos5_x, pos5_y)));
	hasus.push_back(new Hasu(ofPoint(pos6_x, pos6_y)));
	hasus.push_back(new Hasu(ofPoint(pos7_x, pos7_y)));
	hasus.push_back(new Hasu(ofPoint(pos8_x, pos8_y)));
	hasus.push_back(new Hasu(ofPoint(pos9_x, pos9_y)));
	hasus.push_back(new Hasu(ofPoint(pos10_x, pos10_y)));
	hasus.push_back(new Hasu(ofPoint(pos11_x, pos11_y)));
	hasus.push_back(new Hasu(ofPoint(pos12_x, pos12_y)));
	hasus.push_back(new Hasu(ofPoint(pos13_x, pos13_y)));
	hasus.push_back(new Hasu(ofPoint(pos14_x, pos14_y)));
	hasus.push_back(new Hasu(ofPoint(pos15_x, pos15_y)));
	hasus.push_back(new Hasu(ofPoint(pos16_x, pos16_y)));
	
	//ótÇÃìoò^
	for (int i = 0; i < hasus.size(); i++) {
		image.push_back(new ofImage());
		if (i == 0 || i == 2 || i == 5 || i == 7 || i == 8 || i == 10 || i == 13 || i == 15 ) {
			image[i]->load("leef_maru.png");
		}
		else {
			image[i]->load("leef_nami.png");
		}
	}

	//â‘ÇÃìoò^
	for (int i = 0; i < 4; i++) {
		image[ofRandom(0, 15)]->load("hasu_big_edit.png");
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < ripples.size(); i++) {
		ripples[i]->update();

		//égÇ¢èIÇÌÇ¡ÇΩÉÅÉÇÉäÇÕâï˙
		if (ripples[i]->dead == true) {
			ripples.erase(ripples.begin() + i);
		}
	}

	for (int i = 0; i < hasus.size(); i++) {
		hasus[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	//ògÇÃäGâÊ
	ofPushStyle();
	ofSetColor(255, 255, 255);
	ofSetLineWidth(3);
	ofLine(vertex1_x, vertex1_y, vertex2_x, vertex2_y);
	ofLine(vertex2_x, vertex2_y, vertex3_x, vertex3_y);
	ofLine(vertex3_x, vertex3_y, vertex4_x, vertex4_y);
	ofLine(vertex4_x, vertex4_y, vertex1_x, vertex1_y);
	ofPopStyle();

	//ò@ÇÃäGâÊ
	for (int i = 0; i < hasus.size(); i++) {
		ofPushMatrix();
		ofTranslate(hasus[i]->pos.x, hasus[i]->pos.y);
		ofRotateDeg(hasus[i]->deg);
		ofTranslate(-hasus[i]->pos.x, -hasus[i]->pos.y);
		image[i]->draw(hasus[i]->pos.x - (HASU_SIZE / 2), hasus[i]->pos.y - (HASU_SIZE / 2));
		ofPopMatrix();
	}

	//îgñ‰ÇÃäGâÊ
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
			ripples.push_back(new Ripple(ofPoint(pos1_x, pos1_y), ofRandom(70,130) , 4, ofColor(0, ofRandom(70, 255), ofRandom(70, 255)))); //à¯êîÅFà íuÅCîºåaÅCê¸ÇÃëæÇ≥ÅCêF
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
