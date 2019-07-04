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

void setup(){
  Serial.begin(9600);
  pinMode(LS1,INPUT_PULLUP);
  pinMode(LS2,INPUT_PULLUP);
  pinMode(EN_MOT,OUTPUT);
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);

  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);

  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);

  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);
  attachInterrupt(digitalPinToInterrupt(LS1),switchOne,LOW);
  attachInterrupt(digitalPinToInterrupt(LS2),switchTwo,LOW);

}

void loop(){

// digitalWrite(Y_DIR,HIGH); // Enables the motor to move in a particular direction
//  // Makes 200 pulses for making one full cycle rotation
//  for(int x = 0; x < 400; x++) {
//    digitalWrite(Y_STP,HIGH); 
//    delayMicroseconds(500); 
//    digitalWrite(Y_STP,LOW); 
//    delayMicroseconds(500); 
//}
////  delay(1000); // One second delay
////  
////  digitalWrite(Y_DIR,LOW); //Changes the rotations direction
////  // Makes 400 pulses for making two full cycle rotation
////  for(int x = 0; x < 400; x++) {
////    digitalWrite(Y_STP,HIGH);
////    delayMicroseconds(500);
////    digitalWrite(Y_STP,LOW);
////    delayMicroseconds(500);
////  }
////  delay(1000);
////
 
////  delay(100); // One second delay
//  
//
////  delay(1000);


 
//  delay(100); // One second delay
}
void switchOne(){
   digitalWrite(X_DIR,LOW); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(X_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(X_STP,LOW); 
    delayMicroseconds(500); 
  }
}
void switchTwo(){
   digitalWrite(Y_DIR,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(Y_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STP,LOW); 
    delayMicroseconds(500); 
  }
digitalWrite(D1,HIGH);
digitalWrite(D2,LOW);
}
