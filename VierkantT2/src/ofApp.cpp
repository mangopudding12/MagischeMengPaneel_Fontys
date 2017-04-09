#include "ofApp.h"

bool hoi = false; 

//--------------------------------------------------------------
void ofApp::setup()
{
	//Cel(ofVec2f Rbh_, ofVec2f Rlocation_, float snelheid_, int vorm_, ofVec2f Ibh_);
	ofVec2f rbh_, Rloca_, ibh_;
	rbh_.set(200, 200);
	Rloca_.set(ofGetWidth() / 2, 100);
	ibh_.set(40, 40); 

	dolfijn = Cel(rbh_,Rloca_, 0.3,2,ibh_);
}

//--------------------------------------------------------------
void ofApp::update(){
	dolfijn.Imove();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (hoi == true)
	{
		dolfijn.Rdisplay();
	}
	else {
		ofSetBackgroundColor(255);
	}
	
	dolfijn.Idisplay();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	hoi = true; 
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	hoi = false;
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
