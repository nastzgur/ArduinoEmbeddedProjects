include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); 
const int Pin = 2; 
const int red = 3; 
const int yel = 4; 
const int gre = 6; 
int ledState = 0;  
bool lastButtonState = false; 
 
void setup() { 
  pinMode(Pin, INPUT); 
 
  pinMode(red, OUTPUT); 
  pinMode(yel, OUTPUT); 
  pinMode(gre, OUTPUT); 
 
  lcd.begin(16, 2); 
 
  lcd.setCursor(0, 0); 
  lcd.print("LED Color:"); 
  lcd.setCursor(0, 1); 
  lcd.print("NONE"); 
} 
 
void loop() { 
 
  bool currentButtonState = digitalRead(Pin); 
 
  if (currentButtonState && !lastButtonState) { 
 
    ledState = (ledState + 1) % 4;  
 
    digitalWrite(red, LOW); 
    digitalWrite(yel, LOW); 
    digitalWrite(gre, LOW); 
 
    lcd.setCursor(0, 1); 
    switch (ledState) { 
      case 1: 
        digitalWrite(red, HIGH); 
        lcd.print("RED       "); 
        break; 
      case 2: 
        digitalWrite(yel, HIGH); 
        lcd.print("YELLOW    "); 
        break; 
      case 3: 
        digitalWrite(gre, HIGH); 
        lcd.print("GREEN    "); 
        break; 
      default: 
        lcd.print("NONE     "); 
        break; 
    } 
  } 
 
lastButtonState = currentButtonState; 
delay(50);  
} 
