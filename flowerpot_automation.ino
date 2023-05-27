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

#define DHTPIN 2          // pinul digital la care e conectat senzorul
#define DHTTYPE DHT11     // tipul de senzor utilizat (pot fi DHT11, DHT21 sau DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print("°C | Umiditate: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000); // așteptăm 2 secunde până la o nouă citire
}
