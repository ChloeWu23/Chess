#include<iostream>
#include"bishop.h"
using namespace std;

/*Function definition in Class Bishop */
/*Constructor*/
Bishop::Bishop(colour _c) : Piece(_c){
}
/*
ostream& Bishop:: operator<< (Piece* p){
   return  p -> c << " 's Bishop ";
 
}
*/
type Bishop:: piece_type(){
  return bishop;
}
/*Function to make move for bishop piece*/
bool Bishop::valid_move(const char* source, const char* destination, ChessBoard* cb){
  //bool valid = false;
  //move towards diagonal
  //cout <<cb -> is_same_diagonal(source, destination);
  // cout <<  cb-> is_diag_clear(source, destination);
  int  src_row = source[1]-'1'; 
  int  src_col = source[0]-'A';
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';
  if (!cb->get_board(src_row,src_col)) return false;
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent(source,destination))  return false;
  if (cb -> is_same_diagonal(source, destination) && cb-> is_diag_clear(source, destination)) return true;
  return false;
}

void Bishop::get_type(){
  cout << "Bishop" ;
}
