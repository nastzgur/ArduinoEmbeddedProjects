#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int Pin = 8; 
const int led = 9; 
 
bool ledState = false; 
bool lastButtonState = false; 
 
void setup() { 
  pinMode(Pin, INPUT); 
 
  pinMode(led, OUTPUT); 
 
  lcd.begin(16, 2); 
 
  lcd.setCursor(0, 0); 
  lcd.print("LED State:"); 
  lcd.setCursor(0, 1); 
  lcd.print("OFF"); 
} 
 
void loop() { 
 
  bool currentButtonState = digitalRead(Pin); 
 
  if (currentButtonState && !lastButtonState) { 
    ledState = !ledState; 
    digitalWrite(led, ledState ? HIGH : LOW); 
 
    lcd.setCursor(0, 1); 
    if (ledState) { 
      lcd.print("ON            "); 
    } else { 
      lcd.print("OFF           "); 
    } 
  } 
 
  lastButtonState = currentButtonState; 
 
  delay(50);  
}
