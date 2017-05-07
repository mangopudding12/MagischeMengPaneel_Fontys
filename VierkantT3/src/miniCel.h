#pragma once
#include "ofmain.h"

class miniCel 
{
public:
	miniCel() {};
	miniCel(int vorm_, float speed_, float Ibh_x, float Ibh_y, float loca_x, float loca_y, float Iloca_x, float Iloca_y);
	void display();
	void move(float loca_x, float loca_y,float bh_x, float bh_y, int state_, float speedx_, float speedy_);
	ofVec2f Ilocation;

private: 
	int state;
	bool geit = false;
	int vorm;
	float speed; 
	ofVec2f Ibh; 
	
};