#include<iostream>
#include"ChessBoard.h"
#include<cmath>
#include<cstring>
using namespace std;

//int ChessBoard:: pawn_count = 0;

//esbool ChessBoard:: in_check = false;
/*Function defination */

/*Function to initialize the board */
void ChessBoard::initialize_board(){
  cout << "A new chess game is started!" << endl;
  board[0][0] = new Castle(White);
  board[0][1] = new Knight(White);
  board[0][2] = new Bishop(White);
  board[0][3] = new Queen(White);
  board[0][4] = new King(White);
  board[0][5] = new Bishop(White);
  board[0][6] = new Knight(White);
  board[0][7] = new Castle(White);
  
  for(int j=0; j<8; j++){
    board[1][j] = new Pawn(White);
  }
  
  for(int j=0; j<8; j++){
    board[6][j] = new Pawn(Black);
    
  }
  
  board[7][0] = new Castle(Black);
  board[7][1] = new Knight(Black);
  board[7][2] = new Bishop(Black);
  board[7][3] = new Queen(Black);
  board[7][4] = new King(Black);
  board[7][5] = new Bishop(Black);
  board[7][6] = new Knight(Black);
  board[7][7] = new Castle(Black);
  
  for(int i=2; i < 6; i++){
    for(int j=0; j < 8; j++){
      board[i][j] = NULL;
    }
  }
  
}
//===========================================================================
/*Constructor of ChessBoard */
ChessBoard::ChessBoard(){
  initialize_board();
  white_king_position = "E1";
  black_king_position = "E8";
  //black_in_check = 0;
  //white_in_check = 0;
  //turn_count = 0;
}


//============================================================================
//------------------------resetboard()-----------------------------------------
/* Function to reset the board */
void ChessBoard::resetBoard(){
  initialize_board();
  turn_count = 0;
  white_king_position = "E1";
  black_king_position = "E8";
  black_in_check = 0;
  white_in_check = 0;
}


//============================================================================
//------------------get_board()-----------------------------------------
/*Function to get element of the board*/
Piece*ChessBoard::get_board(int r, int c){
  return board[r][c];

}


//===========================================================================
/*Function to check destination and source in the same row*/
bool ChessBoard::is_same_row(const char* source, const char* destination){
  int src_row = source[1]-'1';
  int des_row = destination[1]-'1';
  if (src_row == des_row) return true;
  
  return false;
}


//===========================================================================
//--------------------is_same_col-------------------------------------

/*Function to check destination and source in the same column */
bool ChessBoard::is_same_col(const char* source, const char* destination){
  int src_col = source[0]-'A';
  int des_col = destination[0]-'A';
  if (des_col == src_col) return true;
  
  return false;
}

//===========================================================================
//----------------------is_same_diagonal-----------------------------

/*Function to check whether source and destination are diagnal.*/
bool ChessBoard::is_same_diagonal(const char* source, const char* destination){
  int src_row = source[1]-'1'; 
  int src_col = source[0]-'A';
  int des_row = destination[1]-'1';
  int des_col = destination[0]-'A';
  if ((src_row - des_row) == (src_col - des_col)) return true;
  if (abs(src_row - des_row) == abs(src_col - des_col) && signbit(src_row - des_row) !=signbit(src_col - des_col)) return true; 
  
  return false;
  
}



//===========================================================================
//-------------------------is_row_clear()
/*Function to check whether its empty for the row between source and destination*/
bool ChessBoard:: is_row_clear(const char* source, const char* destination){
  bool flag = true;
  int src_row = source[1]-'1';
  //int des_row = destination[1]-'1';  
  int src_col = source[0]-'A';
  int des_col = destination[0]-'A';
  if (is_same_row(source,destination)){
    int x,y;//x save small number of column
    if(src_col <= des_col) {
      x = src_col;
      y = des_col;
    } else{
      x = des_col;
      y = src_col;
    }
    
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

/*Function to check whethter its empty for the column between source and destination */
bool ChessBoard:: is_col_clear(const char* source, const char* destination){
  bool flag = true;
  int src_row = source[1]-'1';
  int des_row = destination[1]-'1';  
  int src_col = source[0]-'A';
  // int des_col = destination[0]-'A';
  
  if (this -> is_same_col(source,destination)){
    int x,y;//x save small number of row
    if(src_row <= des_row) {
      x = src_row;
      y = des_row;
    } else{
      x = des_row;
      y = src_row;
    }
    
    for (int i= x+1; i <  y ; i++)
      {
	if(board[i][src_col] != NULL) flag = false; 
      }
    
    if (flag == true) return true;
  }
  return false; 
  
}

//===============================================================
/*Function to check whether its empty for the diagnol between source and destination */
bool ChessBoard::is_diag_clear(const char* source, const char* destination){
  //bool valid = false;
  //bool flag = true; //to check between space are all empty
 
  int startx = source[1]-'1';
  int endx = destination[1]-'1';  
  int starty = source[0]-'A';
  int endy = destination[0]-'A';
  int numSteps = abs(endx - startx)-1; 
  //int xdir = signbit(endx-startx) ? -1 : 1; //signbit return true if it is negative inside
  //int ydir = signbit(endy-starty) ? -1 :1;
  
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

/*Function to make move of the piece*/
void ChessBoard::submitMove(const char* source, const char* destination){
  turn_count++;
  Piece* temp_piece;
  bool valid;
  int  source_row = source[1]-'1'; //decimal for row of source, from 0 to 7
  int  source_column = source[0]-'A';//decimal for column of source, from 0 to 7
  int des_row = destination[1]-'1';
  int des_column = destination[0]-'A';

  
  //check valid input
  if (!valid_input(source, destination)){
    turn_count--;
    return;
  }
  
  //check source is empty or not
  if (board[source_row][source_column] == NULL){
    cout << "There is no piece at position " << source <<"!" << endl;
    turn_count--;
    return;
  }
  
  //check whether it is this piece's turn to move  
  if(!is_turn(source)) {
    cout << "It is not " ;
    board[source_row][source_column]->print_colour();
    cout <<"'s turn to move." << endl;
    turn_count--;
    return ;
  }
  
  //check whether it is a valid move
  valid = board[source_row][source_column] -> valid_move(source, destination,this);
  if(!valid) {
    board[source_row][source_column]->print_colour();   
    cout <<"'s ";
    board[source_row][source_column] -> get_type();
    cout <<  " can not moves to "
	 << destination << "!" << endl;
    turn_count--;
    return ;
  }
  
  //if it is a valid move from source to destination and we can actually make move from here
  board[source_row][source_column]->print_colour();
  cout <<"'s " ;
  board[source_row][source_column] ->get_type();
  cout << " moves from "
       << source << " to " << destination;
  //is_opponent.. make sure destination is not null and different colour 
  if (board[des_row][des_column]){
    board[source_row][source_column]->print_colour();
    cout <<"'s " ;
    board[source_row][source_column] ->get_type();
    cout << " moves from "
	 << source << " to " << destination
	 << " taking " ;
    board[des_row][des_column]->print_colour();
    cout <<"'s " ;
    board[des_row][des_column] -> get_type();}
  
  temp_piece = board[des_row][des_column]; //temp document destination piece incase move back
  make_move(source,destination);
  cout << endl;
  
  //Document the color of its moving piece, get_colour returns 1 for White 0 for Black;
  bool colour_chess = board[des_row][des_column] ->get_colour(); //save its own colour, colour_chess is 1 if White
  const char* position;
  //update king's position
  update_king_position(destination);
  
  //position document itself's king's position
  position = colour_chess? white_king_position : black_king_position;
  //make sure this move won't let ltself in check, opponent's colour of chess won't move to its king's position)
  if (in_check(!colour_chess, position)){
    move_back(destination, source, temp_piece);
    update_king_position(source);
    //output ...
    board[source_row][source_column]->print_colour();   
    cout <<"'s ";
    board[source_row][source_column] -> get_type();
    cout <<  " can not moves to "
	 << destination << "!" << endl;
    turn_count--;
    return ;
  }
  
  //position now document it's opponents's king's position
  position = colour_chess? black_king_position: white_king_position;
  
  //check whether it let its opponent in check
  if(in_check(colour_chess,position)){
    //update flag of in_check state
    //if(colour_chess) black_in_check = 1;
    //else white_in_check = 0; 
    if (!is_checkmate(colour_chess)){
      //in_check but not checkmate
      cout << ((colour_chess) ?  "Black" : "White" )
	    << " is in check" << endl;
     } else{
       //check_mate
       cout << ((colour_chess) ? "Black" : "White")
	    << " is checkmate" << endl;
     }
  }
  
  //flag has been updated
 
  //check whether is checkmate
  /*put this in the beginning of the submit function, if it is checkmate then you can't move and return it is checkmate
    
    if(black_in_check && black's turn (count%2 ==0))){
    //check whether checkmate
    //e.g: Black now is in check and to test whether can save king 
    can_save_king(colour: Black){
//move king to the square where not under attack
if(move_king_safe(..) ) return true;//check all the posible positions king can goes and use in_check(colour, position)
//if moving piece now is not knight, then move to make it to be a interposed piece

//capture the checking piece: check if this moving piece is knight or not, if so check knight can 
if(caputure(..)
}

}
 
}


   */
}


//==========================================================================
//-----------------------in_check()----------------------------------------

/**Function check status of whether in_check
  Algorithm: for each its own piece try whether it can move to king's position
@param _colour is the colour of chess is moving now and _position is the opponent's King's position
@return true if it can be attacked
**/
bool ChessBoard::in_check(bool _colour, const char* _position){
  //int r = _position[1] - '1';
  //int c = _position[0] - 'A';
  for (char i ='A'; i <= 'H' ; i++){
    for (char j = '1'; j <= '8'; j++){
      //Note here gives sigmentation fault
      //char* source = NULL;
      //source[0] = i;
      //source[1] = j;
      const char* source = strcat(&i, &j);
      //cout << source[0] << source[1] <<endl;
      int r = j-'1';
      int column = i-'A';
      // if(board[r][column] != NULL) cout << i << j << endl;
      //cout << i << j << endl;
      if (board[r][column] != NULL && board[r][column] -> get_colour() == _colour){
	if (board[r][column] ->valid_move(source, _position,this)) return true;
      }
    }
  }
  return false;
}



//===========================================================================
//---------------------is_checkmate()----------------------------------------
/**
 *Function to check out whether it is in checkmate state
 *@param _colour is the colour of itself's  piece
 *@param white_king is the position of white king on the updated board
 *@param black_king is the position of black king on the updated board
 *@return true if it is in checkmate
 **/

/**
Algorithem: We know it is already in check and see whether can be saved by moving a piece.
 Run all the positions for source on the board for its opponents's piece to all the position on the board and see whether there is a valid move to make it's opponent not in check, if it is which means we can make possible move and the board won't get checkmate state
 **/
 bool ChessBoard::is_checkmate(bool _colour){
   
   //bool flag = true;
   //cout << "here1" << endl;
   for (char src_row = 'A' ; src_row <= 'H' ; src_row++){
     for (char src_col = '1'; src_col <= '8'; src_col++){
       for (char des_row = 'A'; des_row <= 'H'; des_row++){
	 for (char des_col = '1'; des_col <= '8'; des_col++){
	   //char* temp1 = NULL;
	   //char* temp2 = NULL;
	   //temp1[0] = src_row;
	   //temp1[1] = src_col;
	   //cout << temp1 << endl;
	   //temp2[0] = des_row;
	   //temp2[0] = des_col;
	   //const char* source = temp1;
	   //const char* destination = temp2;
	   const char* _source = strcat (&src_row,&src_col);
	   const char* _destination = strcat(&des_row, &des_col);
	  cout << "here2" << endl;
	  cout << "src_row: " <<src_row << endl;
	   cout << "src_col: " << src_col << endl;
	   cout << "des_row " << des_row << endl;
	   cout << "des_col " << des_col << endl;
	   cout << _source << endl;
	   cout << "here" << endl;
	   cout << _destination << endl;
	   if (board[src_col-'1'][src_row- 'A'] && board[src_col-'1'][src_row- 'A']->get_colour() != _colour && board[src_col-'1'][src_row- 'A'] -> valid_move(_source,_destination,this)) {
	     cout << "here3" << endl;
	     //make the move now and update king's position
	     Piece* temp_piece = board[src_col-'1'][src_row- 'A'];
	     //make the potential move
	     make_move(_source,_destination);
	     update_king_position(_destination);
	     bool check_colour = !_colour;
	     const char* position = check_colour ? black_king_position : white_king_position;
	     const char* position2 = check_colour ? white_king_position : black_king_position;
	     //move back after document
	     move_back(_source,_destination,temp_piece);
	     update_king_position(_source);
	     //check this move not make itself in_check;
	     if(!in_check(check_colour,position) && !in_check(!check_colour,position2)) return false;
	   }
	 }
       }
     }
   }
   
  return true;
 }



//===========================================================================
bool ChessBoard::is_turn(const char* source){
  bool flag = false;
  int  source_row = source[1]-'1'; 
  int  source_column = source[0]-'A';
  if(turn_count%2 == 1 && board[source_row][source_column] -> c == White )
    flag = true;
  if(turn_count%2 == 0 && board[source_row][source_column] -> c == Black )
    flag = true;
  
  return flag;

}


//=========================================================================
//------------------------is_opponent()------------------------------------

  /*Function to check whether it's opponents piece
    It returns true if both positions have pieces and have diferent colour
 */
bool ChessBoard::is_opponent(const char* source,const char* destination){
  int src_row = source[1] - '1';
  int src_col = source[0] - 'A';
  int des_row = destination[1] - '1';
  int des_col = destination[0] - 'A';
  if (board[src_row][src_col] != NULL && board[des_row][des_col] != NULL)
    {
      if (board[src_row][src_col] -> get_colour() !=  board[des_row][des_col] -> get_colour()) return true; 
    }
  return false;
}



//============================================================================
//-----------------------------make_move()-----------------------------------
void ChessBoard::make_move (const char* source, const char* destination){
  int src_row = source[1] - '1';
  int src_col = source[0] - 'A';
  int des_row = destination[1] - '1';
  int des_col = destination[0] - 'A';
  board[des_row][des_col] = board[src_row][src_col];
  board[src_row][src_col] = NULL;
}



//===========================================================================
//---------------------move_back()---------------------------------------

void ChessBoard:: move_back (const char* source, const char* destination, Piece* _temp){
  int src_row = source[1] - '1';
  int src_col = source[0] - 'A';
  int des_row = destination[1] - '1';
  int des_col = destination[0] - 'A';
  board[src_row][src_col] = board[des_row][des_col];
  board[des_row][des_col] = _temp;
}



//===========================================================================
//-------------------------valid_input()--------------------------------------

bool ChessBoard::valid_input(const char* source, const char* destination){
  if (source[1] >= '1' && source[1] <= '8' && source[0] >='A' && source[0] <= 'H') return true;
  
  return false;
}


//============================================================================
//-------------------------update_king_position()----------------------------

void ChessBoard::update_king_position(const char* destination){
  int des_row = destination[1] - '1';
  int des_column = destination[0] - 'A';
  bool colour_chess = board[des_row][des_column] -> get_colour();//white is 1
  if (board[des_row][des_column] -> piece_type() == king){
    if (colour_chess) white_king_position = destination;
    else black_king_position = destination;
  }
}

//=========================================================================
const char* ChessBoard::get_black_king_position(){
  return black_king_position;
}

const char* ChessBoard:: get_white_king_position(){
  return white_king_position;
}
