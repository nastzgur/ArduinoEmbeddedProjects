int photo = A7;
int red = 9;   
int threshold = 100; 

void setup() {
  pinMode(red, OUTPUT); 
  Serial.begin(9600);       
}

void loop() {
  int lightLevel = analogRead(photo); 
  Serial.println(lightLevel);            

  if (lightLevel > threshold) {
    digitalWrite(red, HIGH); 
  } else {
    digitalWrite(red, LOW);  
  }

  delay(100); 
  int brightness = map(lightLevel, 0, 1023, 0, 255);

  
  Serial.print("Освiтлення: ");
  Serial.print(lightLevel);
  Serial.print(" -> Яскравiсть свiтодiода: ");
  Serial.println(brightness);

  
  analogWrite(red, brightness);

  delay(100); 
}
