/* Blink without Delay

 Turns on and off a light emitting diode(LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.


 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen

 This example code is in the public domain.


 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants won't change. Used here to
// set pin numbers:
const int ledPin =  13;      // the number of the LED pin
const int micPin = 12;

// Variables will change:
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 250;           // interval set for ideling inbetween claps

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(micPin, INPUT);
}

void loop()
{
  unsigned long current = millis();
  unsigned long interval = 250;
  
  if (current - start > 250 && digitalRead(micPin) == LOW) {
    start = current;
    Serial.println("---------------");
    Serial.println("FIRST CLAP");
    Serial.println("---------------");
    Serial.println();
    currentMillis = millis();
    delay(500);

    if (currentMillis - previousMillis > 500) {
      Serial.println("---------------");
      Serial.println("IDLE");
      Serial.println("---------------");
      Serial.println();
      currentMillis = millis();

      if (currentMillis - previousMillis > 750 && digitalRead(micPin) == LOW) {
        Serial.println("---------------");
        Serial.println("SECOND CLAP");
        Serial.println("---------------");
        Serial.println();
        digitalWrite(ledPin, HIGH);
      }
    }
  }
}
