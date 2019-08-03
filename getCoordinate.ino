 String getCoord(String coords,int pos_num,String coord_type){
  //coord_type if is general coord separation or position separation g or p
  int coord_length;
  coord_type=="p"?coord_length=3:coord_length=6;
  String final_coord = "";
  int current_pos = coord_length * pos_num;
  int end_pos = current_pos +coord_length;
  for(int k =current_pos; k<end_pos;k++){
    final_coord += coords[k];
  }
  return final_coord;
}
