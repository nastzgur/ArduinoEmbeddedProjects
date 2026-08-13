int red = 11; 
int yel = 9; 
int gr  = 6; 
void setup() { 
} 
 void loop() 
{ 
col (red, 255); 
coll(red, 0); 
digitalWrite(red, LOW); 
 
col (yel, 255); 
coll(yel, 0); 
digitalWrite(yel, LOW); 
 
col (gr, 255); 
coll(gr, 0); 
digitalWrite(gr, LOW); 
 
col (yel, 255); 
coll(yel, 0); 
digitalWrite(yel, LOW); 
} 
 
void col(int co, int cout){ 
  for (int i = 0; i < cout; i=i+5){ 
    analogWrite (co, i); 
    delay(100); 
  } 
} 
 
void coll(int c, int cot){ 
  for (int i = 250; i > cot; i=i-5){ 
    analogWrite (c, i); 
    delay(100); 
  } 
} 
