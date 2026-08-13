const int Pin = 12; 
const int red = 3;    
const int yel = 4; 
const int gre = 5;  

int state = 0;           
int buttonState;         
int lastButtonState = LOW;

void setup() {
  pinMode(Pin, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
}

void loop() {
  buttonState = digitalRead(Pin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    state++;
    if (state > 6) state = 0; 
  }
  lastButtonState = buttonState;

  
  digitalWrite(red, state == 1 || state == 4 ? HIGH : LOW);
  digitalWrite(yel, state == 2 || state == 5 ? HIGH : LOW);
  digitalWrite(gre, state == 3 || state == 6 ? HIGH : LOW);

  delay(50); 
}

