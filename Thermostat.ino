#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// LCD Display settings
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables to store temperature readings and user settings
float currentTemperature = 0.0;
float desiredTemperature = 25.0; // Initial desired temperature in Celsius

// Constants for relay control
const int relayPin = 10;

// Constants for user interface
const int upButtonPin = 7;
const int downButtonPin = 8;
const int confirmButtonPin = 9;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
  pinMode(confirmButtonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Desired: ");
  lcd.print(desiredTemperature);
  lcd.print(" C");
  
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  currentTemperature = sensors.getTempCByIndex(0);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(currentTemperature);
  lcd.print(" C");

  // User interaction: Adjust desired temperature
  if (digitalRead(upButtonPin) == LOW) {
    desiredTemperature += 1.0;
    delay(200); // Button debounce delay
  }

  if (digitalRead(downButtonPin) == LOW) {
    desiredTemperature -= 1.0;
    delay(200); // Button debounce delay
  }

  // Temperature control
  if (currentTemperature < desiredTemperature) {
    // Temperature is below desired, turn on the heater.
    digitalWrite(relayPin, HIGH);
  } else {
    // Temperature is at or above desired, turn off the heater.
    digitalWrite(relayPin, LOW);
  }

  // Display desired temperature
  lcd.setCursor(9, 0);
  lcd.print("    "); // Clear previous value
  lcd.setCursor(9, 0);
  lcd.print(desiredTemperature);
  lcd.print(" C");
}
