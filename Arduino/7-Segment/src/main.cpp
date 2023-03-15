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

vgf::CSegment *Segment = new vgf::CSegment();
void init_serial();

int sendeInhalt = 0;

void setup()
{
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
      Segment->display1();
      break;
    case '2':
      Segment->display2();
      break;
    case '3':
      Segment->display3();
      break;
    case '4':
      Segment->display4();
      break;
    case '5':
      Segment->display5();
      break;
    case '6':
      Segment->display6();
      break;
    case '7':
      Segment->display7();
      break;
    case '8':
      Segment->display8();
      break;
    case '9':
      Segment->display9();
      break;
    case '0':
      Segment->display0();
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