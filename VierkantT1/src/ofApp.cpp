#include "ofApp.h"

float  Rb, Rh; 
float marge = 500;
ofVec2f Rlocation; 
ofVec2f Rspeed; 

ofVec

//--------------------------------------------------------------
void ofApp::setup()
{
	Rb = 20; 
	Rh = 20; 
	Rlocation.set(marge, marge);
	Rspeed.set(2, 0);
}

//--------------------------------------------------------------
void ofApp::update()
{

	if (Rlocation.x >= ofGetWidth() - marge && Rlocation.y <= marge)
	{
		Rspeed.x = 0; // stop 
		Rspeed.y = 1; // omlaag
	}
	else if (Rlocation.y >= ofGetHeight() - marge && Rlocation.x >= ofGetWidth() - marge) {
		Rspeed.x = -1; // naar links
		Rspeed.y = 0; // stop
	}
	else if (Rlocation.x <= marge && Rlocation.y >= ofGetHeight() - marge) {
		Rspeed.x = 0; // stop 
		Rspeed.y = -1; // omhoog
	}
	else if (Rlocation.y <= marge && Rlocation.x <= marge) {
		Rspeed.x = 1; // stop 
		Rspeed.y = 0; // omhoog
	}

	Rlocation += Rspeed; 
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(Rlocation.x,Rlocation.y, Rlocation.x);
	ofRect(Rlocation.x,Rlocation.y,Rb,Rh);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
