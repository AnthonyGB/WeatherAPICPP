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
	cout << "Select one of the following menu items to get a 5-day Weather Forecast of any of the following locations or compare 2 different locations.\n" <<
		"a: Orlando, FL.\n" <<
		"s: Houston, TX.\n" <<
		"d: Dallas, TX.\n" <<
		"f: New York City, NY.\n" <<
		"g: London, UK.\n" << 
		"h: Mumbai, IN.\n" <<
		"j: Atlanta, GA.\n" <<
		"k: Milwaukee, WI.\n" <<
		"l: Chicago, IL.\n" << 
		"m: Toronto, CA.\n" << 
		"c: Compare 2 cities.\n" << 
		"b: Have cities battle for superiority.\n" <<
		"1: Quit.\n";
}
