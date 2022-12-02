#include<iostream>
#include<cmath>
#include"knight.h"
#include"ChessBoard.h"
using namespace std;

/*Function definition in Class Knight */
Knight::Knight(colour _c) : Piece(_c){
}
/*
std::ostream& Knight::operator<< (std::ostream& out, Piece* p){
  out << p -> c << " 's Knight ";
  return out;
}
*/
  
bool Knight::valid_move(const char* source, const char* destination, ChessBoard* cb){
  int src_row = source[1]-'1';
  int src_col = source[0]-'A';
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';
  //check moved to position is not same row, column, diagonal
  if (!cb->get_board(src_row,src_col)) return false;
  if (cb -> get_board(des_row,des_col)!=  NULL && !cb ->is_opponent(source,destination)) return false;
  if (!(cb->is_same_row(source, destination)) && !(cb->is_same_col(source, destination)) && !(cb->is_same_diagonal(source, destination)))
    {
      //check destination is the closest
      //L-shape
      if(abs(src_row-des_row) == 1 && abs(src_col-des_col) == 2) return true;
      if(abs(src_row-des_row) == 2 && abs(src_col-des_col) == 1) return true;  
    } 
  return false;
}
 
 void Knight::get_type(){
   cout << "Knight";
 }
 
 type Knight:: piece_type(){
   return knight;
 }

