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
  const char* white_king_position;
  const char* black_king_position;
  bool black_in_check ;
  bool white_in_check ;
  int turn_count;
public:
  //static bool is_in_check;
  // Piece* board[8][8];

  /*Function to get element of the board*/
  Piece* get_board(int r, int c);
  /*Function to check whether it's opponents piece */
  bool is_opponent(const char* source,const char* destination);
  /* Function to make move */
  void submitMove(const char* source, const char* destination);
  /* Function to resetBoard */
  void resetBoard();
  
  /*Function to initialize the board */
  void initialize_board();
  /*Constructor*/
  ChessBoard();
  /* FUnction to check whether source and destination is valid or not */
  bool valid_input(const char* source, const char* destination);
  /* Function to check whether in the same row */
  bool is_same_row(const char* source, const char* destination);
  /*Function to check whether in the same column */
  bool is_same_col(const char* source, const char* destination);
  /*Function to check whether source and destination are diagnal.*/
  bool is_same_diagonal(const char* source, const char* destination);
  
  
  /*Function to check whether its empty for the row between source and destination*/
  bool is_row_clear(const char* source, const char* destination);
  
  /*Function to check whethter its empty for the column between source and destination */
  bool is_col_clear(const char* source, const char* destination);
  
  /*Function to check whether its empty for the diagnol between source and destination */
  
  bool is_diag_clear(const char* source, const char* destination);
  
  /* Function to check whther it is turn to move */
  bool is_turn(const char* source);

  /* Function to make move when valid_move is true */
  void make_move(const char* source, const char* destination);

  /* Function to move_back*/
  void move_back(const char* source, const char* destination, Piece* _temp);

  /* Function to update the King's position */
  void update_king_position(const char* );

  const char* get_black_king_position();
  const char* get_white_king_position();
  /*Function to check after one move, the board is in_check or not*/
   bool in_check (bool _colour, const char* _position);
  /*Functon to check whether it is checkmate */
  bool is_checkmate(bool _colour);

  
};
#endif
