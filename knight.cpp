#include<iostream>
#include<cmath>
#include"knight.h"
#include"ChessBoard.h"
using namespace std;

/*Function definition in Class Knight */
Knight::Knight(string c) : Piece(c){
  piece_type = "Knight";
  // king_flag = 0;
}

bool Knight::get_flag_king(){
  return false;
}
/*
std::ostream& Knight::operator<< (std::ostream& out, Piece* p){
  out << p -> c << " 's Knight ";
  return out;
}
*/
  
bool Knight:: valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb) {
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) ->get_colour();
  //check moved to position is not same row, column, diagonal
  if (!cb->get_board(src_row,src_col)) return false;
  if (cb -> get_board(des_row,des_col) &&  cb->get_board(des_row,des_col) -> get_colour() == chess_colour ) return false;
  
      //check destination is the closest
      //L-shape
  if(abs(src_row-des_row) == 1 && abs(src_col-des_col) == 2) flag = true;
  if(abs(src_row-des_row) == 2 && abs(src_col-des_col) == 1) flag = true;

   //sourc can move to destination and destination is king
  /* 
if (flag == true && cb -> get_board(des_row,des_col) != NULL && cb -> get_board(des_row,des_col) ->  get_colour() != chess_colour && cb->get_board(des_row,des_col) -> get_flag_king())  {return true;}
*/

  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  
  return flag;
}

Knight::~Knight(){

}
/*
 void Knight::get_type(){
   cout << "Knight";
 }
 
 type Knight:: piece_type(){
   return knight;
 }
*/

