#pragma once
//I am using the open weather map api
#ifndef WEATHER
#define WEATHER
using namespace std;
#include <string>

class Weather {
public:
	//constructer and destructor
	Weather();
	~Weather();

	void makeApiCall();

	//Accessors/modifiers
	void setCityID(string cityId);
	string getCityId();

private:
	//api.openweathermap.org/data/2.5/forecast?id=524901
	string url = "api.openweathermap.org/data/2.5/forecast?id=" + cityId + "&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial"; //for celsius units=metric
	string cityId;
	double temperature, maxTemp, minTemp, windSpeed;
	string dateTxt, weatherConditions; //date and conditions(raining storming sunny etc)
};

#endif 