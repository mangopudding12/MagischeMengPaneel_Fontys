#include "VierkantCel.h"

void VierkantCel::SetupminiCel(int vorm_, float speed_, float Ibh_x, float Ibh_y)
{
	for (int i = 0; i < 4; i++)
	{
		mCel[i] = miniCel(vorm_, speed_, Ibh_x, Ibh_y);
	}
}

void VierkantCel::minicelDisplay()
{
		mCel[0].display(location.x, location.y,0,0); // Geeft locatie van vierkant door aan miniCel	
		mCel[1].display(location.x, location.y, bh.x, 0); // Geeft locatie van vierkant door aan miniCel	
		mCel[2].display(location.x, location.y, bh.x, bh.y); // Geeft locatie van vierkant door aan miniCel	
		mCel[3].display(location.x, location.y, 0, bh.y); // Geeft locatie van vierkant door aan miniCel	
}

void VierkantCel::minicelMove()
{

}

void VierkantCel::Vdisplay()
{
	ofSetColor(80, 4, 131);
	ofRect(location.x, location.y, bh.x, bh.y);
}
