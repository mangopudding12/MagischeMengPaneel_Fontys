#pragma once

#include "ofMain.h"
#include "M_HoofdCel.h"
#include "M_VierKantCel.h"
//#include "ofxGPIO.h"

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
		
		bool zichtbaar = false;


		M_VierkantCel testM;
		M_VierkantCel testM1;
		M_VierkantCel testM2;
		M_VierkantCel testM3;
		M_VierkantCel testM4;
		M_VierkantCel testM5;


		// device stuff 
			int welkeApparaat;
			void apparaatSetup(int welkeApparaat_);
			void apparaatUpdate();
			int pot1 = 0;
			int pot2 = 0;

		// Van de arduino
			ofArduino myArduino;
			bool arduino_opstarten;

private:

	// Van de arduino
		void setupArduino(const int & version);
		void analogPinChanged(const int & pinNum);
};