/*
                   #########################
      Project ---> Automation Flower v.0.1.0 ---> Arduino UNO R3 + C/C++
                   #########################
                   
      Needs: --> Flower, 
                 Arduino UNO, 
                 Moisture Sensor, 
                 Water Level Sensor,
                 Water Pump, 
                 Water Hose etc.
                 
      ---> Idea: This is a complete automated flower assistant. If the flower 
                 does not have water, Arduino will send water to the flowerpot. 
                 If there is no water in the water hose, Arduino will send a 
                 message to the mobile phone. If it is very cold, Arduino will 
                 also send a message."
 */

#include <DHT.h>

// air: humidity and temeprature
#define DHTPIN 2          // pinul digital la care e conectat senzorul
#define DHTTYPE DHT11     // tipul de senzor utilizat (pot fi DHT11, DHT21 sau DHT22)
DHT dht(DHTPIN, DHTTYPE);

// earth humidity
#define EARTH_SENSOR A0

// Water sensor
#define WATER_SENSOR A1

// leds
#define GREEN_LED 13  // if temperature is ok, it will be blinked permanent
#define RED_LED 12    // if no water in bol, blink
#define BLUE_LED 8    // if earth haven't water, will be blinked

// rele define here
#define WATER_POMP 3

void setup() {
  
  pinMode(EARTH_SENSOR, INPUT);
  pinMode(WATER_SENSOR, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(WATER_POMP, OUTPUT);
  
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  // air: humidity and temperature senzor Value
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // value for earth humidity senzor
  int senzor_EARTH = analogRead(EARTH_SENSOR);

  // water volum
  int sensor_WATER = analogRead(WATER_SENSOR);

  // Temperature and humidity - air
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print("°C | Umiditate: ");
  Serial.print(humidity);
  Serial.println("%");

  // earth sensor value
  Serial.print("Valoare senzor: ");
  Serial.println(sensorValue);

  delay(2000); // așteptăm 2 secunde până la o nouă citire
}
