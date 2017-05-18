#pragma once
#include "ofMain.h"

class M_HoofdCel
{

public:

	M_HoofdCel() {};

	ofVec2f M_bh; // breedte, hoogte van Middel Vierkant
	ofVec2f M_location; // X,y locatie van Middel Vierkant

	float M_speedy;  // Speed van Middel Vierkant zelf 
	float M_speedx;

	// Mbh_x = breedte 
	// Mbh_y = hoogte 
	void Msetup(float Mbh_x, float Mbh_y, float Mlocation_x, float Mlocation_y);
	
	// Beweging van alle VierKantCel(met elk 4 miniCel) in Middel Vierkant.
	void M_MoveAll();

private:

};