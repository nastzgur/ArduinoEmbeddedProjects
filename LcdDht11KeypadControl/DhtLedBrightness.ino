#include <LiquidCrystal.h> 
#include <DHT.h> 
 
LiquidCrystal lcd(12, 11, 10, 9, 8, 7); 
 
#define DHTPIN A4 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE); 
 
#define RED 3 
#define YEL 5 
#define GRE 6 
 
void setup() { 
  lcd.begin(32, 4); 
 
  dht.begin(); 
 
  pinMode(RED, OUTPUT); 
  pinMode(YEL, OUTPUT); 
  pinMode(GRE, OUTPUT); 
 
  lcd.setCursor(0, 0); 
  lcd.print("Initializing..."); 
  delay(2000); 
} 
 
void loop() { 
 
  float temperature = dht.readTemperature(); 
  float humidity = dht.readHumidity(); 
 
  if (isnan(temperature) || isnan(humidity)) { 
    lcd.setCursor(0, 0); 
    lcd.print("Error reading"); 
    lcd.setCursor(0, 1); 
    lcd.print("DHT22 sensor"); 
    delay(2000); 
    return; 
  } 
 
  int redBrightness = map(temperature, 0, 50, 0, 255);    
  redBrightness = constrain(redBrightness, 0, 255); 
 
  int yellowBrightness = map(humidity, 20, 95, 0, 255);  
  yellowBrightness = constrain(yellowBrightness, 0, 255); 
 
  bool greenState = (temperature < 0 && humidity < 20);  
 
  lcd.setCursor(0, 0); 
  lcd.print("T: "); 
  lcd.print(temperature, 1); 
  lcd.print("C H: "); 
  lcd.print(humidity, 1); 
  lcd.print("%"); 
 
  lcd.setCursor(0, 1); 
  if (greenState) { 
    lcd.print("Green ON     "); 
  } else if (redBrightness > yellowBrightness) { 
    lcd.print("Red "); 
    lcd.print(map(redBrightness, 0, 255, 0, 100)); 
    lcd.print("%     "); 
  } else { 
    lcd.print("Yellow "); 
    lcd.print(map(yellowBrightness, 0, 255, 0, 100)); 
    lcd.print("%     "); 
  } 
 
  analogWrite(RED, redBrightness); 
  analogWrite(YEL, yellowBrightness); 
  digitalWrite(GRE, greenState ? HIGH : LOW); 
 
  delay(1000); 
}
