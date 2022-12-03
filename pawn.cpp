#include<iostream>
#include"pawn.h"
#include"ChessBoard.h"
#include <cmath>
using namespace std;

/*Function definition in Class Pawn*/
Pawn::Pawn(string c) : Piece(c){
  piece_type = "Pawn";
  //king_flag = 0;
}

bool Pawn::get_flag_king(){
  return false;
}
Pawn::~Pawn(){

}

/* Function to move this piece */
bool Pawn::  valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb) {
  
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) ->get_colour();
  
  if (!cb->get_board(src_row,src_col)) return false;
  //cout << "count_pawn:" << count_pawn;
  //make sure can't move to its own piece's destination
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent (src_row, src_col, des_row, des_col)) return false;
  
  //first step move two step along the file
    if (src_row == 1 && cb->get_board(src_row,src_col) -> get_colour()) {
      if (cb -> is_same_col (src_col,des_col) && cb -> is_col_clear(src_row, src_col, des_row, des_col) && abs(src_row-des_row) <= 2 && (cb->get_board(des_row,des_col) == NULL)) {
	//piece_count++;
	flag = true;
      }
    }
    
    if (src_row ==6 && !cb->get_board(src_row,src_col) -> get_colour()) {
      if (cb -> is_same_col(src_col, des_col) && cb -> is_col_clear(src_row, src_col, des_row, des_col) && abs(src_row-des_row) <=2 && (cb->get_board(des_row,des_col) == NULL)) {
	//piece_count++;
      flag = true;
      }
    }
    
 
    //move to the unoccupied square of the same file imediately in front of it
    //white move upwards, black move downwards
    if (cb-> get_board(src_row,src_col) -> get_colour()){
      if(cb ->is_same_col(src_col,des_col) && (des_row - src_row) == 1 && cb -> get_board(des_row,des_col) == NULL){
	//piece_count++;
	flag = true;
      }
  }
    //if it is Black's piece
  if (!cb->get_board(src_row,src_col) -> get_colour()){
    if(cb ->is_same_col(src_col,des_col) && (src_row - des_row) == 1 && cb -> get_board(des_row,des_col) == NULL){
      // piece_count++;
      flag = true;
    }
  }
  
  //capture opponents piece which is on the diagonal position on an adjucant file
  //White move upwards on diagonal
  //Note here need destination is not NULL.
  if (cb ->get_board(des_row,des_col) != NULL){
    //cout << "check" << endl;
    if((cb->get_board(des_row,des_col) -> get_colour() !=  cb->get_board(src_row,src_col) -> get_colour()) && cb -> is_same_diagonal(src_row, src_col, des_row, des_col)){
      //cout << "here1" << endl;
      //source is white
      if (cb->get_board(src_row,src_col) -> get_colour() == 1 ){
	//check position
	if ((des_col-src_col) == 1 && (des_row-src_row) ==1){
	  //cout << "here2" << endl;
	  // piece_count++;
	  flag = true;}
	if ((des_col-src_col) == -1 && (des_row-src_row) == 1)  {
	  //piece_count++;
	  flag = true;
	}
      } else { //source is black
	if ((des_col-src_col) == -1 && (des_row-src_row) == -1){
	  //piece_count++;
	  flag =  true;
	}
	if ((des_col-src_col) == 1 && (des_row-src_row) == -1) {
	  // piece_count++;
	  flag = true;
	}
      }
    }
  }

  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  return flag;
}

/*
void Pawn::get_type(){
    cout << "Pawn";
  }

*/
