#include <Arduino.h>
#include "7seg.h"
#include "timer.h"

/*
    A
   ---
 F|   |B
  | G |
   ---
 E|   |C
  |   |
   --- o dp
    D

*/

void init_serial();

int sendeInhalt = 0;

void setup()
{
  for (int i = 6; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }

  init_serial();
}

void loop()
{
  if (Serial.available() > 0)
  {
    sendeInhalt = Serial.read();

    switch (sendeInhalt)
    {
    case '1':
      display1();
      break;
    case '2':
      display2();
      break;
    case '3':
      display3();
      break;
    case '4':
      display4();
      break;
    case '5':
      display5();
      break;
    case '6':
      display6();
      break;
    case '7':
      display7();
      break;
    case '8':
      display8();
      break;
    case '9':
      display9();
      break;
    case '0':
      display0();
      break;
    default:
      break;
    }
  }
}

void init_serial()
{
  Serial.println("Initialize Serial Monitor...");
  Serial.begin(9600);

  while (!Serial)
  {
    if (timer(5000))
    {
      Serial.println("Serial Monitor failed");
      break;
    }
  }
}
