#include<iostream>
#include"bishop.h"
using namespace std;

/*Function definition in Class Bishop */

/*Constructor*/
Bishop::Bishop(string c) : Piece(c){
  piece_type = "Bishop";
}

/**
 *Function to get king_flag
 *@param return false 
 **/
bool Bishop:: get_flag_king(){
  return false;
}

/**
 *Function to check whether it is a valid move for bishop piece from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
**/

bool Bishop::valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb){
  bool flag = false;

  bool chess_colour = cb->get_board(src_row,src_col) -> is_white();
  
  //check when destination is not empty it is opponent or not
  if (cb -> get_board(des_row,des_col) != NULL 
  && !cb ->is_opponent (src_row, src_col, des_row, des_col))  return false;

  //move towards diagonal: check diagonal is clear or not
  if (cb-> is_diag_clear (src_row, src_col, des_row, des_col)) flag = true;

  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  
  return flag;
}


//destructor
Bishop::~Bishop(){

}
