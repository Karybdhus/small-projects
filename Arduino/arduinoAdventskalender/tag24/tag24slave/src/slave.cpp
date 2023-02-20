#include <Arduino.h>
#include <Wire.h>

const unsigned int POTI_PIN = A0;
const unsigned int LED_PIN = 3;

byte state = LOW;
char brightness[3] = {"255"};

const int CLIENT_ID = 8;

void receiveEvent(int howMany);

void setup()
{
  Serial.begin(9600);

  Wire.begin(CLIENT_ID);
  Wire.onReceive(receiveEvent);
}

void loop()
{
  if (state == HIGH)
  {
    analogWrite(LED_PIN, atoi(brightness));
  }
  else
  {
    analogWrite(LED_PIN, 0);
  }

  Serial.println("");
  Serial.print("Helligkeit: ");
  Serial.print(atoi(brightness));
  Serial.print(" / Status: ");
  Serial.println(state);

  delay(50);
}

void receiveEvent(int howMany)
{
  int charCount = 0;

  while (Wire.available())
  {
    char rxChar = Wire.read();

    if (rxChar == '#')
    {
      state = !state;
    }
    else
    {
      Serial.println(rxChar);
      brightness[charCount] = rxChar;
      charCount++;
    }
  }
}