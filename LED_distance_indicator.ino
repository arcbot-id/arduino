//import library NewPing
#include <NewPing.h>

//define digital pins
#define trigPin 12
#define echoPin 13
#define led_1 2
#define led_2 3
#define led_3 4
#define led_4 5
#define led_5 6
#define led_6 7

//declare a NewPing object called sonar with trigPin as trigger, echoPin as echo, and max distance 30 cm
NewPing sonar (trigPin, echoPin, 30);

//setup procedure; only run once in the beginning
void setup() {
  //debugging purpose only
  Serial.begin (9600);

  //set pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
}

//loop procedure; run in a loop forever
void loop() {
  long distance = sonar.ping_cm();

  if (distance <= 30) {
    digitalWrite(led_1, HIGH);
  }
  else {
    digitalWrite(led_1,LOW);
  }

  if (distance < 25) {
      digitalWrite(led_2, HIGH);
  }
  else {
      digitalWrite(led_2, LOW);
  }

  if (distance < 20) {
      digitalWrite(led_3, HIGH);
  }
  else {
    digitalWrite(led_3, LOW);
  }

  if (distance < 15) {
    digitalWrite(led_4, HIGH);
  }
  else {
    digitalWrite(led_4,LOW);
  }

  if (distance < 10) {
    digitalWrite(led_5, HIGH);
  }
  else {
    digitalWrite(led_5,LOW);
  }

  if (distance < 5) {
    digitalWrite(led_6, HIGH);
  }
  else {
    digitalWrite(led_6,LOW);
  }

  if (distance <= 0){
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
    digitalWrite(led_3,LOW);
    digitalWrite(led_4,LOW);
    digitalWrite(led_5,LOW);
    digitalWrite(led_6,LOW);
  }

  if (distance > 30){
    Serial.println(“Out of range”);
  }
  else {
    Serial.print(distance);
    Serial.println(” cm”);
  }

  //delay between loops
  delay(500);
}
