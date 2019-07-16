
void color_sense(){
   // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency[0] = pulseIn(sensorOut, LOW);
  rgb[0] = map(frequency[0],80,149,255,0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(rgb[0]);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency[1] = pulseIn(sensorOut, LOW);
  rgb[1] = map(frequency[1],120,158,255,0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(rgb[1]);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency[2] = pulseIn(sensorOut, LOW);
  rgb[2] = map(frequency[2],42,50,255,0);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency[2]);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  if(rgb[1]>rgb[0] && rgb[1]>frequency[2]){
    if(rgb[1] > 225){
      Serial.println("GREEN");
    }
  }
  if(rgb[0]>rgb[1] && rgb[0]>frequency[2]){
    if(rgb[0] > 200){
      Serial.println("RED");
    }
  }
}
