void drilling(){
   if(runOnce){
    digitalWrite(46,LOW);
    digitalWrite(47,HIGH);
    for(int k=0; k<distance;k++){
      digitalWrite(Z_STP, HIGH);
      delayMicroseconds(1500);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(1500);
    }
    digitalWrite(46,LOW);
    digitalWrite(47,LOW);
    dir=LOW;
    runOnce= false; 
    delay(1000);
  }
  if(!dir){
  digitalWrite(Y_DIR,LOW);
    for(int k=0; k<distance;k++){
      digitalWrite(Z_STP, HIGH);
      delayMicroseconds(1500);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(1500);
  }
  z_dir = HIGH;
}
