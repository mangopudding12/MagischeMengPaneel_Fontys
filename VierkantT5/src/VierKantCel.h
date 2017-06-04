#pragma once
#include "ofMain.h"
#include "miniCel.h"

class VierkantCel 
{
public:

	// Vierkant
	VierkantCel() {};
	VierkantCel(int V_vorm_, float V_speed_, float V_bh_x, float V_bh_y, float Mloca_x, float Mloca_y, float Vloca_x, float Vloca_y);
	void move(float Mloca_x, float Mloca_y, float Mbh_x, float Mbh_y, int Vstate_, float M_speedx, float M_speedy, float potmeter_snelheid);
	void Vdisplay(int alfa_); // Kleine Vierkant (Met 4 miniCellen in zich)
	ofVec2f V_location;
	ofVec2f oorsprongIlocation;

	// miniCel
	miniCel mCel[4]; // 4 miniCellen PER VierKant
	void SetupminiCel(int vorm_, float speed_, float Ibh_x, float Ibh_y);
	void minicelDisplay(int pot1_); 
	void minicelMove(float snelheid_);
	void ResetLocatie(); 

private: 
	int Mzijde;
	int V_state;
	bool V_geit = false;
	int V_vorm;
	float V_speed;
	ofVec2f V_bh;

	int oorsprongV_state;
};