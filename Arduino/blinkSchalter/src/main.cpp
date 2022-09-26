#include <OneButton.h>
#include <Arduino.h>

void clickedIt();
void doubleClickedIt();
const int buttonPin = 6;
const int ledPin = 2;
 
OneButton button(buttonPin, false);
 
int ledState = LOW;
 
void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT);
 
 button.attachClick(clickedIt);
 button.attachDoubleClick(doubleClickedIt);
 
}
 
void loop() {
 button.tick();
 
 delay(10);
}
 
 
void clickedIt() {
 ledState = !ledState;
 digitalWrite(ledPin, ledState);
}
 
void doubleClickedIt() {
 for (int i=0; i<5; i++) {
 digitalWrite(ledPin, HIGH);
 delay(60);
 digitalWrite(ledPin, LOW);
 delay(60);
 }
 
 digitalWrite(ledPin, ledState);
}