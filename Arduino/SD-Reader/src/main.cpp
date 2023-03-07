#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

File file;

void setup() {

  Serial.begin(9600);
  Serial.println("Initialising SD-Card...");
  
  if (!SD.begin(11)) {
    Serial.println("Initialise SD failed!");
    return; 
  }

  Serial.println("Intialise SD complete!");
  Serial.println("Creating File...");
  file = SD.open("testlog.txt", FILE_WRITE);
  file.close();
  Serial.println("File created!");

}

void loop() {
  // put your main code here, to run repeatedly:
}