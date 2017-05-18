#include "M_VierKantCel.h"

// Succes 
// Kijk wat er in de ofApp.cpp staat
// Dat moet hier allemaal in komen te staan
// PS. Ga even na denken of de VierKantCel clas nog een HoofdCel clas nodig heeft 
// Ik denk het namelijk niet!!! 

void M_VierkantCel::SetupVierKantCel(int vorm_, float speed_, float Ibh_x, float Ibh_y)
{
	
}

void M_VierkantCel::VierKantCelDisplay(int pot_)
{

}

void M_VierkantCel::VierKantCelMove(float snelheid_)
{

}

void M_VierkantCel::M_display()
{
	ofSetColor(250, 90, 50);
	ofRect(M_location.x, M_location.y, M_bh.x, M_bh.y);
}
