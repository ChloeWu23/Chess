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
  
  if (!cb->get_board(src_row,src_col)) return false;

  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent (src_row, src_col, des_row, des_col)) return false;
  
  //first step move two step along the file or move immediate in front of it if not first step
  
  //if move white piece
  if (cb->get_board(src_row,src_col) -> is_white() && cb->get_board(des_row,des_col) == NULL && cb -> is_same_col (src_col,des_col) ) {
    //if it is first step
    if (src_row == 1 && cb -> is_col_clear(src_row, src_col, des_row, des_col) && abs(des_row-src_row) <=2 && (des_row > src_row)) {
      flag = true;	
    }
      //not first step
    if ((des_row - src_row) == 1) flag = true;
  }

    //if move black piece
  if (!cb->get_board(src_row,src_col)-> is_white() && cb->get_board(des_row,des_col) == NULL && cb -> is_same_col (src_col,des_col) ) {
    //if it is first step
    if (src_row == 6 && cb -> is_col_clear(src_row, src_col, des_row, des_col) && abs(des_row-src_row) <=2 && (src_row > des_row)) {
      flag = true;	
    }
      //not first step
    if ((src_row - des_row) == 1) flag = true;
  }
   

  //capture opponents piece which is on the diagonal position on an adjucant file
  //White move upwards on diagonal
  //Note here need destination is not NULL.

  if (cb -> is_opponent(src_row,src_col,des_row,des_col)){
    //white piece
    if (cb->get_board(src_row,src_col) -> is_white()){
      //check position
      if ((des_col-src_col) == 1 && (des_row-src_row) ==1){
	  flag = true;
      }
      if ((des_col-src_col) == -1 && (des_row-src_row) == 1)  {
	flag = true;
      }
    } else { //source is black
      if ((des_col-src_col) == -1 && (des_row-src_row) == -1){
	
	flag =  true;
      }
      if ((des_col-src_col) == 1 && (des_row-src_row) == -1) {
	 
	flag = true;
      }
    }
  }
  
  
  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour)){
      flag = false;
    }
  }
  
  return flag;
}

