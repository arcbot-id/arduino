//import library Servo
#include <Servo.h>
//import library NewPing
#include <NewPing.h>

//declare constants
const int ServoPin = 10;
const int TriggerPin = 6;
const int EchoPin = 7;

//declare a NewPing object called sonar with TriggerPin as trigger, EchoPin as echo, and 100 cm as max distance
NewPing sonar (TriggerPin, EchoPin, 100);
//declare a Servo object called servo
Servo servo;

////setup procedure; only run once in the beginning
void setup()
{
  Serial.begin(9600);

  //attach servo pin to ServoPin
  servo.attach(ServoPin);
}

void loop()
{
  //measure distance and output them to serial monitor
  int cm = sonar.ping_cm();
  Serial.println(cm);

  //map the distance to scale of 15-100
  int angle = map(cm, 2, 15, 15, 100);
  //move servo to certain degree of angle
  servo.write(angle);

  //delay between loops
  delay(50);
}
