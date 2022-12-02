#ifndef QUEEN_H
#define QUEEN_H
#include"ChessBoard.h"
#include"piece.h"

class Queen: public Piece {
 public:
  Queen(colour _c);
  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  void get_type();
  type piece_type();
  // std::ostream& operator<< (std::ostream& out, Piece* p);
};

#endif
