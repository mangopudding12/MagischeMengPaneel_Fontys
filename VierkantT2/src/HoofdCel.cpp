#include "HoofdCel.h"


HoofdCel::HoofdCel(ofVec2f rbh_, ofVec2f Rloca_, ofVec2f ibh_)
{
	vierK = Cel(rbh_, Rloca_);

	// Dit zijn de 4 bewegende bollen langs de rand van vierkant
	IB1 = iZes(Rloca_, 2, 0.3, ibh_, 0, 0, rbh_); 
	IB2 = iZes(Rloca_, 2, 0.3, ibh_, rbh_.x, 0, rbh_);
	IB3 = iZes(Rloca_, 2, 0.3, ibh_, rbh_.x, rbh_.y, rbh_);
	IB4 = iZes(Rloca_, 2, 0.3,ibh_, 0, rbh_.y, rbh_);
}

void HoofdCel::IBmove()
{
	IB1.Imove(); 
	IB2.Imove(); 
	IB3.Imove();
	IB4.Imove(); 
}

void HoofdCel::Vmove()
{
	vierK.Rmove(); 
}

void HoofdCel::IBdisplay()
{
	ofSetColor(19, 186, 191);
	IB1.Idisplay();
	ofSetColor(19, 186, 150);
	IB2.Idisplay();
	ofSetColor(19, 186, 100);
	IB3.Idisplay();
	ofSetColor(19, 186, 50);
	IB4.Idisplay();
}

void HoofdCel::Vdisplay()
{
	vierK.Rdisplay();
}

