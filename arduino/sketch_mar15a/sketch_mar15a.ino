//int ledRed = 12;      // LED connected to digital pin 4
//#define constrain(amt,low,high);
int front = 6;
int back = 5;
int right = 4;
int left = 3;
int pot=A0;
const int ref=850;
int range=constrain(range,825,875);
// front with right = p
// front with left = q

void setup(){
 // Open serial connection.
 Serial.begin(9600);
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

void tyre_straight(){
  int d1=analogRead(pot);
  Serial.println(d1);
  if (analogRead(pot)< 830)
      { 
         tyre_left();
       delay(50);
       digitalWrite(left,HIGH);  
      }
      
  else if(analogRead(pot)>870)
      { 
        tyre_right();
         delay(50);
        digitalWrite(right,HIGH); 
      } 
   else
   {
     digitalWrite(left,HIGH);
     digitalWrite(right,HIGH); 
   }
  delay(10);      
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
     digitalWrite(left,HIGH);
}
void move_right(){
     digitalWrite(front,LOW);
     digitalWrite(back,HIGH);
     digitalWrite(right,LOW);
     digitalWrite(left,HIGH);
}
void loop()
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
         tyre_left();
       }
       else if (str[0]== 'r'){
         tyre_right();
       }
       else if (str[0]== 'p'){
         move_right();
       }
      else if (str[0]== 'q'){
         move_left();
       }
       else {
         tyre_straight();
         move_straight();
       }
  }
}


