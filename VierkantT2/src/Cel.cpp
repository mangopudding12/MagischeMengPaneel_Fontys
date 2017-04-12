#include "Cel.h"


Cel:: Cel(ofVec2f Rbh_, ofVec2f Rlocation_ )
{
	Rbh = Rbh_;

	// Locatie van vierkant is beginlocatie van innerlijke object 
	Rlocation = Rlocation_;
}


void Cel::Rdisplay() // Grote Vierkant
{
	ofSetColor(80, 4, 131);
	ofRect(Rlocation.x, Rlocation.y, Rbh.x, Rbh.y);
}

