#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() 
{
	vierkant.setup(200,200,mouseX,mouseY);
	vierkant.SetupminiCel(2, 0.3, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	
}

//--------------------------------------------------------------
void ofApp::update()
{
	vierkant.minicelMove();
	vierkant.MoveAll(mouseX,mouseY); 
}

//--------------------------------------------------------------
void ofApp::draw()
{
	vierkant.Vdisplay();
	vierkant.minicelDisplay(); 
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
