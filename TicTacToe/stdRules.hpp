#pragma once
#include <iostream>
#include "Rules.hpp"
using namespace std;

class stdRules : public Rules
{
public:
    stdRules() {}

    bool checkWin(Board board, int row, int col, Symbol symbol) override
    { // initialisation for winning
        bool isWin = true;

        // rule for a matching row
        for (int i = 0; i < board.getSize(); i++)
        {
            if (board.getCellSymbol(row, i) != symbol.getSymbol())
            {
                isWin = false;
                break;
            }
        }
        if (isWin)
            return isWin;

        // rule for a matching column
        isWin = true;
        for (int i = 0; i < board.getSize(); i++)
        {
            if (board.getCellSymbol(i, col) != symbol.getSymbol())

            {
                isWin = false;
                break;
            }
        }
        if (isWin)
            return isWin;

        // rule for a matching diagonal
        isWin = true;
        for (int i = 0; i < board.getSize(); i++)
        {
            if (board.getCellSymbol(i, i) != symbol.getSymbol())
            {
                isWin = false;
                break;
            }
        }
        if (isWin)
            return isWin;

        // rule for a matching anti-diagonal
        isWin = true;
        for (int i = 0; i < board.getSize(); i++)
        {
            if (board.getCellSymbol(i, board.getSize() - 1 - i) != symbol.getSymbol())
            {
                isWin = false;
                break;
            }
        }
        return isWin;
    }

    bool checkDraw(Board board) override
    {
        for (int i = 0; i < board.getSize(); i++)
        {
            for (int j = 0; j < board.getSize(); j++)
            {
                if (board.isCellEmpty(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidMove(Board board, int row, int col) override
    {
        return board.isCellEmpty(row, col);
    }

    ~stdRules() {}
};
