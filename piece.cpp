#include<iostream>
#include"piece.h"
#include<string>
#include<cstring>
#include<cassert>
using namespace std;
/*Function definition in Class Piece*/
/*
Piece::Piece(colour _c) {
  c = _c;
}
*/
Piece::Piece(string c) {
  piece_colour = c;
  king_flag = 0;
}

bool Piece::get_flag_king(){
  return king_flag;
}

std::ostream&  operator<<(std::ostream &out, Piece* p){
  out << p -> piece_colour << " 's " << p -> piece_type;
  return out;
}

string Piece::print_colour(){
  return piece_colour;
 
}


//White is true
bool Piece:: get_colour(){
  //cout << "check"<< endl;
  // if(piece_colour == "White") return true;
  //assert(this);
  if(!piece_colour.compare("White")) return true; 
  return false;
}
