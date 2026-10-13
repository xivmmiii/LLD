#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "stdRules.hpp"
#include "Board.hpp"
using namespace std;

int Player::idCounter = 1;
int main()
{
    cout << "WELCOME TO TIC-TAC-TOE GAME" << endl;
    cout << "It is a two-player game" << endl;

    string player1Name, player2Name;
    char player1Symbol, player2Symbol;

    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Enter Player 1 symbol: ";
    cin >> player1Symbol;

    cout << "Enter Player 2 name: ";   
    cin >> player2Name;
    cout << "Enter Player 2 symbol: ";
    cin >> player2Symbol;

    Player player1(player1Name, Symbol(player1Symbol));
    Player player2(player2Name, Symbol(player2Symbol));

    int boardSize;
    cout << "What board size do you want to play in"<<endl;
    cin >> boardSize;

    Game game(boardSize, new stdRules());
    game.addPlayer(player1);
    game.addPlayer(player2);

    game.displayBoard();
    game.playGame();

    return 0;
}
