#define CLK 2    
#define DT 3     

#define RED 10
#define YEL 11
#define GRE 12

int currentStateCLK;
int lastStateCLK;

int ledCounter = 0;

const int LED_COUNT = 3;

void setup() {
 
  Serial.begin(9600);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(YEL, OUTPUT);
  pinMode(GRE, OUTPUT);

  lastStateCLK = digitalRead(CLK);
}

void loop() {

  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK) {

    if (digitalRead(DT) != currentStateCLK) {
  
      ledCounter++;
    } else {
      ledCounter--;
    }

    if (ledCounter >= LED_COUNT) {
      ledCounter = 0;
    } else if (ledCounter < 0) {
      ledCounter = LED_COUNT - 1;
    }

    Serial.print("LED Counter: ");
    Serial.println(ledCounter);

    updateLEDs();
  }

  lastStateCLK = currentStateCLK;
}

void updateLEDs() {

  digitalWrite(RED, LOW);
  digitalWrite(YEL, LOW);
  digitalWrite(GRE, LOW);

  switch (ledCounter) {
    case 0:
      digitalWrite(RED, HIGH);
      break;
    case 1:
      digitalWrite(YEL, HIGH);
      break;
    case 2:
      digitalWrite(GRE, HIGH);
      break;
  }
}

