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

#include "ofMain.h"
#include "ofApp.h"

 //========================================================================
int main() {
	ofSetupOpenGL(768, 768, OF_WINDOW);

	ofRunApp(new ofApp());
}
