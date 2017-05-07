#pragma once

#include "ofMain.h"
#include "HoofdCel.h"
#include "VierkantCel.h"


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
		
		VierkantCel vierkant;
		VierkantCel vierkant1;
		VierkantCel vierkant2;
		VierkantCel vierkant3;
		VierkantCel vierkant4;
		VierkantCel vierkant5;
		VierkantCel vierkant6;
		VierkantCel vierkant7;



		bool zichtbaar = false; 
};