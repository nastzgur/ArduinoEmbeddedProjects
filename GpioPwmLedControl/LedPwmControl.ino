int photo = A7;
int red = 9;  
int yel = 10;
int gre = 11; 
int thre = 100; 

void setup() { 
  Serial.begin(9600);       
}

void loop() {
  int val = analogRead(photo); 
  Serial.println(val);            

  int redB = map(val, 0, 341, 0, 255);     
  int yelB = map(val, 341, 682, 0, 255); 
  int greB = map(val, 682, 1015, 0, 255);

 
  if (val <= 341) {
    analogWrite(red, redB);
    analogWrite(yel, 0);
    analogWrite(gre, 0);
  } else if (val > 342 && val <= 682) {
    analogWrite(red, 255);             
    analogWrite(yel, yelB);
    analogWrite(gre, 0);
  } else if (val > 683) {
    analogWrite(red, 255);             
    analogWrite(yel, 255);          
    analogWrite(gre, greB);
  }

  delay(100); 
  
}
