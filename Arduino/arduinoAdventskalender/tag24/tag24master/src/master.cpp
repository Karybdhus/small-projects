#include <Arduino.h>
#include <Wire.h>

const unsigned int BUTTON_PIN = 3;
const unsigned int POTI_PIN = A0;

const int CLIEN_ID = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(POTI_PIN, INPUT);

  Wire.begin();
}

void loop()
{
  char cstr[4];

  if (digitalRead(BUTTON_PIN) == LOW)
  {
    Serial.println("BUTTON PRESSED");
    Wire.beginTransmission(CLIEN_ID);
    Wire.write('#');
    Wire.endTransmission();

    while (digitalRead(BUTTON_PIN) == LOW)
    {
    }
  }

  sprintf(cstr, "%03d", analogRead(POTI_PIN) / 4);

  Serial.print("Helligkeit: ");
  Serial.println(cstr);
  Wire.beginTransmission(CLIEN_ID);
  Wire.write(cstr);
  Wire.endTransmission();

  delay(100);
}