#include <Arduino.h>
#include <Keypad.h>

const int ROW_NUM = 4;    // four rows
const int COLUMN_NUM = 3; // three columns

char keys[ROW_NUM][COLUMN_NUM] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'}};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};   // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

String SystemPath = "EFIKJGDCBA";
String PlayerPath = "_";
int resetgame = 0;
const int MotorPin = 12;
String themessage = "Hello, This Script created by Ali Jaafar (Barmajino) for Square-51 in ABC Dbayeh for more info contact me \"barmajino@gmail.com\"";
void setup()
{

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(themessage);
  pinMode(MotorPin, 1);
  digitalWrite(MotorPin, 0);
}

void runCode()
{
  digitalWrite(MotorPin, 1);
}

void loop()
{
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if (key)
  {
    PlayerPath += key;
    Serial.println(" Player path : " + PlayerPath + " and the SystemPath : " + SystemPath);
    if (resetgame && key != SystemPath.lastIndexOf('A'))
    {
      resetgame = 0;
      digitalWrite(MotorPin, 0);
      Serial.println("Reset");
    }
  }
  // Serial.println(PlayerPath.indexOf(SystemPath));
  if (PlayerPath.indexOf(SystemPath) > 0)
  {
    Serial.println("True");
    resetgame = 1;
    runCode();
    PlayerPath = "_";
  }
}
