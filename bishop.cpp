#include<iostream>
#include"bishop.h"
using namespace std;

/*Function definition in Class Bishop */
/*Constructor*/
Bishop::Bishop(string c) : Piece(c){
  piece_type = "Bishop";
  // king_flag = 0;
}

bool Bishop:: get_flag_king(){
  return false;
}
/*Function to make move for bishop piece*/
bool Bishop::valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb){
  bool flag = false;
  bool chess_colour = cb->get_board(src_row,src_col) ->get_colour();
  
  if (!cb->get_board(src_row,src_col)) return false;
  if (cb -> get_board(des_row,des_col) != NULL && !cb ->is_opponent (src_row, src_col, des_row, des_col))  return false;
  
  if (cb -> is_same_diagonal (src_row, src_col, des_row, des_col) && cb-> is_diag_clear (src_row, src_col, des_row, des_col)) flag = true;

  if (flag == true && cb -> is_capture_king (des_row, des_col, chess_colour)) return true;
  
  if (flag == true){
    if (!cb -> confirm_move(src_row, src_col, des_row, des_col,chess_colour))
      flag = false;
  }
  
  return flag;
}


Bishop::~Bishop(){

}
