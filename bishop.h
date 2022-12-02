#ifndef BISHOP_H
#define BISHOP_H
#include"ChessBoard.h"
#include"piece.h"

class Bishop: public Piece {
 public:
  Bishop(colour _c);
  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  void get_type();
  type piece_type();
  //ostream& operator<< (Piece* p);
};

#endif
