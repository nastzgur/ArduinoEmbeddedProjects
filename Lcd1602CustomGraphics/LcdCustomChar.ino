#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte sym1[7] = {
  0b10001,
  0b10001,
  0b11001,
  0b10101,
  0b10011,
  0b10001,
  0b10001,
};

byte sym2[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b10001,
  0b10001,
  0b00000
};

byte sym3[8] = {
  0b01111,
  0b10000,
  0b10000,
  0b01110,
  0b00001,
  0b00001,
  0b11110,
  0b00000

};
byte sym4[8] = {
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00000
};
byte sym5[8] = {
 0b10001,
 0b10001,
 0b01010,
 0b01010,
 0b00100,
 0b00100,
 0b00100,
 0b00000
};
byte sym6[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b10001,
  0b10001,
  0b00000
};

void setup() {
 
  lcd.begin(16, 2);
  lcd.print("Zghurska A.V.");
  
  lcd.createChar(1, sym1);
  lcd.createChar(2, sym2);
  lcd.createChar(3, sym3);
  lcd.createChar(4, sym4);
  lcd.createChar(5, sym5);
  lcd.createChar(6, sym6);
};

void loop() {
  
  lcd.setCursor(0, 1);
  for(int i = 1; i <6; i++){
    lcd.write(i); 
  delay(250);  
  }

  for(int i = 1; i <6; i++){
  lcd.setCursor(6, 1);
  lcd.write(i); 
  delay(250);  
  }
  
}
