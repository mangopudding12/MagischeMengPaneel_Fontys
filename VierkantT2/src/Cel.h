#pragma once
#include "ofMain.h"

using namespace std;
// Let op 
// Wanneer er hoogte_ = parameter 
// Wanneer er hoogte = globale of lokale variable 

class Cel
{
private:
	
	ofVec2f Rbh;
	ofVec2f Rlocation;
	
public:
	
	Cel() {}; // Default contructor -- niet weg halen!!

	// hoogte_ = Hoogte van vierkant 
	// breedte_ = breedte van vierkant 
	// ofVec2f location_ = waar gaan we vierkant tekenen op het scherm
	// snelheid_ = hoe hard de ... langs de randen van vierkant verplaatst 
	// vorm_ = bewegende object vierkant(1), driehoek(2), cirkel(3)
	Cel(ofVec2f Rbh_, ofVec2f Rlocation_);

	//void Idisplay(); // Bewegen innerlijke object 
	void Rdisplay(); // niet bewegende vierkant 
};

