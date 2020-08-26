#include <Servo.h>

#define button_A 2
#define button_B 3
#define button_C 4
#define button_D 5

#define pinLED_1 7
#define pinLED_2 6
#define pinServo 8

Servo servo;

int arr[] = {0, 0, 0, 0};
int pass[] = {1, 2, 3, 4};

bool checked = false;

void(* ku_reset) (void) = 0;
 

void setup()
{
  Serial.begin(9600);

  pinMode(button_A, INPUT_PULLUP);
  pinMode(button_B, INPUT_PULLUP);
  pinMode(button_C, INPUT_PULLUP);
  pinMode(button_D, INPUT_PULLUP);

  pinMode(pinLED_1, OUTPUT);
  pinMode(pinLED_2, OUTPUT);


  Serial.println("SERVO RESET");
  servo.attach(pinServo);
  servo.write(0);
  servo.detach();

}

void loop()
{
  if (digitalRead(button_A) == LOW){ //if button1 is pressed
    checkEntered1(1); //call checkEntered and pass it a 1
    
    delay(250);//wait, needed for correct functioning, otherwise
               //buttons are deemed to be pressed more than once
    
  }
  else if (digitalRead(button_B) == LOW){ //if button2 is pressed
    checkEntered1(2); //call checkEntered1 and pass it a 2
    
    delay(250); //wait
    
  }
  else if (digitalRead(button_C) == LOW){ //if button3 is pressed
    checkEntered1(3); //call checkEntered1 and pass it a 3
    
    delay(250); //wait
    
  }
  else if (digitalRead(button_D) == LOW){ //if button4 is pressed
    checkEntered1(4); //call checkEntered1 and pass it a 4
    
    delay(250); //wait
    
  }
  
}

void checkEntered1(int button){ //check the first element of the entered[] array
  //digitalWrite(LED[button-1],HIGH);
  if (arr[0] != 0){ //if it is not a zero, i.e. it has already been inputted
    checkEntered2(button); //move on to checkEntered2, passing it "button"
  }
  
  else if(arr[0] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    arr[0] = button; //set the first element as the button that has been pressed
    Serial.print("1: ");Serial.println(arr[0]); //for debugging
  }
  
}

void checkEntered2(int button){ //check the second element of the arr[] array
  //digitalWrite(LED[button-1],HIGH);
  if (arr[1] != 0){ //if it is not a zero, i.e. it has already been inputted
    checkEntered3(button); //move on to checkEntered3, passing it "button"
  }
  
  else if(arr[1] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    arr[1] = button; //set the second element as the button that has been pressed
    Serial.print("2: ");Serial.println(arr[1]); //for debugging
  }
  
}

void checkEntered3(int button){  //check the third element of the arr[] array
  //digitalWrite(LED[button-1],HIGH);
  if (arr[2] != 0){ //if it is not a zero, i.e. it has already been inputted
    checkEntered4(button); //move on to checkEntered4, passing it "button"
  }
  
  else if (arr[2] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    arr[2] = button; //set the third element as the button that has been pressed
    Serial.print("3: ");Serial.println(arr[2]); //for debugging
  }
  
}

void checkEntered4(int button){  //check the third element of the arr[] array
  //digitalWrite(LED[button-1],HIGH);
  if (arr[3] == 0){ //if it is zero, i.e. if it hasn't been defined with a button yet
    arr[3] = button; //set the third element as the button that has been pressed
    Serial.print("4: ");Serial.println(arr[3]); //for debugging
    delay(100); //allow time for processing
    compareCode();
  }
}

void compareCode()
{
   for(int i = 0; i < 4; i++)
   {
    Serial.println(arr[i]);
   }
   
  if(arr[0] == pass[0] && arr[1] == pass[1] && arr[2] == pass[2] && arr[3] == pass[3])
  {
    digitalWrite(pinLED_1, HIGH);
    delay(1000);
    digitalWrite(pinLED_1, LOW);
    digitalWrite(pinLED_2, LOW);

    Serial.println("SERVO RUNNING");
    
    servo.attach(pinServo);
    for(int i = 0; i <= 180 ; i++)
    {
      servo.write(i);
    }
    
    delay(10000);

    servo.write(10);
  delay(1000);
  ku_reset();
   
  }
  else
  {
    for(int i = 1; i <= 2; i++)
    {
      digitalWrite(pinLED_2, HIGH);
      delay(500);
      digitalWrite(pinLED_2, LOW);
      delay(500);
    }

    close_all();
     ku_reset();
  }

}

void close_all()
{
  digitalWrite(pinLED_1, LOW);
  digitalWrite(pinLED_2, LOW);
}
