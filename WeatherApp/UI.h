#pragma once
#include <iostream>
using namespace std;

//just inlining some stuff to do with console 

void displayIntroduction()
{
	cout << "Welcome to V's and Anthony's Console Weather Application!\n" << 
		"Using the Open Weather api, we will bring you current weather forecasts from locations around the globe.\n\n";
}

void displayMenu()
{
	//just place holders for now we'll decide what to do later
	cout << "Select one of the following menu items to get a Current Weather Forecast of any of the following locations.\n" <<
		"a: Orlando, FL.\n" <<
		"b: Houston, TX.\n" <<
		"c: Austin, TX.\n" <<
		"d: New York City, NY.\n" <<
		"e: London, UK.\n";
}
