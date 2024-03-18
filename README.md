# Chess Game Simulation in C++


## Table of Contents
1. [Problem Statement](#problem-statement)
2. [Design and Implementation](#design-and-implementation)
    - [OOP Design](#oop-design)
    - [Game State Management](#game-state-management)
    - [User Interaction](#user-interaction)
3. [Compilation and Running](#compilation-and-running)
    - [Compiling the Project](#compiling-the-project)
    - [Running the Game](#running-the-game)

4. [Testing and Debugging](#testing-and-debugging)
    - [Test Cases](#test-cases)
    - [Debugging Strategies](#debugging-strategies)



   

# Problem Statement

This project is designed to simulate chess games and manage the game state on the chessboard. Starting with the initial configuration of a chess game, it allows players to move their pieces alternately, as is standard in chess, with one player controlling the white pieces and the other controlling the black pieces. It focuses on implementing the rules of chess, managing the game state, and allowing two players to play a game of chess through a terminal interface.

The project evaluates whether each move is valid and determines if either king is in check or stalemate, ultimately assessing if the game has finished or not.




Note That:
* Specific Rules of each piece's movement and when to finish the game are given in `./Asset/description.pdf`
* Given several famous chess games with different results for testing in `ChessMain.cpp`
* To be supplemented

# Design and Implementation

## OOP Design

The UML diagram is below:
![can't find](https://github.com/ChloeWu23/ChessBoard/blob/main/Asset/uml.png?raw=true)

* Class Hierarchy: abstract class `Piece`, serving as the base for individual piece class like `Bishop`, `Knight`, etc. 

* Polymorphism: in abstract class having virtual function like `valid_move` which will be overridden in child class. So it allows `ChessBoard` class to interact with pieces polymorphically. This design provide dynamic determination of valid move based during runtime. 

### Game State Management

* Board Representation: The chessboard is represented as a 2D array within the ChessBoard class, with each cell potentially holding a pointer to a `Piece `object. It allows easy access to pieces based on their positions on board.

* Move Validation: Move validation is a critical aspect of the project, implemented through a combination of the `valid_move` method in piece classes and additional checks in the `ChessBoard` class. This includes not only verifying the legality of a piece's movement pattern but also ensuring moves do not leave the player's king in check.

* Game State Detection: In order to detect in check and checkmate, iterating over potential moves of all pieces to identify threats to the king and determine if escape moves are available. The detection mechanism is invoked after every move to update the game state accordingly


### User Interaction
Allow players to input their moves in standard chess notation.(e.g.: E2 to E4) and see the progress.



## Compilation and Running

Ensure having C++ compiler(such as GCC or Clang) intalled in system.


### Compiling the Project
To compile the project, navigate to the project directory in your terminal and run the following command:

```bash
make ./chess
```
This command will compile the source files and create an executable named `chess`.

### Running the Game
```bash
./chess
```
The game will start in the terminal interface. You'll be prompted to enter moves in standard chess notation (e.g., "E2 to E4"). The board state will be displayed after each move, along with any important game state updates like checks or checkmates.

To make a move, enter the source and destination squares (e.g., "E2 E4"). The game will validate the move and update the board accordingly. For detailed rules and move options, refer to the description.pdf provided in the repository.


## Testing and Debugging

 Notably, the game was tested against several famous chess games to validate the implementation of chess rules and the game state management logic. 

## Test Cases

Key Testing Scenerios included:

* peice-specific rules
* which turn
* in check
* checkmate
* stalemate

## Debugging Strategies

* visualization: print board 
* unit test for each function of different piece
* Breakpoints and Step-Through: use gdb for C++ debugger and set breakpoints at critical sections of the code, allowing step through exectution 
* Peer Review


 
