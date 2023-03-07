#include "timer.h"

unsigned long timeout_start_time = 0;

bool timer(unsigned long time)
{
  unsigned long currentMillis = millis();

  if (timeout_start_time == 0)
  {
    timeout_start_time = currentMillis;
  }

  if (currentMillis > (timeout_start_time + time))
  {
    timeout_start_time = 0;
    return true;
  }
  return false;
}
