void checkLimitSwitch(){
  if(digitalRead(2)==LOW){
  digitalWrite(3,HIGH);
}
else{
  digitalWrite(3,LOW);
}
}
