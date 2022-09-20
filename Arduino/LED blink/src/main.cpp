#include <Arduino.h>
#include "timer.h"

bool ANred, AUSgreen;
int LEDred = 6;    // Rot an Port 6
int LEDgreen = 10; // Grün an Port 10

void setup()
{
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
}

void loop()
{
  bool zeit_abgelaufen = timer(1000);

  if (zeit_abgelaufen && !ANred)
  {
    digitalWrite(LEDred, HIGH);
    ANred = true;
  }
  else if (zeit_abgelaufen && ANred)
  {
    digitalWrite(LEDred, LOW);
    ANred = false;
  }

  if (zeit_abgelaufen && !AUSgreen)
  {
    digitalWrite(LEDgreen, LOW);
    AUSgreen = true;
  }
  else if (zeit_abgelaufen && AUSgreen)
  {
    digitalWrite(LEDgreen, HIGH);
    AUSgreen = false;
  }
}