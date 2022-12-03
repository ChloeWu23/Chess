/* Class Declaration For Chess Play */
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"castle.h"
#include"bishop.h"
#include"pawn.h"
#include"piece.h"
#include"queen.h"
#include"knight.h"
#include"king.h"
/*
  ChessBoard class
*/
class ChessBoard {
  // friend class Piece;:
private:
  Piece* board[8][8];
  int turn_count;
  int white_king_row;
  int white_king_col;
  int black_king_row;
  int black_king_col;
  
public:
  void print_board();
  /*Function to get element of the board*/
  Piece* get_board(int r, int c);
  /*Function to check whether it's opponents piece */
  // bool is_opponent(const char* source,const char* destination);
  bool is_opponent(int src_row, int src_col, int des_row, int des_col);
  /* Function to make move */
  void submitMove(const char* source, const char* destination);
  /* Function to resetBoard */
  void resetBoard();
  
  /*Function to initialize the board */
  void initialize_board();
  /*Constructor*/
  ChessBoard();
  /* FUnction to check whether source and destination is valid or not */
  //bool valid_input(const char* source, const char* destination);
  bool valid_input (int src_row, int src_col, int des_row, int des_col);
  /* Function to check whether in the same row */
  //bool is_same_row(const char* source, const char* destination);
  bool is_same_row(int src_row, int des_row);
  /*Function to check whether in the same column */
  // bool is_same_col(const char* source, const char* destination);
  bool is_same_col(int src_col, int des_col);
  /*Function to check whether source and destination are diagnal.*/
  // bool is_same_diagonal(const char* source, const char* destination);
  bool is_same_diagonal (int src_row, int src_col, int des_row, int des_col);
  
  /*Function to check whether its empty for the row between source and destination*/
  //bool is_row_clear(const char* source, const char* destination);
  bool is_row_clear (int src_row, int src_col, int des_row, int des_col);
  /*Function to check whethter its empty for the column between source and destination */
  //bool is_col_clear(const char* source, const char* destination);
  bool is_col_clear(int src_row, int src_col, int des_row, int des_col);
  /*Function to check whether its empty for the diagnol between source and destination */
  // bool is_diag_clear(const char* source, const char* destination);
  bool is_diag_clear (int src_row, int src_col, int des_row, int des_col);
  /* Function to check whther it is turn to move */
  // bool is_turn(const char* source);
  bool is_turn (int src_row, int src_col);
  /* Function to make move when valid_move is true */
  //void make_move(const char* source, const char* destination);
  void make_move(int src_row, int src_col, int des_row, int des_col);
  /* Function to move_back*/
  // void move_back(const char* source, const char* destination, Piece* _temp);
  void move_back (int src_row, int src_col, int des_row, int des_col, Piece* _temp);
  /* Function to update the King's position */
  void update_king_position(int des_row, int des_col);

  /*Function to confirm we can actually make a move */
  bool confirm_move(int src_row, int src_col, int des_row, int des_col, bool chess_colour);
  //const char* get_black_king_position();
  //int get_bkr (); //get black king row
  //int get_bkc (); //get black king column
  //int get_wkr ();
  //int get_wkc ();
  
  //const char* get_white_king_position();
  /*Function to check after one move, the board is in_check or not*/
  bool in_check (bool colour, int king_row, int king_col);
  /*Functon to check whether it is checkmate */
  bool is_checkmate(bool colour);
  /*Function to check whether it is statemate */
  bool is_stalemate(bool colour);
  
  /* Destructor */
   ~ChessBoard();
 
};
#endif
