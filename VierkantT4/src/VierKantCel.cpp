#include "VierkantCel.h"

// Let op er zijn dingen in de MiniCel class veranderd.
// Deze kan je dus niet meer als voorbeeld nemen voor deze klas.
// Kijk in de VierKant_T3 project voor de orginele code.

VierkantCel::VierkantCel(int V_vorm_, float V_speed_, float V_bh_x, float V_bh_y, float Mloca_x, float Mloca_y, float Vloca_x, float Vloca_y)
{
	V_vorm = V_vorm_;
	V_speed = V_speed_;
	V_bh.set(V_bh_x, V_bh_y);

	// Word de positie van VierKant bepaald ten opzichte van Middel Vierkant
	V_location.set(Mloca_x + Vloca_x, Mloca_y + Vloca_y);
}

void VierkantCel::SetupminiCel(int vorm_, float speed_, float Ibh_x, float Ibh_y)
{
	mCel[0] = miniCel(vorm_, speed_, Ibh_x, Ibh_y,V_location.x, V_location.y, 0, 0); // Geeft locatie van vierkant door aan miniCel	
	mCel[1] = miniCel(vorm_, speed_, Ibh_x, Ibh_y,V_location.x, V_location.y, V_bh.x, 0); // Geeft locatie van vierkant door aan miniCel	
	mCel[2] = miniCel(vorm_, speed_, Ibh_x, Ibh_y, V_location.x, V_location.y, V_bh.x, V_bh.y); // Geeft locatie van vierkant door aan miniCel	
	mCel[3] = miniCel(vorm_, speed_, Ibh_x, Ibh_y, V_location.x, V_location.y, 0, V_bh.y); // Geeft locatie van vierkant door aan miniCel	
}

void VierkantCel::minicelDisplay(int pot_)
{
	for (int i = 0; i < 4; i++)
	{
		mCel[i].display(pot_); // Geeft locatie van vierkant door aan miniCel	
	}
}

void VierkantCel::minicelMove(float snelheidpotmeter_)
{
		mCel[0].move(V_location.x, V_location.y, V_bh.x, V_bh.y, 1, Mzijde,V_speed, snelheidpotmeter_);
		mCel[1].move(V_location.x, V_location.y, V_bh.x, V_bh.y, 2, Mzijde, V_speed, snelheidpotmeter_);
		mCel[2].move(V_location.x, V_location.y, V_bh.x, V_bh.y, 3, Mzijde, V_speed, snelheidpotmeter_);
		mCel[3].move(V_location.x, V_location.y, V_bh.x, V_bh.y, 4, Mzijde, V_speed, snelheidpotmeter_);
}

void VierkantCel::Vdisplay()
{
	ofSetColor(80, 4, 131);
	ofRect(V_location.x, V_location.y, V_bh.x, V_bh.y);
}

void VierkantCel::move(float Mloca_x, float Mloca_y, float Mbh_x, float Mbh_y, int Vstate_, float M_speedx, float M_speedy)
{

	if (V_geit == false)
	{
		V_state = Vstate_;
		V_geit = true;
	}

	if (V_state == 1) // Links naar recht bewegen op Xas.
	{
		Mzijde = 1;
		V_location.x += (V_speed + M_speedx);
		V_location.y = Mloca_y - V_bh.y/2;

		if (V_location.x >= (Mloca_x + Mbh_x) - V_bh.x / 2)
		{
			V_location.x = (Mloca_x + Mbh_x) - V_bh.x / 2;
			V_state = 2;
		}
	}
	else if (V_state == 2) // Beneden naar boven op de yAS (houd rekening het is omgekeerd)
	{
		Mzijde = 2;
		V_location.x = (Mloca_x + Mbh_x) - V_bh.x / 2;
		V_location.y += (V_speed + M_speedy);

		if (V_location.y >= (Mloca_y + Mbh_y) - V_bh.y / 2)
		{
			V_location.y = (Mloca_y + Mbh_y) -V_bh.y / 2;
			V_state = 3;
		}
	}
	else if (V_state == 3) // Links naar Rechts op de Xas 
	{
		Mzijde = 3;
		V_location.x -= (V_speed - M_speedx);
		V_location.y = (Mloca_y + Mbh_y) - V_bh.y / 2;

		if (V_location.x <= Mloca_x - V_bh.x / 2)
		{
			V_location.x = Mloca_x - V_bh.x / 2;
			V_state = 4;
		}
	}
	else if (V_state == 4) // Boven naar beneden op de Yas 
	{
		Mzijde = 4;
		V_location.x = Mloca_x - V_bh.x / 2;
		V_location.y -= (V_speed - M_speedy);

		if (V_location.y <= Mloca_y - V_bh.y / 2)
		{
			V_location.y = Mloca_y - V_bh.y / 2;
			V_state = 1;
		}
	}
}
