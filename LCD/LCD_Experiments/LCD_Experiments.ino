#include <LiquidCrystal.h>

const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 

LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Booting Up");
  Serial.begin(9600);
  lcd.clear();

}

int count=0;
void loop() {
  
  int x;
  x = analogRead (0);
  lcd.setCursor(0,0);  
  lcd.print(count);
  lcd.setCursor(10,1);  
  if (x < 100) {
    lcd.print ("Right ");
  }
  else if (x < 300) {
    lcd.print ("Up    ");
    count++;
  }
  else if (x < 500){
    lcd.print ("Down  ");
    count--;
  }
  else if (x < 700){
    lcd.print ("Left  ");
  }
  else if (x < 900){
    lcd.print ("Select  ");
  }
  delay(100);
  //lcd.clear();
  

}
