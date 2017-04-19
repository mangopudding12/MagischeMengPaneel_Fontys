#include "Cel.h"


Cel:: Cel(ofVec2f Rbh_, ofVec2f Rlocation_ )
{
	Rbh = Rbh_;

	// Locatie van vierkant is beginlocatie van innerlijke object 
	Rlocation = Rlocation_;
	Speed.set(0.3, 0.3);
}


void Cel::Rmove()
{
	Rlocation.x += ofRandom(-0.4,0.4); 
	Rlocation.y += ofRandom(-0.4, 0.4);
}


void Cel::Rdisplay() // Grote Vierkant
{
	ofSetColor(80, 4, 131);
	ofRect(Rlocation.x, Rlocation.y, Rbh.x, Rbh.y);
}
