/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 More info at: http://goo.gl/kJ8Gl
 */

#define TRIG_PIN 8
#define ECHO_PIN 9

void setup() {
  Serial.begin (115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  int duration, distance;
  
  //reset
  digitalWrite(TRIG_PIN, HIGH);
  delay(1);
  digitalWrite(TRIG_PIN, LOW);
  
  //calculate distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  
  //output
  if (distance >= 200 || distance <= 10){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(10);
}
