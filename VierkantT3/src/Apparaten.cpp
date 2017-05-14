#include "Apparaten.h"

// Denk dat ik deze functie moet aanroepen in setup van ofApp
// anders is de kans groot dat je error krijg omdat die niet communiceren met setupArduino functie
Apparaten::Apparaten(int welkeApparaat_)
{
	welkeApparaat = welkeApparaat_;
}

void Apparaten::setup()
{
	if (welkeApparaat == 1) // arduino
	{
		preSetupArduino(); // setup arduino

	}
	else if (welkeApparaat == 2) // raspberry pi 
	{

	}
	else if (welkeApparaat == 3) // geen apparaten
	{

	}
	else 
	{
		cout << "crazzzzzz setup" << endl; 
	}


}

void Apparaten::update()
{
	if (welkeApparaat == 1) // arduino
	{
		myArduino.update();
	}
	else if (welkeApparaat == 2) // raspberry pi 
	{

	}
	else if (welkeApparaat == 3) // geen apparaten
	{

	}
	else
	{
		cout << "crazzzzzz update" << endl;
	}
}

void Apparaten::preSetupArduino()
{
	// Arduino connection pc 
	ofAddListener(myArduino.EInitialized, this, &Apparaten::setupArduino);
	arduino_opstarten = false;
	myArduino.connect("COM3", 57600); // aan deze poort zit de arduino 
	myArduino.sendFirmwareVersionRequest(); // Deze regel code niet weg halen anders werkt het niet meer
}

void Apparaten::setupArduino(const int & version)
{
	ofRemoveListener(myArduino.EInitialized, this, &Apparaten::setupArduino);
	arduino_opstarten = true;

	// Vertellen welke electronica op welke pin zit en wat het doet 
	myArduino.sendAnalogPinReporting(0, ARD_ANALOG); // potmeter1
	myArduino.sendAnalogPinReporting(1, ARD_ANALOG); // potmeter2

	ofAddListener(myArduino.EAnalogPinChanged, this, &Apparaten::analogPinChanged);
}

void Apparaten::analogPinChanged(const int & pinNum)
{
	pot1 = myArduino.getAnalog(0);
	pot2 = myArduino.getAnalog(1);
}
