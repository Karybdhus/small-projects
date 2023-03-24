#include <Arduino.h>
#include "7seg.h"
#include "timer.h"
#include "rcData.h"

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
  rcWithEndMarker();
  sendeInhalt = transmitNumber();

  Serial.print("sendeInhalt: ");
  Serial.println(sendeInhalt);
  switch (sendeInhalt)
  {
    case 1:
      Segment->failure1();
      break;
    case 2:
      Segment->failure2();
      break;
    case 3:
      Segment->failure3();
      break;
    case 4:
      Segment->failure4();
      break;
    case 5:
      Segment->failure5();
      break;
    case 6:
      Segment->failure6();
      break;
    case 7:
      Segment->failure7();
      break;
    case 8:
      Segment->failure8();
      break;
    case 9:
      Segment->failure9();
      break;
    case 0:
      Segment->failure0();
      break;
    default:
      Segment->clear();
      break;
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