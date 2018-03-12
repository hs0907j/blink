#include "ds18b20.h"

ds18b20::ds18b20(int pin, const char* Name, const char* PW, const char* Key) {
	pinNumber = pin;
	wifiName = Name;
	wifiPW = PW;
	apiKey = Key;

	pWire = new OneWire(pinNumber);
	pDallas = new DallasTemperature(pWire);
}

ds18b20::~ds18b20(void) {
	if(pWire != NULL) delete pWire;
	if(pDallas != NULL)delete pDallas;
}

void ds18b20::setup(void) {
	Serial.begin(115200);
	Serial.println("Dallas Temperature Check Program Setup\n");

	Serial.print("Connecting to " + String(wifiName));
	WiFi.begin(wifiName, wifiPW);
	while (WiFi.status() != WL_CONNECTED) {
		delay(1000);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("Connected");
	Serial.println("");

	pDallas->begin();
}

float ds18b20::getTemperature(void) {
	float RET;

	Serial.print(" Requesting temperatures...");
	pDallas->requestTemperatures();
	Serial.println("DONE");

	Serial.print("Temperature for Device is: ");
	RET = pDallas->getTempCByIndex(0);
	Serial.print(RET);
	Serial.print("\n");

	return RET;
}

void ds18b20::sendTemperature(float temp) {
	WiFiClient client;

	if (client.connect(server, 80)) { // use ip 184.106.153.149 or api.thingspeak.com
		String postStr = apiKey;
		postStr += "&field1=";
		postStr += String(temp);
		postStr += "\r\n\r\n";

		client.print("POST /update HTTP/1.1\n");
		client.print("Host: api.thingspeak.com\n");
		client.print("Connection: close\n");
		client.print("X-THINGSPEAKAPIKEY: " + String(apiKey) + "\n");
		client.print("Content-Type: application/x-www-form-urlencoded\n");
		client.print("Content-Length: ");
		client.print(postStr.length());
		client.print("\n\n");
		client.print(postStr);
		Serial.println("now WiFi Client connected and sending over\n");
	}//end if

	client.stop();
}//end send

