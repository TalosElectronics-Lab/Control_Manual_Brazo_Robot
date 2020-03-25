#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define joystick_x A1
#define joystick_y A0
#define joystick_sw A2

LiquidCrystal_I2C lcd(0x3F,16,2);

Servo Servo_1;
Servo Servo_2;
Servo Servo_3;
Servo Servo_4;
Servo Servo_5;
Servo Servo_6;


int Angulo = 0;
int Angulo_1 = 90;
int Angulo_2 = 90;
int Angulo_3 = 90;
int Angulo_4 = 90;
int Angulo_5 = 90;
int Angulo_6 = 90;

char Estado;
int Velocidad = 25;
int Avance = 10;
int Numero_servo = 1;


byte Mover_Servo(Servo Servo_1, int Angulo_Actual, int Angulo, int 
Velocidad);

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Control Manual");

  Servo_1.attach(2);
  Servo_2.attach(3);
  Servo_3.attach(4);
  Servo_4.attach(5);
  Servo_5.attach(6);
  Servo_6.attach(7);

  pinMode(joystick_sw, INPUT_PULLUP);

  Home();
  delay(2000);
}

void loop()
{
  Serial.println(digitalRead(joystick_sw));
  lcd.setCursor(0,1);
  
  lcd.print("servo " + String(Numero_servo));
  
  if (!digitalRead(joystick_sw))
  {
    while (!digitalRead(joystick_sw))
    {
      delay(20);
    }
    Numero_servo++;
    if(Numero_servo>6)
    {
      Numero_servo=1;
    }
  }
  if (analogRead(joystick_x) > 600)
  {
    if (Numero_servo == 1)
    {
      Estado = 'e';
      lcd.setCursor(10,1);
      lcd.print(Angulo_1);
      lcd.print(" ");
    }
    else if (Numero_servo == 2)
    {
      Estado = 'g';
      lcd.setCursor(10,1);
      lcd.print(Angulo_2);
      lcd.print(" ");
    }
    else if (Numero_servo == 3)
    {
      Estado = 'h';
      lcd.setCursor(10,1);
      lcd.print(Angulo_3);
      lcd.print(" ");
    }
    else if (Numero_servo == 4)
    {
      Estado = 'k';
      lcd.setCursor(10,1);
      lcd.print(Angulo_4);
      lcd.print(" ");
    }
    else if (Numero_servo == 5)
    {
      Estado = 'l';
      lcd.setCursor(10,1);
      lcd.print(Angulo_5);
      lcd.print(" ");
    }
    else if (Numero_servo == 6)
    {
      Estado = 'n';
      lcd.setCursor(10,1);
      lcd.print(Angulo_6);
      lcd.print(" ");
    }
    
  }
  else if (analogRead(joystick_x) < 400)
  {
    if (Numero_servo == 1)
    {
      Estado = 'd';
      lcd.setCursor(10,1);
      lcd.print(Angulo_1);
      lcd.print(" ");
    }
    else if (Numero_servo == 2)
    {
      Estado = 'f';
      lcd.setCursor(10,1);
      lcd.print(Angulo_2);
      lcd.print(" ");
    }
    else if (Numero_servo == 3)
    {
      Estado = 'i';
      lcd.setCursor(10,1);
      lcd.print(Angulo_3);
      lcd.print(" ");
    }
    else if (Numero_servo == 4)
    {
      Estado = 'j';
      lcd.setCursor(10,1);
      lcd.print(Angulo_4);
      lcd.print(" ");
    }
    else if (Numero_servo == 5)
    {
      Estado = 'm';
      lcd.setCursor(10,1);
      lcd.print(Angulo_5);
      lcd.print(" ");
    }
    else if (Numero_servo == 6)
    {
      Estado = 'o';
      lcd.setCursor(10,1);
      lcd.print(Angulo_6);
      lcd.print(" ");
    }
  }
  else
  {
    Estado = 0;
  }
  
  if (Serial.available() > 0)
  {
    Estado = Serial.read();
  }
  switch (Estado)
  {
    case 'e':
      if (Angulo_1 > 0)
      {
        Angulo_1 = Mover_Servo(Servo_1, Angulo_1, Angulo_1 - Avance, 
Velocidad);
      }
      break;

    case 'd':
      if (Angulo_1 < 180)
      {
        Angulo_1 = Mover_Servo(Servo_1, Angulo_1, Angulo_1 + Avance, 
Velocidad);
      }
      break;

    case 'g':
      if (Angulo_2 > 0)
      {
        Angulo_2 = Mover_Servo(Servo_2, Angulo_2, Angulo_2 - Avance, 
Velocidad);
      }
      break;

    case 'f':
      if (Angulo_2 < 180)
      {
        Angulo_2 = Mover_Servo(Servo_2, Angulo_2, Angulo_2 + Avance, 
Velocidad);
      }
      break;

    case 'h':
      if (Angulo_3 < 180)
      {
        Angulo_3 = Mover_Servo(Servo_3, Angulo_3, Angulo_3 - Avance, 
Velocidad);
      }

      break;

    case 'i':
      if (Angulo_3 > 0)
      {
        Angulo_3 = Mover_Servo(Servo_3, Angulo_3, Angulo_3 + Avance, 
Velocidad);
      }
      break;

    case 'j':
      if (Angulo_4 < 180)
      {
        Angulo_4 = Mover_Servo(Servo_4, Angulo_4, Angulo_4 + Avance, 
Velocidad);
      }

      break;

    case 'k':
      if (Angulo_4 > 0)
      {
        Angulo_4 = Mover_Servo(Servo_4, Angulo_4, Angulo_4 - Avance, 
Velocidad);
      }
      break;

    case 'l':
      if (Angulo_5 < 180)
      {
        Angulo_5 = Mover_Servo(Servo_5, Angulo_5, Angulo_5 + Avance, 
Velocidad);
      }

      break;

    case 'm':
      if (Angulo_5 > 0)
      {
        Angulo_5 = Mover_Servo(Servo_5, Angulo_5, Angulo_5 - Avance, 
Velocidad);
      }
      break;

    case 'n':
      if (Angulo_6 < 180)
      {
        Angulo_6 = Mover_Servo(Servo_6, Angulo_6, Angulo_6 + Avance, 
Velocidad);
      }

      break;

    case 'o':
      if (Angulo_6 > 0)
      {
        Angulo_6 = Mover_Servo(Servo_6, Angulo_6, Angulo_6 - Avance, 
Velocidad);
      }
      break;


    case 'p':
      //Funcion 1
      Home();
      break;
    case 'q':
      //Funcion 1
      break;

  }


}

void Home()
{
  Angulo_1 = Mover_Servo(Servo_1, Angulo_1, 90, 25);
  Angulo_2 = Mover_Servo(Servo_2, Angulo_2, 90, 25);
  Angulo_3 = Mover_Servo(Servo_3, Angulo_3, 90, 25);
  Angulo_4 = Mover_Servo(Servo_4, Angulo_4, 90, 10);
  Angulo_5 = Mover_Servo(Servo_5, Angulo_5, 90, 10);
  Angulo_6 = Mover_Servo(Servo_6, Angulo_6, 90, 10);
}
byte Mover_Servo(Servo Servo_1, int Angulo_Actual, int Angulo, int 
Velocidad)
{
  while (Angulo_Actual != Angulo)
  {
    if (Angulo_Actual < Angulo)
    {
      Angulo_Actual++;
      Servo_1.write(Angulo_Actual);
      delay(Velocidad);
    }
    else
    {
      Angulo_Actual--;
      Servo_1.write(Angulo_Actual);
      delay(Velocidad);
    }

  }
  return (Angulo_Actual);

}

