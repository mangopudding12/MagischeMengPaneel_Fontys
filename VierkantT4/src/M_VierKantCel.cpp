#include "M_VierKantCel.h"

// Succes 
// Kijk wat er in de ofApp.cpp staat
// Dat moet hier allemaal in komen te staan
// PS. Ga even na denken of de VierKantCel clas nog een HoofdCel clas nodig heeft 
// Ik denk het namelijk niet!!! 

//M_VierkantCel::M_VierkantCel(float Mbh_x, float Mbh_y)
//{
	//M_bh.set(Mbh_x,Mbh_y);
//}

void M_VierkantCel::SetupVierKantCel(int vorm_, float speed_, float Vbh_x, float Vbh_y)
{
	
	// Onderverdeling
	// 0 t/m 3 coordinaten
	// 0,0 -> x+breedte,0 -> x+breedte,y+hoogte -> 0,y+hoogte

	// int V_vorm_, float V_speed_, float V_bh_x, float V_bh_y, float Mloca_x, float Mloca_y, float Vloca_x, float Vloca_y
	vierkant[0] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x-Vbh_x/2, M_location.y - Vbh_y / 2, 0, 0);
	vierkant[0].SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[1] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x, 0);
	vierkant[1].SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[2] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x, M_bh.y);
	vierkant[2].SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[3] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, 0, M_bh.y);
	vierkant[3].SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	// 3 t/m 7 coordinaten 
	// x+breedte/2,0 -> enzo.

	vierkant[4] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x/2, 0);
	vierkant[4].SetupminiCel(2, 1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[5] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x, M_bh.y/2);
	vierkant[5].SetupminiCel(2, 1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[6] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x / 2, M_bh.y);
	vierkant[6].SetupminiCel(2, 1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	// 1
	vierkant[7] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, 0, M_bh.y/2);
	vierkant[7].SetupminiCel(2, 1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	
}

void M_VierkantCel::VierKantCelDisplay(int pot_)
{
	for (int i = 0; i < 4; i++)
	{
	vierkant[i].minicelDisplay(150);
	//vierkant[i].Vdisplay();
	}

	vierkant[4].minicelDisplay(1023);
	vierkant[5].minicelDisplay(1023);
	vierkant[6].minicelDisplay(1023);
	vierkant[7].minicelDisplay(1023);

	//vierkant[4].Vdisplay();
	//vierkant[5].Vdisplay();
	//vierkant[6].Vdisplay();
	//vierkant[7].Vdisplay();
}

void M_VierkantCel::VierKantCelMove(float snelheid_)
{
	for (int i = 0; i < 8; i++)
	{
		//float Mloca_x, float Mloca_y, float Mbh_x, float Mbh_y, int Vstate_, float M_speedx, float M_speedy
		vierkant[i].minicelMove(snelheid_);
	}

	vierkant[0].move(M_location.x, M_location.y, M_bh.x, M_bh.y,1,0,0);
	vierkant[1].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 2, 0, 0);
	vierkant[2].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 3, 0, 0);
	vierkant[3].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 4, 0, 0);
	vierkant[4].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 1, 0, 0);
	vierkant[5].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 2, 0, 0);
	vierkant[6].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 3, 0, 0);
	vierkant[7].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 4, 0, 0);

}

void M_VierkantCel::M_display()
{
	ofSetColor(250, 90, 50);
	ofRect(M_location.x, M_location.y, M_bh.x, M_bh.y);
}
