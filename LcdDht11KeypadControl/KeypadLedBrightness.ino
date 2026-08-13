#include <LiquidCrystal.h> 
#include <Keypad.h> 
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
 
const byte ROWS = 4;  
const byte COLS = 4; 
 
char keys[ROWS][COLS] = { 
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'}, 
  {'*', '0', '#', 'D'} 
}; 
 
byte rowPins[ROWS] = {9, 8, 7, 6};     
byte colPins[COLS] = {A2, A3, A4, A5};     
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
 
const int red = 10;  
 
void setup() { 
   
  lcd.begin(16, 2); 
 
  pinMode(red, OUTPUT); 
 
  lcd.setCursor(0, 0); 
  lcd.print("Key Pressed:"); 
} 
 
void loop() { 
  char key = keypad.getKey(); 
 
  if (key) {  
    int brightness = 0;  
 
    lcd.setCursor(0, 1); 
    lcd.print("                "); 
    lcd.setCursor(0, 1); 
    lcd.print(key); 
 
    
    if (key >= '1' && key <= '9') { 
      brightness = (key - '0') * 10;  
    } else if (key == '*') { 
      brightness = 100;  
    } else if (key == '#') { 
      brightness = 0;  
    } else if (key == '0') { 
      brightness = 100;  
    } 
 
    analogWrite(red, map(brightness, 0, 100, 0, 255)); 
 
    lcd.setCursor(8, 1); 
    lcd.print(brightness); 
    lcd.print("%   "); 
  } 
} 
