#include<iostream>
#include"ChessBoard.h"
#include<cmath>
#include<cstring>
using namespace std;

/*Function defination */

/**
 *Function to initialize the board 
**/
void ChessBoard::initialize_board(){
  cout << "A new chess game is started!" << endl;
  board[0][0] = new Castle("White");
  board[0][1] = new Knight("White");
  board[0][2] = new Bishop("White");
  board[0][3] = new Queen("White");
  board[0][4] = new King("White");
  board[0][5] = new Bishop("White");
  board[0][6] = new Knight("White");
  board[0][7] = new Castle("White");
  
  for(int j = 0; j < 8; j++){
    board[1][j] = new Pawn("White");
  }
  
  for(int j = 0; j < 8; j++){
    board[6][j] = new Pawn("Black");
    
  }
  
  board[7][0] = new Castle("Black");
  board[7][1] = new Knight("Black");
  board[7][2] = new Bishop("Black");
  board[7][3] = new Queen("Black");
  board[7][4] = new King("Black");
  board[7][5] = new Bishop("Black");
  board[7][6] = new Knight("Black");
  board[7][7] = new Castle("Black");
  
  for(int i = 2; i < 6; i++){
    for(int j = 0; j < 8; j++){
      board[i][j] = NULL;
    }
  }
  
}

//===========================================================================
//-----------------------print Board()--------------------------------------
/**
 * Function to print out the current chessboard
 **/
void ChessBoard::print_board(){
  for (char c = 'A'; c <= 'H'; c++){
    if (c == 'A') cout << "   ";
    cout << c <<"   " << "  |";}
    cout<< endl;
    for (int i = 7 ; i >= 0; i--){
      cout << i+1 << "  ";
    for (int j = 0; j < 8; j++){
     
      if (board[i][j])
	cout << board[i][j] -> piece_colour[0] << " " << board[i][j]->piece_type[0] << board[i][j] -> piece_type[1] << "  |";
      else cout << "NULL" <<"  |";
    }
    cout << endl;
  }

}




//===========================================================================
//-----------------------Constructor-----------------------------------------
/**
 *Constructor of ChessBoard 
**/
ChessBoard::ChessBoard(){
  initialize_board();
  white_king_row = 0;
  white_king_col = 4;
  black_king_row = 7;
  black_king_col = 4;
  turn_count = 0;
}

//============================================================================
//---------------------------------- Destructor------------------------------
/** 
 *Destructor of ChessBoard 
**/
ChessBoard::~ChessBoard(){
  for (int row = 0; row < 8; row++){
    for (int col = 0; col < 8; col++){
      if (board[row][col]) {
	delete board[row][col];
	board[row][col] = NULL;
      }
    }

  }

}

//============================================================================
//------------------------resetboard()-----------------------------------------
/** 
 *Function to reset the board 
**/
void ChessBoard::resetBoard(){
  initialize_board();
  turn_count = 0;
  white_king_row = 0;
  white_king_col = 4;
  black_king_row = 7;
  black_king_col = 4;
}


//============================================================================
//------------------get_board()-----------------------------------------
/**
 *Function to get element of the board
 *@param r: integer of row mumbers on the board
 *@param c: integer of column numbers on the board
 *@param return: return pointer to a instance of Piece class which on the position (r,c) on the board 
*/
Piece* ChessBoard::get_board(int r, int c){
  return board[r][c];

}


//===========================================================================
/**
 *Function to check destination and source in the same row
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param return: return true if position of souece and destination on the same row 
**/
bool ChessBoard::is_same_row (int src_row, int des_row){
  //int src_row = source[1]-'1';
  //int des_row = destination[1]-'1';
  if (src_row == des_row) return true;
  
  return false;
}


//===========================================================================
//--------------------is_same_col-------------------------------------

/**Function to check destination and source in the same column 
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece.
 *@param return: return true if position of souece and destination on the same column 
**/
bool ChessBoard::is_same_col (int src_col,int des_col){
    if (des_col == src_col) return true;
  
  return false;
}

//===========================================================================
//----------------------is_same_diagonal-----------------------------
/**
 *Function to check whether source and destination are diagnal.
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true if position of souece and destination on the same diagonal 
**/
bool ChessBoard::is_same_diagonal (int src_row, int src_col, int des_row, int des_col){
 
  if ((src_row - des_row) == (src_col - des_col)) return true;
  if (abs(src_row - des_row) == abs(src_col - des_col) && signbit(src_row - des_row) !=signbit(src_col - des_col)) return true; 
  
  return false;
  
}


//===========================================================================
//-------------------------is_row_clear()
/**
 *Function to check whether its empty for the row between source and destination
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true if there are no piece between source and destination
**/
bool ChessBoard:: is_row_clear (int src_row, int src_col, int des_row, int des_col){
  bool flag = true;
 
  if (is_same_row (src_row,des_row)){
    int x,y;
    
    x = (src_col <= des_col) ? src_col : des_col;
    y = (src_col <= des_col) ? des_col : src_col;
    
    for (int i= x+1; i < y ; i++)
      {
	if (board[src_row][i] != NULL) flag = false; 
      }
    
    if (flag == true) return true;
  }
  
  return false; 
}



//======================================================================
//------------------is_col_clear()-------------------------

/**
 *Function to check whethter its empty for the column between source and destination 
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true if there are no piece between source and destination,else return false
 **/
bool ChessBoard:: is_col_clear (int src_row, int src_col, int des_row, int des_col) {
  bool flag = true;
  
  if (is_same_col(src_col, des_col)){
    int x,y; //x save small number of row
    
    x = (src_row <= des_row) ? src_row : des_row;
    y = (src_row <= des_row) ? des_row : src_row;
    
    for (int i= x+1; i <  y ; i++)
      {
	if (board[i][src_col] != NULL) flag = false; 
      }
    
    if (flag == true) return true;
  }
  return false; 
  
}

//===============================================================
/**
 *Function to check whether its empty for the diagnol between source and destination 
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true if there are no piece between source and destination,else return false.
 **/
bool ChessBoard::is_diag_clear(int startx, int starty, int endx, int endy){
  
  int numSteps = abs(endx - startx)-1; 
  int xdir = (endx > startx) ? 1 : -1;
  int ydir = (endy > starty) ? 1 : -1;
  for (int i = 0; i< numSteps; i++)
    {
      startx += xdir;
      starty += ydir;
      
      if (board[startx][starty] != NULL) {
	return false;
      }
    }  
  return true;
}


//===============================================================
//--------------------------Submitmove() ------------------------
/**
 *Function to make move of the piece
 *@param source: pointer to a constant array of characters which is the source position  of the ChessPiece you want to move
 *@param destiantion: pointer to a constant array of characters which is the destinaiton position you want to move to/
**/
void ChessBoard::submitMove(const char* source, const char* destination){
  turn_count++;
  int  src_row = source[1]-'1'; //decimal for row of source, from 0 to 7
  int  src_col = source[0]-'A';//decimal for column of source, from 0 to 7
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';

  
  //check valid input
  if (!valid_input(src_row,src_col,des_row, des_col)){
    turn_count--;
    cout << "It is not valid input of source or destination position" << endl;
    return;
  }
  
  //check source is empty or not
  if (board[src_row][src_col] == NULL){
    cout << "There is no piece at position " << source <<"!" << endl;
    turn_count--;
    return;
  }
 
  //check whether it is this piece's turn to move  
  if (!is_turn(src_row, src_col)) {
    cout << "It is not "
	 << board[src_row][src_col]->print_colour()
         <<"'s turn to move." << endl;
    turn_count--;
    return ;
  }

  
  //check whether it is a valid move
  bool valid = board[src_row][src_col] -> valid_move(src_row, src_col, des_row, des_col,this);
  if (!valid) {
    cout << board[src_row][src_col]
         <<  " can not moves to "
	 << destination << "!" << endl;
    turn_count--;
    return ;
  }
  
  //if it is a valid move from source to destination and we can actually make move from here
  cout << board[src_row][src_col]
       << " moves from "
       << source << " to " << destination;
  //destination is not null we can take piece
  if (board[des_row][des_col]){
    cout << " taking "
	 << board[des_row][des_col];
  }
   
  cout << endl;

  //after print out setence we need, we can make move here
  make_move (src_row, src_col, des_row, des_col);
  //update king's position
  update_king_position(des_row, des_col);
  
  //Document the color of its moving piece, is_white() returns 1 for White 0 for Black;
  bool colour_chess = board[des_row][des_col] ->is_white(); //save its own colour, colour_chess is 1 if White
  
  //position now document it's opponents's king's position
  //position = colour_chess? black_king_position: white_king_position;
  int now_king_row = colour_chess? black_king_row : white_king_row;
  int now_king_col = colour_chess? black_king_col : white_king_col;
 
  if (in_check(colour_chess,now_king_row, now_king_col)){
    if (!AnyPossibleMove (!colour_chess)){
      //in_check but not checkmate
      cout << ((colour_chess) ?  "Black" : "White" )
	   << " is in checkmate" << endl;
    } else {
      //check_mate
      cout << ((colour_chess) ? "Black" : "White")
	   << " is in check" << endl;
    } 
  }
  else {
    if (!AnyPossibleMove (!colour_chess))
      cout << ((colour_chess) ?  "Black" : "White" )
	   << " is in stalemate" << endl;
  }
  return;
}


//==========================================================================
//-----------------------in_check()----------------------------------------

/**Function check status of whether in_check
  *@param colour : bool value which true stands for white, false for black.
  *@param king_row: integer of row numbers of King which in different colour
  *param king_col: integer of column numbers of King which is different colour from  @param colour
  *@return true if king is in check
**/
bool ChessBoard::in_check (bool colour, int king_row, int king_col){
  /**
   Algorithm: for each piece with same colour as input try whether it can move to king's position
   **/
  for (int i = 0; i <= 7; i++){
    for (int j = 0; j <= 7; j++){
     
      if (board[i][j] != NULL && board[i][j] -> is_white() == colour){

	if (board[i][j] ->valid_move(i,j, king_row,king_col,this)) return true;
      }
    }
  }
  return false;
}



//===========================================================================
//---------------------AnyPossibleMove()----------------------------------------
/**
 *Function to check out whether it is in checkmate state
 *@param colour is the bool variable and stands for colour of piece which you need to check whther it is in checkmate or not, true stands for white colour, false stands for black colour.
 *@return true if there is a possible move to save it from in check state; else return false
 **/
 bool ChessBoard::AnyPossibleMove (bool colour){
   /**
      Algorithm: We know it is already in check and see whether can be saved by moving a piece.Run all the positions for source on the board for its opponents's piece to all the position on the board and see whether there is a valid move to make it's opponent not in check, if it is which means we can make possible move and the board won't get checkmate state
 **/
   bool flag = false;
   for (int src_row = 0 ; src_row < 8; src_row++) {
     for (int src_col = 0 ; src_col < 8; src_col++) {
       for (int des_row = 0; des_row < 8; des_row++) {
	 for (int des_col = 0; des_col < 8; des_col++) { 
	   if ((board[src_row][src_col]!= NULL) && board[src_row][src_col]-> is_white()  == colour && board[src_row][src_col] -> valid_move(src_row,src_col,des_row,des_col,this)) {
	     
	     flag= true;
	     
	   }
	 }
       }
     }
   }
   
   return flag;
 }



//===========================================================================
//--------------------------is_turn()----------------------------------------
/**
 *Function to check whether it is white or black;s turn to move
 *@param src_row: integer of number of rows of the source position
 *@param src_col: integer of number of columns of the source position
 *@param return: return true if it is this source's piece's turn to move
 **/
bool ChessBoard::is_turn(int src_row, int src_col){
  bool flag = false;
  //white moves first
  if (turn_count%2 == 1 && board[src_row][src_col] -> is_white() )
    flag = true;
  if (turn_count%2 == 0 && !board[src_row][src_col] -> is_white() )
    flag = true;
  
  return flag;

}


//=========================================================================
//------------------------is_opponent()------------------------------------

/**Function to check whether it's opponents piece
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: true if both positions have pieces and have diferent colour
 */
bool ChessBoard::is_opponent (int src_row, int src_col, int des_row, int des_col){
  if (board[src_row][src_col] != NULL && board[des_row][des_col] != NULL)
    {
      if (board[src_row][src_col] -> is_white() !=  board[des_row][des_col] -> is_white()) return true; 
    }
  return false;
}



//============================================================================
//-----------------------------make_move()-----------------------------------
/**
 *Function to move piece from source position to destination and set source to be empty
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 **/
void ChessBoard::make_move (int src_row, int src_col, int des_row, int des_col){
 
  board[des_row][des_col] = board[src_row][src_col];
  board[src_row][src_col] = NULL;
}



//===========================================================================
//---------------------move_back()---------------------------------------
/**
 *Function to move ChessPiece back from destination to source and put temp Piece on the destination
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param temp: a pointer to an instance of Piece
 **/
void ChessBoard:: move_back (int src_row, int src_col, int des_row, int des_col, Piece* temp){
  
  board[src_row][src_col] = board[des_row][des_col];
  board[des_row][des_col] = temp;
}



//===========================================================================
//-------------------------valid_input()--------------------------------------
/**
 *Function to check whtehr it is a valid input for both source and destination position
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return true if both input of source and destination are valid.
 **/
bool ChessBoard::valid_input(int src_row, int src_col, int des_row, int des_col){
  if (src_row >= 0 && src_row < 8 && src_col >= 0 && src_col < 8 && des_row >= 0 && src_row < 8 && des_col >= 0 && des_col < 8) return true;
  
  return false;
}


//============================================================================
//-------------------------update_king_position()----------------------------
/**
 *Function to update King's position if we move King
 *@param des_row: integer of row numbers of the destination which we moved Chess Piece to.
 *@param des_col: integer of column numbers of the destiantion 
 **/
void ChessBoard::update_king_position (int des_row, int des_col){
  bool colour_chess = board[des_row][des_col] -> is_white();//white is 1
  if (board[des_row][des_col] -> get_flag_king()){ // it returns true if it is king
    if (colour_chess) {
      white_king_row = des_row;
      white_king_col = des_col;}
    else {
      black_king_row = des_row;
      black_king_col = des_col;
    }
  }
}


//===========================================================================
//--------------------Function to confirm move-------------------------------
/**
 *Function to check it won't make itself in check after move
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: returns true if this move won't make itself in check
 **/
bool ChessBoard::confirm_move (int src_row, int src_col, int des_row, int des_col, bool chess_colour){
  bool flag = true;
  Piece* temp_piece = board[des_row][des_col];
  //try make move
  make_move (src_row, src_col, des_row, des_col);
  //update king's position
  update_king_position (des_row, des_col);
  
  // r,c document its own king's position
  int r = chess_colour? white_king_row : black_king_row;
  int c = chess_colour? white_king_col : black_king_col;
  //check whether this move will make itself in check;
  //If it let itself in check then we have to move back

  if (in_check (!chess_colour, r, c)) {
    flag = false;
  }
  //undo the move
  move_back (src_row,src_col, des_row, des_col, temp_piece);
  //update king's position
  update_king_position (src_row, src_col);
  return flag;
}

//-------------------------------------------------------------------------------
//--------------------- is_capture_king() ----------------------------------------
/**
 *Function to check whether the destination piece you captured is King or not.
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param chess_colour: bool variable which stands for the colour of moving piece of the source, true stands for white, false stands for black.
 *@param return true if it capture capture King
 **/

//Note here chess_colour is the colour of moving piece from source
bool ChessBoard:: is_capture_king(int des_row, int des_col, bool chess_colour){
  if ( board[des_row][des_col] != NULL && board[des_row][des_col] -> is_white() != chess_colour && board[des_row][des_col] -> get_flag_king()) return true;
  return false;
}
