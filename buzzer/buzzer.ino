/*
Example 13.0
Drive a piezoelectric buzzer with Arduino
http://tronixstuff.wordpress.com/tutorials > Chapter 13
*/
void setup()
{
     pinMode(11, OUTPUT);   // sets the pin as output
}
void loop()
{
     analogWrite(11,128);
     delay(500);
     digitalWrite(11, LOW);
     delay(500);
}
