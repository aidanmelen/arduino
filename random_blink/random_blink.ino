void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);1
  pinMode(7, OUTPUT);
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A1, OUTPUT);
  
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
}

void set_color() {

    analogWrite(2, random(0, 255));
    analogWrite(3, random(0, 255));
    analogWrite(4, random(0, 255));

    analogWrite(5, random(0, 255));
    analogWrite(6, random(0, 255));
    analogWrite(7, random(0, 255));

    analogWrite(8, random(0, 255));
    analogWrite(9, random(0, 255));
    analogWrite(10, random(0, 255));

    analogWrite(11, random(0, 255));
    analogWrite(12, random(0, 255));
    analogWrite(A1, random(0, 255));

    analogWrite(A1, random(0, 255));
    analogWrite(A2, random(0, 255));
    analogWrite(A3, random(0, 255));

    analogWrite(A5, random(0, 255));
    analogWrite(A6, random(0, 255));
    analogWrite(A7, random(0, 255));
}

void loop() {
  set_color();
  
  int r_delay = random(200, 900);
  delay(r_delay);
}
