#include "HoofdCel.h"

void HoofdCel::setup(float bh_x, float bh_y, float location_x, float location_y)
{
	
	bh.set(bh_x, bh_y);
	location.set(location_x, location_y);
	cout << location << endl;
}

void HoofdCel::MoveAll()
{
	speedx = ofRandom(-1, 1);
	speedy = ofRandom(-1,1);

	location.x += speedx;
	location.y += speedy;

	
}

