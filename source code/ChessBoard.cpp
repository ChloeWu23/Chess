#include<iostream>
#include"ChessBoard.h"
#include<cmath>
#include<cstring>
using namespace std;

/*Function defination */

/**
 *Function to initialize the board
**/
/* Note that: for each cell on the board holds a pointer to piece.
*/
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
      board[i][j] = nullptr;
    }
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
	  board[row][col] = nullptr; //note better to set deleted points to NULL
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
//--------------------------is_turn()----------------------------------------
/**
 *Function to check whether it is white or black's turn to move
 *@param src_row: integer of number of rows of the source position
 *@param src_col: integer of number of columns of the source position
 *@param return: return true if it is this source's piece's turn to move
 **/
bool ChessBoard::is_turn(int src_row, int src_col){
  //check if the piece at given position matches its turn
  //white moves first, and turn_count is 0 initially.
  //white's turn
  if (turn_count%2 == 0 && board[src_row][src_col] -> is_white()){
    return true;
  }
    
  //black's turn
  if (turn_count%2 == 1 && !board[src_row][src_col] -> is_white() )
    return true;
  
  return false;
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
  if (src_row >= 0 && src_row < 8 && src_col >= 0 && src_col < 8 
      && des_row >= 0 && src_row < 8 && des_col >= 0 && des_col < 8){
      return true;
  }
  
  return false;
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
  if (board[src_row][src_col] && board[des_row][des_col])
    {
      if (board[src_row][src_col] -> is_white() !=  board[des_row][des_col] -> is_white()) return true; 
    }
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
  
  return abs(src_row - des_row) == abs(src_col - des_col);
  
}


//===========================================================================
//-------------------------is_row_clear()
/**
 *Function to check whether all cells between des and source which are in the same row are empty or not
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param return: return true if there are no piece between source and destination
**/
bool ChessBoard:: is_row_clear (int src_row, int src_col, int des_row, int des_col){
  //ensure the check is only performed if des and src are on the same row
  if (src_row != des_row){
    return false;
  }
  
  int start = min(src_col, des_col) + 1; //start index for need checked cell
  int end = max(src_col, des_col); 
  
  for (int i= start; i < end; i++)
    {
      if (board[src_row][i] != nullptr) return false; 
    }
  
  return true; 
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
    if (src_col != des_col){
      return false;
    }
  
  int start,end; 
  
  start = min(src_row, des_row) + 1;
  end = max(src_row, des_row);
  for (int i= start; i <  end ; i++)
    {
      if (board[i][src_col] != nullptr) return false; 
    }
  
  return true; 
  
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
  //first check whether it is same dignal, if not no need check further
  if (is_same_diagonal(startx,starty,endx,endy) == false){
    return false;
  }

  int numSteps = abs(endx - startx); 
  int row_dir = (endx > startx) ? 1 : -1;
  int col_dir = (endy > starty) ? 1 : -1;

  for (int i = 1; i< numSteps; i++)
    {
      int cur_row = startx + i*row_dir;
      int cur_col = starty+ i*col_dir;
	  
      if (board[cur_row][cur_col] != nullptr) {
	        return false;
      }
    }

  return true; //no piece found in the way
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
  board[src_row][src_col] = nullptr;
}


//===========================================================================
//---------------------move_back()---------------------------------------
/**
 *Function to move ChessPiece back from destination to source and put its original piece on the destination
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param temp: a pointer to an instance of Piece; it is record of piece previously on des
 **/
void ChessBoard:: move_back (int src_row, int src_col, int des_row, int des_col, Piece* temp){
  
  board[src_row][src_col] = board[des_row][des_col];
  board[des_row][des_col] = temp;
}


//============================================================================
//-------------------------update_king_position()----------------------------
/**
 *Function to update King's position if we move King
 *@param des_row: integer of row numbers of the destination which we moved Chess Piece to.
 *@param des_col: integer of column numbers of the destiantion 
 **/

void ChessBoard::update_king_position (int des_row, int des_col){
  bool is_white_chess = board[des_row][des_col] -> is_white();

  //check whether we are moving king or not
  //note that this function works after we call make_move
  if (board[des_row][des_col] -> get_flag_king()){ // it returns true if it is king
    if (is_white_chess) {
      white_king_row = des_row;
      white_king_col = des_col;}
    else { //moving black king
      black_king_row = des_row;
      black_king_col = des_col;
    }
  }
}


//-------------------------------------------------------------------------------
//--------------------- is_capture_king() ----------------------------------------
/**
 *Function to check whether the destination piece you captured is King of the opponent's
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param is_white_chess: bool variable which stands for the colour of moving piece is white or not
 *@param return true if it capture capture King
 **/

//Note here chess_colour is the colour of moving piece from source
bool ChessBoard:: is_capture_king(int des_row, int des_col, bool is_white_chess){
  if ( board[des_row][des_col] != nullptr 
  && board[des_row][des_col] -> is_white() != is_white_chess 
  && board[des_row][des_col] -> get_flag_king()) return true;
  return false;
}


//==========================================================================
//-----------------------in_check()----------------------------------------

/** Function check whether the color of king provided in_check
  *@param opponent_colour : bool value which stands for color different from king
  *@param king_row: integer of row numbers of King which in different colour
  *param king_col: integer of column numbers of King which is different colour from  @param colour
  *@return true if king is in check
**/

bool ChessBoard::in_check (bool opponent_color, int king_row, int king_col){
  /**
   Algorithm: Brute -Force
   Itterate each piece with same color as colour and still on board and check whether it can
   attack this king's position
   **/
  for (int i = 0; i <= 7; i++){
    for (int j = 0; j <= 7; j++){
     //each non-empty piece with same color as input and check whether it can attack this king
      if (board[i][j] != nullptr && board[i][j] -> is_white() == opponent_color){
	      if (board[i][j] ->valid_move(i,j, king_row,king_col,this)) return true;
      }     
    }
  }
  return false;
}


//===========================================================================
//--------------------Function to confirm move-------------------------------
/**
 *Function to check it won't make itself in check after move
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param is_white: bool variable to record the colour of the moving piece. true stands for white
 *@param return: returns true if this move won't make itself in check
 **/

bool ChessBoard::confirm_move (int src_row, int src_col, int des_row, int des_col, bool is_white){
  Piece* temp_piece = board[des_row][des_col]; //record des piece in case moving back
  
  //make potential move
  make_move (src_row, src_col, des_row, des_col);
  //update king's position
  update_king_position (des_row, des_col);
  
  // king_r,king_c document its own king's position
  int king_r = is_white? white_king_row : black_king_row;
  int king_c = is_white? white_king_col : black_king_col;

  //check whether this move will make itself in check and 
  //If it let itself in check then we can not confirm this move
  bool inCheck = in_check (!is_white, king_r, king_c);

  //undo the move we only need to know whether this move is valid or not, no need to really move it
  move_back (src_row,src_col, des_row, des_col, temp_piece);
  //update king's position
  update_king_position (src_row, src_col);

  return !inCheck;
}

//===========================================================================
//--------------------Function to check valid move-------------------------------
/**
 *Function to check it won't make itself in check after move
 *@param src_row: integer of row numbers of the source CHess Piece
 *@param des_row: integer of row numbers of the destiantion Chess Piece.
 *@param src_col: integer of column numbers of the source CHess Piece
 *@param des_col: integer of column numbers of the destiantion Chess Piece
 *@param chess_color: bool variable to record the colour of the moving piece. true stands for white
 *@param return: returns true if it is valid
 **/

bool ChessBoard::is_valid_move(int src_row, int src_col, int des_row, int des_col, bool chess_colour) {
    
    // Check for a piece at the destination that is not an opponent
    if (get_board(des_row, des_col)  && !is_opponent(src_row, src_col, des_row, des_col)) {
        return false;
    }

    // Check if the move captures the opponent's king, which could be a winning condition
    if (is_capture_king(des_row, des_col, chess_colour)) {
        return true; // Move is valid as it captures the king
    }

    // Check if the move puts the player's own king in check
    if (!confirm_move(src_row, src_col, des_row, des_col, chess_colour)) {
        return false;
    }
    return true; // Passed all checks
}


//===========================================================================
//---------------------AnyPossibleMove()----------------------------------------
/**
 *Function to check out whether the given color piece can make further move
 *@param is_white is the bool variable and stands for colour of piece which you need to check whether 
 it can make any further move
 *@return true if there is a possible to move; else return false
 **/

 bool ChessBoard::AnyPossibleMove (bool is_white){
   /**
      Algorithm: Brute-Force
      Iterate all the positions for source and destination on the board 
      and see whether there is a valid move to make from source to des
  **/
   for (int src_row = 0 ; src_row < 8; src_row++) {
     for (int src_col = 0 ; src_col < 8; src_col++) {
       for (int des_row = 0; des_row < 8; des_row++) {
	        for (int des_col = 0; des_col < 8; des_col++) { 
	            if ((board[src_row][src_col]!= nullptr) 
              && board[src_row][src_col]-> is_white()  == is_white 
              && board[src_row][src_col] -> valid_move(src_row,src_col,des_row,des_col,this)) 
              {
                return true;
	            }
	          }
          }
        }
      }  
    return false;
 }

//===============================================================
//--------------------------Submitmove() ------------------------
/**
 *Function to make move of the piece
 *@param source: pointer to a constant array of characters which is the source position  of the ChessPiece you want to move
 *@param destiantion: pointer to a constant array of characters which is the destinaiton position you want to move to/
**/
void ChessBoard::submitMove(const char* source, const char* destination){
  
  int  src_row = source[1]-'1'; //decimal for row of source, from 0 to 7
  int  src_col = source[0]-'A';//decimal for column of source, from 0 to 7
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';

  
  //check valid input
  if (!valid_input(src_row,src_col,des_row, des_col)){
    cout << "It is not valid input of source or destination position" << endl;
    return;
  }
  
  //check source is empty or not
  if (board[src_row][src_col] == nullptr){
    
    cout << "There is no piece at position " << source <<"!" << endl;
    return;
  }
 
  //check whether it is this piece's turn to move  
  if (!is_turn(src_row, src_col)) {
    cout << "It is not "
	 << board[src_row][src_col]->print_colour()
         <<"'s turn to move." << endl;
    return ;
  }

  
  //check whether it is a valid move
  bool valid = board[src_row][src_col] -> valid_move(src_row, src_col, des_row, des_col,this);
  if (!valid) {
    cout << board[src_row][src_col]
         <<  " can not moves to "
	 << destination << "!" << endl;
    return ;
  }
  
  //if it is a valid move from source to destination and we can actually make move from here
  turn_count++;
  cout << board[src_row][src_col]
       << " moves from "
       << source << " to " << destination;

  //destination is not null we can take piece 
  capturePiece(des_row, des_col); 
  cout << endl;
  
  //execute the move and update the game state
  make_move (src_row, src_col, des_row, des_col);
  update_king_position(des_row, des_col);

  //record the color of its moving piece
  bool is_white_chess = board[des_row][des_col] ->is_white(); //moving piece's color

  // opponent_king record it's opponents's king's position
  int opponent_king_row = is_white_chess? black_king_row : white_king_row;
  int opponent_king_col = is_white_chess? black_king_col : white_king_col;
 
  //Post-move checks for check, checkmate, and stalemate
    postMoveChecks(is_white_chess, opponent_king_row, opponent_king_col);
  return;
}



//===========================================================================
//---------------------capturePiece()----------------------------------------
/**
 *Function to capture piece at destination
 *@param des_row: integer of row number destination
 * @param des_col: integer of col number for destination
 *@return void
 **/
void ChessBoard::capturePiece(int des_row, int des_col){
  if (board[des_row][des_col]){
    cout << " taking " << board[des_row][des_col];
    delete board[des_row][des_col];
    board[des_row][des_col] = nullptr; //avoid dangling pointer
  }
}


//===========================================================================
//---------------------postMoveChecks()----------------------------------------
/**
 *Function to check out whether the given color piece can make further move
 *@param is_white_chess: is the bool variable and stands for colour of piece whether white or not
 *@param opponent_king_row: integer of row number for opponent's king
 * @param opponent_king_row: integer of col number for opponent's king
 *@return void
 **/
void ChessBoard::postMoveChecks(bool is_white_chess, int opponent_king_row, int opponent_king_col){
  //check whether after this move make its opponent in check
  if (in_check(is_white_chess,opponent_king_row, opponent_king_col)){
    //in_check and also in checkmate
    if (!AnyPossibleMove (!is_white_chess)){
      cout << ((is_white_chess) ?  "Black" : "White" )
	      << " is in checkmate" << endl;
      } else {
      //in check but there exists possible move to save it
        cout << ((is_white_chess) ? "Black" : "White")
	      << " is in check" << endl;
      } 
  } else if(!AnyPossibleMove (!is_white_chess)){
      cout << ((is_white_chess) ?  "Black" : "White" )
	   << " is in stalemate" << endl;
  }
}

//Note: this function helps with debug, didn't use it in this program
/**
 * Function to print out the current chessboard
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
**/
