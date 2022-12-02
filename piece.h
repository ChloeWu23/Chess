//this is abstract class
#ifndef PIECE_H
#define PIECE_H
//#include"ChessBoard.h"
#include<iostream>
using namespace std;

class ChessBoard;
enum colour {Black, White};
enum type {king, castle, bishop, queen, knight, pawn};
class Piece{
  friend class ChessBoard;
  //friend class Pawn;
protected:
  colour c;
  // Piece_type p;
  // int piece_count;
public:
  Piece(colour _c); //default constructor
  virtual bool valid_move(const char* source, const char* destination, ChessBoard* cb) = 0;
  virtual void get_type() = 0;
   void print_colour(); //print the name of enum colour variable
  virtual type piece_type() = 0;
  ostream& operator<< ( Piece* p) ;
  //void set_count();
  bool get_colour(); //White returns true;
  
};
#endif
