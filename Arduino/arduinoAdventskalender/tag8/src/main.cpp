#include <Arduino.h>

const unsigned int MIN_LED_PIN = 3;
const unsigned int MAX_LED_PIN = 12;
const unsigned int POTI_PIN = A0;

void setup()
{
  Serial.begin(9600);

  for (int pin = MIN_LED_PIN; pin <= MAX_LED_PIN; pin++)
  {
    pinMode(pin, OUTPUT);
  }
  pinMode(POTI_PIN, OUTPUT);
}

void loop()
{
  int potiValue = analogRead(POTI_PIN);

  Serial.print("gemessener Poti-Wert: ");
  Serial.println(potiValue);

  int pegel = map(potiValue, 0, 1023, MIN_LED_PIN - 1, MAX_LED_PIN);

  Serial.print("Ermittelter Pegel-Wert: ");
  Serial.println(pegel);

  for (int pin = MIN_LED_PIN; pin <= MAX_LED_PIN; pin++)
  {
    digitalWrite(pin, pin <= pegel ? HIGH : LOW);
  }
  delay(50);
}