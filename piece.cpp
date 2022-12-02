#include<iostream>
#include"piece.h"
using namespace std;
/*Function definition in Class Piece*/

Piece::Piece(colour _c) {
  c = _c;
}
/*
ostream& Piece:: operator<<(Piece* p){
  return p->c;
}
*/
void Piece::print_colour(){
  
  switch(c){
  case Black: cout << "Black"; break;
  case White: cout << "White"; break;
  }
 
}
//White is true
bool Piece:: get_colour(){
  //cout << "check"<< endl;
  if(c == White) return true;
  return false;
}
