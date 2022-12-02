#ifndef BISHOP_H
#define BISHOP_H
#include"ChessBoard.h"
#include"piece.h"

class Bishop: public Piece {
 public:
  Bishop(string c);
  // bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  //void get_type();
  //type piece_type();
  //ostream& operator<< (Piece* p);
};

#endif
