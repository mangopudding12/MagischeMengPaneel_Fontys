#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() 
{
	ofSetBackgroundColor(255);

	vierkant.setup(80, 80, 100,100);
	vierkant.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant1.setup(80, 80, 500, 100);
	vierkant1.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant2.setup(80, 80, 100, 530);
	vierkant2.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant3.setup(80, 80, 500, 450);
	vierkant3.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant4.setup(80, 80, 870, 560);
	vierkant4.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant5.setup(80, 80, 600, 290);
	vierkant5.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant6.setup(80, 80, 250, 300);
	vierkant6.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant7.setup(80, 80, 870, 100);
	vierkant7.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

}

//--------------------------------------------------------------
void ofApp::update()
{
	vierkant.minicelMove();
	vierkant.MoveAll();

	vierkant1.minicelMove();
	vierkant1.MoveAll();

	vierkant2.minicelMove();
	vierkant2.MoveAll();

	vierkant3.minicelMove();
	vierkant3.MoveAll();

	vierkant4.minicelMove();
	vierkant4.MoveAll();

	vierkant5.minicelMove();
	vierkant5.MoveAll();

	vierkant6.minicelMove();
	vierkant6.MoveAll();

	vierkant7.minicelMove();
	vierkant7.MoveAll();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (zichtbaar == true)
	{
		vierkant.Vdisplay();
		vierkant2.Vdisplay();
		vierkant1.Vdisplay();
		vierkant3.Vdisplay();
		vierkant4.Vdisplay();
		vierkant5.Vdisplay();
		vierkant6.Vdisplay();
		vierkant7.Vdisplay();
	}


	vierkant.minicelDisplay(); 
	vierkant1.minicelDisplay();	
	vierkant2.minicelDisplay();
	vierkant3.minicelDisplay();
	vierkant4.minicelDisplay();
	vierkant5.minicelDisplay();
	vierkant6.minicelDisplay();
	vierkant7.minicelDisplay();

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (zichtbaar == false)
	{
		zichtbaar = true;
	}
	else {
		zichtbaar = false;
	}
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	
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
