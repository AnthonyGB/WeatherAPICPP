// WeatherApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Install cpr (c requests for people library)
// and rapidJSON. 
#include <iostream>
#include <rapidjson/document.h>
//#include <rapidjson/writer.h>
//#include <rapidjson/stringbuffer.h>
#include <cpr/cpr.h>
#include "Weather.h";
#include "UI.h";

using namespace std;

int main(int argc, char** argv)
{
	displayIntroduction();
	displayMenu();

	bool run = true;
	
	char option;
	cin >> option;

	do 
	{
		switch (option) 
		{
			case 'a' : 
				Weather Orlando;
				Orlando.GetWeatherData("Orlando");
				Orlando.display();
				cin.clear();
				cin.ignore(10000, '\n');
		}
		run = false;
	} while (run);

	//Weather Houston;
	//Weather Chicago;
	//Chicago.GetWeatherData("Chicago");
	//Houston.GetWeatherData("Houston");
	//Houston.compare(Chicago);

	//cout << "Select one of the following menu items to get a Current Weather Forecast of any of the following locations.\n" <<
	//	"a: Orlando, FL.\n" <<
	//	"b: Houston, TX.\n" <<
	//	"c: Dallas, TX.\n" <<
	//	"d: New York City, NY.\n" <<
	//	"e: London, UK.\n" <<
	//	"f: Mumbai, IN.\n" <<
	//	"g: Atlanta, GA.\n" <<
	//	"h: Milwaukee, WI.\n" <<
	//	"j: Chicago, IL." <<
	//	"k: Toronto, CA.";		
	/*"c: Compare 2 cities.\n" << 
	"b: Have cities battle for superiority.\n" <<
	"1: Quit.\n";*/

	return 0;
}

