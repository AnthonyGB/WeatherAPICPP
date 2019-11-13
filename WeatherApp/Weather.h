#pragma once
//I am using the open weather map api
#ifndef WEATHER
#define WEATHER
using namespace std;
#include <string>
#include <cpr/cpr.h>
#include <rapidjson/document.h>
#include <iostream>
#include <iomanip>

const int ARRAY_SIZE = 5;

struct WeatherData 
{
	double temperature, maxTemp, minTemp, windSpeed;
	string dateTxt, weatherConditions; //date and conditions(raining storming sunny etc)
};

class Weather 
{
public:
	//constructer and destructor
	Weather();
	~Weather();
	//list ops
	void addToList(WeatherData o, int index);
	void emptyList(int index);
	void display();

	//working with api & json
	string makeApiCall(string url);
	void ParseAndFill(string json);

	//Accessors/modifiers
	void setUrl(string cityId);
	string getUrl();


private:
	//api.openweathermap.org/data/2.5/forecast?id={cityid}&&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial
	string url; //for celsius units=metric
	int current_size;
	WeatherData DataByDay[ARRAY_SIZE];
	//string cityId;
};



#endif 