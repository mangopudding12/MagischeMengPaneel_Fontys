#pragma once
#include "ofmain.h"

class miniCel 
{
public:
	miniCel() {};
	miniCel(int vorm_, float speed_, float Ibh_x, float Ibh_y);
	void display(float loca_x,float loca_y, float Iloca_x, float Iloca_y);

private: 
	int vorm;
	float speed; 
	ofVec2f Ibh; 
	ofVec2f Ilocation; 
};