#include <DHT.h> 
#include <LiquidCrystal.h> 
#define DHTPIN 9         
#define DHTTYPE DHT22    
DHT dht(DHTPIN, DHTTYPE);     
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   
int red = 6; 
int yel = 7; 
int gre = 8; 
 
void setup() { 
  lcd.begin(16, 2);    
  dht.begin();         
 
  pinMode(red, OUTPUT); 
  pinMode(yel, OUTPUT); 
  pinMode(gre, OUTPUT); 
} 
 
void loop() { 
  float humidity = dht.readHumidity();     
  float temperature = dht.readTemperature();  
 
  if (isnan(humidity) || isnan(temperature)) { 
    lcd.setCursor(0, 0); 
    lcd.print("error"); 
    return; 
  } 
 
  lcd.setCursor(0, 0); 
  lcd.print("T:"); 
  lcd.print(temperature); 
  lcd.print(" C "); 
  lcd.print("H:"); 
  lcd.print(humidity); 
  lcd.print(" %"); 
 
  if(humidity > 40 && temperature > 30 ){ 
    digitalWrite(red, HIGH); 
    digitalWrite(yel, HIGH);  
    digitalWrite(gre, LOW);  
    lcd.setCursor(0, 1); 
    lcd.print("Red and Yellow Led"); 
    } 
  else if (temperature > 30 ) { 
    digitalWrite(red, HIGH);    
    digitalWrite(yel, LOW);  
    digitalWrite(gre, LOW);   
    lcd.setCursor(0, 1); 
    lcd.print("Red LED            "); 
  } 
  else if (humidity > 40) { 
    digitalWrite(red, LOW);     
    digitalWrite(yel, HIGH);  
    digitalWrite(gre, LOW);   
    lcd.setCursor(0, 1); 
    lcd.print("Yellow LED        "); 
} 
else { 
digitalWrite(red, LOW);     
digitalWrite(yel, LOW);  
digitalWrite(gre, HIGH);  
lcd.setCursor(0, 1); 
lcd.print("Green LED     
"); 
} 
delay(2000);  
} 
