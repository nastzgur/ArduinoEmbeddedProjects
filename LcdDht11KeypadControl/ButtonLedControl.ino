#include <LiquidCrystal.h> 
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
 
const int Pin = 8; 
const int led = 9; 
 
bool buttonState = false; 
 
void setup() { 
 
  pinMode(Pin, INPUT); 
 
  pinMode(led, OUTPUT); 
 
  lcd.begin(16, 2); 
 
  lcd.setCursor(0, 0); 
  lcd.print("Button State:"); 
} 
 
void loop() { 
 
  buttonState = digitalRead(Pin); 
 
  if (buttonState) { 
    digitalWrite(led, HIGH); 
  } else { 
    digitalWrite(led, LOW); 
} 
lcd.setCursor(0, 1); 
if (buttonState) { 
lcd.print("Pressed      
");  
} else { 
lcd.print("Not Pressed  "); 
} 
delay(100);  
}
