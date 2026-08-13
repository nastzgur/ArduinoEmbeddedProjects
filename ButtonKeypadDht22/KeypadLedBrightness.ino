#include <Keypad.h>  

const byte ROWS = 4; 
const byte COLS = 3;  
char keys[ROWS][COLS] = {  
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {12, 11, 10, 9};  
byte colPins[COLS] = {8, 7, 6};      
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int red = 3;

void setup() {
  pinMode(red, OUTPUT); 
}

void loop() {
  char key = keypad.getKey();  
  if (key) {  
    switch (key) {
      case '0':  
        analogWrite(red, 255);
        break;
      case '1':  
        analogWrite(red, 26);  
        break;
      case '2':  
        analogWrite(red, 51);  
        break;
      case '3':  
        analogWrite(red, 77);  
        break;
      case '4':  
        analogWrite(red, 102);  
        break;
      case '5': 
        analogWrite(red, 128);  
        break;
      case '6':  
        analogWrite(red, 153);  
        break;
      case '7':  
        analogWrite(red, 179);  
        break;
      case '8':  
        analogWrite(red, 204);  
        break;
      case '9':  
        analogWrite(red, 230);  
        break;
      case '*':  
        analogWrite(red, 255);
        break;
      case '#':  
        analogWrite(red, 0);
        break;
    }
  }
}

