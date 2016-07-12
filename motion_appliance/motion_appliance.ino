/*
 * This simple project uses a PIR sensor and a relay in order to turn on a house appliance with motion.
 *
 * The PIR Sensor is an easy to use digital infrared motion sensor module.
 *
 * The sensor's output pin goes to HIGH if motion is present; else it will go LOW.
 *
 * @author: Aidan Melen
 * @date: 05/14/2015
 */

const int ledPin = 13;
const int micPin = 12;
const int pirPin = 11;//the digital pin connected to the PIR sensor's output
const int relay1Pin = 7;

const int setupTime = 0;
const int calibrationTime = 10; // the time we give the sensor to calibrate (10-60 secs according to the datasheet)
boolean first = true;

/*
  led function
  **/
void led()
{
  digitalWrite(ledPin, HIGH); //turn ON
  delay(500); // delay 0.5 seconds
  digitalWrite(ledPin, LOW); // turn OFF
  delay(500); 
}


/*
  Setup function
  **/
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relay1Pin, OUTPUT);

  digitalWrite(pirPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(relay1Pin, LOW);

  Serial.println("ALLOW HUMAN TO GET OUT OF THE WAY OF SENSOR");
  for (int i = setupTime; i > 0; i--) {
    Serial.println(i);
    led();
  }

  // give the sensor some time to calibrate
  Serial.println("CALIBRATING PIR SENSOR:");
  for (int i = calibrationTime; i > 0; i--) {
    Serial.println(i);
    led();
  }
  Serial.println();
  Serial.println("SENSOR IS ACTIVE");
  Serial.println();
}


/*
 Loop function
 **/
void loop() {

  if (digitalRead(pirPin) == HIGH) { // object detected
    if (first)
    {
      Serial.println("---------------");
      Serial.println("MOTION DETECTED");
      Serial.println("---------------");
      Serial.println();
      first = false;
    }
    digitalWrite(relay1Pin, HIGH);
  }

 if (digitalRead(pirPin) == LOW) {
    digitalWrite(relay1Pin, LOW);
    first = true;
  }

}
