#include "Message.h"
#include "ofApp.h"

using namespace std;

Message::Message(string _message, ofPoint _r_pos, ofPoint _l_pos){
	message_R.load(_message);
	message_L.load(_message);
	state = false;
	r_pos = _r_pos;
	l_pos = _l_pos;
}

Message::~Message() {
}

void Message::draw() {
	if (state == true) {
		message_R.draw(r_pos.x, r_pos.y);
		message_L.draw(l_pos.x, l_pos.y);
	}
}
