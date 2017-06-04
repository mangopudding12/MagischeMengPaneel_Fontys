#include "M_HoofdCel.h"

void M_HoofdCel::Msetup(float Mbh_x, float Mbh_y, float Mlocation_x, float Mlocation_y)
{
	M_bh.set(Mbh_x, Mbh_y);
	M_location.set(Mlocation_x, Mlocation_y);
}

void M_HoofdCel::M_MoveAll()
{
	M_speedx = ofRandom(-1, 1);
	M_speedy = ofRandom(-1, 1);


	M_location.x += M_speedx;
	M_location.y += M_speedy;
}
