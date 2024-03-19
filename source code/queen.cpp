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
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) ->is_white();
  
  if (cb -> get_board(des_row,des_col) !=NULL && !cb ->is_opponent(src_row, src_col, des_row, des_col)) return false;
  
  //move toward rank
  if(cb -> is_row_clear(src_row, src_col, des_row, des_col))  flag = true;
  
  //move towards file
  if(cb -> is_col_clear(src_row, src_col, des_row, des_col))  flag = true;
  
  //move towards diagonal
  if (cb-> is_diag_clear (src_row, src_col, des_row, des_col)) flag =  true;

  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  
  return flag;
}

//destructor
Queen:: ~Queen(){

}

