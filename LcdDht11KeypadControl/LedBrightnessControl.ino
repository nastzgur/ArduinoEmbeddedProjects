#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int Pin = 8; 
const int red = 9; 
 
// Змінні для управління яскравістю 
int brightness = 0; // Поточна яскравість у відсотках 
int step = 5;       // Поточний крок зміни яскравості 
bool lastButtonState = false; 
 
void setup() { 
 
  pinMode(Pin, INPUT); 
 
  pinMode(red, OUTPUT); 
 
  lcd.begin(16, 2); 
 
  lcd.setCursor(0, 0); 
  lcd.print("Brightness:"); 
  lcd.setCursor(0, 1); 
  lcd.print("0%            "); 
} 
 
void loop() { 
  bool currentButtonState = digitalRead(Pin); 
 
  if (currentButtonState && !lastButtonState) { 
    brightness += step; 
 
    if (brightness > 100) { 
      brightness = 100; 
      step = -10; 
    } else if (brightness < 0) { 
      brightness = 0; 
      step = 5; 
    } 
 
    analogWrite(red, map(brightness, 0, 100, 0, 255)); 
 
    lcd.setCursor(0, 1); 
    lcd.print(brightness); 
    lcd.print("%            "); 
  } 
 
  lastButtonState = currentButtonState; 
 
  delay(50);  
} 
