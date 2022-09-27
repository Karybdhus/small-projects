#include <Arduino.h>

unsigned long timeout_start_time = 0;
bool timer(unsigned long zeit);
bool AN;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  bool zeit_abgelaufen = timer(500);

  if (zeit_abgelaufen && !AN)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    AN = true;
  }
  else if (zeit_abgelaufen && AN)
  {
    digitalWrite(LED_BUILTIN, LOW);
    AN = false;
  }
}

bool timer(unsigned long zeit)
{
  unsigned long currentMillis = millis();

  if (timeout_start_time == 0)
  {
    timeout_start_time = currentMillis;
  }

  if (currentMillis > (timeout_start_time + zeit))
  {
    timeout_start_time = 0;
    return true;
  }
  return false;
}