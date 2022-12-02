//this is abstract class
#ifndef PIECE_H
#define PIECE_H
//#include"ChessBoard.h"
#include<iostream>
using namespace std;

class ChessBoard;
//enum colour {Black, White};
//enum type {king, castle, bishop, queen, knight, pawn};
class Piece{
  friend class ChessBoard;
  //friend class Pawn;
protected:
  string piece_colour;
  string piece_type;
  bool king_flag;
  //Piece_type p;
  // int piece_count;
public:
  Piece(string c); //default constructor
  virtual bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb) = 0;
  bool get_flag_king();
  //virtual void get_type() = 0;
  string print_colour(); //print the name of enum colour variable
  //virtual type piece_type() = 0;
 friend std::ostream& operator<< (std::ostream& out,Piece* p);
  bool get_colour(); //White returns true;
  
};
#endif
