#include<iostream>
#include<cmath>
#include"knight.h"
#include"ChessBoard.h"
using namespace std;

/*Function definition in Class Knight */

//constructor
Knight::Knight(string c) : Piece(c){
  piece_type = "Knight";
}


/**
 * Function to get King_flag
 * @param return false;
 **/
bool Knight::get_flag_king(){
  return false;
}


/**
 *Function to see whether it is a valid move for piece knight from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
**/
bool Knight:: valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb) {
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) -> is_white();
  
  if (!cb->get_board(src_row,src_col)) return false;
  //same colour for destination and source
  if (cb -> get_board(des_row,des_col) &&  cb->get_board(des_row,des_col) -> is_white() == chess_colour ) return false;
  
  //check destination is the closest
  //L-shape
  if(abs(src_row-des_row) == 1 && abs(src_col-des_col) == 2) flag = true;
  if(abs(src_row-des_row) == 2 && abs(src_col-des_col) == 1) flag = true;

   //check whether source can move to destination and destination is king

  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  
  return flag;
}

Knight::~Knight(){

}


