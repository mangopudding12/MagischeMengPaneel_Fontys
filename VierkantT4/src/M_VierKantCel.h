#pragma once

#include "ofMain.h"
#include "M_HoofdCel.h" // HoofdCel is van VierkantCel
#include "VierKantCel.h" // VierkantCel zelf

class M_VierkantCel : public M_HoofdCel
{
public:
	M_VierkantCel() {}; // Default
	
	// Maak 8 VierKantCel aan.
	VierkantCel vierkant0;
	VierkantCel vierkant1;
	VierkantCel vierkant2;
	VierkantCel vierkant3;
	VierkantCel vierkant4;
	VierkantCel vierkant5;
	VierkantCel vierkant6;
	VierkantCel vierkant7;
	


	// Vierkant functies 
	void SetupVierKantCel(int vorm_, float speed_, float Ibh_x, float Ibh_y);
	void VierKantCelDisplay(int pot_);
	void VierKantCelMove(float snelheid_);

	// Middel vierkant (8 VierKantCel, per VierKantCel (4 miniCel)) = 32
	void M_display(); // niet bewegende vierkant 
};