#define trigPinf1 12
#define echoPinf1 13
#define trigPinf2 9
#define echoPinf2 8
#define trigPinl 9
#define echoPinl 8

void setup() {
  Serial.begin (9600);
  pinMode(trigPinf1, OUTPUT);
  pinMode(echoPinf1, INPUT);
  pinMode(trigPinf2, OUTPUT);
  pinMode(echoPinf2, INPUT);
}

long fsense1() {
  long duration, distancef1;
  digitalWrite(trigPinf1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinf1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPinf1, LOW);
  duration = pulseIn(echoPinf1, HIGH);
  distancef1 = (duration/2) / 29.1;
 /* if (distancef1 >= 200 || distancef1 <= 0){
    Serial.print(distancef1);
    Serial.println("Out of range");
  }
  else {
    Serial.print(distancef1);
    Serial.println(" cm");
  } */
  
  return distancef1;
}

long fsense2() {
  long duration, distancef2;
  digitalWrite(trigPinf2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinf2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPinf2, LOW);
  duration = pulseIn(echoPinf2, HIGH);
  distancef2 = (duration/2) / 29.1;
  /*if (distancef2 >= 200 || distancef2 <= 0){
    Serial.print(distancef2);
    Serial.println("Out of range");
  }
  else {
    Serial.print(distancef2);
    Serial.println(" cm");
  }*/
  
  return distancef2;
}

/*int lsense() {
  long duration, distancel;
  digitalWrite(trigPinl, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPinl, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPinl, LOW);
  duration = pulseIn(echoPinl, HIGH);
  distancel = (duration/2) / 29.1;
  if (distancel >= 200 || distancel <= 0){
    Serial.print(distancel);
    Serial.println("Out of range");
  }
  else {
    Serial.print(distancel);
    Serial.println(" cm");
  }
  
  return distancel;
}
*/
void loop()
{
  int d,d1,d2;
  d1 = fsense1();
  Serial.println("d1= "+d1);
  d2 = fsense2();
  Serial.println("d2= "+d2);
  if(d1 < d2)
    d=fsense1();
  else
    d=fsense2();
    
  //Serial.println(d);
  
  if (d<75)
    Serial.println("STOP!");
  else
    Serial.println("Keep_Going");
    
  /*dl=lsense();
  if(dl<40)
    Serial.println("Left Turn Prohibited!");
  else
    Serial.println("Left is clear");*/
  
  delay(100);
} 
