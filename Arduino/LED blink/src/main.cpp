#include <Arduino.h>
#include "timer.h"

bool AN;
int LEDred = 6;    // Rot an Port 6
int LEDgreen = 10; // Grün an Port 10

void setup()
{
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
}

void loop()
{
  bool zeit_abgelaufen = timer(500);

  if (zeit_abgelaufen && !AN)
  {
    digitalWrite(LEDred, HIGH);
    digitalWrite(LEDgreen, LOW);
    AN = true;
  }
  else if (zeit_abgelaufen && AN)
  {
    digitalWrite(LEDred, LOW);
    digitalWrite(LEDgreen, HIGH);
    AN = false;
  }
}