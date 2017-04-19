#pragma once
#include "ofmain.h"

class HoofdCel
{
public: 
	
	HoofdCel() {};

	ofVec2f bh;
	ofVec2f location;
 
	void setup(float bh_x, float bh_y, float location_x, float location_y);
	void MoveAll(); 

private: 

};