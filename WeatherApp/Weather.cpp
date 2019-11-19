#include "Weather.h";

Weather::Weather()
{
	five_day_forecast.assign(5, WeatherData());
}

Weather::~Weather() 
{
}

void Weather::setCityName(string cityName) 
{
	this->cityName = cityName;
}

string Weather::getCityName() 
{
	return cityName;
}

void Weather::GetWeatherData(string cityname) 
{
	this->setCityName(cityName);
	string json, url, cityid;
	for (int i = 0; i < 10; i++) 
	{
		if (cityname == cities[i].name) 
		{
			cityid = cities[i].id;
		}
	}
	url = "api.openweathermap.org/data/2.5/forecast?id=" + cityid + "&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial";
	auto request = cpr::Get(cpr::Url{url});
	json = request.text; //JSON text string
	Parse(json);
}

void Weather::Parse(string json) 
{
	rapidjson::Document doc;
	doc.Parse(json.c_str());
	if (doc.HasMember("list"))
	{
		if (doc["list"].IsArray())
		{
			rapidjson::Value& jsonElements = doc["list"];
			list<WeatherData>::iterator it = five_day_forecast.begin();
			for (int i = 0; i < jsonElements.Size(), it != five_day_forecast.end(); i = i + 7, it++) {
				for (auto& m : jsonElements[i].GetObject()) //for each member, do this 
				{
					//switch statement here. Some objects are arrays, some are objects
					string name = m.name.GetString();
					if (name == "main")
					{
						it->temperature = m.value["temp"].GetDouble();
						it->maxTemp = m.value["temp_max"].GetDouble();
						it->minTemp = m.value["temp_min"].GetDouble();
					}
					else if (name == "weather")
					{
						it->weatherConditions = jsonElements[i]["weather"][0]["description"].GetString();
					}
					else if (name == "wind")
					{
						it->windSpeed = m.value["speed"].GetDouble();
					}
					else if (name == "dt_txt")
					{
						it->dateTxt = m.value.GetString();
					}
				}
			}
		}
	}

}

void Weather::display() 
{
	for(list <WeatherData> ::iterator i = five_day_forecast.begin(); i != five_day_forecast.end(); i++)
	{
		
		cout << "Weather data for " << i->dateTxt.substr(0, 10)
			<< ":\nTemperature: " << setw(40) << left << i->temperature << "\nMax: " << setw(40) << left << i->maxTemp << "\nMin: " << setw(40) << left
			<< i->minTemp << "\nWind Speed: " << setw(40) << left << i->windSpeed
			<< "\nWeather Description: " << setw(40) << left << i->weatherConditions << "\n\n";
	}
}

void Weather::compare(Weather& city) 
{
	cout << "City 1 Forecast:\n\n\n";
	this->display();
	cout << "City 2 Forecast:\n\n\n";
	city.display();
}

//void Weather::battle(Weather& city) 
//{
//	if (city.getCityName == "Houston" || this->cityName == "Houston") 
//	{
//		cout << "Houston is amazing. We don't do battles against Houston.\n\n";
//	}
//}