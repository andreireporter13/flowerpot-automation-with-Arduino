/*
  New project -> Arduino
  ...
  -> Flowerpot automation v.1.0
*/

// Define pin for sensors:
const int water_pump_pin = 6;
const int soil_sensor_pin = A0;
const int water_level_pin = A1;

// interval for check if need water pump
unsigned long previousMillis = 0;
const unsigned long interval = 24 * 3600 * 1000; // 24 hours in milliseconds

// Builtin led need for pulse :))
const int led_builtin_pin = LED_BUILTIN;


void setup() {
  
    pinMode(water_pump_pin, OUTPUT);

    // set analog pins ---> !
    pinMode(soil_sensor_pin, INPUT);
    pinMode(water_level_pin, INPUT);
  
    pinMode(led_builtin_pin, OUTPUT);
}


void loop() {

    unsigned long current_time = millis();

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
