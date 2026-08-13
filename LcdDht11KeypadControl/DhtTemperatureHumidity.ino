#include <LiquidCrystal.h> 
#include <DHT.h> 
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
 
#define DHTPIN 7  
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE); 
 
void setup() { 
   
  lcd.begin(16, 2); 
 
  lcd.setCursor(0, 0); 
  lcd.print("Temp:    C"); 
  lcd.setCursor(0, 1); 
  lcd.print("Humidity:    %"); 
  dht.begin(); 
} 
 
void loop() { 
 
  float temp = dht.readTemperature();  
  float hum = dht.readHumidity();      
 
  if (isnan(temp) || isnan(hum)) { 
    lcd.setCursor(0, 0); 
    lcd.print("Error reading  "); 
    lcd.setCursor(0, 1); 
    lcd.print("DHT22 sensor   "); 
    delay(2000); 
    return; 
  } 
 
  lcd.setCursor(6, 0); 
  lcd.print("   ");  
  lcd.setCursor(6, 0); 
  lcd.print(temp); 
 
  lcd.setCursor(10, 1); 
  lcd.print("   ");  
  lcd.setCursor(10, 1); 
lcd.print(hum); 
delay(2000);  
}
