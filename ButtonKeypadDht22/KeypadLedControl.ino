const int Pin = 12; 
const int red = 3;    
int brightness = 0;      
bool increasing = true;  

int buttonState;
int lastButtonState = LOW;

void setup() {
  pinMode(Pin, INPUT_PULLUP);
  pinMode(red, OUTPUT);
}

void loop() {
  buttonState = digitalRead(Pin);

  
  if (buttonState == LOW && lastButtonState == HIGH) {
    if (increasing) {
      brightness += 51; 
      if (brightness >= 255) {
        brightness = 255;
        increasing = false; 
      }
    } else {
      brightness -= 51; 
      if (brightness <= 0) {
        brightness = 0;
        increasing = true; 
      }
    }
  }
  lastButtonState = buttonState;

  analogWrite(red, brightness);
  delay(50); 
}

