#include "miniCel.h"

miniCel::miniCel(int vorm_, float speed_, float Ibh_x, float Ibh_y)
{
	vorm = vorm_;
	speed = speed_;
	Ibh.set(Ibh_x,Ibh_y);
}

void miniCel::display(float loca_x, float loca_y, float Iloca_x, float Iloca_y)
{
	ofSetColor(0, 0, 200);
	ofSetCircleResolution(6); // Per ongeluk een 6 hoek hihi 
	ofEllipse(loca_x + Iloca_x, loca_y + Iloca_y, Ibh.x , Ibh.y );
}
