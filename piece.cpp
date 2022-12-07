#include<iostream>
#include"piece.h"
#include<string>
//#include<cstring>

using namespace std;

/**
 *Constructor
 **/
Piece::Piece(string c) {
  piece_colour = c;
 
}

/**
 *
 **/
std::ostream&  operator<<(std::ostream &out, Piece* p){
  out << p -> piece_colour << "'s " << p -> piece_type;
  return out;
}

string Piece::print_colour(){
  return piece_colour;
 
}

Piece::~Piece(){

}

//White is true
bool Piece:: is_white(){
  
  if(piece_colour == "White") return true; 
  return false;
}

bool Piece::get_flag_king(){
  return false;
}
