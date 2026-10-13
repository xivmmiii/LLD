#pragma once
#include <iostream>
#include "Board.hpp"
using namespace std;

class Rules
{
public:
    virtual ~Rules() {};
    virtual bool checkWin(Board board, int row, int col, Symbol symbol) = 0;
    virtual bool checkDraw(Board board) = 0;
    virtual bool isValidMove(Board board, int row, int col) = 0;
    
};