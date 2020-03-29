#include "Adafruit_DHT.h"

// Modified example sketch for DHT temperature sensors
// Written by ladyada, modified by PirateGuy97

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11		// DHT 11 
//#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(30000);

	float t = dht.getTempCelcius();
	
	String temp = String(t);

    Particle.publish("temp", temp, PRIVATE);
}

