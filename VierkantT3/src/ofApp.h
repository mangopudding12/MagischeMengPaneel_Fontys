#pragma once

#include "ofMain.h"
#include "HoofdCel.h"
#include "VierKantCel.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		
		//vector<VierkantCel>vierkantte;

		VierkantCel vierkant;
		VierkantCel vierkant1;
		VierkantCel vierkant2;
		VierkantCel vierkant3;
		VierkantCel vierkant4;
		VierkantCel vierkant5;
		VierkantCel vierkant6;
		VierkantCel vierkant7;
		bool zichtbaar = false; 

		// device stuff 
		void apparaatSetup(int welkeApparaat_);
		void apparaatUpdate();
		int welkeApparaat;

		ofArduino myArduino;
		bool arduino_opstarten;
		float pot1;
		float pot2;
private: 
	void setupArduino(const int & version);
	void analogPinChanged(const int & pinNum);
};