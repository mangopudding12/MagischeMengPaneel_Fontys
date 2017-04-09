#pragma once
#include "ofMain.h"

using namespace std; 
// Let op 
// Wanneer er hoogte_ = parameter 
// Wanneer er hoogte = globale of lokale variable 

class Cel_R
{
private: 
	int vorm; 
	ofVec2f Ibh;
	ofVec2f Rbh;

	ofVec2f Rlocation; 
	ofVec2f Ilocation; 

public:
	// hoogte_ = Hoogte van vierkant 
	// breedte_ = breedte van vierkant 
	// ofVec2f location_ = waar gaan we vierkant tekenen op het scherm
	// snelheid_ = hoe hard de ... langs de randen van vierkant verplaatst 
	// vorm_ = bewegende object vierkant(1), driehoek(2), cirkel(3)
	Cel_R(ofVec2f Rbh_, ofVec2f Rlocation_,float snelheid_, int vorm_,ofVec2f Ibh_);
	
	void Idisplay(); // Bewegen innerlijke object 
	void Rdisplay(); // niet bewegende vierkant 
};

