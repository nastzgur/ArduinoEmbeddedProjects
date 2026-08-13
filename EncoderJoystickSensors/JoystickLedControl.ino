#define VRx A0  
#define VRy A1  

#define RED 3
#define GRE 4
#define YEL 5
#define BLU 6
#define WHI 7

const int thresholdLow = 200;   
const int thresholdHigh = 800; 

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GRE, OUTPUT);
  pinMode(YEL, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(WHI, OUTPUT);
}

void loop() {

  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);

  if (xPosition > thresholdHigh) {
    digitalWrite(RED, HIGH);
    digitalWrite(GRE, LOW);
  } else if (xPosition < thresholdLow) {
    digitalWrite(RED, LOW);
    digitalWrite(GRE, HIGH);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GRE, LOW);
  }

  if (yPosition > thresholdHigh) {
    digitalWrite(YEL, HIGH);
    digitalWrite(BLU, LOW);
  } else if (yPosition < thresholdLow) {
    digitalWrite(YEL, LOW);
    digitalWrite(BLU, HIGH);
  } else {
    digitalWrite(YEL, LOW);
    digitalWrite(BLU, LOW);
  }

  if (xPosition >= thresholdLow && xPosition <= thresholdHigh &&
      yPosition >= thresholdLow && yPosition <= thresholdHigh) {
    digitalWrite(WHI, HIGH);
  } else {
    digitalWrite(WHI, LOW);
  }

  delay(50);
}
