#include<iostream>
#include"queen.h"

using namespace std;

/*Function definition in Class Queen */
Queen::Queen(colour _c) : Piece(_c){
  
}
/*
std::ostream& Queen::operator<< (std::ostream& out, Piece* p){
  out << p ->c << " 's Queen ";
  return out;
}
*/
bool Queen::valid_move(const char* source, const char* destination, ChessBoard* cb){
  int  src_row = source[1]-'1'; 
  int  src_col = source[0]-'A';
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';
  
   if (!cb->get_board(src_row,src_col)) return false;
  if (cb -> get_board(des_row,des_col) !=NULL && !cb ->is_opponent(source,destination)) return false;
  //move toward rank
  if( cb -> is_same_row(source,destination) && cb -> is_row_clear(source,destination))  return true;
 
  //move towards file
  if( cb -> is_same_col(source,destination) && cb -> is_col_clear(source,destination))  return true;
  
  //move towards diagonal
  if (cb -> is_same_diagonal(source, destination) && cb-> is_diag_clear(source, destination)) return true;
  
  return false;
}

void Queen::get_type(){
  cout << "Queen";
}
 
type Queen::piece_type(){
  return queen;
}
