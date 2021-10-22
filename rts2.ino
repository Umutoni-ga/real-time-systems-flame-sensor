
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, flamepin=7 ;
int flame= LOW;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(flamepin, INPUT);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
void loop() {
  // read the sensor on analog A0:
  flame= digitalRead(flamepin);
  
  if (flame == HIGH){
    lcd.setCursor(0,0);
    lcd.print("**A fire has ");
    lcd.setCursor(0,1);
    lcd.print("been detected**");
    }
  else{
    lcd.setCursor(0,0);
    lcd.print("**No fire ");
    lcd.setCursor(0,1);
    lcd.print("detected**");
    }
  
  delay(10);  // delay between reads
  lcd.clear();
}
