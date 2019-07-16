#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <Keypad.h>
#define EN   11  
#define EN_MOT 2
#define LS1  19
#define LS2  18 
#define D1   47
#define D2   46
//Direction pin
#define X_DIR     48 
#define Y_DIR     50
#define Z_DIR     52

//Step pin
#define X_STP     49
#define Y_STP     51 
#define Z_STP     53 

//Color Sensor
#define S0 46
#define S1 47
#define S2 44
#define S3 45
#define sensorOut 43


int frequency[] = {0,0,0};
int rgb[] = {0,0,0};


bool Y_DIR_c = HIGH;
bool runSw2Once = false;
bool runSw1Once = false;
String len = "";
int ilen;
String width = "";
int iwidth;
bool lenReady=false;//check if length obtained
int len_check =0;//check if all numbers i.e 3 of the length have been captured.
bool widReady =false; //check if width obtained
bool start = true; //prevent loop from starting from length once obtained
int leadScrewPitch = 2; //mm

//KEYPAD DETAILS
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','F'}
};
byte colPins[COLS] = {5,4,3,2}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {9,8,7,6.}; //connect to the column pinouts of the keypad

//LCD DETAILS
const int LCD_COLS = 20;
const int LCD_ROWS = 4;
int status;

//Instantiating of classes in code
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
hd44780_I2Cexp lcd;

void setup(){
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
   status = lcd.begin(LCD_COLS,LCD_ROWS);
  if(status){
    status = -status;
    hd44780::fatalError(status);
  }
  Serial.begin(9600);
  lcd.print("Welcome!");
  lcd.setCursor(0,0);
  lcd.clear();
  customKeypad.setHoldTime(500);
  Serial.begin(9600);
  pinMode(LS1,INPUT_PULLUP);
  pinMode(LS2,INPUT_PULLUP);
  pinMode(EN_MOT,OUTPUT);
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);

  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);

  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);

  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);
//  attachInterrupt(digitalPinToInterrupt(LS1),switchOne,LOW);
//  attachInterrupt(digitalPinToInterrupt(LS2),switchTwo,LOW);
goHome();
}

void loop(){
  
getMeasure();
}
void switchTwo(){
   digitalWrite(X_DIR,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
   int pulses = (ilen/leadScrewPitch)*400;
   if(!runSw1Once){
  for(int x = 0; x < pulses; x++) {
    digitalWrite(X_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(X_STP,LOW); 
    delayMicroseconds(500); 
    if(x%400==0){
      Y_DIR_c = !Y_DIR_c;
      runSw2Once = false;
      switchOne(Y_DIR_c);
      }
  }
  runSw1Once=true;
   }
   goHome();
}
void switchOne(bool DIR){
    digitalWrite(Y_DIR,DIR); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  int pulses = (iwidth/leadScrewPitch)*40; //Multiplied by 40 as a correction to motor taking pitch as 10mm;
  Serial.println(iwidth);
  if(!runSw2Once){
  for(int x = 0; x < pulses; x++) {
    digitalWrite(Y_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STP,LOW); 
    delayMicroseconds(500);
  }
  runSw2Once=true;
  }
  delay(1000);
}
