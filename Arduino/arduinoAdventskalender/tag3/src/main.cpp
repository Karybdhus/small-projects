#include <Arduino.h>

const unsigned int LEDred = 6;
const unsigned int redDelay = 500;

struct LED
{
  unsigned int pin;
  unsigned int delayMs;
};

LED LEDgreen = {3, 2000};

void setup()
{
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen.pin, OUTPUT);
}

void loop()
{
  digitalWrite(LEDgreen.pin, HIGH);
  delay(LEDgreen.delayMs);
  digitalWrite(LEDgreen.pin, LOW);

  digitalWrite(LEDred, HIGH);
  delay(redDelay);
  digitalWrite(LEDred, LOW);
}
