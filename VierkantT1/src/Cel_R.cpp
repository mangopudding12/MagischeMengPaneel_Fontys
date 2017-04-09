#include "Cel_R.h"


Cel_R::Cel_R(ofVec2f Rbh_, ofVec2f Rlocation_, float snelheid, int vorm_, ofVec2f Ibh_)
{
	vorm = vorm_;

	Ibh = Ibh_; 
	Rbh = Rbh_;

	// Locatie van vierkant is beginlocatie van innerlijke object 
	Ilocation = Rlocation_;  
	Rlocation = Rlocation_;

}

void Cel_R::Idisplay()
{
	if (vorm == 1) { // Vierkant
		ofRect(Ilocation.x, Ilocation.y, Ibh.x, Ibh.y);
	}
		else if (vorm == 2) { // Driehoek
			ofSetCircleResolution(6);
			ofEllipse(Ilocation.x, Ilocation.y, Ibh.x, Ibh.y);
		}
		else if (vorm == 3) { // Cirkel 
			ofEllipse(Ilocation.x, Ilocation.y, Ibh.x, Ibh.y);
		}
		else { // default vorm 
			cout << "Even dat je het weet je kan alleen maar .." << endl; 
			cout << "voor Vorm alleen 1,2,3 invullen" << endl; 
			cout << "jij hebt nu " << vorm << " ingevult daarom default vorm" << endl;

			ofEllipse(Ilocation.x,Ilocation.y,Ibh.x,Ibh.y);
	}
}

void Cel_R::Rdisplay() // Grote Vierkant
{
	ofSetColor(40, 100, 150);
	ofRect(Rlocation.x, Rlocation.y, Rbh.x, Rbh.y);
}

