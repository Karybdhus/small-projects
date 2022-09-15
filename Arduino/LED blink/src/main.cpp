#include <time.h>
#include <Arduino.h>

unsigned long timeout_start_time = 0;
bool LED;
bool timer(unsigned long zeit);
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  bool zeit_abgelaufen = timer(1000);

  if (zeit_abgelaufen && !LED)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    LED = true;
  }
  else if (zeit_abgelaufen && LED)
  {
    digitalWrite(LED_BUILTIN, LOW);
    LED = false;
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