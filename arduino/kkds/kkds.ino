int front = 6;
int back = 5;
int left= 4;
int right = 3;
int pot=A0;
const int ref=710;
int d1;

void setup(){
 // Open serial connection.
 Serial.begin(9600);
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
     digitalWrite(left,HIGH);
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
       digitalWrite(left,LOW);
       delay(10);
       digitalWrite(left,HIGH);  
      }
      
  else if(analogRead(pot)>670)
      { 
        digitalWrite(right,LOW);
         delay(10);
        digitalWrite(right,HIGH); 
      } 
   else
   {
     digitalWrite(left,HIGH);
     digitalWrite(right,HIGH); 
   } 
   if(570<analogRead(pot) || analogRead(pot)>670)
     break;
   delay(10);
  }
}

void loop()
{
  tyre_straight();
  delay(1500);
  move_straight();
  delay(1000);
  move_right();
  delay(1500);
  digitalWrite(right,HIGH);
  digitalWrite(front,HIGH);
  tyre_straight();
  delay(1500);
  move_left();
  delay(1500);
  digitalWrite(left,HIGH);
  digitalWrite(front,HIGH);
  delay(1000);
  
  //if(Serial.available() > 0){  
      /* char data = Serial.read();
       char str[2];
       str[0] = data;
       str[1] = '\0';// if data present, blink
       int i=0;
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
 // }
  else{
    digitalWrite(front,HIGH);
    digitalWrite(back,HIGH);
    digitalWrite(left,HIGH);
    digitalWrite(right,HIGH);
  }
  
  delay(500);
      if(i==0) str[0]='f';
      else if(i==1) str[0]='r';
      else if(i==2) str[0]='l';
      else { //tyre_straight();
              setup();}
  i++;*/
}
/* parking: A=fwd; B=stop+fullLeft+fwd+delay(10); C=stop+fullright+fwd+delay(10); D=stop.*/
