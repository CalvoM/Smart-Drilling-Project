void getMeasure(){
  if(start){
    lcd.setCursor(0,0);
  lcd.print("Enter Length:");
  char customKey = customKeypad.getKey();  
  if (customKey){
    lcd.print(customKey);
    len +=customKey;
    while(len_check<2){
      customKey = customKeypad.getKey();
      if(customKey){
        lcd.print(customKey);
        len_check++;
        len +=customKey;
      }
    }
    lenReady=true;
    start = false;
    len_check = 0;
    ilen = len.toInt();
    Serial.println(ilen);
  }
    }
   //When length obtained
  if(lenReady){
    lcd.setCursor(0,1);
    lcd.print("Enter Width :");
    char customKey = customKeypad.getKey();
      for(int i =0;i<1000;i++){
    
  }
    if (customKey){
      lcd.print(customKey);
      width +=customKey;
      while(len_check<2){
        customKey = customKeypad.getKey();
        if(customKey){
          lcd.print(customKey);
          len_check++;
          width +=customKey;
        }
      }
      widReady = true;
    }
  }
  //When width obtained
  if(widReady){
  
  iwidth = width.toInt();
  lcd.setCursor(0,2);
  lcd.print(ilen);
  lcd.setCursor(0,3);
  lcd.print(iwidth);
  switchTwo();
  }
}
