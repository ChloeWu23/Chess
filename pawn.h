#ifndef PAWN_H
#define PAWN_H
#include"ChessBoard.h"
#include"piece.h"

class Pawn : public Piece {

public:
  Pawn(colour _c);
  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  void get_type();
  type piece_type();
  void set_count();
  //std::ostream& operator<< (std::ostream& out, Piece* p);
  //static int count_pawn;
};

#endif
