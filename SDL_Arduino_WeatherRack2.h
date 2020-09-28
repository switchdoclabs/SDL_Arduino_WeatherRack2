//
//   SDL_Arduino_WeatherRack2.h
//   Version 1.2
//   SwitchDoc Labs   September 2020
//
//

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#define WEATHERRACK2_TIMEOUT 500
#define READ_WEATHERRACK2 true
#define READ_SDL_INDOOR_TH true

#define NO_MESSAGE 0
#define MESSAGE_CRC_ERROR_WR2 1
#define MESSAGE_CRC_ERROR_ITH 2
#define MESSAGE_TIMEOUT 3
#define MESSAGE_WEATHERRACK2_GOOD 4
#define MESSAGE_INDOORTH_GOOD 5


#define RX_IN_PIN 8


// Message Structures


/*
messageid : increments by one for each message (WeatherRack2 or Indoor T/H sensor) received and CRC verified<BR>
time: If you have set up the real time clock, it would be good to insert the time in this slot<BR>
model:  Description of the Sensor received<BR>
device: Serial Number of the sensor - changed on powerup but can be used to discriminate from other similar sensors in the area<BR>
modelnumber:   Sensor Model Number<BR>
battery:  0 if battery good, 1 if battery is getting low<BR>
avewindspeed: Average Wind Speed in m/s<BR>
gustwindspeed: Last Gust Speed in m/s<BR>
winddirection: Wind Direction in degrees from 0-359.<BR>
cumulativerain:  Total rain since last reset or power off.  in mm.<BR>
temperature:  outside temperature in C.
humidity:  Relative Humidity in %. <BR>
light:  Visible Sunlight in lux. <BR>
uv:  UV Index * 10 (meaning an uv index of 0.8 is in the example message above)<BR>
CRC: Calculated CRC value (It will match the CRC off of the message or you would not have received the message)<BR>

 */

struct WR2Message {
  long messageid;
  String time;
  int device;
  int modelnumber;
  int battery;
  float avewindspeed;
  float gustwindspeed;
  int winddirection;
  long cumulativerain;
  float temperature;
  int humidity;
  long light;
  int uv;
  int CRC;
  
};

/*
messageid : increments by one for each message (WeatherRack2 or Indoor T/H sensor) received and CRC verified<BR>
time: If you have set up the real time clock, it would be good to insert the time in this slot<BR>
model:  Description of the Sensor received<BR>
device: Serial Number of the sensor - changed on powerup but can be used to discriminate from other similar sensors in the area<BR>
modelnumber:   Sensor Model Number<BR>
battery:  0 if battery good, 1 if battery is getting low<BR>
temperature:  outside temperature in C.
humidity:  Relative Humidity in %. <BR>
CRC: Calculated CRC value (It will match the CRC off of the message or you would not have received the message)<BR>
*/


struct IndoorTHMessage{
  long messageid;
  String time;
  int device;
  int modelnumber;
  int channel;
  int battery;
  float temperature;
  int humidity;
  int CRC;  
};


class SDL_Arduino_WeatherRack2 {
  public:
    SDL_Arduino_WeatherRack2(long timeout = WEATHERRACK2_TIMEOUT, boolean read_weatherrack2 = READ_WEATHERRACK2, boolean read_indoorth = READ_SDL_INDOOR_TH  );


    void begin(void);
    int returnMessageValues();

    int waitForNextMessage();
    void setTimeout(long my_timeout);
    void set_ReadWeatherRack2(boolean my_read_weatherrack2);
    void set_ReadIndoorth(boolean my_readindoorth);
    long readHeadersFound();
    long readWeatherRack2Found();
    long readSDLIndoorTHFound();

    long _timeout;
    boolean _read_weatherrack2;
    boolean _read_indoorth;

    WR2Message currentWR2;
    IndoorTHMessage currentIndoorTH;



  private:

    int findNextMessage();

    long messageID;


    long headersFound;
    long FT300MessagesFound;
    long FT007MessagesFound;




    int add(byte bitData);
    uint8_t Checksum(int length, uint8_t *buff);
    uint8_t GetCRC(uint8_t crc, uint8_t * lpBuff, uint8_t ucLen);

    void eraseManchester();



};
