#define button_red 12
#define button_yellow 9
#define button_green 6
#define button_blue 2

#define led_red 13
#define led_yellow 10
#define led_green 5
#define led_blue 3


void setup()
{
  pinMode(button_red, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);

  pinMode(button_yellow, INPUT_PULLUP);
  pinMode(led_yellow, OUTPUT);

  pinMode(button_green, INPUT_PULLUP);
  pinMode(led_green, OUTPUT);

  pinMode(button_blue, INPUT_PULLUP);
  pinMode(led_blue, OUTPUT);

  Serial.begin(9600);
  Serial.println("SETUP COMPLETE");
}

void loop()
{
  if(digitalRead(button_red) == 0)
    {
      digitalWrite(led_red, HIGH);
      Serial.println("RED ON");
    }
  else
    {
      digitalWrite(led_red, LOW);
      //Serial.println("RED OFF");
    }

  if(digitalRead(button_yellow) == 0)
    {
      digitalWrite(led_yellow, HIGH);
      Serial.println("YELLOW ON");

    }
  else
    {
      digitalWrite(led_yellow, LOW);
      //Serial.println("YELLOW OFF");

    }

  if(digitalRead(button_green) == 0)
    {
      digitalWrite(led_green, HIGH);
      Serial.println("GREEN ON");

    }
  else
    {
      digitalWrite(led_green, LOW);
      //Serial.println("GREEN OFF");

    }

  if(digitalRead(button_blue) == 0)
    {
      digitalWrite(led_blue, HIGH);
      Serial.println("BLUE ON");

    }
  else
    {
      digitalWrite(led_blue, LOW);
      //Serial.println("BLUE OFF");

    }
}
