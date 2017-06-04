#include "ofApp.h"

// Marijn !!! 
// Als de arduino het niet doet wees dan alsjeblieft niet zo dom!! 
// Zet standaard firmate er weer op super top :) Good luck :P hihi 


//--------------------------------------------------------------
void ofApp::setup() 
{
	ofSetBackgroundColor(255);

	aantal_Potmeters = 5;
	// Maak array waar we alle potmeter data in bewaren
	pot = new int[aantal_Potmeters];
	state_optie3 = new int[aantal_Potmeters];

	for (int i = 0; i < aantal_Potmeters; i++)
	{
		pot[i] = 0; 
		state_optie3[i] = 1;
	}

	for (int i = 0; i < aantal_Potmeters/2; i++)
	{
		state_optie3[i] = 0;
	}
	cout << "Voor arduino setup" << endl; 
	//  1 = arduino  2= raspberry pi  3= geen apparaat 1
	apparaatSetup(1);

	// aantal(maximaal 10 daarna doet die raar, even getal) , breedte , hoogte 
	alles.SetupEverything(6);
}


//--------------------------------------------------------------
void ofApp::update()
{
	apparaatUpdate();
		
	alles.MoveEverything(pot[0],pot[2]); 
}



//--------------------------------------------------------------
void ofApp::draw()
{
	alles.Display(pot[1], pot[3], pot[4]);
}


void ofApp::apparaatSetup(int welkeApparaat_)
{

	// Dit zorgt ervoor dat we geen errors krijgen 
	// Wanneer er geen aruino of raspberry pi is aangesloten.
	welkeApparaat = welkeApparaat_;

	if (welkeApparaat == 1) // arduino
	{
		ofAddListener(myArduino.EInitialized, this, &ofApp::setupArduino);
		arduino_opstarten = false;
		myArduino.connect("COM3", 57600); // aan deze poort zit de arduino 
		cout << " arduino setup" << endl;
		myArduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer
		cout << "Hier werk ik ook nog" << endl;
	}
	else if (welkeApparaat == 2) // raspberry pi 
	{
		// setup de mcp3008 chip
		//mcp.setup("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);
	}
	else if (welkeApparaat == 3) // geen apparaten
	{
		// Standaart waarden die je kan veranderen
		for (int i = 0; i < aantal_Potmeters; i++)
		{
			pot[i] = 0; 
		}
	}
	else
	{
		cout << "crazzzzzz update" << endl;
	}
	
}

void ofApp::apparaatUpdate()
{
	if (welkeApparaat == 1) // arduino
	{
		myArduino.update();

	}
	else if (welkeApparaat == 2) // raspberry pi 
	{
		// Om de data uit de chip te lezen.  
		// dit moet in de update anders werkt het niet 
		//data[0] = 1;
		//data[1] = 0b10000000 | (((a2dChannel & 7) << 4));
		//data[2] = 0;

		//data2[0] = 1;
		//data2[1] = 0b10000000 | (((a2dChannel2 & 7) << 4));
		//data2[2] = 0;

		//mcp.readWrite(data);//sizeof(data) );
		//mcp.readWrite(data2);

		//pot1 = 0;
		//pot1 = (data[1] << 8) & 0b1100000000;

		// wanneer je | weghaalt word data van 0 255 en dat 4 keer overnieuw
		// dus niet weghalen | dan data van 0 1023.
		//pot1 |= (data[2] & 0xff);

		//pot2 = 0;
		//pot2 = (data2[1] << 8) & 0b1100000000;

		// wanneer je | weghaalt word data van 0 255 en dat 4 keer overnieuw
		// dus niet weghalen | dan data van 0 1023.
		//pot2 |= (data2[2] & 0xff);

		//cout << "....... " << pot2 << endl;
		//cout << "The Result is: " << pot1 << endl;
	}
	else if (welkeApparaat == 3) // geen apparaten
	{
		for (int i = 0; i < aantal_Potmeters; i++)
		{
			if (state_optie3[i] == 0)
			{
				if (pot[i] >= 1023)
				{
					state_optie3[i] = 1;
				}
				pot[i]--;
			}
			else if (state_optie3[i] == 1)
			{
				if (pot[i] <= 0)
				{
					state_optie3[i] = 0;
				}
				pot[i]++;
			}
		}
		
	}
	else
	{
		cout << "crazzzzzz update" << endl;
	}
}

void ofApp::setupArduino(const int & version)
{
	cout << arduino_opstarten << endl; 
	ofRemoveListener(myArduino.EInitialized, this, &ofApp::setupArduino);
	arduino_opstarten = true;

	// Vertellen welke electronica op welke pin zit en wat het doet 
	for (int i = 0; i < aantal_Potmeters; i++)
	{
		myArduino.sendAnalogPinReporting(i, ARD_ANALOG); // potmeter1
		cout << i << endl; 
	}
	
	ofAddListener(myArduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	cout << arduino_opstarten << endl;
}


void ofApp::analogPinChanged(const int & pinNum)
{
	for (int i = 0; i < aantal_Potmeters; i++)
	{
		pot[i] = myArduino.getAnalog(i);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	// r 
	if (key == 114)
	{
		alles.ResetLocaties();
	}

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------
void ofApp::exit()
{
	cout << "pointers gedelet" << endl; 
	delete[] alles.testM;
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
