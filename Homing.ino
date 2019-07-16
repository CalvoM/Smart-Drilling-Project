void goHome(){

if(digitalRead(18)==HIGH){
  while(digitalRead(18)==HIGH){
     digitalWrite(X_DIR,HIGH); 
    digitalWrite(X_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(X_STP,LOW); 
    delayMicroseconds(500); 
  }
  Serial.println("X_AXIS HOMED");
 if(digitalRead(19)==HIGH){
  while(digitalRead(19)==HIGH){
     digitalWrite(Y_DIR,HIGH);
     digitalWrite(Y_STP,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(Y_STP,LOW); 
    delayMicroseconds(500);
  }
  Serial.println("Y-AXIS HOMED");
 }
else if(digitalRead(19)==HIGH){
  while(digitalRead(19)==HIGH){
     Serial.println("Y-AXIS HOMING");
  }
  Serial.println("Y_AXIS HOMED");
 if(digitalRead(18)==HIGH){
  while(digitalRead(18)==HIGH){
     Serial.println("X-AXIS HOMING");
  }
  Serial.println("X-AXIS HOMED");
}
}
}
}
