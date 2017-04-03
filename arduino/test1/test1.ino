int analogInPin = A0;
const int ledRightPin = 6;
const int ledLeftPin = 9;
const int ledFrontPin = 3;
const int ledBackPin = 5;
int straight, right, left;
void setup() {
  pinMode(ledRightPin, OUTPUT);
  pinMode(ledLeftPin, OUTPUT);
  pinMode(ledFrontPin, OUTPUT);
  pinMode(ledBackPin, OUTPUT);
  pinMode(analogInPin, INPUT);
  digitalWrite(ledRightPin, HIGH);
  digitalWrite(ledLeftPin, HIGH);
  digitalWrite(ledFrontPin, HIGH);
  digitalWrite(ledBackPin, HIGH);// initially they are off:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(analogInPin);
  //digitalWrite(ledFrontPin, LOW);
  Serial.println(x);
  straight = 0;
  right = 0;
  left = 0;

  if (straight) {
    digitalWrite(ledFrontPin, LOW);
    if (analogRead(analogInPin) > 650) {
      digitalWrite(ledRightPin, LOW);
    }
    else if (analogRead(analogInPin) < 650) {
      digitalWrite(ledLeftPin, LOW);
    }
  }
  if (right) {

    digitalWrite(ledRightPin, LOW);
    delay(100);
  }
  if (left) {

    digitalWrite(ledLeftPin, LOW);
    delay(100);
  }

  delay(3000);
  straight = 1;
  delay(3000);
  right = 1;
  delay(3000);
  right = 0;
  left = 1;
  //delay(3000);
}

