#ifndef KNIGHT_H
#define KNIGHT_H

#include"piece.h"

class Knight: public Piece {
 public:
  Knight(string c);
  //  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  //void get_type();
  //type piece_type();
  bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
 
};

#endif
