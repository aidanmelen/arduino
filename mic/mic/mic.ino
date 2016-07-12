int micPin = 12;
int ledPin = 13;
boolean first = true;

int micValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {
  if (digitalRead(micPin) == LOW) {
    if (first)
    {
      Serial.println("---------------");
      Serial.println("SOUND DETECTED");
      Serial.println("---------------");
      Serial.println();
      first = false;
    }
    digitalWrite(ledPin, HIGH); //turn ON
    delay(200);
  } else {
    digitalWrite(ledPin, LOW); // turn OFF
    first = true;
  }


}
