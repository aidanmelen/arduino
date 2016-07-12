/*
 * The start of an Embedded Systems group project.
 *
 * @author: Aidan Melen, Conrad Lieness, Grady Mellin
 * @date: 05/14/2015
 *
 * The PIR Sensor is an easy to use digital infrared motion sensor module.
 *
 * The sensor's output pin goes to HIGH if motion is present; else it will go LOW.
 */

boolean first = true;

int ledPin = 13;
int micPin = 12;
int pirPin = 11;    // the digital pin connected to the PIR sensor's output
int buzzerPin = 10;

int calibrationTime = 10; // the time we give the sensor to calibrate (10-60 secs according to the datasheet)


/*
  Setup function
  **/
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(micPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(pirPin, LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(micPin, LOW);
  digitalWrite(buzzerPin, LOW);


  //give the sensor some time to calibrate
  Serial.println("CALIBRATING SENSOR");
  for (int i = calibrationTime; i > 0; i--) {
    Serial.println(i);
    digitalWrite(ledPin, HIGH); // led ON
    delay(500);
    digitalWrite(ledPin, LOW); // led OFF
    delay(500); 
  }
  Serial.println("SENSOR ACTIVE");
}


/*
 Loop function
 **/
void loop() {

  if (digitalRead(pirPin) == HIGH) { // object detected
    if (first) {
      Serial.println("---------------");
      Serial.println("MOTION DETECTED");
      Serial.println("---------------");
      Serial.println();
      first = false;
    }
    digitalWrite(ledPin, HIGH);
    analogWrite(buzzerPin, 1023);
    delay(500);

  } else { // no objects detected
    digitalWrite(ledPin, LOW);
    analogWrite(buzzerPin, LOW);
    delay(500);
    first = true;
  }

}
