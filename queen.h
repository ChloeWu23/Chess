#ifndef QUEEN_H
#define QUEEN_H
#include"ChessBoard.h"
#include"piece.h"

class Queen: public Piece {
 public:
  Queen(string c);
  //bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  //void get_type();
  //type piece_type();
  bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  
};

#endif
