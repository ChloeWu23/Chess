#include<iostream>
#include"king.h"
#include<cmath>
using namespace std;

/*Function definition in Class King*/


/* Constructor */
King::King(string c) : Piece(c) {
  piece_type = "King";
 
}


/**
 *Function to see whether it is a valid move for piece king from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
**/
/* Note here valid means that it follows rule of its piece and if make this move 
it wont make itself in check */
bool King:: valid_move(int src_row, int src_col, int des_row, int des_col, ChessBoard* cb){
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) -> is_white();
  
 
  //can't move to position where having its own piece
  if (cb -> get_board(des_row,des_col) != NULL 
    && !cb ->is_opponent (src_row, src_col, des_row, des_col)) {
    return false;
  }

  //destination position is as required: move one square in any direction
  if (abs (des_col-src_col) == 1 && src_row == des_row) flag = true;
  if (abs (des_row-src_row) == 1 && src_col == des_col) flag = true;
  if (abs (des_col-src_col) == 1 && cb -> is_same_diagonal(src_row, src_col, des_row,des_col)) flag = true;

  //check whether capture king
  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;

  //check not let itself in check
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
 
  return flag;      
}

//destuctor
King::~King( ){
}


/**
 * Function to get king_flag
 * @param return true since it is piece of King
 **/
bool King::get_flag_king(){
  return true;
}
