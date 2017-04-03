const int analogInPin = 6;
const int ledRightPin = 5;
const int ledLeftPin = 4;
const int ledFrontPin = 3;
const int ledBackPin = 2;
const float threshold = 3.81;

void setup() {
  digitalWrite(ledRightPin, HIGH);
  digitalWrite(ledLeftPin, HIGH);
  digitalWrite(ledFrontPin, HIGH);
  digitalWrite(ledBackPin, HIGH);// put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
  digitalWrite(ledFrontPin, LOW);
  char condition = Serial.read();
  if (condition == 's'){
    if (analogRead(analogInPin)>threshold){
      digitalWrite(ledRightPin, LOW);
      }
    else if (analogRead(analogInPin)<threshold){
      digitalWrite(ledLeftPin, LOW);
      }
    }
    if (condition == 'r'){
      
    digitalWrite(ledRightPin, LOW);
    delay(100);
    digitalWrite(ledLeftPin, LOW);
    }
    if (condition == 'l'){
      
    digitalWrite(ledLeftPin, LOW);
    delay(100);
    digitalWrite(ledRightPin, LOW);
    }
    delay(100);
    }
    
}
