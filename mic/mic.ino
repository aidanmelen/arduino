
const int ledPin = 13;
const int micPin = 12;

boolean first = true;

void setup ()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(micPin, INPUT);
  
  digitalWrite(ledPin, LOW);
}

void loop ()
{
  if (digitalRead(micPin) == LOW) {
    if (first) {
      Serial.println("---------------");
      Serial.println("SOUND DETECTED");
      Serial.println("---------------");
      Serial.println();
      first = false;
    }
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, LOW);
    first = true;
  }
}  

