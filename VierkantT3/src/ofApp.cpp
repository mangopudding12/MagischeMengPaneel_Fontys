#include "ofApp.h"

// Marijn !!! 
// Als de arduino het niet doet wees dan alsjeblieft niet zo dom!! 
// Zet standaard firmate er weer op super top :) Good luck :P hihi 


//--------------------------------------------------------------
void ofApp::setup() 
{
	//  1 = arduino  2= raspberry pi  3= geen apparaat 
	apparaatSetup(3);
	
	ofSetBackgroundColor(255);

	vierkant.setup(200, 200, 500,100);
	vierkant.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant1.setup(80, 80, 500, 100);
	vierkant1.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant2.setup(80, 80, 100, 530);
	vierkant2.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant3.setup(80, 80, 500, 450);
	vierkant3.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant4.setup(80, 80, 870, 560);
	vierkant4.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant5.setup(80, 80, 600, 290);
	vierkant5.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant6.setup(80, 80, 250, 300);
	vierkant6.SetupminiCel(2, 0.1, 30, 30); // int vorm_, float speed_, float Ibh_x, float Ibh_y	

	vierkant7.setup(80, 80, 870, 100);
	vierkant7.SetupminiCel(2, 0.1, 20, 20); // int vorm_, float speed_, float Ibh_x, float Ibh_y	
}


//--------------------------------------------------------------
void ofApp::update()
{
	apparaatUpdate();
	

	vierkant.minicelMove(pot2);
	vierkant.MoveAll();

	vierkant1.minicelMove(pot2);
	vierkant1.MoveAll();

	vierkant2.minicelMove(pot2);
	vierkant2.MoveAll();

	vierkant3.minicelMove(pot2);
	vierkant3.MoveAll();

	vierkant4.minicelMove(pot2);
	vierkant4.MoveAll();

	vierkant5.minicelMove(pot2);
	vierkant5.MoveAll();

	vierkant6.minicelMove(pot2);
	vierkant6.MoveAll();

	vierkant7.minicelMove(pot2);
	vierkant7.MoveAll();
}



//--------------------------------------------------------------
void ofApp::draw()
{
	if (zichtbaar == true)
	{
		vierkant.Vdisplay();
		vierkant2.Vdisplay();
		vierkant1.Vdisplay();
		vierkant3.Vdisplay();
		vierkant4.Vdisplay();
		vierkant5.Vdisplay();
		vierkant6.Vdisplay();
		vierkant7.Vdisplay();
	}


	
	vierkant3.minicelDisplay(pot1);
	vierkant4.minicelDisplay(pot1);
	vierkant5.minicelDisplay(pot1);
	vierkant6.minicelDisplay(pot1);
	vierkant7.minicelDisplay(pot1);
	vierkant.minicelDisplay(pot1);
	vierkant1.minicelDisplay(pot1);
	vierkant2.minicelDisplay(pot1);
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
		myArduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer
	}
	else if (welkeApparaat == 2) // raspberry pi 
	{
		// setup de mcp3008 chip
		//mcp.setup("/dev/spidev0.0", SPI_MODE_0, 1000000, 8);
	}
	else if (welkeApparaat == 3) // geen apparaten
	{
		// Standaart waarden die je kan veranderen
		pot1 = 0;
		pot2 = 0; 
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
		// Hier hoeft niks te gebeuren.
		int static state = 0;

		if (state == 0)
		{
			if (pot1 >= 1023)
			{
				state = 1;
			}
			pot1 --;
		}
		else if (state == 1)
		{
			if (pot1 <= 0)
			{
				state = 0;
			}
			pot1 ++;
		}

		if (state == 0)
		{
			if (pot2 >= 1023)
			{
				state = 1;
			}
			pot2++;
		}
		else if (state == 1)
		{
			if (pot2 <= 0)
			{
				state = 0;
			}
			pot2--;
		}
		cout << pot2 << endl;
	}
	else
	{
		cout << "crazzzzzz update" << endl;
	}
}

void ofApp::setupArduino(const int & version)
{
	ofRemoveListener(myArduino.EInitialized, this, &ofApp::setupArduino);
	arduino_opstarten = true;

	// Vertellen welke electronica op welke pin zit en wat het doet 
	myArduino.sendAnalogPinReporting(0, ARD_ANALOG); // potmeter1
	myArduino.sendAnalogPinReporting(1, ARD_ANALOG); // potmeter2

	ofAddListener(myArduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}


void ofApp::analogPinChanged(const int & pinNum)
{
	pot1 = myArduino.getAnalog(0);
	pot2 = myArduino.getAnalog(1);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (zichtbaar == false)
	{
		zichtbaar = true;
	}
	else {
		zichtbaar = false;
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
