#pragma once
#include "ofMain.h"

class Apparaten
{
public: 
	Apparaten() {};
	Apparaten(int welkeApparaat_); // constuctor 

	// Algemene 
	void setup();
	void update(); 

	// Raspberry pi stuff 


	// Arduino stuff
	ofArduino myArduino;
	int pot1;
	int pot2;


private: 
	//  1 = arduino  2= raspberry pi  3= geen apparaat 

	// Arduino stuff 
	int welkeApparaat; 
	void setupArduino(const int & version);
	void preSetupArduino();
	void analogPinChanged(const int & pinNum);
	bool arduino_opstarten;
};