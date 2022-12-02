#ifndef KING_H
#define KING_H
#include "piece.h"
#include "ChessBoard.h"


class King : public Piece {
private:
  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
public:
  //constructor
  King(colour _c);
  void get_type();
  type piece_type();
  //ostream& operator<< (Piece* p);
};

#endif
