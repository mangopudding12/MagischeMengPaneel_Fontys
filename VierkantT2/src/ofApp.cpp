#include "ofApp.h"

bool hoi = false; 

//--------------------------------------------------------------
void ofApp::setup()
{
	
	ofVec2f rbh_, Rloca_, ibh_;
	rbh_.set(200, 200);
	Rloca_.set(ofGetWidth() / 2, 100);
	ibh_.set(40, 40); 

	dolfijn = Cel(rbh_,Rloca_);
	vis = iZes(Rloca_, 2, 0.3, ibh_,0,0, rbh_);
	vis1 = iZes(Rloca_, 2, 0.3, ibh_, 200, 0, rbh_);
	vis2 = iZes(Rloca_, 2, 0.3, ibh_, 200, 200, rbh_);
	vis3 = iZes(Rloca_, 2, 0.3, ibh_, 0, 200, rbh_);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (hoi == false)
	{
		vis.Imove();
		vis1.Imove();
		vis2.Imove();
		vis3.Imove();
	}
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
	
	ofSetColor(19, 186, 191);
	vis.Idisplay(); 
	ofSetColor(19, 186, 150);
	vis1.Idisplay();
	ofSetColor(19, 186, 100);
	vis2.Idisplay();
	ofSetColor(19, 186, 50);
	vis3.Idisplay();
	
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
