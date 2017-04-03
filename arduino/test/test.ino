//int ledRed = 12;      // LED connected to digital pin 4
//#define constrain(amt,low,high);
int front = 6;
int back = 5;
int left = 4;
int right = 3;
int pot=A0;
const int ref=850;
int d1;
int range=constrain(range,825,875);
// front with right = p
// front with left = q

void setup(){
 // Open serial connection.
 Serial.begin(9600);
 int d1=analogRead(pot);

 //pinMode(ledRed, OUTPUT);
 pinMode(front,OUTPUT);
 pinMode(back,OUTPUT);
 pinMode(left,OUTPUT);
 pinMode(right,OUTPUT);
 digitalWrite(front,HIGH);
 digitalWrite(back,HIGH);
 digitalWrite(right,HIGH);
 digitalWrite(left,HIGH);
 
}

void move_straight()
{
     digitalWrite(front,LOW);
     digitalWrite(back,HIGH);
     digitalWrite(right,HIGH);
     digitalWrite(left,HIGH);
}
void reverse()
{
     digitalWrite(front,HIGH);
     digitalWrite(back,LOW);
     digitalWrite(right,HIGH); 
     digitalWrite(left,HIGH); 
}
void tyre_left(){
     digitalWrite(front,HIGH);
     digitalWrite(back,HIGH);
     digitalWrite(right,HIGH);
     digitalWrite(left,LOW);
}
void move_left(){
     digitalWrite(front,LOW);
     digitalWrite(back,HIGH);
     digitalWrite(right,HIGH);
     digitalWrite(left,LOW);
}
void tyre_right(){
     digitalWrite(front,HIGH);
     digitalWrite(back,HIGH);
     digitalWrite(right,LOW);
     digitalWrite(left,LOW);
}
void move_right(){
     digitalWrite(front,LOW);
     digitalWrite(back,HIGH);
     digitalWrite(right,LOW);
     digitalWrite(left,HIGH);
}
void tyre_straight()
{ 
  while(analogRead(pot)>670 || analogRead(pot)<525)
  {
  Serial.println(analogRead(pot));
  if (analogRead(pot)< 525)
      { 
         tyre_left();
       delay(30);
       digitalWrite(left,HIGH);  
      }
      
  else if(analogRead(pot)>670)
      { 
        tyre_right();
         delay(30);
        digitalWrite(right,HIGH); 
      } 
   else
   {
     digitalWrite(left,HIGH);
     digitalWrite(right,HIGH); 
   } 
   if(570<analogRead(pot)<670)
     break;
   delay(10);
  }
}

void loop(){
  
tyre_straight();
}
/*void loop()
{  
  tyre_straight();
  move_straight();
  if(Serial.available() > 0){  
       char data = Serial.read();
       char str[2];
       str[0] = data;
       str[1] = '\0';// if data present, blink
       if(str[0] == 'f'){
         tyre_straight();
         move_straight();
          }
       else if(str[0] == 'b'){
         tyre_straight();
         reverse();
       }
       else if(str[0] == 'l'){
         move_left();
       }
       else if (str[0]== 'r'){
         move_right();
         
       }
       else {
         tyre_straight();
         move_straight();
       }
  }
}*/


