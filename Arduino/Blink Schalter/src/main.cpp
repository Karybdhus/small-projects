#include <Arduino.h>

const int ledPin = 2;
const int buttonPin = 6;

void setup()
{
  pinMode(buttonPin, OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, INPUT);
}

void loop()
{
  bool schalter;

  schalter = digitalRead(buttonPin);
  Serial.println(schalter, DEC);
  if (schalter)
  {
    digitalWrite(ledPin, HIGH);
  }
  else if (!schalter)
  {
    digitalWrite(ledPin, LOW);
  }
}
