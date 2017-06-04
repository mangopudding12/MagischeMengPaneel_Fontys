#pragma once

#include "ofMain.h"
//#include "M_HoofdCel.h"
//#include "M_VierKantCel.h"
//#include "ofxGPIO.h"
#include "DisplayEverything.h"

// ofxGPIO werkt niet in openFrameworks op mijn PC op de een of andere manier.

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
		void exit();

		DisplayEverything alles; 

		// device stuff 
			int welkeApparaat;
			void apparaatSetup(int welkeApparaat_);
			void apparaatUpdate();
			
			int clear = 0; 

		// Van de arduino
			ofArduino myArduino;
			bool arduino_opstarten;

private:

	// Van de arduino
		void setupArduino(const int & version);
		void analogPinChanged(const int & pinNum);

		int* pot;
		int aantal_Potmeters;
		int* state_optie3;
};