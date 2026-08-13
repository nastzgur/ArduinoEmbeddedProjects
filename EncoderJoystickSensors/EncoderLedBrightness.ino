#define CLK 2
#define DT 3

#define RED_LED 9
#define YELLOW_LED 10
#define GREEN_LED 11

int currentStateCLK;
int lastStateCLK;

int brightnessRed = 0;
int brightnessYellow = 0;
int brightnessGreen = 0;

const int stepSize = 13; 

const int maxBrightness = 255;
const int minBrightness = 0;

void setup() {
  
  Serial.begin(9600);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  lastStateCLK = digitalRead(CLK);
}

void loop() {

  currentStateCLK = digitalRead(CLK);

  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(DT) != currentStateCLK) {
      increaseBrightness();
    } else {
      decreaseBrightness();
    }

    Serial.print("Red: ");
    Serial.print(brightnessRed);
    Serial.print(" Yellow: ");
    Serial.print(brightnessYellow);
    Serial.print(" Green: ");
    Serial.println(brightnessGreen);
  }

  lastStateCLK = currentStateCLK;

  analogWrite(RED_LED, brightnessRed);
  analogWrite(YELLOW_LED, brightnessYellow);
  analogWrite(GREEN_LED, brightnessGreen);
}

void increaseBrightness() {
  if (brightnessRed < maxBrightness) {
    brightnessRed = constrain(brightnessRed + stepSize, minBrightness, maxBrightness);
  } else if (brightnessYellow < maxBrightness) {
    brightnessYellow = constrain(brightnessYellow + stepSize, minBrightness, maxBrightness);
  } else if (brightnessGreen < maxBrightness) {
    brightnessGreen = constrain(brightnessGreen + stepSize, minBrightness, maxBrightness);
  }
}

void decreaseBrightness() {
  if (brightnessGreen > minBrightness) {
    brightnessGreen = constrain(brightnessGreen - stepSize, minBrightness, maxBrightness);
  } else if (brightnessYellow > minBrightness) {
    brightnessYellow = constrain(brightnessYellow - stepSize, minBrightness, maxBrightness);
  } else if (brightnessRed > minBrightness) {
    brightnessRed = constrain(brightnessRed - stepSize, minBrightness, maxBrightness);
  }
}
