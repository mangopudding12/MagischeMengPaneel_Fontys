#include "VierkantCel.h"

void VierkantCel::SetupminiCel(int vorm_, float speed_, float Ibh_x, float Ibh_y)
{
	mCel[0] = miniCel(vorm_, speed_, Ibh_x, Ibh_y,location.x, location.y, 0, 0); // Geeft locatie van vierkant door aan miniCel	
	mCel[1] = miniCel(vorm_, speed_, Ibh_x, Ibh_y,location.x, location.y, bh.x, 0); // Geeft locatie van vierkant door aan miniCel	
	mCel[2] = miniCel(vorm_, speed_, Ibh_x, Ibh_y, location.x, location.y, bh.x, bh.y); // Geeft locatie van vierkant door aan miniCel	
	mCel[3] = miniCel(vorm_, speed_, Ibh_x, Ibh_y, location.x, location.y, 0, bh.y); // Geeft locatie van vierkant door aan miniCel	
}

void VierkantCel::minicelDisplay()
{
	for (int i = 0; i < 4; i++)
	{
		mCel[i].display(); // Geeft locatie van vierkant door aan miniCel	
	}
}

void VierkantCel::minicelMove()
{
		mCel[0].move(location.x, location.y, bh.x, bh.y,1,speedx, speedy);
		mCel[1].move(location.x, location.y, bh.x, bh.y,2,speedx, speedy);
		mCel[2].move(location.x, location.y, bh.x, bh.y, 3, speedx, speedy);
		mCel[3].move(location.x, location.y, bh.x, bh.y, 4, speedx, speedy);
}

void VierkantCel::Vdisplay()
{
	ofSetColor(80, 4, 131);
	ofRect(location.x, location.y, bh.x, bh.y);
}
