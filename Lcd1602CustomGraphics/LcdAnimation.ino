#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); 
  lcd.write(0xE2); 
  lcd.write(0xE0);
  lcd.write(0x6B);
  lcd.setCursor(0, 1);
  lcd.write(0xF6); 
  lcd.write(0xF7);
}
void loop(){
}
