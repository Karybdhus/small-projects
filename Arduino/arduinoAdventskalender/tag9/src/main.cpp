#include <Arduino.h>
#include "timer.h"

const unsigned int POTI_PIN = A0;
const unsigned int LED_PINS[4] = {3, 5, 6, 9};

void setup()
{
  Serial.begin(9600);

  for (int pin = 0; pin < 4; pin++)
  {
    pinMode(LED_PINS[pin], OUTPUT);
  }
  pinMode(POTI_PIN, INPUT);
}

void loop()
{
  bool delayValue = timer(1000);

  if (delayValue)
  {
    int potiValue = analogRead(POTI_PIN);

    Serial.println("----------");
    Serial.print("gemessener Poti-Wert: ");
    Serial.println(potiValue);

    int pegel = potiValue * 4;

    Serial.print("Ermittelter Pegel: ");
    Serial.println(pegel);

    for (int ledIndex = 0; ledIndex < 4; ledIndex++)
    {
      int brightness = (pegel - ledIndex * 1023) / 4;
      if (brightness > 255)
      {
        brightness = 255;
      }
      else if (brightness < 0)
      {
        brightness = 0;
      }

      Serial.print("Pin: ");
      Serial.print(LED_PINS[ledIndex]);
      Serial.print(" / ");
      Serial.println(brightness);

      analogWrite(LED_PINS[ledIndex], brightness);
    }
  }
}