#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
const int buzzerPin = 7;

long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  for(int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    if(distance < 40 && distance > 0) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }
  }
  
  for(int i = 165; i >= 15; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    if(distance < 40 && distance > 0) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}