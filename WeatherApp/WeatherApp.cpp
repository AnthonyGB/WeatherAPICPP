// WeatherApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Install cpr (c requests for people library)
// and rapidJSON NOT pugixml. TYSM (:




#define CURL_STATICLIB
#include <iostream>
//#include <pugixml.hpp>
#include <rapidjson/document.h>
#include "Weather.h";
#include "UI.h";
#include <cpr/cpr.h>
using namespace std;

int main(int argc, char** argv)
{
	auto request = cpr::Get(cpr::Url{"api.openweathermap.org/data/2.5/weather?q=London,uk&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial"});
	string rString = request.text; //JSON text string
	cout << rString;
	//displayIntroduction();
	//displayMenu();
	//pugi::xml_attribute_struct;
	return 0;
}

