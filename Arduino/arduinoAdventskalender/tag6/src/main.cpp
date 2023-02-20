#include <Arduino.h>

const unsigned int LEDred = 3;
const unsigned int POTI_PIN = A0;

void setup()
{
  Serial.begin(9600);

  pinMode(LEDred, OUTPUT);
  pinMode(POTI_PIN, INPUT);
}

void loop()
{
  int potiValue = analogRead(POTI_PIN);

  Serial.print("gemessener Poti-Wert: ");
  Serial.println(potiValue);

  int ledBrightness = potiValue / 4; //Da analogRead einen Wert zwischen 0 und 1023 liefert, analogWrite aber nur 0-255 zulässt, muss /4 geteilt werden.

  analogWrite(LEDred, ledBrightness);
  delay(50);
}