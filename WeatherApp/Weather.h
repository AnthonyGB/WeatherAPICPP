#pragma once
//I am using the open weather map api
#ifndef WEATHER
#define WEATHER
using namespace std;
#include <string>
#include <cpr/cpr.h>
#include <rapidjson/document.h>
#include <iostream>
#include <list>
#include <iomanip>
#include <iterator>
const int ARRAY_SIZE = 5;

struct WeatherData 
{
	double temperature, maxTemp, minTemp, windSpeed;
	string dateTxt, weatherConditions; //date and conditions(raining storming sunny etc)
};

struct City 
{
	string name, id;
};

class Weather 
{
public:
	//constructer and destructor
	Weather();
	~Weather();

	void display();

	void setCityName(string cityName);
	string getCityName();

	//working with api & json
	void GetWeatherData(string cityname);
	void Parse(string json);

	void compare(Weather& city);
	void battle(Weather& city); 

private:
	//api.openweathermap.org/data/2.5/forecast?id={cityid}&&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial
	//string url; //for celsius units=metric
	list<WeatherData> five_day_forecast;
	string cityName;
	const City cities[10] = { 
		{"Houston", "4699066"}, {"Dallas", "4684888"}, {"Mumbai", "1275339"}, {"London", "2643743"}, {"New York", "5128581"}, 
		{"Orlando", "4167147"}, {"Atlanta", "4180439"}, {"Milwaukee", "5263045"}, {"Chicago", "4887398"}, {"Toronto", "6167865"}
	};
};



#endif 