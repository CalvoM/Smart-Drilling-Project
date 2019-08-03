#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <Keypad.h>
#define EN_X   10
#define EN_Y   11
#define EN_Z   12  
#define EN_MOT 2
#define LS1  19
#define LS2  18 
#define D1   47
#define D2   46
//Direction pin
#define X_DIR     48 
#define Y_DIR     50
#define Z_DIR     52
int distance = 1090;
//Step pin
#define X_STP     49
#define Y_STP     51 
#define Z_STP     53 

bool z_dir = HIGH;
bool runOnce = true;
int offsetDistance = 10;
int frequency[] = {0,0,0};
int rgb[] = {0,0,0};

int home_x = 0; //initial home positions x and y
int home_y = 0; 
bool Y_DIR_c = HIGH;
bool runSw2Once = false;
bool runSw1Once = false;
String all_coord="";
String len = "";
String x_pos="";
int ix;
int iy;
String y_pos="";
int numOfHoles = 0;
String pos = "";
int ilen;
String width = "";
int iwidth;
bool LCD_ready = false; //Check if all measurements taken;
bool lenReady=false;//check if length obtained
int len_check =0;//check if all numbers i.e 3 of the length have been captured.
bool widReady =false; //check if width obtained
bool start = true; //prevent loop from starting from length once obtained
int leadScrewPitch = 8; //mm

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
  pinMode(46,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(44,OUTPUT);
  digitalWrite(44,HIGH);
   status = lcd.begin(LCD_COLS,LCD_ROWS);
  if(status){
    status = -status;
    hd44780::fatalError(status);
  }
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

  pinMode(EN_X, OUTPUT);
  pinMode(EN_Y, OUTPUT);
  pinMode(EN_Z, OUTPUT);
digitalWrite(Z_DIR,z_dir);
  digitalWrite(EN_X, LOW);
  digitalWrite(EN_Y, LOW);
  digitalWrite(EN_Z, LOW);
  goHome();
}

void loop(){
  
getPositions();
}
