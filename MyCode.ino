#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

# define STEP1 53
//# define STEP2 49

# define DIR1 52
//# define DIR2 46

# define MS1_1 48
# define MS2_1 50
# define MS3_1 51
 
//# define MS1_2 47
//# define MS2_2 44
//# define MS3_2 45

# define LSW_1 2
# define LSW_2 3

hd44780_I2Cexp lcd;
const int LCD_COLS = 20;
const int LCD_ROWS = 4;
int status;
bool first_run = true;
void setup(){
  //Set up for the first a4988 chip
  pinMode(STEP1,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(MS1_1,OUTPUT);
  pinMode(MS2_1,OUTPUT);
  pinMode(MS3_1,OUTPUT);
  //Set up for the second a4988 chip
//  pinMode(STEP2,OUTPUT);
//  pinMode(DIR2,OUTPUT);
//  pinMode(MS1_2,OUTPUT);
//  pinMode(MS2_2,OUTPUT);
//  pinMode(MS3_2,OUTPUT);
  //Limit switches
  pinMode(LSW_1,INPUT);
  pinMode(LSW_2,INPUT);
  // Setting the step to 1/16th
  digitalWrite(MS1_1,HIGH);
  digitalWrite(MS2_1,HIGH);
  digitalWrite(MS3_1,HIGH);
//  digitalWrite(MS1_2,HIGH);
//  digitalWrite(MS2_2,HIGH);
//  digitalWrite(MS3_2,HIGH);
  //LCD config
  status = lcd.begin(LCD_COLS,LCD_ROWS);
  if(status){
    status = -status;
    hd44780::fatalError(status);
  }
  lcd.print("SMART DRILL");
}
void loop(){
  digitalWrite(DIR1,HIGH);
//  digitalWrite(DIR2,HIGH);
while(true){
  digitalWrite(13,HIGH);
    digitalWrite(STEP1,HIGH);
//    digitalWrite(STEP2,HIGH);
    delayMicroseconds(50);
    digitalWrite(STEP1,LOW);
//    digitalWrite(STEP2,LOW);
    delayMicroseconds(50);
    digitalWrite(DIR1,LOW);
    delayMicroseconds(50);
}
}
