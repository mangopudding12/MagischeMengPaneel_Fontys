#include "miniCel.h"

miniCel::miniCel(int vorm_, float speed_, float Ibh_x, float Ibh_y, float V_loca_x, float V_loca_y, float Iloca_x, float Iloca_y)
{
	vorm = vorm_;
	speed = speed_;
	Ibh.set(Ibh_x,Ibh_y);
	Ilocation.set(V_loca_x + Iloca_x, V_loca_y + Iloca_y);
}

void miniCel::display(int kleur_)
{
	int kleur = ofMap(kleur_, 0, 1023, 0, 255);
	ofSetColor(75, kleur, kleur-50);
	ofSetCircleResolution(6); // Per ongeluk een 6 hoek hihi 
	ofEllipse(Ilocation.x,Ilocation.y, Ibh.x , Ibh.y );
}


void miniCel::move(float loca_x, float loca_y, float bh_x, float bh_y,int state_, float V_speed, float snelheidpotmeter_)
{
	speed = ofMap(snelheidpotmeter_, 0, 1023, 0.1, 3); // de 3 niet hoger maken want dan wordt vierkant verstoort
	

	if (geit == false)
	{
		state = state_; 
		geit = true;
	}

	if (state == 1) // Links naar recht bewegen op Xas.
	{
		Ilocation.x += (speed + V_speed);
		Ilocation.y = loca_y;	

		if (Ilocation.x >= (loca_x + bh_x))
		{
			Ilocation.x = (loca_x + bh_x);
			state = 2;
		}
	}
	else if (state == 2) // Beneden naar boven op de yAS (houd rekening het is omgekeerd)
	{
		Ilocation.x = loca_x + bh_x;
		Ilocation.y += (speed + V_speed);

		if (Ilocation.y >= (loca_y + bh_y))
		{
			Ilocation.y = (loca_y + bh_y);
			state = 3;
		}
	}
	else if (state == 3) // Links naar Rechts op de Xas 
	{
		Ilocation.x -= (speed - V_speed);
		Ilocation.y = loca_y + bh_y;

		if (Ilocation.x <= loca_x)
		{
			Ilocation.x = loca_x;
			state = 4;
		}
	}
	else if (state == 4) // Boven naar beneden op de Yas 
	{
		Ilocation.x = loca_x;
		Ilocation.y -= (speed - V_speed);

		if (Ilocation.y <= loca_y)
		{
			Ilocation.y = loca_y;
			state = 1;
		}
	}
}
