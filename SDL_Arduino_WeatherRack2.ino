
/*
  SDL_Arduino_WeatherRack2
  Example for Arduino
  September 2020

*/


#include "SDL_Arduino_WeatherRack2.h"

SDL_Arduino_WeatherRack2 weatherRack2;




void setup()
{
  Serial.begin(115200);
  Serial.println(F("-----------"));
  Serial.println(F("SwitchDoc Labs"));
  Serial.println(F("Arduino WeatherRack2 and Indoor T/H Test"));
  Serial.println(F("-----------"));

  weatherRack2 = SDL_Arduino_WeatherRack2(600, true, true );

  weatherRack2.begin();

}

int currentValue;

void loop()
{

  Serial.println("------------");

  currentValue = weatherRack2.waitForNextMessage();
  switch (currentValue)
  {
    case NO_MESSAGE:
      Serial.println("NO_MESSAGE");
      break;
    case MESSAGE_CRC_ERROR_WR2:
      Serial.println("MESSAGE_CRC_ERROR_WR2");
      break;

    case MESSAGE_CRC_ERROR_ITH:
      Serial.println("MESSAGE_CRC_ERROR_ITH");
      break;
    case MESSAGE_TIMEOUT:
      Serial.println("MESSAGE_TIMEOUT");
      break;
    case MESSAGE_WEATHERRACK2_GOOD:
      Serial.println("MESSAGE_WEATHERRACK2_GOOD");
      Serial.println();
      Serial.print(F("currentWR2.messageid="));
      Serial.println(weatherRack2.currentWR2.messageid);
      Serial.print(F("currentWR2.time="));
      Serial.println(weatherRack2.currentWR2.time);
      Serial.print(F("currentWR2.device="));
      Serial.println(weatherRack2.currentWR2.device);
      Serial.print(F("currentWR2.modelnumber="));
      Serial.println(weatherRack2.currentWR2.modelnumber);
      Serial.print(F("weatherRack2.currentWR2.battery="));
      Serial.println(weatherRack2.currentWR2.battery);

      Serial.print(F("currentWR2.avewindspeed="));
      Serial.println(weatherRack2.currentWR2.avewindspeed);
      Serial.print(F("currentWR2.gustwindspeed="));
      Serial.println(weatherRack2.currentWR2.gustwindspeed);
      Serial.print(F("currentWR2.winddirection="));
      Serial.println(weatherRack2.currentWR2.winddirection);
      Serial.print(F("currentWR2.cumulativerain="));
      Serial.println(weatherRack2.currentWR2.cumulativerain);

      Serial.print(F("currentWR2.temperature="));
      Serial.println(weatherRack2.currentWR2.temperature);
      Serial.print(F("currentWR2.humidity="));
      Serial.println(weatherRack2.currentWR2.humidity);
      Serial.print(F("currentWR2.light="));
      Serial.println(weatherRack2.currentWR2.light);
      Serial.print(F("currentWR2.uv="));
      Serial.println(weatherRack2.currentWR2.uv);
      Serial.print(F("currentWR2.CRC=0x"));
      Serial.println(weatherRack2.currentWR2.CRC, HEX);



      break;
    case MESSAGE_INDOORTH_GOOD:
      Serial.println(F("MESSAGE_INDOORTH_GOOD"));
      Serial.println();
      Serial.print(F("IndoorTHMessage.messageid="));
      Serial.println(weatherRack2.currentIndoorTH.messageid);
      Serial.print(F("IndoorTHMessage.time="));
      Serial.println(weatherRack2.currentIndoorTH.time);
      Serial.print(F("IndoorTHMessage.device="));
      Serial.println(weatherRack2.currentIndoorTH.device);
      Serial.print(F("IndoorTHMessage.modelnumber="));
      Serial.println(weatherRack2.currentIndoorTH.modelnumber);
      Serial.print(F("IndoorTHMessage.channel="));
      Serial.println(weatherRack2.currentIndoorTH.channel);
      Serial.print(F("IndoorTHMessage.battery="));
      Serial.println(weatherRack2.currentIndoorTH.battery);
      Serial.print(F("IndoorTHMessage.temperature="));
      Serial.println(weatherRack2.currentIndoorTH.temperature);
      Serial.print(F("IndoorTHMessage.humidity="));
      Serial.println(weatherRack2.currentIndoorTH.humidity);
      Serial.print(F("IndoorTHMessage.CRC=0x"));
      Serial.println(weatherRack2.currentIndoorTH.CRC, HEX);
      break;

    default:
      Serial.println("UNKNOWN");
      Serial.print(F("Returned Value="));
      Serial.println(currentValue);
      break;
  }

  Serial.println();
  Serial.print(F("Headers Found="));
  Serial.println(weatherRack2.readHeadersFound());
  Serial.print(F("WeatherRack2 Sensors Found="));
  Serial.println(weatherRack2.readWeatherRack2Found());
  Serial.print(F("Indoor T/H Found="));
  Serial.println(weatherRack2.readSDLIndoorTHFound());
  Serial.println();
  delay(5000);

}
