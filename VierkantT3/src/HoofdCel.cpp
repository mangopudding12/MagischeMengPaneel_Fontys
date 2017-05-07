#include "HoofdCel.h"

void HoofdCel::setup(float bh_x, float bh_y, float location_x, float location_y)
{
	bh.set(bh_x, bh_y);
	location.set(location_x, location_y);
}

void HoofdCel::MoveAll(int mouse,int mousey)
{
	speed = mouse;
	location.x = speed;
	location.y = mousey;
}

