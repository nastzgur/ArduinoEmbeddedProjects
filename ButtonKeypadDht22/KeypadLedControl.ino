#include <Keypad.h>  

const byte ROWS = 4;  
const byte COLS = 3;  
char keys[ROWS][COLS] = {  
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};   
byte colPins[COLS] = {6, 7, 8};       
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int red = 9;
const int yel = 10;
const int gre = 11;

bool blinkState = false;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
}

void loop() {
  char key = keypad.getKey();  

  if (key) {  
    switch (key) {
      case '1':  
        digitalWrite(red, HIGH);
        break;
      case '4':  
        digitalWrite(red, LOW);
        break;
      case '2':  
        digitalWrite(yel, HIGH);
        break;
      case '5':  
        digitalWrite(yel, LOW);
        break;
      case '3':  
        digitalWrite(gre, HIGH);
        break;
      case '6':  
        digitalWrite(gre, LOW);
        break;
      case '7':  
        digitalWrite(red, HIGH);
        digitalWrite(yel, HIGH);
        digitalWrite(gre, HIGH);
        break; 
      case '9':  
        blinkAll();
        break;
      case '8':  
        digitalWrite(red, LOW);
        digitalWrite(yel, LOW);
        digitalWrite(gre, LOW);
        break;
      case '*':  
        digitalWrite(red, HIGH);
        digitalWrite(gre, HIGH);
        digitalWrite(yel, LOW);
        break;
      case '#':  
        digitalWrite(red, LOW);
        digitalWrite(gre, LOW);
        digitalWrite(yel, HIGH);
        break;
    }
  }
}

void blinkAll() {
  for (int i = 0; i < 10; i++) {  
    blinkState = !blinkState;
    digitalWrite(red, blinkState);
    digitalWrite(yel, blinkState);
    digitalWrite(gre, blinkState);
    delay(300);  
  }
}
