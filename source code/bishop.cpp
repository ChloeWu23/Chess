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
  //bool flag = false;

  bool chess_colour = cb->get_board(src_row,src_col) -> is_white();

  if (cb-> is_diag_clear (src_row, src_col, des_row, des_col)){
    return cb -> is_valid_move(src_row, src_col, des_row, des_col, chess_colour);
  }
  return false;

}


//destructor
Bishop::~Bishop(){

}
