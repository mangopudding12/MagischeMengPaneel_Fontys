#include "ofApp.h"

// Ik heb een probleem 
// de lijnen volgende blokjes checken alleen in het begin
// de locatie van het vierkant maar ik wil eigenlijk dat 
// ze constant kijken naar de locatie van het vierkant. 
// Want dan kan ik het vierkant ook bewegen en daar reageren de 
// lijn volgende vierkanten dan ook op. 
// Mijn code is nu al een rommeltje aaaaaa 
// Misschien is er eerder over nadenken toch een goed plan hihi :P 


bool hoi = false; 

//--------------------------------------------------------------
void ofApp::setup()
{ 
	ofVec2f rbh, Rloca, ibh; 
	ibh.set(40, 40);

	for (int i = 0; i < 5; i++)
	{
		rbh.set(20*(i+2), 20 * (i + 2));
		Rloca.set(50 + ((i*120)+150), 200);
		

		cell[i] = HoofdCel(rbh, Rloca, ibh);
	}
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < 5; i++)
	{
		cell[i].IBmove();
		cell[i].Vmove(); 
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < 5; i++)
	{
		if (hoi == true)
		{
			cell[i].Vdisplay();
		}
		else {
			ofSetBackgroundColor(255);
		}

		cell[i].IBdisplay();
	}
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
