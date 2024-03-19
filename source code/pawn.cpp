#include<iostream>
#include"pawn.h"
#include"ChessBoard.h"
#include <cmath>
using namespace std;

/*Function definition in Class Pawn*/

//constructor
Pawn::Pawn(string c) : Piece(c){
  piece_type = "Pawn";
}

/**
 * Functiont to get king_flag
 *@param return false
 **/
bool Pawn::get_flag_king(){
  return false;
}

//destructor
Pawn::~Pawn(){

}

/**
 *Function to see whether it is a valid move for piece pawn from source to destination
 *@param src_row: integer of row numbers of the source Chess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true it is a valid move
**/
bool Pawn::  valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb) {
  
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) -> is_white ();
  int direction = chess_colour? 1 : -1; //white moves up and black moves down
  
  if (cb -> get_board(des_row,des_col) != NULL 
      && !cb ->is_opponent (src_row, src_col, des_row, des_col)) return false;
  
  //Forward move
  if(src_col == des_col){
    //single step forward
    if (!cb -> get_board(des_row, des_col) && (des_row - src_row) == direction){
      flag = true;
    }
    //intial double step forward
    int initialRow = chess_colour ? 1: 6;
    if (src_row == initialRow && !cb -> get_board(des_row, des_col)
        && des_row - src_row == 2* direction
        && cb -> is_col_clear(src_row, src_col, des_row, des_col)){
          flag = true;
    }
  }

  //Diagnal Capture
  if (abs(des_col-src_col) == 1 && des_row - src_row == direction
      && cb -> is_opponent(src_row, src_col, des_row, des_col)){
        flag = true;
      }
  
  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour)){
      flag = false;
    }
  }
  
  return flag;
}

