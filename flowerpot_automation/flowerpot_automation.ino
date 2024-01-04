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
  //pinMode(BUZZER, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEM, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);

}


void loop() {

  // count days
  unsigned long current_time = millis();
  int current_days = current_time / (1000UL * 3600UL * 24UL);

  // this function will be blinked led forever
  heart_beat_led(current_time);
  
}


void heart_beat_led(unsigned long time) {
  if (time - heart_beat_previous >= heart_beat_interval) {
    heart_beat_previous = time;

    if (digitalRead(13) == LOW) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
}
