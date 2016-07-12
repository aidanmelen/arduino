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

const int redPin = 7;
const int grePin = 5;
const int bluPin = 3;

const int pirPin = 12; //the digital pin connected to the PIR sensor's output
const int relayPin = 13;

const int setupTime = 10;
const int calibrationTime = 15; // the time we give the sensor to calibrate (10-60 secs according to the datasheet)
const int powerTime = 25; // minutes
const int resetTime = 300; // seconds

boolean first = true;
boolean reset = true;

/*
  red led function
  **/
void redLed()
{
  digitalWrite(redPin, 255); //turn ON
  digitalWrite(grePin, 0); //turn ON
  digitalWrite(bluPin, 0); //turn ON
  delay(500); // delay 0.5 seconds
  digitalWrite(redPin, LOW); // turn OFF
  digitalWrite(grePin, LOW); // turn OFF
  digitalWrite(bluPin, LOW); // turn OFF
  delay(500);
}

/*
  green led  ON function. Three blinks total
  **/
void greenLed()
{
  digitalWrite(redPin, 0); //turn ON
  digitalWrite(grePin, 255); //turn ON
  digitalWrite(bluPin, 0); //turn ON
  delay(100);
  digitalWrite(redPin, LOW); // turn OFF
  digitalWrite(grePin, LOW); // turn OFF
  digitalWrite(bluPin, LOW); // turn OFF
  delay(300);
  digitalWrite(redPin, 0);
  digitalWrite(grePin, 255);
  digitalWrite(bluPin, 0);
  delay(100);
  digitalWrite(redPin, LOW);
  digitalWrite(grePin, LOW);
  digitalWrite(bluPin, LOW);
  delay(300);
  digitalWrite(redPin, 0);
  digitalWrite(grePin, 255);
  digitalWrite(bluPin, 0);
  delay(100);
  digitalWrite(redPin, LOW);
  digitalWrite(grePin, LOW);
  digitalWrite(bluPin, LOW);
}

/*
  blue led function
  **/
void blueLed()
{
  digitalWrite(redPin, 0); //turn ON
  digitalWrite(grePin, 0); //turn ON
  digitalWrite(bluPin, 255); //turn ON
  delay(500); // delay 0.5 seconds
  digitalWrite(redPin, LOW); // turn OFF
  digitalWrite(grePin, LOW); // turn OFF
  digitalWrite(bluPin, LOW); // turn OFF
  delay(500);
}

/*
  yellow led function
  **/
void yellowLed()
{
  digitalWrite(redPin, 200); //turn ON
  digitalWrite(grePin, 255); //turn ON
  digitalWrite(bluPin, 0); //turn ON
  delay(500); // delay 0.5 seconds
  digitalWrite(redPin, LOW); // turn OFF
  digitalWrite(grePin, LOW); // turn OFF
  digitalWrite(bluPin, LOW); // turn OFF
  delay(500);
}


/*
  Setup function
  **/
void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(grePin, OUTPUT);
  pinMode(bluPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(pirPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(grePin, LOW);
  digitalWrite(bluPin, LOW);
  digitalWrite(relayPin, LOW);

  Serial.println("ALLOW HUMAN TO GET OUT OF THE WAY OF SENSOR");
  for (int i = setupTime; i > 0; i--) {
    Serial.println(i);
    blueLed();
  }

  // give the sensor some time to calibrate
  Serial.println();
  Serial.println("CALIBRATING PIR SENSOR:");
  for (int i = calibrationTime; i >= 0; i--) {
    Serial.println(i);
    if (i == 0) {
      greenLed();
    } else {
      redLed();
    }
  }
  Serial.println();
  Serial.println("SENSOR IS ACTIVE");
  Serial.println();
}


void powerCycle() {
  digitalWrite(relayPin, HIGH);
  greenLed();
  Serial.print("Running Power Cycle for "); Serial.print(powerTime); Serial.println(" Minutes");
  for (int i = 1; i <= powerTime; i++) {
    delay(60000);
    Serial.print("Minute: ");
    Serial.println(i);
  }
}




/*
 Loop function
 **/
void loop() {

  first = true;

  if (digitalRead(pirPin) == HIGH) { // inital object was detected
    if (first) {
      Serial.println("---------------"); Serial.println("MOTION DETECTED"); Serial.println("---------------"); Serial.println();
      first = false;
    }

    powerCycle(); // run for powerTime

    for (int i = 1; i <= resetTime; i++) { // Check for reset motion during the last five minutes of activation time

      if (digitalRead(pirPin) == HIGH) {
        Serial.println("---------------"); Serial.println("REACTIVATE TIMER"); Serial.println("---------------"); Serial.println();
        powerCycle(); // run for powerTime
        i = 0;

      } else { // PIR is Low
        yellowLed();
        Serial.println(i);
      } 
    } // end loop()
  } // end PIR if
  
if (digitalRead(pirPin) == LOW) { // no object was detected
  digitalWrite(relayPin, LOW);
  first = true;
}
}
