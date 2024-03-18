#ifndef BISHOP_H
#define BISHOP_H
#include"ChessBoard.h"
#include"piece.h"

class Bishop: public Piece {
 public:
  Bishop (string c);
  bool valid_move (int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  bool get_flag_king ();
  virtual ~Bishop ();

};

#endif
