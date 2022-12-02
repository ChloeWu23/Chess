#include<iostream>
#include"pawn.h"
#include"ChessBoard.h"
#include <cmath>
using namespace std;

/*Function definition in Class Pawn*/
Pawn::Pawn(colour _c) : Piece(_c){
  //piece_count = 0;
}
/*
std::ostream& Pawn::operator<< (std::ostream& out, Piece* p){
  out << p -> c << " 's Pawn ";
  return out;
}
*/
type Pawn::piece_type(){
  return pawn;
}


/*Function to get number of count_pawn
void Pawn::set_count(){
  piece_count -= 1;
}
*/

/* Function to move this piece */
bool Pawn::valid_move(const char* source, const char* destination, ChessBoard* cb){
  int src_row = source[1]-'1';
  int des_row = destination[1]-'1';  
  int src_col = source[0]-'A';
  int des_col = destination[0]-'A';
  if (!cb->get_board(src_row,src_col)) return false;
  //cout << "count_pawn:" << count_pawn;
  //make sure can't move to its own piece's destination
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent(source,destination)) return false;
     //first step move two step along the file
    if (src_row == 1 && cb->get_board(src_row,src_col) -> get_colour()) {
      if (cb -> is_same_col(source,destination) && cb -> is_col_clear(source,destination) && abs(src_row-des_row) <=2 && (cb->get_board(des_row,des_col) == NULL)) {
	//piece_count++;
	return true;
      }
    }
    
    if (src_row ==6 && !cb->get_board(src_row,src_col) -> get_colour()) {
      if (cb -> is_same_col(source,destination) && cb -> is_col_clear(source,destination) && abs(src_row-des_row) <=2 && (cb->get_board(des_row,des_col) == NULL)) {
	//piece_count++;
      return true;
      }
    }
    
 
    //move to the unoccupied square of the same file imediately in front of it
    //white move upwards, black move downwards
    if (cb-> get_board(src_row,src_col) -> get_colour()){
      if(cb ->is_same_col(source,destination) && (des_row - src_row) == 1 && cb -> get_board(des_row,des_col) == NULL){
	//piece_count++;
	return true;
      }
  }
    //if it is Black's piece
  if (!cb->get_board(src_row,src_col) -> get_colour()){
    if(cb ->is_same_col(source,destination) && (src_row - des_row) == 1 && cb -> get_board(des_row,des_col) == NULL){
      // piece_count++;
      return true;
    }
  }
  
  //capture opponents piece which is on the diagonal position on an adjucant file
  //White move upwards on diagonal
  //Note here need destination is not NULL.
  if (cb ->get_board(des_row,des_col) != NULL){
    //cout << "check" << endl;
    if((cb->get_board(des_row,des_col) -> get_colour() !=  cb->get_board(src_row,src_col) -> get_colour()) && cb -> is_same_diagonal(source, destination)){
      //cout << "here1" << endl;
      //source is white
      if (cb->get_board(src_row,src_col) -> get_colour() == 1 ){
	//check position
	if ((des_col-src_col) == 1 && (des_row-src_row) ==1){
	  //cout << "here2" << endl;
	  // piece_count++;
	  return true;}
	if ((des_col-src_col) == -1 && (des_row-src_row) == 1)  {
	  //piece_count++;
	  return true;
	}
      } else { //source is black
	if ((des_col-src_col) == -1 && (des_row-src_row) == -1){
	  //piece_count++;
	  return true;
	}
	if ((des_col-src_col) == 1 && (des_row-src_row) == -1) {
	  // piece_count++;
	  return true;
	}
      }
    }
  }
  return false;
}


void Pawn::get_type(){
    cout << "Pawn";
  }

