
void color_sense(){
     // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency[0] = pulseIn(sensorOut, LOW);
  rgb[0] = map(frequency[0],125,147,255,0);//129 139
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency[0]);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency[1] = pulseIn(sensorOut, LOW);
  rgb[1] = map(frequency[1],137,174,255,0);//140,152
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency[1]);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency[2] = pulseIn(sensorOut, LOW);
  rgb[2] = map(frequency[2],125,150,255,0);//109,132
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency[2]);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  if(rgb[1]>rgb[0] && rgb[1]>rgb[2] && rgb[1]<300){
    if(rgb[1] > 240){
      lcd.clear();
      lcd.print("GREEN");
      Serial.println("GREEN");
    }
  }
  if(rgb[0]>rgb[1] && rgb[0]>rgb[2] && rgb[0]<256){
    if(rgb[0] > 240){
      lcd.clear();
      lcd.print("RED");
      Serial.println("RED");
      digitalWrite(EN_X, HIGH);
      delayMicroseconds(500);
      digitalWrite(EN_X,LOW);
      digitalWrite(X_DIR,LOW);
      for(int j=0;j<400;j++){
        digitalWrite(X_DIR,LOW);
        digitalWrite(X_STP,HIGH); 
        delayMicroseconds(500); 
        digitalWrite(X_STP,LOW);
        delayMicroseconds(500);
      }
      digitalWrite(EN_X, HIGH);
    }
  }
   if(rgb[2]>rgb[1] && rgb[2]>rgb[1] && rgb[2]){
    if(rgb[2] > 240){
      lcd.clear();
      lcd.print("BLUE");
      Serial.println("BLUE");
    }
  }
}
