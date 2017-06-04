#include "DisplayEverything.h"

void DisplayEverything::SetupEverything(int aantal_)
{
	int kolommen = 0; // hoeveel er zijn
	float Mbh_tijdelijk = 0; // tijdelijke breedte vierkant
	aantalxas = aantal_;
	
	Mbh_tijdelijk = ofGetWidth() / aantalxas; // tijdelijke breedte vierkant
	Mbh_x_ = (ofGetWidth()-(Mbh_tijdelijk/5)) / aantalxas; // echt breedte vierkant zodat echt past op het scherm

	Mbh_y_ = Mbh_x_; // Hoogte vierkant is gelijk aan de Breedte 
	aantalyas = (ofGetHeight() / Mbh_x_) + 2; // Hier zorgen we ervoor dat er minder op Yas staan dan op Xas want Yas is korter
	aantalxas += 2;

	Mlocation_x = -(Mbh_x_ - ((Mbh_x_/5)/2)); // schrijf er 1 naar links
	Mlocation_y = - (Mbh_y_ - ((Mbh_y_ / 5) / 2)); // schrijf er 1 naar links omhoog


	testM = new M_VierkantCel[aantalxas*aantalyas];

	// float Mbh_x, float Mbh_y, float Mlocation_x, float Mlocation_y
	for (int y = 0; y < aantalyas; y++)
	{
		for (int x = 0; x < aantalxas; x++)
		{
			testM[kolommen].Msetup(Mbh_x_,Mbh_y_,Mlocation_x+(x*Mbh_x_),Mlocation_y+(y*Mbh_y_));
			testM[kolommen].SetupVierKantCel(2, 0.5, Mbh_x_/4, Mbh_y_/4);
			kolommen++;
		}
	}
}

void DisplayEverything::MoveEverything(int pot0_,int pot2_)
{
	for (int i = 0; i < aantalxas*aantalyas; i++)
	{
		//testM[i].M_MoveAll();
		testM[i].VierKantCelMove(pot0_,pot2_);
	}
}

void DisplayEverything::Display(int pot1_, int pot3_, int pot4_)
{
	int kolommen = 0;

	for (int r = 0; r <aantalyas; r++)
	{
		for (int i = 0; i < aantalxas; i++)
		{
			if (r % 2 == 0)
			{
				if (kolommen % 2 == 0)
				{
					testM[kolommen].M_display(pot1_);
				}
			}
			else if (r % 2 == 1)
			{
				if (kolommen % 2 == 1)
				{
					testM[kolommen].M_display(pot1_);
				}
			}

			kolommen++;
		}
	}
	
	for (int r = 0; r < aantalxas*aantalyas; r++)
	{
		testM[r].VierKantCelDisplay(200, pot3_, pot4_);
	}
}

void DisplayEverything::ResetLocaties()
{
	for (int i = 0; i < aantalxas*aantalyas; i++)
	{
		testM[i].ResetLocatie();
	}
}
