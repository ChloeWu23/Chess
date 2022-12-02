#include<iostream>
#include"king.h"
#include<cmath>
using namespace std;

/*Function definition in Class King*/
King::King(colour _c) : Piece(_c){
}
/*
ostream& King::operator<< (Piece* p) {
  std::ostream out;
  out << p ->c << " 's King ";
  return out;
}
*/
void King::get_type(){
  cout << "King" ;
}

type King:: piece_type(){
  return king;
}
/*Function to move piece king*/
/* Note here valid means that it follows rule of its piece and it didnt move t its own piece's position and make its own under in check */
bool King:: valid_move(const char* source, const char* destination, ChessBoard* cb){
  int  src_row = source[1]-'1'; //decimal for row of source, from 0 to 7
  int  src_col = source[0]-'A';//decimal for column of source, from 0 to 7
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';
  if (!cb->get_board(src_row,src_col)) return false;
  //bool white_colour = cb->get_board(src_row,src_col) -> get_colour();
  //const char* king_position = white_colour? cb
  //check the move is valid or not
  //destination position is as required and whether we take piece on that position or not
 
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent(source,destination))  return false;
  
  //bool is_white_colour = cb->get_board(src_row,src_col) ->get_colour();
  //const char* position = NULL;
  //if (is_white_colour) position = cb->get_board(src_row,src_col) ->get_white_king_position();
  //else position =  cb->get_board(src_row,src_col) ->get_black_king_position();
  //if (in_check (!is_white_colour, position)) return false;
  //first step move two step along the file
  if (abs (des_col-src_col) == 1 && cb -> is_same_row(source, destination)) return true;
  if (abs (des_row-src_row) == 1 && cb -> is_same_col(source,destination)) return  true;
  if (abs (des_col-src_col) == 1 && cb -> is_same_diagonal(source, destination)) return true;
  
  return false;
      
}



