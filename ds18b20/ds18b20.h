#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>

class ds18b20 {
private:
	int pinNumber;
	const char* server = "api.thingspeak.com";
	const char* wifiName;
	const char* wifiPW;
	const char* apiKey;

	OneWire* pWire;
	DallasTemperature* pDallas;

public:
	ds18b20(int pin, const char* Name, const char* PW, const char* Key);
	~ds18b20();

	void setup(void);
	float getTemperature(void);
	void sendTemperature(float temp);
	
};