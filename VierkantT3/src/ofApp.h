#pragma once

#include "ofMain.h"
#include "HoofdCel.h"
#include "VierKantCel.h"
//#include "ofxGPIO.h"

// Je moet nog van github de ofxGPIO.h blibotheek downloaden anders werk dit allemaal niet
// Vergeet die bibliotheek niet in de goeie openframeworks map te zettten. 

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
			int welkeApparaat;
			void apparaatSetup(int welkeApparaat_);
			void apparaatUpdate();
			int pot1 = 0;
			int pot2 = 0;

		// Van de arduino
			ofArduino myArduino;
			bool arduino_opstarten;
			
		// raspberry pi 
		// a2dChannel geeft aan welke pin je
		// uitleest op de chip!!! 
		//	int a2dChannel = 0; // pin 1
		//	unsigned char data[3];

		//	int a2dChannel2 = 1; // pin 2
		//	unsigned char data2[3];
		//	MCP mcp;

private:

	// Van de arduino
		void setupArduino(const int & version);
		void analogPinChanged(const int & pinNum);
};