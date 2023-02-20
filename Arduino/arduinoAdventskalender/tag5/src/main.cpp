#include <Arduino.h>

const unsigned int LEDred = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(LEDred, OUTPUT);
}

void loop()
{
  for (int i = 1; i <= 255; i++)
  {
    analogWrite(LEDred, i);

    Serial.println(i);
    delay(20);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite(LEDred, i);
    Serial.println(i);
    delay(20);
  }
}
