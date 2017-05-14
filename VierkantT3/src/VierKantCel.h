#pragma once
#include "ofMain.h"
#include "HoofdCel.h"
#include "miniCel.h"

class VierkantCel :  public HoofdCel
{
public:
	VierkantCel() {}; // Default
	miniCel mCel[4]; // 4 miniCellen

	
	// miniCel
	void SetupminiCel(int vorm_, float speed_, float Ibh_x, float Ibh_y);
	void minicelDisplay(int pot_); 
	void minicelMove(float snelheid_);

	// Grote vierkant
	void Vdisplay(); // niet bewegende vierkant 
};