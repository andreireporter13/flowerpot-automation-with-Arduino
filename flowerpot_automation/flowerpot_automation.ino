/*
  Arduino Project -> FlowerPot Automation v2.0
  ...
  Board: Arduino Nano with Atmega328p
  Releu high level comand 5v/250vcc
  ...
*/
//
//
// Define PIN for Sensors:
//
// ... Analogic
#define SOIL_SENSOR A0
#define WATER_LEVEL_SENSOR A2
#define FOTOSENSOR A6
#define TEMP_SENSOR A4

// ... Digital
#define WATER_PUMP 4
#define LED_BUILTIN

// ... PWM
#define BUZZER 3
#define RGB_RED 9
#define RGB_GREEN 10
#define RGB_BLUE 11
//

unsigned int previousDays = 0;
unsigned int interval = 2 // zile


void setup() {

  // ... Analogic
  pinMode(SOIL_SENSOR, INPUT);
  pinMode(WATER_LEVEL_SENSOR, INPUT);
  pinMode(FOTOSENSOR, INPUT);
  pinMode(TEMP_SENSOR, INPUT);
  
  // ... Digital
  pinMode(WATER_PUMP, OUTPUT);

  // ... PWM
  pinMode(BUZZER, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEM, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);

}


void loop() {

   unsigned long current_time = millis() / (1000UL * 3600UL * 24UL);

    // time to check if spent 24 hours
    if (current_time - previousMillis >= interval) {
        previousMillis = current_time;

        // here read the values of sensors
        int soil_data_sensor = analogRead(soil_sensor_pin);
        int water_data_level = analogRead(water_level_pin);

        // check for human interaction
        if (water_data_level <= 200 && soil_data_sensor <= 10) {

            // request for water
            while (water_data_level <= 200) {

                // set alert blink sound
                alert_blink_sound();

                water_data_level = analogRead(water_level_pin);

                // set sleep
                delay(3000);
            }
        }
        else if (water_data_level > 200 && soil_data_sensor <= 10) {
            pump_with_water();
        }
    }
}


void alert_blink_sound() {
  digitalWrite(led_builtin_pin, HIGH);
  delay(300);
  digitalWrite(led_builtin_pin, LOW);
  delay(300);

  // plus, in future, add and buzzer here
}


void pump_with_water() {
    digitalWrite(water_pump_pin, HIGH);
    delay(4000);
    digitalWrite(water_pump_pin, LOW);
    delay(1500);
}
