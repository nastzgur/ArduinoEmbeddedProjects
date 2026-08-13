const int Pin = 12;
const int red = 3;
const int yel = 6;
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

  // Обробка натискання кнопки
  if (buttonState == LOW && lastButtonState == HIGH) {
    state++;
    if (state > 5) state = 0; // Повернення до початкового стану
  }
  lastButtonState = buttonState;

  // Логіка роботи
  if (state == 0) {
    analogWrite(red, 0);
    analogWrite(yel, 0);
    analogWrite(gre, 0);
  } else if (state == 1) {
    analogWrite(red, 85);   // 33%
    analogWrite(yel, 0);
    analogWrite(gre, 0);
  } else if (state == 2) {
    analogWrite(red, 85);   // 33%
    analogWrite(yel, 170); // 66%
    analogWrite(gre, 0);
  } else if (state == 3) {
    analogWrite(red, 85);   // 33%
    analogWrite(yel, 170); // 66%
    analogWrite(gre, 255); // 100%
  } else if (state == 4) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(red, i);
      analogWrite(yel, i);
      analogWrite(gre, i);
      delay(10);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(red, i);
      analogWrite(yel, i);
      analogWrite(gre, i);
      delay(10);
    }
  }
  delay(50); // Антидребезг
}

