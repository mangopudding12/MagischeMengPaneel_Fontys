#pragma once
#include "ofMain.h"

class miniCel 
{
public:
	miniCel() {};
	miniCel(int vorm_, float speed_, float Ibh_x, float Ibh_y, float loca_x, float loca_y, float Iloca_x, float Iloca_y);
	void display(int kleur_);
	void move(float loca_x, float loca_y,float bh_x, float bh_y, int state_, int Mzijde_, float V_speed, float snelheidpotmeter_);
	ofVec2f Ilocation;
	ofVec2f oorsprongIlocation;

	void resetLocation();


private: 
	int state;
	bool geit = false;
	int vorm;
	float speed; 
	ofVec2f Ibh; 

	int Mzijde;
	int oorsprongState; 
	int oorspongMzijde;
};