#ifndef CASTLE_H
#define CASTLE_H
#include"ChessBoard.h"
#include"piece.h"
class Castle : public Piece{
public:
  //constructor
  Castle(colour _c);
  bool valid_move(const char* source, const char* destination, ChessBoard* cb);
  void get_type();
  type piece_type();
  //ostream& operator<< (Piece* p);
};

#endif
