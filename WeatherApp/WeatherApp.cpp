// WeatherApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Install cpr (c requests for people library)
// and rapidJSON. 
#include <iostream>
//#include <rapidjson/document.h>
//#include <rapidjson/writer.h>
//#include <rapidjson/stringbuffer.h>
//#include <cpr/cpr.h>
#include "Weather.h";
#include "UI.h";

using namespace std;

int main(int argc, char** argv)
{












	/*BELOW IS ALL TESTING*/

	//Weather WeatherObject;
	////cout << WeatherObject.getUrl() << "\n";
	///WeatherObject.setUrl("2643743");
	//string url = WeatherObject.getUrl();
	//string json = WeatherObject.makeApiCall(url);

	//cout << json << "\n";
	// for 5 day forecast.=> api.openweathermap.org/data/2.5/forecast?id=2643743&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial <= for 5 day every 3 hours forecast. below is just testing
	// api.openweathermap.org/data/2.5/weather?q=London,uk&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial <= current weather forecast use for testing
	//auto request = cpr::Get(cpr::Url{"api.openweathermap.org/data/2.5/forecast?id=2643743&APPID=f2cc4ae311506f4fae2685b91b863ef6&units=imperial"});
	//string rString = request.text; //JSON text string
	//rapidjson::Value &s =
	//cout << rString << "\n\n";


	// 1. Parse a JSON string into DOM.
	//rapidjson::Document doc;
	//doc.Parse(rString.c_str());

	//if (doc.HasMember("list")) 
	//{
	//	if (doc["list"].IsArray()) 
	//	{
	//		rapidjson::Value& list = doc["list"];
	//		int dayNumber = 1;
	//		for (int i = 0 ; i < list.Size(); i= i+7) {
	//			for (auto& m : list[i].GetObject()) //for each member, do this 
	//			{
	//				//switch statement here. Some objects are arrays, some are objects
	//				string name = m.name.GetString();
	//				if (name == "main") 
	//				{
	//					printf("Temp on day %i is %f\n", dayNumber, m.value["temp"].GetDouble());
	//				}
	//				else {
	//					printf("Name of member on day %i is %s\n", dayNumber, name.c_str());
	//				}
	//			}
	//			dayNumber++;
	//		}
	//	}
	//}

	//string dayWTime = doc["list"][0]["dt_txt"].GetString();
	//cout << dayWTime.substr(0, 10);

	//cout << doc["list"][0]["main"]["temp"].GetDouble(); <= this is how you get the member of a double for example on the multiple day forecast


	//if (doc.HasMember("weather")) 
	//{
	//	if (doc["weather"].IsArray())
	//	{
	//		//cout << "true";
	//		rapidjson::Value& weather = doc["weather"][0];
	//		for (auto& m : doc.GetObject())
	//			printf("Type of member %s is\n",
	//				m.name.GetString());
	//		cout << "\n";
	//		for (auto& m : doc["weather"][0].GetObject()) {
	//			if (m.value.IsString()) 
	//			{
	//				printf("Value of member %s is %s\n",
	//					m.name.GetString(), m.value.GetString());
	//			}
	//			else 
	//			{
	//				cout << "hello\n"; //note to self. try code below later
	//				//cout << typeid(m.value).name();
	//				printf("Value of member %s is %i\n",
	//					m.name.GetString(), m.value.GetInt());
	//			}
	//		}
	//	}
	// }
	
	// 2. Modify by DOM
	//rapidjson::Value& coords = doc["id"];

	//// 3. Stringify the dom
	//rapidjson::StringBuffer buffer;
	//rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	//doc.Accept(writer);
	//cout << buffer.GetString() << "\n\n";
	//doc.Parse<0>(rString.c_str);
	//rapidjson::Value& s = doc["weather"];
								   
	//displayIntroduction();
	//displayMenu();
	return 0;
}

