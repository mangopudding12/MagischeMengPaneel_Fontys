#pragma once
#include "ofMain.h"
#include "iZes.h"
#include "Cel.h"

class HoofdCel
{
public:
	HoofdCel() {}; // Default constructor -- Anders werkt het niet!!! 
	HoofdCel(ofVec2f rbh_, ofVec2f Rloca_, ofVec2f ibh_);
	void IBmove(); 
	void Vmove(); 
	void IBdisplay(); 
	void Vdisplay(); 

	Cel vierK;
	iZes IB1;
	iZes IB2;
	iZes IB3;
	iZes IB4;
};