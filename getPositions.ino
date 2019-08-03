void getPositions(){
  if(start){
    lcd.setCursor(0,0);
  lcd.print("No. of Holes:");
  char customKey = customKeypad.getKey();  
  if (customKey){
    lcd.print(customKey);
    pos +=customKey;
    numOfHoles = pos.toInt();
    delay(900);
    lcd.clear();  
  
  for(int h = 0;h<numOfHoles;h++){
    lcd.setCursor(0,h);
    lcd.print("Pos(xy)- ");
    lcd.print(h+1);
    lcd.print(" ");
    customKey = customKeypad.getKey();
    while(len_check<6){
      customKey = customKeypad.getKey();
      if(customKey){
        lcd.print(customKey);
        len_check++;
        len +=customKey;
      }
    }
    x_pos += len[0];
    x_pos += len[1];
    x_pos += len[2];
    y_pos += len[3];
    y_pos += len[4];
    y_pos += len[5];
    all_coord += x_pos;
    all_coord += y_pos;
    Serial.println(x_pos);
    Serial.println(y_pos);
    Serial.print("X");
    ix = x_pos.toInt();
    Serial.println(ix);
    iy = y_pos.toInt();
    Serial.print("Y");
    Serial.println(iy);
    len_check =0;
    x_pos = "";
    y_pos = "";
    ix =0;
    iy =0;
    start=false;
    len="";
   }
 }
 Serial.println(all_coord);
 switchTwo();
  }
}
