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

	//float bh_x, float bh_y, float location_x, float location_y
	testM.Msetup(250,250,100,50);
	testM.SetupVierKantCel(2,0.3,60,60);

	testM1.Msetup(250, 250, 350, 50);
	testM1.SetupVierKantCel(2, 0.3, 60, 60);

	testM2.Msetup(250, 250, 100, 300);
	testM2.SetupVierKantCel(2, 0.3, 60, 60);

	testM3.Msetup(250, 250, 350, 300);
	testM3.SetupVierKantCel(2, 0.3, 60, 60);

	testM4.Msetup(250, 250, 600, 50);
	testM4.SetupVierKantCel(2, 0.3, 60, 60);

	testM5.Msetup(250, 250, 600, 300);
	testM5.SetupVierKantCel(2, 0.3, 60, 60);

}


//--------------------------------------------------------------
void ofApp::update()
{
	apparaatUpdate();
	
	testM.VierKantCelMove(50);

	testM1.VierKantCelMove(50);

	testM2.VierKantCelMove(50);

	testM3.VierKantCelMove(50);

	testM4.VierKantCelMove(50);

	testM5.VierKantCelMove(50);

}



//--------------------------------------------------------------
void ofApp::draw()
{
	testM.M_display();
	testM4.M_display();
	testM3.M_display();
	


	testM.VierKantCelDisplay(0);
	testM1.VierKantCelDisplay(0);
	testM2.VierKantCelDisplay(0);
	testM3.VierKantCelDisplay(0);
	testM4.VierKantCelDisplay(0);
	testM5.VierKantCelDisplay(0);

	/*
	vierkant3.minicelDisplay(pot1);
	vierkant4.minicelDisplay(pot1);
	vierkant5.minicelDisplay(pot1);
	vierkant6.minicelDisplay(pot1);
	vierkant7.minicelDisplay(pot1);
	vierkant.minicelDisplay(pot1);
	vierkant1.minicelDisplay(pot1);
	vierkant2.minicelDisplay(pot1);*/
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
		//cout << pot2 << endl;
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
