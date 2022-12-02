#ifndef KNIGHT_H
#define KNIGHT_H

#include"piece.h"

class Knight: public Piece {
 public:
  Knight(colour _c);
  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  void get_type();
  type piece_type();
  //std::ostream& operator<< (std::ostream& out, Piece* p);
};

#endif
