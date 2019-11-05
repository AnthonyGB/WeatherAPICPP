#pragma once
//I am using the open weather api
#ifndef WEATHER
#define WEATHER
using namespace std;
#include <string>

struct WeatherData 
{
	double temperature, maxTemp, minTemp; 
	string weatherConditions; //raining storming sunny etc
};

class Weather {
public:
	//constructer and destructor
	Weather();
	~Weather();

private:
	//there's more secure ways to do this but since this is for school, I don't want to bother so iput the api key in here
	string url = "api.openweathermap.org/data/2.5/weather?q={" + cityName + "},{" + countryCode + "}&APPID={f2cc4ae311506f4fae2685b91b863ef6}&units=imperial"; //for celsius units=metric
	/* if we want to pass an id instead for better accuracy this will be the url...
	"http://api.openweathermap.org/data/2.5/forecast?id={ city id}&APPID={APIKEY}"
	*/
	string cityName;
	string countryCode;
};

#endif 