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
byte rowPins[ROWS] = {10, 9, 8 ,7};     
byte colPins[COLS] = {A5, A4, A3, A2};     
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 
void setup() { 
lcd.begin(16, 2); 
lcd.setCursor(0, 0); 
lcd.print("Key Pressed:"); 
} 
void loop() { 
char key = keypad.getKey(); 
if (key) {  
lcd.setCursor(0, 1); 
lcd.print("                
");  
lcd.setCursor(0, 1); 
lcd.print(key); 
} 
} 
