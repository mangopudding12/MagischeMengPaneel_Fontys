#pragma once
#include "ofMain.h"
#include "M_HoofdCel.h"
#include "M_VierKantCel.h"


class DisplayEverything
{
public: 
	// constructor 
	DisplayEverything() {};

	void SetupEverything(int aantal_);
	void MoveEverything(int pot0_, int pot2_);
	void Display(int pot1_, int pot3_, int pot4_);
	void ResetLocaties(); 

	// Pionter van M_VierkantCel
	M_VierkantCel* testM;

private: 
	
	float Mbh_x_;
	float Mbh_y_;
	int aantalxas; // aantal vierkanten op de xas
	int aantalyas;
	float Mlocation_x = 0;
	float Mlocation_y = 0;
};