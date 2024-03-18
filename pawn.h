#ifndef PAWN_H
#define PAWN_H
#include"ChessBoard.h"
#include"piece.h"

class Pawn : public Piece {

public:
  Pawn (string c);
  bool valid_move (int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  virtual ~Pawn();
  bool get_flag_king();
};

#endif
