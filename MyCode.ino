/*
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define OUT 10
// include the library code:
#include <LiquidCrystal.h>
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  //
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  //
  pinMode(OUT,INPUT);
  //
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  //
  Serial.begin(9600);
  
  lcd.begin(20,4);
 
  // Print a message to the LCD.
  
  lcd.setCursor(0,1);
  lcd.print("EN292-0613/2014");
  lcd.setCursor(0,2);
  lcd.print("EN292-0599/2014");
  lcd.setCursor(0,3);
  lcd.print("BEGINNING..");
  delay(2000);
  lcd.clear();
  lcd.print("COLOR DETAILS");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
//  lcd.setCursor(0, 1);
//  // print the number of seconds since reset:
//  lcd.print(millis() / 1000);
digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(OUT, LOW);
  
   // Printing the RED (R) value
  lcd.setCursor(0,1);
  lcd.print("R = ");
  lcd.setCursor(2,1);
  lcd.print(redFrequency);
  delay(100);
 
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(OUT, LOW);
  
  // Printing the GREEN (G) value  
  lcd.setCursor(0,2);
  lcd.print("G = ");
  lcd.setCursor(2,2);
  lcd.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(OUT, LOW);
  
  // Printing the BLUE (B) value 
   lcd.setCursor(0,3);
  lcd.print("B = ");
  lcd.setCursor(2,3);
  lcd.print(blueFrequency);
  delay(100);
 
}
