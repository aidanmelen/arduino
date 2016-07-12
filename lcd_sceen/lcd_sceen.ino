//Displaying the text “Hello World!” and “Fibidi.com” .

//    http://www.fibidi.com/?p=734

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 4);
}

void flashScreen() {
  delay(1000);
  lcd.setCursor(6, 1);
  lcd.print("ARDUINO");

  lcd.setCursor(8, 2);
  lcd.print("BREATHALYZER");
}

void calibrationScreen() {
  lcd.setCursor(1, 0);
  lcd.print("CALIBRATING SENSOR");
  for (int i = 15; i > 0; i--) {
    delay(500);
    if (i >= 10) {
      lcd.setCursor(13, 2);
      lcd.print(i);
    } else {
      lcd.setCursor(13, 2);
      lcd.print("   ");
      lcd.setCursor(14, 2);
      lcd.print(i);
    }
  }
}

void buttonScreen() {
  lcd.setCursor(4, 0);
  lcd.print("SENSOR READY");
  lcd.setCursor(6, 2);
  lcd.print("PRESS THE BUTTON");
  lcd.setCursor(8, 3);
  lcd.print("TO CONTINUE");
}

void blowScreen() {
  lcd.setCursor(2, 1);
  lcd.print("BLOW INTO SENSOR");
}

void bacScreen() {
  double bac = 0.01;
  lcd.setCursor(1, 0);
  //lcd.print(String("BAC RESULT: ") + bac);
  lcd.print("NO ALCOHOL PRESENT");
  lcd.setCursor(6, 2);
  lcd.print("PRESS THE BUTTON");
  lcd.setCursor(8, 3);
  lcd.print("TO CONTINUE");
}

void loop() {
  /*
  flashScreen();
  delay(2000);
  lcd.clear();

  calibrationScreen();
  lcd.clear();
 
  buttonScreen();
  delay(2000);
  lcd.clear();
  
  blowScreen();
  delay(2000);
  lcd.clear();
  */
  
  bacScreen();
  delay(2000);
  lcd.clear();
}

