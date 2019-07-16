//#include <Wire.h>
//#include <hd44780.h>
//#include <hd44780ioClass/hd44780_I2Cexp.h>
//#include <Keypad.h>
//
//String len = "";
//int ilen;
//String width = "";
//int iwidth;
//bool lenReady=false;//check if length obtained
//int len_check =0;//check if all numbers i.e 3 of the length have been captured.
//bool widReady =false; //check if width obtained
//bool start = true; //prevent loop from starting from length once obtained
//
////KEYPAD DETAILS
//const byte ROWS = 4; //four rows
//const byte COLS = 4; //four columns
////define the symbols on the buttons of the keypads
//char hexaKeys[ROWS][COLS] = {
//  {'1','2','3','A'},
//  {'4','5','6','B'},
//  {'7','8','9','C'},
//  {'*','0','#','F'}
//};
//byte colPins[COLS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
//byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the column pinouts of the keypad
//
////LCD DETAILS
//const int LCD_COLS = 20;
//const int LCD_ROWS = 4;
//int status;
//
////Instantiating of classes in code
//Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
//hd44780_I2Cexp lcd;
//
//void setup(){
//  status = lcd.begin(LCD_COLS,LCD_ROWS);
//  if(status){
//    status = -status;
//    hd44780::fatalError(status);
//  }
//  Serial.begin(9600);
//  lcd.print("Welcome!");
//  lcd.setCursor(0,0);
//  lcd.clear();
//  customKeypad.setHoldTime(500);
//}
//  
//void loop(){
//  getMeasure();
//}
