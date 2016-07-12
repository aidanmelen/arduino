/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int two = 2;
int thr = 3;
int fou = 4;
int fiv = 5;
int six = 6;
int sev = 7;
int eig = 8;
int nin = 9;
int ten = 10;
int ele = 11;
int twe = 12;
int thi = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(two, OUTPUT);
  pinMode(thr, OUTPUT);
  pinMode(fou, OUTPUT);
  pinMode(fiv, OUTPUT);
  pinMode(six, OUTPUT);
  pinMode(sev, OUTPUT);
  pinMode(eig, OUTPUT);
  pinMode(nin, OUTPUT);
  pinMode(ten, OUTPUT);
  pinMode(ele, OUTPUT);
  pinMode(twe, OUTPUT);
  pinMode(thi, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(two, HIGH);
  digitalWrite(thr, HIGH);
  digitalWrite(fou, HIGH);
  digitalWrite(fiv, HIGH);
  digitalWrite(six, HIGH);
  digitalWrite(sev, HIGH);
  digitalWrite(eig, HIGH);
  digitalWrite(nin, HIGH);
  digitalWrite(ten, HIGH);
  digitalWrite(ele, HIGH);
  digitalWrite(twe, HIGH);
  digitalWrite(thi, HIGH);
  delay(1000);
  digitalWrite(two, LOW);
  digitalWrite(thr, LOW);
  digitalWrite(fou, LOW);
  digitalWrite(fiv, LOW);
  digitalWrite(six, LOW);
  digitalWrite(sev, LOW);
  digitalWrite(eig, LOW);
  digitalWrite(nin, LOW);
  digitalWrite(ten, LOW);
  digitalWrite(ele, LOW);
  digitalWrite(twe, LOW);
  digitalWrite(thi, LOW);
  delay(1000);
}
