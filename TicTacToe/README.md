TicTacToe (C++) - Version 1

A console-based TicTacToe game written in C++ as a low-level design (LLD) practice project. The focus of this project is clean object-oriented design: separating the board, the rules and the game flow so that each part can be changed or replaced independently.


OVERVIEW

Two players take turns placing their symbol on an N x N board. The game checks for a win or a draw after every move and ends when one of them happens. The board size is not hard-coded, so the same code works for 3x3 or larger boards.


DESIGN

The project is split into small classes, each with one responsibility.

Symbol
Represents a mark on the board (for example X, O or an empty cell). It stores a single character and provides getSymbol and setSymbol.

Board
Owns the grid of cells and the board size. It knows how to place a symbol, check whether a cell is empty, report the symbol at a cell, and display itself. It does not know anything about winning or whose turn it is.

Rules (abstract class)
Defines the contract every rule set must follow:
- checkWin: tells whether the last move wins the game
- checkDraw: tells whether the board is full with no winner
- isValidMove: tells whether a move is allowed
It has a virtual destructor so that objects can be safely deleted through a Rules pointer.

stdRules (derived from Rules)
The standard TicTacToe rules. A move wins if it completes a full row, a full column, the main diagonal or the anti-diagonal. Only the lines passing through the last move are checked, so a win check costs O(n) per move instead of scanning the whole board. A move is valid if it is inside the board and the cell is empty.

Player
Represents a participant. A player chooses a move and returns it as a row and column pair.

Game
Controls the flow of the game. It holds the Board, the players and a pointer to a Rules object, and runs the turn loop: ask the current player for a move, validate it, place it, check for a win or draw, then switch to the next player.


DESIGN IDEAS USED

- Abstraction and inheritance: Rules is an abstract base class and stdRules is one implementation.
- Runtime polymorphism: Game works through a Rules pointer, so a different rule set can be used without changing Game.
- Strategy pattern: the rules are a swappable behavior that is passed to Game.
- Separation of concerns: the board stores state, the rules decide outcomes, the game coordinates turns.
- Constructor initializer lists for member and base class initialization.


FILE STRUCTURE

Symbol.hpp     Symbol class
Board.hpp      Board class
Rules.hpp      abstract Rules class
StdRules.hpp   standard rules implementation
Player.hpp     Player class
Game.hpp       Game class
main.cpp       program entry point

Adjust the names above to match the actual files in the project.


REQUIREMENTS

- A C++17 compatible compiler (developed with g++ from MSYS2 UCRT64, version 16.2.0)
- Any terminal (PowerShell, Command Prompt or the VS Code terminal)


BUILD AND RUN

From the project folder, compile all source files together:

g++ -std=c++17 -Wall -Wextra *.cpp -o tictactoe

Run the program:

PowerShell:      .\TicTacToe
Command Prompt:  game.exe

If g++ is not recognized, add the MSYS2 folder (for example C:\msys64\ucrt64\bin) to your PATH and restart the terminal.


HOW TO PLAY

1. Start the program.
2. Players take turns entering a row and a column to place their symbol.
3. Invalid moves (outside the board or on a filled cell) are rejected and the player is asked again.
4. The game ends when a player completes a row, column or diagonal, or when the board is full (draw).

Rows and columns are numbered starting from 0.


KNOWN LIMITATIONS IN VERSION 1

- Only the standard rules are implemented.
- No automated tests yet.
- Draw detection scans the whole board each turn.
- The Rules object is managed with a raw pointer.
- Input validation is basic.


PLANNED IMPROVEMENTS

- Pass objects by const reference and make getters const throughout.
- Replace raw pointers with smart pointers (unique_ptr) so that cleanup is automatic.
- Add unit tests for win, draw and invalid-move cases.
- Track a move counter so draw detection takes constant time.
- Add a computer-controlled player.
- Add alternative rule sets (for example a variant where completing a line loses).
- Add a CMake or Makefile build.