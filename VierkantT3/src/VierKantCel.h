#pragma once
#include "ofmain.h"
#include "HoofdCel.h"
#include "miniCel.h"

class VierkantCel :  public HoofdCel
{
public:
	VierkantCel() {}; // Default
	miniCel mCel[4]; // 4 miniCellen

	
	// miniCel
	void SetupminiCel(int vorm_, float speed_, float Ibh_x, float Ibh_y);
	void minicelDisplay(); 
	void minicelMove(); 

	// Grote vierkant
	void Vdisplay(); // niet bewegende vierkant 
};