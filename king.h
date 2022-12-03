#ifndef KING_H
#define KING_H
#include "piece.h"
#include "ChessBoard.h"


class King : public Piece {
private:
  //bool king_flag;
  // bool valid_move(const char* source, const char* destination, ChessBoard* cb);
public:
  //constructor
   ~King();
  King(string c);
  //void get_type();
  //type piece_type();
  bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  bool get_flag_king();
  //ostream& operator<< (Piece* p);
};

#endif
