#include "M_VierKantCel.h"



void M_VierkantCel::SetupVierKantCel(int vorm_, float speed_, float Vbh_x, float Vbh_y)
{
	
	// Onderverdeling
	// 0 t/m 3 coordinaten
	// 0,0 -> x+breedte,0 -> x+breedte,y+hoogte -> 0,y+hoogte

	// int V_vorm_, float V_speed_, float V_bh_x, float V_bh_y, float Mloca_x, float Mloca_y, float Vloca_x, float Vloca_y
	vierkant[0] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x-Vbh_x/2, M_location.y - Vbh_y / 2, 0, 0);
	vierkant[0].SetupminiCel(2, 0.3, Vbh_x/3, Vbh_y/3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[1] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x, 0);
	vierkant[1].SetupminiCel(2, 0.3, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[2] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x, M_bh.y);
	vierkant[2].SetupminiCel(2, 0.3, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[3] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, 0, M_bh.y);
	vierkant[3].SetupminiCel(2, 0.3, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	// 3 t/m 7 coordinaten 
	// x+breedte/2,0 -> enzo.

	vierkant[4] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x/2, 0);
	vierkant[4].SetupminiCel(2, 1, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[5] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x, M_bh.y/2);
	vierkant[5].SetupminiCel(2, 1, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant[6] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, M_bh.x / 2, M_bh.y);
	vierkant[6].SetupminiCel(2, 1, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	// 1
	vierkant[7] = VierkantCel(vorm_, speed_, Vbh_x, Vbh_y, M_location.x - Vbh_x / 2, M_location.y - Vbh_y / 2, 0, M_bh.y/2);
	vierkant[7].SetupminiCel(2, 1, Vbh_x / 3, Vbh_y / 3); // int vorm_, float speed_, float Ibh_x, float Ibh_y	
}

void M_VierkantCel::VierKantCelDisplay(int pot1_, int pot3_, int pot4_)
{
	// Er zijn maar 4 Vierkanten die je aan en uit kan zetten. 
	zichtbaarVdisplay = ofMap(pot3_, 0, 1023, 0, 8);
	zichtbaarMiniCel = ofMap(pot4_, 0, 1023, 0, 8);

	for (int i = 0; i < zichtbaarVdisplay; i++)
	{
		vierkant[i].Vdisplay(150);

	}

	for (int i = 0; i < zichtbaarMiniCel; i++)
	{
		if (i < 4)
		{
			vierkant[i].minicelDisplay(150);
		}
		else {
			vierkant[i].minicelDisplay(310);
		}
		
		
	}

	
}

void M_VierkantCel::VierKantCelMove(int pot0_,int pot2_)
{
	for (int i = 0; i < 8; i++)
	{
		//float Mloca_x, float Mloca_y, float Mbh_x, float Mbh_y, int Vstate_, float M_speedx, float M_speedy
		vierkant[i].minicelMove(pot0_);
	}

	vierkant[0].move(M_location.x, M_location.y, M_bh.x, M_bh.y,1,0,0,pot2_);
	vierkant[1].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 2, 0, 0, pot2_);
	vierkant[2].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 3, 0, 0, pot2_);
	vierkant[3].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 4, 0, 0, pot2_);
	vierkant[4].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 1, 0, 0, pot2_);
	vierkant[5].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 2, 0, 0, pot2_);
	vierkant[6].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 3, 0, 0, pot2_);
	vierkant[7].move(M_location.x, M_location.y, M_bh.x, M_bh.y, 4, 0, 0, pot2_);

}

void M_VierkantCel::ResetLocatie()
{
	for (int i = 0; i < 8; i++)
	{
		vierkant[i].ResetLocatie();
	}
}

void M_VierkantCel::M_display(int pot1_)
{
	zichtbaarMdisplay = ofMap(pot1_, 0, 1023, 0, 255);

	ofSetColor(250, 90, 50, zichtbaarMdisplay);
	ofRect(M_location.x, M_location.y, M_bh.x, M_bh.y);
}
