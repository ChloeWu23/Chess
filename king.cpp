#include<iostream>
#include"king.h"
#include<cmath>
using namespace std;

/*Function definition in Class King*/
/*
King::King(colour _c) : Piece(_c){
}
*/
/* Constructor */
King::King(string c) : Piece(c) {
  piece_type = "King";
  king_flag = 1;
}
/*
void King::get_type(){
  cout << "King" ;
}
type King:: piece_type(){
  return king;
}
*/

/*Function to move piece king*/
/* Note here valid means that it follows rule of its piece and it didnt move t its own piece's position and make its own under in check */
bool King:: valid_move(int src_row, int src_col, int des_row, int des_col, ChessBoard* cb){
  bool flag = false;
  
  //chess_colour is the colour of the chess which is tryna make move, on the source, 1 represents White colour
  //Piece* temp_piece = NULL;
  bool chess_colour = cb->get_board(src_row,src_col) ->get_colour();
  
  //make sure the souece is not empty
  if (!cb->get_board(src_row,src_col)) return false;
 
  //can't move to position where having its own piece
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent (src_row, src_col, des_row, des_col))  return false;
  //destination position is as required 
  if (abs (des_col-src_col) == 1 && cb -> is_same_row(src_row, des_row)) flag = true;
  if (abs (des_row-src_row) == 1 && cb -> is_same_col(src_col,des_col)) flag = true;
  if (abs (des_col-src_col) == 1 && cb -> is_same_diagonal(src_row, src_col, des_row,des_col)) flag = true;
  
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  /*  //try make move
      Piece* temp_piece = cb->get_board(des_row, des_col);
      cb -> make_move (src_row, src_col, des_row, des_col);
      //update king's position
      cb -> update_king_position (des_row, des_col);
      
      int r = chess_colour? cb -> get_wkr() : cb -> get_bkr();
    int c = chess_colour? cb -> get_wkc() : cb -> get_bkc();
    //check whether this move will make itself in check;
    if (cb -> in_check (!chess_colour, r, c)) {
    flag = false;
    //undo the move
    cb -> move_back (src_row,src_col, des_row, des_col, temp_piece);
      //update king's position
      cb -> update_king_position (src_row, src_col);
      }
      }
    */
  return flag;      
}



