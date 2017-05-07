#include "miniCel.h"

miniCel::miniCel(int vorm_, float speed_, float Ibh_x, float Ibh_y, float loca_x, float loca_y, float Iloca_x, float Iloca_y)
{
	vorm = vorm_;
	speed = speed_;
	Ibh.set(Ibh_x,Ibh_y);
	Ilocation.set(loca_x + Iloca_x, loca_y + Iloca_y);
}

void miniCel::display()
{
	ofSetColor(50, 255, 100);
	ofSetCircleResolution(6); // Per ongeluk een 6 hoek hihi 
	ofEllipse(Ilocation.x,Ilocation.y, Ibh.x , Ibh.y );
}


void miniCel::move(float loca_x, float loca_y, float bh_x, float bh_y,int state_, float speedx_,float speedy_)
{
	//cout << state << endl;

	if (geit == false)
	{
		state = state_; 
		geit = true;
	}

		// Verplaatsing Xas van Links naar Rechts 
		if (Ilocation.x <= (loca_x + bh_x) && Ilocation.x >= loca_x && state == 1)
		{
			Ilocation.x += (speed +speedx_);
			Ilocation.y = loca_y;	
		}
		else if (Ilocation.x < loca_x  && state == 1)
		{
			Ilocation.x = loca_x + speedx_;
			Ilocation.y = loca_y;
		}
		else if (Ilocation.x >= (loca_x + bh_x) && state == 1) {
			state = 2;
		} 



		else if (Ilocation.y <= (loca_y + bh_y) && Ilocation.y >= loca_y && state == 2)
		{
			Ilocation.x = loca_x + bh_x;
			Ilocation.y += (speed + speedy_);
		}
		else if (Ilocation.y < loca_y && state == 2)
		{
			Ilocation.x = loca_x + bh_x;
			Ilocation.y = loca_y + speedy_;
		}
		else if (Ilocation.y >= (loca_y + bh_y) && state == 2)
		{
			state = 3;
		} 
		


		// Zorgt dat vierkant van Rechts naar Links beweegt op Xas 
		else if (Ilocation.x <= loca_x + bh_x && Ilocation.x > loca_x  && state == 3)
		{
			Ilocation.x -= (speed - speedx_);
			Ilocation.y = loca_y + bh_y;
		}
		// Wanneer er een hard versnelling is naar Links wordt met deze 
		// else if ervoor gezorgt dat kleine vierkant in grote vierkant blijft
		else if (Ilocation.x > loca_x + bh_x && state == 3) 
		{
			Ilocation.x = (loca_x + bh_x) + speedx_;
			Ilocation.y = loca_y + bh_y;
		} 
		else if (Ilocation.x < loca_x && state == 3)
		{
			state = 4;
		}
		

		else if (Ilocation.y <= loca_y + bh_y && Ilocation.y > loca_y  && state == 4)
		{
			Ilocation.x = loca_x;
			Ilocation.y -= (speed - speedy_);
		}
		else if (Ilocation.y > loca_y + bh_y && state == 4)
		{
			Ilocation.x = loca_x;
			Ilocation.y = (loca_y + bh_y) + speedy_;
		}
		else if (Ilocation.y <= loca_y && state == 4)
		{
			state = 1;
		}
}
