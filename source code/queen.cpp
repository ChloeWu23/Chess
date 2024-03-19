#include<iostream>
#include"queen.h"

using namespace std;

/*Function definition in Class Queen */

//constructor
Queen::Queen(string c) : Piece(c){
  piece_type = "Queen";
}

/**
 * Function to get king_flag
 * @param return false
 **/
bool Queen::get_flag_king(){
  return false;
}

/**
 *Function to see whether it is a valid move for piece Queen from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
**/
bool Queen::valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb){
  bool valid = false;
  bool chess_colour = cb->get_board(src_row,src_col) ->is_white();
  
  //move toward rank
  if(cb -> is_row_clear(src_row, src_col, des_row, des_col))  valid = true;
  
  //move towards file
  if(cb -> is_col_clear(src_row, src_col, des_row, des_col))  valid = true;
  
  //move towards diagonal
  if (cb-> is_diag_clear (src_row, src_col, des_row, des_col)) valid =  true;

  if (valid){
    return cb->is_valid_move(src_row, src_col, des_row, des_col, chess_colour);

  } 
  return false;
}

//destructor
Queen:: ~Queen(){

}

