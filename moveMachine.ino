void moveMachine(){
  digitalWrite(Y_DIR,HIGH);
  digitalWrite(X_DIR,HIGH);
  for(int l=0;l<numOfHoles;l++){
   String coord="";
   String x_coord = "";
   String y_coord="";
    coord = getCoord(all_coord,l,"g");
    x_coord = getCoord(coord,0,"p");
    Serial.println(coord);
    int i_x = x_coord.toInt() - home_x;
    Serial.println(i_x);
    y_coord = getCoord(coord,1,"p");
    int i_y = y_coord.toInt() - home_y;
    Serial.println(i_y);
    if(i_x<0){
      digitalWrite(X_DIR,LOW);
      i_x = 0 - i_x;
      Serial.print("X is behind");
      Serial.println(i_x);
    }
    if(i_y<0){
      digitalWrite(Y_DIR,LOW);
      i_y = 0 - i_y;
      Serial.print("Y is behind");
      Serial.println(i_y);
    }
    int x_pulses = i_x/leadScrewPitch * 200;
    int y_pulses = i_y/leadScrewPitch * 200;
    for(int lx=0;lx<x_pulses;lx++){
      digitalWrite(X_STP, HIGH);
      delayMicroseconds(500);
      digitalWrite(X_STP, LOW);
      delayMicroseconds(500);
    }
   for(int ly=0;ly<y_pulses;ly++){
    digitalWrite(Y_STP, HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_STP, LOW);
    delayMicroseconds(500);
   }
   runOnce=true;
   drilling();
   home_x = i_x;
   home_y = i_y;
  }
}
