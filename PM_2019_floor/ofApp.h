#pragma once

#include "ofMain.h"
#include "Ripple.h"
#include "point.h"
#include "Hasu.h"
#include "Sound.h"
#include "Message.h"
#include "Mask.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void createRipple(int _no, ofPoint _pos, int _state, int _rippleNum);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		//ofSerial serial; //シリアル通信のインスタンス
		int getData;
		ofVideoPlayer hasuike;
		int resetCounter;
		int messageType;

};
