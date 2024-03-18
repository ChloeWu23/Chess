# Chess Game Simulation in C++

## Problem Statement

This project is designed to simulate chess games and manage the game state on the chessboard. Starting with the initial configuration of a chess game, it allows players to move their pieces alternately, as is standard in chess, with one player controlling the white pieces and the other controlling the black pieces. It focuses on implementing the rules of chess, managing the game state, and allowing two players to play a game of chess through a terminal interface.

The project evaluates whether each move is valid and determines if either king is in check or stalemate, ultimately assessing if the game has finished or not.




Note That:
* Specific Rules of each piece's movement and when to finish the game are given in `description.pdf`
* Given several famous chess games with different results for testing
* to be supplemented


## Class Design

The UML diagram is below:
![can't find](https://github.com/ChloeWu23/ChessBoard/blob/main/uml.png?raw=true)




## Features
1. Initialization: 

    Set up a chessboard with all pieces in their starting positions.

2. Piece Movement

3. Game State Management: 

    check for in check, checkmate, and stalemate.
    
4. User Interaction: 

    Allow players to input their moves in standard chess notation.(e.g.: E2 to E4) and see the progress.


## Compilation and Running

1. Ensure having C++ compiler(such as GCC or Clang) intalled in system.

2. Complile with running `makefile` :
    
    `make ./chess`: make executable files for cpp

    `./chess`: run compiled program to start the game and check terminal output




