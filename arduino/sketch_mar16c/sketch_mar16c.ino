int front = 6;
int back = 5;
int right = 4;
int left = 3;
int pot=A0;
const int ref=710;
int d1;

void setup() {
  // put your setup code here, to run once:
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

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(front, LOW);
}
