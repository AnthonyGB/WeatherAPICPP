// WeatherApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//https://curl.haxx.se/libcurl/c/example.html some examples of libcurl being used. I suggest looking through it along with documentation
//tinyxml will allow us to parse the info we get from curl and output it to console. If you prefer a different XML parser like pugi let me know and ill switch it.
//I have not looked extensively at the documentation so i'll have to learn how to use them but they work
#define CURL_STATICLIB
#include <iostream>
#include <pugixml.hpp>
#include "Weather.h";
#include "UI.h";
#include <cpr/cpr.h>
using namespace std;

int main(int argc, char** argv)
{
	auto request = cpr::Get(cpr::Url{"api.openweathermap.org/data/2.5/weather?q={London},{uk}&APPID={f2cc4ae311506f4fae2685b91b863ef6}&units=imperial"});

	displayIntroduction();
	displayMenu();
	//pugi::xml_attribute_struct;
	return 0;
}

