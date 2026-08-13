#include <DHT.h>

#define DHTPIN 2      
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

const int red = 9;
const int yel = 10;
const int gre = 11;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
}

void loop() {

  float temperature = dht.readTemperature(); 
  float humidity = dht.readHumidity();       

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Помилка зчитування з DHT22");
    return; 
  }

  Serial.print("Температура: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Вологість: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temperature > 30) {

    digitalWrite(red, HIGH);
  } else {
    digitalWrite(red, LOW);
  }

  if (humidity > 40) {

    digitalWrite(yel, HIGH);
  } else {
    digitalWrite(yel, LOW);
  }

  if (temperature <= 30 && humidity <= 40) {

    digitalWrite(gre, HIGH);
  } else {
    digitalWrite(gre, LOW);
  }

  delay(2000);
}
