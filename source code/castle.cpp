#include<iostream>
#include"piece.h"
#include"castle.h"

using namespace std;

//constructor
Castle::Castle(string c) : Piece(c){
  piece_type = "Castle";
}

//destructor
Castle::~Castle(){

}

/**
 * Function to get king flag
 * return false since its not piece of King.
 **/
bool Castle::get_flag_king(){
  return false;
}


/**
 *Function to see whether it is a valid move for piece Castle from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
 **/

bool Castle:: valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb){
  bool chess_colour = cb->get_board(src_row,src_col) -> is_white();
  
  //if the move either horizotal or vertial and can not leap 
  bool valid = (cb -> is_row_clear(src_row, src_col, des_row, des_col))
              ||(cb -> is_col_clear(src_row, src_col, des_row, des_col));
  
  if (valid){
    return cb->is_valid_move(src_row, src_col, des_row, des_col, chess_colour);
  }

  return false;

    }

