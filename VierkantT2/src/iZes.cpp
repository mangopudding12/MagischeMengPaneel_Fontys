
#include "iZes.h"

iZes::iZes(ofVec2f Ilocation_, int vorm_, float speed_, ofVec2f Ibh_, int x, int y, ofVec2f Rbh_)
{
	//Rlocation = Ilocation_; 
	Rbh = Rbh_; 
	Ilocation.x = Ilocation_.x+x;
	Ilocation.y = Ilocation_.y; 
	snelheid = speed_; 
	vorm = vorm_;

	Ibh = Ibh_; 
}


void iZes ::Imove()
{
	if (Ilocation.x >= (Rlocation.x + Rbh.x) && Ilocation.y <= Rlocation.y)
	{
		Ispeed.x = 0; // stop 
		Ispeed.y = snelheid; // omlaag
	}
	else if (Ilocation.y >= (Rlocation.y + Rbh.y) && Ilocation.x >= (Rlocation.x + Rbh.x)) {
		Ispeed.x = -snelheid; // naar links
		Ispeed.y = 0; // stop
	}
	else if (Ilocation.x <= Rlocation.x && Ilocation.y >= (Rlocation.y + Rbh.y)) {
		Ispeed.x = 0; // stop 
		Ispeed.y = -snelheid; // omhoog
	}
	else if (Ilocation.y <= Rlocation.y && Ilocation.x <= Rlocation.x) {
		Ispeed.x = snelheid; // stop 
		Ispeed.y = 0; // omhoog
	}

	Ilocation += Ispeed;
}



void iZes::Idisplay()
{
	static int berichtShow = 1;
	

	if (vorm == 1) { // Vierkant
		ofRect(Ilocation.x - (Ibh.x / 2), Ilocation.y - (Ibh.y / 2), Ibh.x, Ibh.y);
	}
	else if (vorm == 2) { // Driehoek
		ofSetCircleResolution(6); // Per ongeluk een 6 hoek hihi 
		ofEllipse(Ilocation.x, Ilocation.y, Ibh.x, Ibh.y);
	}
	else if (vorm == 3) { // Cirkel
		ofSetCircleResolution(100);
		ofEllipse(Ilocation.x, Ilocation.y, Ibh.x, Ibh.y);
	}
	else { // default vorm 

		if (berichtShow == 1) // waarschuwing laten zien 
		{
			cout << "Even dat je het weet je kan alleen maar .." << endl;
			cout << "voor Vorm alleen 1,2,3 invullen" << endl;
			cout << "jij hebt nu " << vorm << " ingevult daarom default vorm" << endl;
			cout << "\n" << endl;
			berichtShow = 0; // hierdoor bericht maar 1 keer laten zien
		}
		ofSetCircleResolution(100); // mooie ronde cirkel 
		ofEllipse(Ilocation.x, Ilocation.y, 20, 20);
	}
}
