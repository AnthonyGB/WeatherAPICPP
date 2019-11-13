#include "Weather.h";

Weather::Weather() : current_size(0)
{}

Weather::~Weather() 
{
}

//void Weather::setCityID(string cityId) 
//{
//	this->cityId = cityId;
//}

//string Weather::getCityId() 
//{
//	return cityId;
//}

void Weather::setUrl(string cityId)
{
	this->url = "api.openweathermap.org/data/2.5/forecast?id=" + cityId +"&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial";
}

string Weather::getUrl() 
{
	return url;
}

string Weather::makeApiCall(string url) 
{
	string json;
	auto request = cpr::Get(cpr::Url{url});
	json = request.text; //JSON text string
	return json;
}

//pass pointer of empty array along with json, then parse json and fill the array
void Weather::ParseAndFill(string json) 
{
	rapidjson::Document doc;
	doc.Parse(json.c_str());
	if (doc.HasMember("list")) 
	{
		if (doc["list"].IsArray())
		{
			rapidjson::Value& list = doc["list"][0];
			//int dayNumber = 1;
			for (int i = 0, objIndex = 0; i < list.Size(); i = i + 7, objIndex++) {
				for (auto& m : list[i].GetObject()) //for each member, do this 
				{
					string name = m.name.GetString();
					if (name == "main") 
					{
						DataByDay[objIndex].temperature = m.value["temp"].GetDouble();
						DataByDay[objIndex].maxTemp = m.value["temp_max"].GetDouble();
						DataByDay[objIndex].minTemp = m.value["temp_min"].GetDouble();
					}
					else if (name == "weather") 
					{
						DataByDay[objIndex].weatherConditions = list[i]["weather"][0]["description"].GetString();
					}
					else if (name == "wind")
					{
						DataByDay[objIndex].windSpeed = m.value["speed"].GetDouble();
					}
					else if (name == "dt_txt") 
					{
						DataByDay[objIndex].dateTxt = m.value.GetString();
					}
				}
			}
		}
	}
}

//add to end of list whenn used in for loop
void Weather::addToList(WeatherData o, int index) 
{
	if (current_size == ARRAY_SIZE) 
	{
		cerr << "Cannot add another WeatherData element, teminating program...\n";
		exit(1);
	}
	else if (index < 0) 
	{
		cerr << "Invalid position for adding a WeatherData element. Nothing was changed.\n";
		return;
	}
	else 
	{
		DataByDay[index] = o;
		current_size++;
	}
}

void Weather::emptyList(int index) 
{
	if (current_size == 0)
	{
		cout << "No weatherdata is currently loaded\n";
		return;
	}
	else current_size = 0;
}

void Weather::display() 
{
	for(int i = 0; i < current_size; i++)
	{
		cout << "Weather data for " << DataByDay[i].dateTxt.substr(0, 10)
			<< ":\nTemperature: " << setw(25) << DataByDay[i].temperature << "\nMax: " << setw(25) << DataByDay[i].maxTemp << "\nMin: " << setw(25) << DataByDay[i].minTemp
			<< "\nWind Speed: " << setw(25) << DataByDay[i].windSpeed
			<< "\nWeather Description: " << setw(25) << DataByDay[i].weatherConditions << "\n";
	}
}

//bool Weather::isEmpty() 
//{
//	return current_size == 0;
//}