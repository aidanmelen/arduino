#include <NewPing.h>

#define PING_PIN 40 // Arduino pin for both trig and echo

NewPing sonar(PING_PIN, PING_PIN );

void setup() {

Serial.begin(115200);

}

void loop() {

delay(20); // Wait 10ms between pings (about 20 pings/sec) with a 5ms delay.

unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).

Serial.print("Ping: ");
Serial.print(uS / US_ROUNDTRIP_CM); // convert time into distance

Serial.println("cm"); 
}
