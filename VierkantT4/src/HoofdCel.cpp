#include "HoofdCel.h"

void HoofdCel::setup(float bh_x, float bh_y, float location_x, float location_y)
{
	bh.set(bh_x, bh_y);
	location.set(location_x, location_y);
}

void HoofdCel::MoveAll()
{
	// De speed van VierKantCel is straks niet meer random
	// Maar volgt de buitenste lijnen van Middel Vierkant
	//speedx = ofRandom(-1, 1);
	//speedy = ofRandom(-1,1);

	location.x += speedx;
	location.y += speedy;
}

