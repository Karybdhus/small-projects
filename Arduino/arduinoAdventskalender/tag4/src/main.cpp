#include <Arduino.h>

struct LED // Stuct zur Anlage von LEDs und deren Delay
{
  unsigned int pin;
  unsigned int delayMs;
};

LED LEDred = {3, 2000};    // Rot auf Pin 3, 2000 ms delay
LED LEDyellow = {4, 1000}; // Geld auf Pin 4, 1000 ms delay
LED LEDgreen = {5, 4000};  // Grün auf Pin 5, 4000 ms delay

const String WARTE_STRING = "warte ";
const String MS_STRING = "ms";

void setup()
{
  Serial.begin(9600);

  pinMode(LEDred.pin, OUTPUT); // LEDs als Ausgänge definieren
  pinMode(LEDyellow.pin, OUTPUT);
  pinMode(LEDgreen.pin, OUTPUT);

  Serial.println(F("Ampel initialisiert")); // Serielle Ausgabe mit Zeilenumbruch
}

void loop()
{
  Serial.println(F("Gruenphase"));
  digitalWrite(LEDgreen.pin, HIGH);

  Serial.print(WARTE_STRING);
  Serial.print(LEDgreen.delayMs);
  Serial.println(MS_STRING);

  delay(LEDgreen.delayMs);

  Serial.println(F("Gelbphase"));
  digitalWrite(LEDgreen.pin, LOW);
  digitalWrite(LEDyellow.pin, HIGH);

  Serial.print(WARTE_STRING);
  Serial.print(LEDyellow.delayMs);
  Serial.println(MS_STRING);

  delay(LEDyellow.delayMs);

  Serial.println(F("Rotphase"));
  digitalWrite(LEDyellow.pin, LOW);
  digitalWrite(LEDred.pin, HIGH);

  Serial.print(WARTE_STRING);
  Serial.print(LEDred.delayMs);
  Serial.println(MS_STRING);

  delay(LEDred.delayMs);

  Serial.println(F("Rot/Gelbphase"));
  digitalWrite(LEDyellow.pin, HIGH);

  Serial.print(WARTE_STRING);
  Serial.print(LEDyellow.delayMs);
  Serial.println(MS_STRING);

  delay(LEDyellow.delayMs);

  Serial.println(F("Alle aus"));
  digitalWrite(LEDred.pin, LOW);
  digitalWrite(LEDyellow.pin, LOW);
}