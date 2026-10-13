#pragma once
#include <iostream>
#include <queue>
#include "Board.hpp"
#include "Player.hpp"
#include "stdRules.hpp"

using namespace std;

class Game
{
private:
    Board board;
    Rules *rules;
    bool gameOver;
    queue<Player> players;

public:
    Game(int boardSize, Rules *rules) : board(boardSize), rules(rules), gameOver(false) {}
    // rules(rules) here means rules will belong to the class the rules will belong to, outside game g(new stdRules()) will be passed and rules will become the object of stdRules and have a pointer of type Rules)
    void addPlayer(Player player)
    {
        players.push(player);
    }
    void changeTurn()
    {
        Player player = players.front();
        players.pop();
        players.push(player);
    }
    void playGame()
    {
        while (!gameOver)
        {
            Player currPLayer = players.front();
            cout << currPLayer.getName()
                 << "'s turn : " << endl;
            cout << "Enter row and col index to make a move" << endl;

            auto [row, col] = currPLayer.makeMove();

            if (rules->isValidMove(this->board, row, col))
            {
                this->board.placeSymbol(row, col, currPLayer.getSymbol());
                if (rules->checkWin(this->board, row, col, currPLayer.getSymbol()))
                {
                    gameOver = true;
                    this->displayBoard();

                    cout << currPLayer.getName() << " won the game" << endl;
                    continue;
                }
                if (rules->checkDraw(this->board))
                {
                    gameOver = true;
                    this->displayBoard();

                    cout << "The game has been drawn" << endl;
                    continue;
                }
            }
            else
            {
                cout << "Invalid move. Try Again!!" << endl;
                continue;
            }
            this->displayBoard();
            players.pop();
            players.push(currPLayer);
        }
    }
    void displayBoard()
    {
        this->board.displayBoard();
    }
};