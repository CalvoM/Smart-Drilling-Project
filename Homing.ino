void goHome(){

if(digitalRead(18)==HIGH){
  while(digitalRead(18)==HIGH){
     digitalWrite(X_DIR,LOW); 
    digitalWrite(X_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(X_STP,LOW); 
    delayMicroseconds(500); 
  }
  Serial.println("X_AXIS HOMED");
 if(digitalRead(19)==HIGH){
  while(digitalRead(19)==HIGH){
     digitalWrite(Y_DIR,LOW);
     digitalWrite(Y_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STP,LOW); 
    delayMicroseconds(500);
  }
  Serial.println("Y-AXIS HOMED");
  delay(1000);
 }
else if(digitalRead(19)==HIGH){
  while(digitalRead(19)==HIGH){
    digitalWrite(Y_DIR,LOW);
     digitalWrite(Y_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STP,LOW); 
    delayMicroseconds(500);
     Serial.println("Y-AXIS HOMING");
  }
  Serial.println("Y_AXIS HOMED");
  delay(1000);
}
}
}
