#pragma once

#include "ofMain.h"
#include "M_HoofdCel.h" // HoofdCel is van VierkantCel
#include "VierKantCel.h" // VierkantCel zelf

class M_VierkantCel : public M_HoofdCel
{
public:
	M_VierkantCel() {}; // Default
	//M_VierkantCel(float Mbh_x, float Mbh_y);


	// Maak 8 VierKantCel aan.
	VierkantCel vierkant[8];

	
	// Vierkant functies 
	void SetupVierKantCel(int vorm_, float speed_, float Ibh_x, float Ibh_y);
	void VierKantCelDisplay(int pot_);
	void VierKantCelMove(float snelheid_);

	// Middel vierkant (8 VierKantCel, per VierKantCel (4 miniCel)) = 32
	void M_display(); // niet bewegende vierkant 

private: 
	//ofVec2f M_bh;
};