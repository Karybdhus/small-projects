#include <Arduino.h>

struct LED
{
  unsigned int pin;
};

LED red = {3};
LED green = {4};
LED yellow = {5};
LED bigRed = {6};

const unsigned int POTI_PIN = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(POTI_PIN, INPUT);
  pinMode(red.pin, OUTPUT);
  pinMode(yellow.pin, OUTPUT);
  pinMode(green.pin, OUTPUT);
  pinMode(bigRed.pin, OUTPUT);
}

void loop()
{
  int potiValue = analogRead(POTI_PIN);
  Serial.print("gemessener Poti-Wert: ");
  Serial.println(potiValue);

  if (potiValue < 10) // Werte kleiner als 10 würde zu Flackern führen, daher Korrektur
  {
    potiValue = 10;
  }

  if (potiValue > 1013) // Werte größer als 1013 s.o.
  {
    potiValue = 1013;
  }

  if (potiValue < 512)
  {
    Serial.println("Vorwärts");

    int wartezeit = potiValue * 4;
    Serial.print("Wartezeit: ");
    Serial.println(wartezeit);

    digitalWrite(red.pin, HIGH);
    delay(wartezeit);
    digitalWrite(red.pin, LOW);

    digitalWrite(green.pin, HIGH);
    delay(wartezeit);
    digitalWrite(green.pin, LOW);

    digitalWrite(yellow.pin, HIGH);
    delay(wartezeit);
    digitalWrite(yellow.pin, LOW);

    digitalWrite(bigRed.pin, HIGH);
    delay(wartezeit);
    digitalWrite(bigRed.pin, LOW);
  } else {
    Serial.println("Rückwärts");

    int wartezeit = (512 - (potiValue - 511)) * 4;

    Serial.print("Wartezeit: ");
    Serial.println(wartezeit);

    digitalWrite(bigRed.pin, HIGH);
    delay(wartezeit);
    digitalWrite(bigRed.pin, LOW);

    digitalWrite(yellow.pin, HIGH);
    delay(wartezeit);
    digitalWrite(yellow.pin, LOW);

    digitalWrite(green.pin, HIGH);
    delay(wartezeit);
    digitalWrite(green.pin, LOW);

    digitalWrite(red.pin, HIGH);
    delay(wartezeit);
    digitalWrite(red.pin, LOW);
  }
}