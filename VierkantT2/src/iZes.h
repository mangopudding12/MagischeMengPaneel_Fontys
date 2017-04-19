#pragma once
#include "ofMain.h"
#include "Cel.h"

class iZes : public Cel
{
public: 
	iZes() {};
	iZes(ofVec2f Ilocation_, int vorm_, float speed_,ofVec2f Ibh_, int x, int y, ofVec2f Rbh_);
	
	void Idisplay(); 
	void Imove();

private: 
	ofVec2f Rbh;
	//ofVec2f Rlocation;
	int vorm;
	float snelheid;
	ofVec2f Ibh;
	ofVec2f Ilocation;
	ofVec2f Ispeed;

};